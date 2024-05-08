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

int n = (1 << 16) + 1;
ll dp[M][4];

ll rec(int n, int lvl) {
	ll &res = dp[n][lvl];
	if (res != -1)
		return res;
	if (n == 1)
		return res = 0;

	if (!lvl) {
		if (n > 1)
			return res = INF;
		return res = 0;
	}
//	if (lvl == 1)
//		return res = (n - 1)*1ll*(n - 2)/2;
	
	res = INF;

	int lb = 1, rb = min(n - 1, 200);
	if (lvl == 1)
		lb = rb = n - 1;

	for (int g = lb; g <= rb; ++g) {
		int s = (n - 1)/g;
		int b = s + 1;

		int cb = (n - 1) % g;
		int cs = g - cb;

		ll cost = cb*1ll*rec(b, lvl - 1) + cs*1ll*rec(s, lvl - 1) + (g - 1)*1ll*(g - 2) / 2;
//		ll cost = o*1ll*rec((n - 1) / g + 1, lvl - 1) + (g - o)*1ll*rec((n - 1) / g, lvl - 1) + (g - 1)*1ll*(g - 2) / 2;
		res = min(res, cost);
	}	

	return res;
}

void solve() {
	memset(dp, -1, sizeof dp);
	cout << rec(n, 3) << endl;
	cout << 6*(n -  1) << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}