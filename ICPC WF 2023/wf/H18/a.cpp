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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, w, h;

struct Point{
	int x, y;
	int get() {
		if (!y)
			return x;
		if (x == w)
			return w + y;
		if (y == h)
			return h + w + (w - x);

		assert(!x);
		return h + 2*w + (h - y);
	}
};


vi vals;
bool md[M];
int l[M], r[M], id[M*2], t[M << 3], lz[M << 3];
Point a[M], b[M], v[M*2];

void push(int v) {
	if (lz[v]) {
		lz[v << 1] += lz[v];
		t[v << 1] += lz[v];

		lz[v << 1 | 1] += lz[v];
		t[v << 1 | 1] += lz[v];

		lz[v] = 0;
	}
}


void update(int l, int r, int x, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		lz[v] += x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);
}


int get(int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (tl == tr)
		return tl;

	push(v);
	int tm = (tl + tr) >> 1;
	if (t[v << 1 | 1] == n)
		return get(v << 1 | 1, tm + 1, tr);
	return get(v << 1, tl, tm);
}

void f(pair < double, double > &p, double x) {
	if (p.s == 0)
		p.f += 0.5*x;
	else if (p.f == w)
		p.s += 0.5*x;
	else if (p.s == h)
		p.f -= 0.5*x;
	else {
		assert(p.f == 0);
		p.s -= 0.5*x;
	}
}
 
void solve() {
	cin >> n >> w >> h;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;
		cin >> b[i].x >> b[i].y;

		l[i] = a[i].get();
		r[i] = b[i].get();
		if (l[i] > r[i]) {
			swap(a[i], b[i]);
			swap(l[i], r[i]);
		}
		vals.pb(l[i]);
		vals.pb(r[i]);
	}
	                                   x
	sort(all(vals));
	for (int i = 1; i <= n; ++i) {
		l[i] = lower_bound(all(vals), l[i]) - vals.begin();
		r[i] = lower_bound(all(vals), r[i]) - vals.begin();

		v[l[i]] = a[i];
		v[r[i]] = b[i];

		id[l[i]] = i;
		id[r[i]] = i;

		update(l[i], r[i], 1);
	}

	
	for (int i = 0; i < 2*n; ++i) {
		int j = id[i];
		if (t[1] == n) {
			int x = get();
			pair < double, double > p1 = mp(v[i].x, v[i].y);
			pair < double, double > p2 = mp(v[x].x, v[x].y);

			f(p1, -1);
			f(p2, -1);
			
			cout << 1 << "\n";				
			cout << p1.f << ' ' << p1.s << ' ';
			cout << p2.f << ' ' << p2.s << '\n';
			return;
		}

		if (!md[j]) {
			update(l[j], r[j], -1);
			update(0, l[j], 1);
			update(r[j], sz(vals) - 1, 1);
		} else {
			update(l[j], r[j], 1);
			update(0, l[j], -1);
			update(r[j], sz(vals) - 1, -1);
		}

		md[j] ^= 1;
	}

	cout << 2 << "\n";
	cout << 0 << ' ' << 0.5 << ' ' << w << ' ' << h - 0.5 << "\n";
	cout << 0 << ' ' << h - 0.5 << ' ' << w << ' ' << 0.5 << "\n";

}	

main () {
	cout << setprecision(6) << fixed;
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}