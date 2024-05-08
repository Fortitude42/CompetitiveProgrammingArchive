#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {}

	bool operator < (const Point &p) const  {
		return tie(x, y) < tie(p.x, p.y);
	}

	bool operator == (const Point &p) const  {
		return tie(x, y) == tie(p.x, p.y);
	}

	double angle() const {
		return atan2(y, x);
	}

	Point rotate(double a) const {
		return Point(round(x*cos(a) - y*sin(a)), round(x*sin(a) + y*cos(a)));
	}
};

Point a[3], b[3], c[3];
set < vi > q;

void check(int x, int y) {
	double an = atan2(y, x);
	vector < pii > v[2], vv[2];
	for (int i = 0; i < 3; ++i) {
		c[i] = a[i].rotate(an);
		v[0].pb(mp(c[i].x, b[i].x));
		v[1].pb(mp(c[i].y, b[i].y));
	}


	for (int i = 0; i < 2; ++i) {
		sort(all(v[i]));
		if (v[i][0].f == v[i].back().f) {
			if (v[i][0].s == v[i][1].s && v[i][0].s == v[i][2].s) {
				vv[i].pb(mp(0, 0));
				vv[i].pb(mp(0, 1));
			}
			continue;
		}

		int k = (v[i].back().s - v[i][0].s) / (v[i].back().f - v[i][0].f);
		int b = v[i][0].s - v[i][0].f*k;

		bool ok = 1;
		for (auto tmp : v[i])
			if (k*tmp.f + b != tmp.s) {
				ok = 0;
				break;
			}

		if (k != 0 && ok)
			vv[i].pb(mp(k, b));				
	}

//	cout << sz(vv[0]) << ' ' << sz(vv[1]) << endl;
	for (auto i0 : vv[0])
		for (auto i1 : vv[1]) {
			vi cur = {x, y, i0.f, i0.s, i1.f, i1.s};
			q.insert(cur);
		}			
}

void check() {
	for (int x = -10; x <= 10; ++x) {
		check(x, 10);
		check(x, -10);
		check(10, x);
		check(-10, x);
	}
			
}
 
void solve(int tt) {
	for (int i = 0; i < 3; ++i)
		cin >> a[i].x >> a[i].y;

	if (a[0] == Point(0, 0) && a[0] == a[1] && a[0] == a[2]) {
		exit(0);
	}

	for (int i = 0; i < 3; ++i)
		cin >> b[i].x >> b[i].y;

	sort(a, a + 3);
	q.clear();
	do {
		check();
	} while (next_permutation(a, a + 3));

	cout << "Case " << tt << ": ";

	if (!sz(q)) 
		cout << "no solution";
	else if (sz(q) == 2)
		cout << "equivalent solutions";
	else
		cout << "inconsistent solutions";
	cout << "\n";
}

main () {
	fastio
  for (int tt = 1; ; ++tt) {
    solve(tt);
  }
}