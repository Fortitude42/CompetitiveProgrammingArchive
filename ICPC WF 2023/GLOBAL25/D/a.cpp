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

map < pii, int > dp;
map < pii, int > p;

int get(int n, int k) {
	if (!k)
		return 1;

	if (dp.count(mp(n, k)))
		return dp[mp(n, k)];

	for (int c = n; c > 0; --c) {
		int cur = n / c;
		if (k - cur >= 0 && get(n % c, k - cur) == 1)  {
			p[mp(n, k)] = c;
			dp[mp(n, k)] = 1;
			return 1;
		}
	}

	return dp[mp(n, k)] = 0;

}
 
void solve() {
	for (int n = 100; n <= 120; ++n)
		for (int k = 1; k <= n; ++k)
			if (get(n, k))
				cout << n << ' ' << k << ' ' << p[mp(n, k)] << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}