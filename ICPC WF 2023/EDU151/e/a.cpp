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
const int N = 150, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



int n, k, a[M], m; 
int dp[M][M][M];

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x)
			a[++m] = i;
	}

	dp[0][0][0] = 1;

	for(int i = 0; i < m; ++i)
		for (int s = 0; s <= k; ++s)
			for (int lst = 0; lst <= n; ++lst) {			
//				add(dp[i][s][lst + 1], dp[i][s][lst]);
				for (int lst1 = lst + 1; lst1 <= n; ++lst1)
					if (s + abs(lst1 - a[i + 1]) <= k)
						add(dp[i + 1][s + abs(lst1 - a[i + 1])][lst1], dp[i][s][lst]);
			}

//	cerr << dp[1][1][3] << endl;


	int ans = 0;
	for (int j = 0; j <= k; ++j)
		if (!((k - j) & 1)) {
			for (int lst = 1; lst <= n + 1; ++lst) {
				add(ans, dp[m][j][lst]);
				cerr << j << ' ' << lst << ' ' << dp[m][j][lst] << endl;
			}
		}

	cout << ans << endl;
}


main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}