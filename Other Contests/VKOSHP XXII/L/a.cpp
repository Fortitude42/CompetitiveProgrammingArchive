//template by paradox & gege & parasat
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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, k, a[M], b[M], c[M], d[M];
int sk[M], sm[M], ans, mn[M][20];
vi pos[M], rems, st;
 
void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

void build() {
	for (int i = 2; i <= n; ++i)
		d[i] = d[i >> 1] + 1;

	for (int i = 1; i <= n; ++i)
		mn[i][0] = c[i];

	for (int j = 1; j < 20; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}

int get(int l, int r) {
	int D = d[r - l + 1];
	return min(mn[l][D], mn[r - (1 << D) + 1][D]);
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		if (a[i] < b[i])
			swap(a[i], b[i]);

		sk[i] = (sk[i - 1] + a[i]) % k;
		sm[i] = (sm[i - 1] + a[i]) % MOD;
		c[i] = (a[i] % k) == (b[i] % k) ? inf : (a[i] - b[i]);
		rems.pb(sk[i]);

		add(ans, a[i] * 1ll * i % MOD * (n - i + 1) % MOD);
	}

	build();

	rems.pb(0);
	sort(all(rems));
	rems.resize(unique(all(rems)) - rems.begin());
	
	for (int i = 0; i <= n; ++i) {
		sk[i] = lower_bound(all(rems), sk[i]) - rems.begin();
		pos[sk[i]].pb(i);
	}


	for (int x = 0; x < sz(rems); ++x) {
		if (sz(pos[x]) <= 1)
			continue;

		int m  = sz(pos[x]) - 1;
		vi e(m), l(m), r(m), ss(m);
		//~calculate array e
		for (int y = 0; y < m; ++y) {
			e[y] = get(pos[x][y] + 1, pos[x][y + 1]);
			ss[y] = ((!y ? 0 : ss[y - 1]) + sm[pos[x][y]]) % MOD;
		}

		//~calculate array l
		st.clear();
		for (int y = 0; y < m; ++y) {
			while (sz(st) && e[st.back()] > e[y]) 
				st.ppb();

			l[y] = !sz(st) ? 0 : (st.back() + 1);
			st.pb(y);
		}

		//~calculate array r
		st.clear();
		for (int y = m - 1; y >= 0; --y) {
			while (sz(st) && e[st.back()] >= e[y])
				st.ppb();

			r[y] = !sz(st) ? (m - 1) : (st.back() - 1);
			st.pb(y);
		}


		int prv = -1;
		for (int y = 0; y < m; ++y) {
			if (e[y] == inf) {//~case when f(l, r) is zero
				add(ans, -sm[pos[x][y + 1]] * 1ll * (y - prv) % MOD);
				add(ans, ss[y]);
				if (prv != -1)
					add(ans, -ss[prv]);
			} else {
				add(ans, -1ll * (y - l[y] + 1) * (r[y] - y + 1) % MOD * e[y] % MOD);
				prv = y;
			} 
		}
	}

	printf("%d\n", ans);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}