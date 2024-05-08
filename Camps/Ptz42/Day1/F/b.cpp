//by paradox & gege & parasat
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

ll x;
vector < ll > G[5];
vi g[5];
int n, a[M], c[5], ind[5];
 
bool run() {
	c[1]++;

	for (int j = 1; j <= 3; ++j) {
		if (c[j] <= min(sz(g[j]), 12 / j))
			break;
		c[j] = 0;
		c[j + 1]++;
	}

	return c[4] <= min(sz(g[4]), 3);
}

void solve() {
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		if (a[i] % 5 > 0)
			g[5 - (a[i] % 5)].pb(a[i] + 5 - a[i] % 5);
	}

	int rem = x % 5;
	x -= (x % 5);
	
	for (int i = 0; i < 5; ++i)
		sort(all(g[i]));


	int ans = 0;
	do {
		int res = 0, Sz = 0;
		ll cur = 0;
		vector < ll > gg;

		for (int i = 1; i <= 4; ++i) {
			G[i].clear();
			ind[i] = 0;

			for (int j = 0; j < c[i]; ++j) {
				cur += g[i][j];
				res += i;
			}

			for (int j = c[i]; j + (12 / i) - 1 < sz(g[i]); j += (12 / i)) {
				ll s = 0;
				for (int x = 0; x < (12 / i); ++x)
					s += g[i][j + x];
				assert(!sz(G[i]) || G[i].back() <= s);	
				G[i].pb(s);
				++Sz;
			}
		}

		while (sz(gg) < Sz) {
			int i = 0;
			for (int j = 1; j <= 4; ++j)
				if (ind[j] < sz(G[j]) && (!i || G[j][ind[j]] < G[i][ind[i]]))
					i = j;

//			assert(i > 0);
//			assert(!sz(gg) || gg.back() <= G[i][ind[i]]);
			gg.pb(G[i][ind[i]++]);
		}

		for (int i = 0; i <= sz(gg); ++i) {
			if (cur > x)
				break;
			ans = max(ans, res);
			if (i < sz(gg)) {
				res += 12;		 
				cur += gg[i];
			}
		}
	} while (run());


	cout << ans + rem << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

