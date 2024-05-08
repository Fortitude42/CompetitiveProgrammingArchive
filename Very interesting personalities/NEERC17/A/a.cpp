//by paradox & gege & parasat
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
typedef tree < pii, null_type, less < pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e5, inf = 2e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi vals;
pii L, R;
set < pii > q[M << 2];
int n, t[M], x[M], y[M], ind[M];

void upd(int pos, pii x, bool add, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (add)
		q[v].insert(x);
	else
		q[v].erase(x);

	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(pos, x, add, v << 1, tl, tm);
	else
		upd(pos, x, add, v << 1 | 1, tm + 1, tr);
}

void get(int l, int r, int X, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		auto it = q[v].lower_bound(mp(X, 0));
		if (it != q[v].end())
			R = min(R, *it);
		if (it != q[v].begin()) {
			it--;
			L = max(L, *it);
		}

		return;
	}

	int tm = (tl + tr) >> 1;
	get(l, r, X, v << 1, tl, tm);
	get(l, r, X, v << 1 | 1, tm + 1, tr);
}

ll f(int i, int j) {
	return (x[i] - x[j]) * 1ll * (x[i] - x[j]) + (y[i] - y[j]) * 1ll * (y[i] - y[j]) - y[i] * 1ll * y[i];
}


void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
		if (t[i] == 1)
			vals.pb(y[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	for (int i = 1; i <= n; ++i) {
		if (t[i] == 1) {
			ind[i] = lower_bound(all(vals), y[i]) - vals.begin();
			upd(ind[i], mp(x[i], i), 1);
		} else {
			int j = lower_bound(all(vals), (y[i] + 1) / 2) - vals.begin();
			
			L = mp(-inf, -1);
			R = mp(inf, -1);
			get(j, sz(vals) - 1, x[i]);

			pair < ll, int > res = mp(INF, -1);
			if (L.s > 0)
				res = min(res, mp(f(L.s, i), L.s));
			if (R.s > 0)
				res = min(res, mp(f(R.s, i), R.s));

			if (res.f >= 0)
				printf("-1\n");
			else {
				printf("%d\n", res.s);
				upd(ind[res.s], mp(x[res.s], res.s), 0);
			}
		}
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                                      