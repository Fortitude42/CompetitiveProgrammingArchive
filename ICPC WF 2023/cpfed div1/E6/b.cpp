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
const int N = 1e2 + 5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n;
double dp[M][M];

void solve() {
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int h = 1; h <= i; ++h) {
			for (int j1 = 0; j1 < i; ++j1) {
				int j2 = i - 1 - j1;
				for (int h1 = 0; h1 <= h - 1; ++h1)
					for (int h2 = 0; h2 <= h - 1; ++h2) {
						if (max(h1, h2) != h - 1)
							continue;
						dp[i][h] += dp[j1][h1]*dp[j2][h2];
//						cout << i << ' ' << h << endl;
//						cout << j1 << ' ' << h1 << endl;
//						cout << j2 << ' ' << h2 << endl << endl;
					}
			}
			
			dp[i][h] /= i;
		}
		
	cout << fixed << setprecision(6);
	for (int h = 1; h <= n; ++h)
		cout << dp[n][h] << endl;
}

main () {
	fastio
	int TT = 1;
 	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}