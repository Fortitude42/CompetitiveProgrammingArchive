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

int n, k, j, g, s[M];
map < int, int > dp[M];


int rec(int pk, int pj) {
	if (dp[pk].count(pj))
		return dp[pk][pj];

	int nk = pk + k, nj = pj + j;
	if (min(nk, nj) > n)
		return dp[pk][pj] = 0;

	if (nk == nj)
		return dp[pk][pj] = min(rec(nk - 1, pj), rec(pk, nj - 1)) + 1;

	int d = (((pj - pk) % j) + j) % j;
	int x = s[d];
	if (x == -1 || pk + x*k > n)
		return dp[pk][pj] = (n - pk) / k + (n - pj) / j;

	int m = pk + x*k;
	int y = (m - pj) / j;
	return dp[pk][pj] = rec(pk + (x - 1)*k, pj + (y - 1)*j) + x - 1 + y - 1;
}
 
void solve() {
	cin >> k >> j >> n;
	memset(s, -1, sizeof s);

	for (int x = 1; x <= j; ++x) {
		int y = k*1ll*x % j;
		if (s[y] == -1)
			s[y] = x;
	}

	cout << rec(0, 0) << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}