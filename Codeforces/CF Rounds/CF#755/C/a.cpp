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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, a[M];
vi pos[M][2];
vector < ll > vals;
ll s[M][2], b[M], t[M << 2][2];

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v][tl & 1] = b[tl];
		t[v][(tl + 1) & 1] = INF;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);

	for (int j = 0; j < 2; ++j)
		t[v][j] = min(t[v << 1][j], t[v << 1 | 1][j]);
}                                                            

int get(int l, int r, int lvl, ll x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr || t[v][lvl] >= x)
		return n + 1;

	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;
	if (l <= tl && tr <= r) {
		if (t[v << 1][lvl] < x)
			return get(l, r, lvl, x, v << 1, tl, tm);
		return get(l, r, lvl, x, v << 1 | 1, tm + 1, tr);
	}

	int a = get(l, r, lvl, x, v << 1, tl, tm);
	if (a < n + 1)
		return a;

	return get(l, r, lvl, x, v << 1 | 1, tm + 1, tr);
}
 

int find(int l, int r, ll x, int lvl) {
	int j = lower_bound(all(vals), x) - vals.begin();
	if (j == sz(vals) || x != vals[j])
		return 0;

	int lf = lower_bound(all(pos[j][lvl]), l) - pos[j][lvl].begin();
	int rg = upper_bound(all(pos[j][lvl]), r) - pos[j][lvl].begin() - 1;
	if (lf > rg)
		return 0;

	return rg - lf + 1;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j)
			s[i][j] = s[i - 1][j];
		
		int x = (i & 1);
		s[i][x] += a[i];
		b[i] = s[i][x] - s[i][x ^ 1];
		vals.pb(b[i]);
//		cerr << s[i][0] << ' ' << s[i][1] << endl4;
//		cerr << b[i] << endl;
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	for (int i = 1; i <= n; ++i) {
		int x = (i & 1);
		int j = lower_bound(all(vals), b[i]) - vals.begin();
		pos[j][x].pb(i);
	}

	build();

	ll ans = 0;

	for (int l = 1; l <= n; ++l) {
		ll x = b[l - 1];
		if (!(l & 1))
			x = -x;

		int R = min(get(l, n, 0, x), get(l, n, 1, -x)) - 1;
//		cerr << x << ' ' << R << endl;
		if (R < l)
			continue;

		ans += find(l, R, x, 0);
		ans += find(l, R, -x, 1);
	}

	printf("%lld\n", ans);
//	cerr << ans << endl;

	for (int i = 0; i < sz(vals); ++i)
		for (int j = 0; j < 2; ++j)
			pos[i][j].clear();

	vals.clear();
}

main () {
  	int TT;
  	TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}