#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 2e9, maxn = 5e6 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, q, xc[N], yc[N], r[N], xa[N], ya[N], xb[N], yb[N], ymn[N], ymx[N], t[(N*3) << 2];
vector < pair < int, pii > > V;
bool res[N];
vi X; 
 
void build (int v = 1, int tl = 0, int tr = N*3 - 1) {
	t[v] = -inf;
	if (tl == tr)
		return;
 
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}
 
void update (int pos, int x, int v = 1, int tl = 0, int tr = N*3 - 1) {
	t[v] = max(t[v], x);
	if (tl == tr)
		return;
 
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
}
 
 
int get (int l, int r, int v = 1, int tl = 0, int tr = N*3 - 1) {
	if (l > r || l > tr || tl > r)
		return -inf;
 
	if (l <= tl && tr <= r)
		return t[v];
 
	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}
 
 
 
 
 
main () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &xc[i], &yc[i], &r[i]);
		X.pb(xc[i]);
	}
 
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i], &ymn[i], &ymx[i]);
		if (xa[i] > xb[i]) {
			swap(xa[i], xb[i]);
			swap(ya[i], yb[i]);
		}
 
		X.pb(xa[i]);
		X.pb(xb[i]);
	}
 
 
 
	sort(all(X));
	X.resize(unique(all(X)) - X.begin());
	
	for (int i = 1; i <= n; ++i) {
		xc[i] = lower_bound(all(X), xc[i]) - X.begin();
		V.pb(mp(yc[i] - r[i], mp(0, i)));
	}
 
	for (int i = 1; i <= q; ++i) {
		xa[i] = lower_bound(all(X), xa[i]) - X.begin();
		xb[i] = lower_bound(all(X), xb[i]) - X.begin();
		V.pb(mp(ymn[i], mp(1, i)));
	}
 
	sort(all(V));
 
	build();
	for (auto x : V) {
		int i = x.s.s, tp = x.s.f;
		if (!tp) 
			update(xc[i], yc[i] + r[i]);
		else {
			if (get(xa[i], xb[i]) >= ymx[i])
				res[i] = 0;
			else
				res[i] = 1;
		}
	}
 
	for (int i = 1; i <= q; ++i)
		puts(res[i] ? "YES" : "NO");
 
}
