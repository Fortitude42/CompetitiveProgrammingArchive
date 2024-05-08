#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

struct Point{
	ll x, y, id;

	Point(): x(0), y(0){}

	Point(int x, int y): x(x), y(y) {}

	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}

	ll cross(const Point &p) const{
		return x*p.y - y*p.x;
	}

	ll cross(const Point &a, const Point &b) {
		return (a - *this).cross(b - *this);
	}

	int sector() const {
		if (x >= 0 && y >= 0)
			return 0;

		if (x >= 0 && y < 0)
			return 1;

		if (x < 0 && y < 0)
			return 2;

		return 3;
	}
};


bool cmp(const Point &p1, const Point &p2) {
	if (p1.sector() != p2.sector())
		return p1.sector() < p2.sector();

	return p1.cross(p2) < 0;
}


int n, lw[M][M];
Point p[M], tmp[M*3];
Point k[M][M], b[M][M];


Point normalize(Point p) {
	if (!p.x)
		return Point(0, 0);

	if (!p.y)
		return Point(1, 0);

	bool neg = 0;
	if (p.x < 0) {
		neg ^= 1;
		p.x = -p.x;
	}

	if (p.y < 0) {
		neg ^= 1;
		p.y = -p.y;
	}

	int g = __gcd(p.x, p.y);
	p.x /= g;
	p.y /= g;

	return Point(neg ? -p.x : p.x, p.y);
}

int get(int x) {
	int y = 1;
	while (y*(y - 1) / 2 < x)
		++y;

	assert(y*(y - 1)/2 == x);
	return y;
}

vector < pair < pii, pii > > g[M*M];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}


	for (int i = 1; i <= n; ++i) {
		int k = 0;
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				tmp[++k] = p[j] - p[i];
				tmp[k].id = p[j].id;
			}
			
		sort(tmp + 1, tmp + 1 + k, cmp);
		reverse(tmp + 1, tmp + 1 + k);
		for (int j = k + 1; j <= k + k + k; ++j)
			tmp[j] = tmp[j - k];


		int l = k - 1, r = k + 2;
		for (int j = k + 1; j <= k + k; ++j) {
			r = max(r, j);
			l = j - 1;
			r = j + 1;

			while (tmp[j].cross(tmp[r - 1]) < 0)
				r--;
			while (tmp[j].cross(tmp[l + 1]) < 0)
				l++;
			

			while (r < k + j && tmp[j].cross(tmp[r]) >= 0) 
				++r;

			while (l > j - k && tmp[j].cross(tmp[l]) >= 0)
				--l;

			lw[i][tmp[j].id] = min(n, r - l);
		}
	}

	vector < pii > vals;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			k[i][j] = normalize(p[i] - p[j]);
			if (!k[i][j].x)
				b[i][j] = Point(p[i].x, 1);
			else if (!k[i][j].y)
				b[i][j] = Point(p[i].y, 1);
			else 
				b[i][j] = normalize(Point(k[i][j].x, p[j].y*k[i][j].x - p[j].x*k[i][j].y));
			
			vals.pb(mp(k[i][j].x, k[i][j].y));
		}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			int x = lower_bound(all(vals), mp(k[i][j].x, k[i][j].y)) - vals.begin();
			g[x].pb(mp(mp(b[i][j].x, b[i][j].y), mp(i, j)));
		}

	set < vector < pii > > ans;
	ans.insert({mp(1, n)});

	for (int i = 0; i < sz(vals); ++i) {		
		vector < pii > cur;
		vector < pii > v;

		sort(all(g[i]));
		for (int j = 0; j < sz(g[i]); ) {
			int jj = j, cnt = 0;
			while (jj < sz(g[i]) && g[i][jj].f == g[i][j].f) {
				++cnt;
				++jj;
			}

			
			int i1 = g[i][j].s.f, i2 = g[i][j].s.s;
			if (mp(p[i1].x, p[i1].y) < mp(p[i2].x, p[i2].y)) 
				swap(i1, i2);

			v.pb(mp(lw[i1][i2], get(cnt)));
			j = jj;
		}

		sort(all(v));

		for (int j = 0; j < sz(v); ++j) {
			cur.pb(mp(1, v[j].f - v[j].s - (!j ? 0 : v[j - 1].f)));
			cur.pb(mp(v[j].s, 1));
		}

		cur.pb(mp(1, n - v.back().f));

		vector < pii > cur1;
		for (int j = 0; j < sz(cur); ) {
			if (cur[j].s <= 0) {
				j++;
				continue;
			}

			int sum = 0, j1 = j;
			while (j1 < sz(cur)) {
				if (cur[j1].s <= 0) {
					j1++;
					continue;
				}

				if (cur[j1].f != cur[j].f)
					break;
				sum += cur[j1++].s;
			}

			cur1.pb(mp(cur[j].f, sum));
			j = j1;
		}
/*
		for (auto x : v)
			cout << x.f << ' ' << x.s << endl;
		cout << endl;
		for (auto x : cur1)
			cout << x.f << ' ' << x.s << endl;
		cout << endl << endl;*/

		ans.insert(cur1);
		reverse(all(cur1));
		ans.insert(cur1);
	}


	cout << sz(ans) << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}