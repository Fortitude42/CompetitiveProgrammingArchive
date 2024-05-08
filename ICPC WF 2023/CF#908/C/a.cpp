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


int m; 
ll l[M], r[M], sc[M];
int n[M];
map < ll, ll > cnt;
map < ll, vector < pii > > g;
vector < ll > a[M], c[M];

void solve() {
	scanf("%d", &m);
	ll mn = 0, mx = 0, sumc = 0;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%lld%lld", &n[i], &l[i], &r[i]);

		mn = min(INF, l[i]+mn);
		mx = min(INF, r[i]+mx);
		a[i].resize(n[i]);
		c[i].resize(n[i]);

		for (int j = 0; j < n[i]; ++j) {
			scanf("%lld", &a[i][j]);					
			g[a[i][j]].pb({i, j});
		}

		for (int j = 0; j < n[i]; ++j) {
			scanf("%lld", &c[i][j]);			
			cnt[a[i][j]] += c[i][j];
			sumc += c[i][j];
			sc[i] += c[i][j];
		}
		
	}


	ll ans = INF;
	for (ll x = mn; x <= mx; ++x) {
		if (!cnt.count(x)) {
			ans = 0;
			break;
		}
		
		ll need = x, took = 0;
		need -= mx;
		for (auto [i, j] : g[x]) {
			need += r[i];

			ll others = min(r[i], sc[i] - c[i][j]);
			if (others < l[i]) {
				took += l[i] - others;
				others = l[i];
			}
			need -= others;
		}

		ans = min(ans, took + max(0ll, need));
	}

	printf("%lld\n", ans);

	cnt.clear();
	g.clear();
	sumc = 0;
	for (int i = 1; i <= m; ++i)
		sc[i] = 0;
}

main () {
  int TT;
  TT = 1;
  	scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}