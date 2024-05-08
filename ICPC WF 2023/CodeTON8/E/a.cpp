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
const int N = 500, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int l, n;
int dp[M][M][M], s[M];
 
int solve(int l, int n) {
	memset(dp, 0, sizeof dp);
	memset(s, 0, sizeof s);

	for (int i = 1; i <= l; ++i)
		dp[i][1][0] = 1;

	for (int lst = 1; lst < l; ++lst)
		for (int cnt = 1; cnt < 2*n; ++cnt)
			for (int mx = 0; mx <= l; ++mx)
				for (int nxt = lst + 1; nxt <= l; ++nxt) {
					int nmx = mx;
					if (cnt & 1)
						nmx = max(nmx, nxt - lst);

				    int &cur = dp[nxt][cnt + 1][nmx];
					cur = (cur + dp[lst][cnt][mx]) % MOD;
					if (cnt + 1 == 2*n)
						s[nmx] = (s[nmx] + dp[lst][cnt][mx]) % MOD;
				}

	int ans = 0;
	for (int mx = l - 1; mx <= l; ++mx)
		if (!(mx & 1))
			ans = (ans + s[mx]) % MOD;

	return ans % MOD;
}
/*
void solve() {
	int l, n;
	cin >> l >> n;
	cout << solve(l, n) << "\n";
}
*/
main () {
  int TT;
  TT = 1;
  for (int l = 10; l <= 10; ++l)
  	for (int n = 1; 2*n <= l; ++n)
  		cout << solve(l, n) << ' ';
/*
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
*/
}