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
const int N = 500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, rc[M], cc[M];
char c[M][M], ans[M][M];
 
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> c[i][j];
			ans[i][j] = '.';
		}

	for (int i = 1; i <= n; ++i)
		rc[i] = 0;
	for (int j = 1; j <= m; ++j)
		cc[j] = 0;

	for (int j = 1; j <= m; ++j)
		for (int i = 1; i <= n; ++i)
			if (c[i][j] == 'L') {
				if (!cc[j]) {
					ans[i][j] = 'W';
					ans[i][j + 1] = 'B';
				} else {
					ans[i][j] = 'B';
					ans[i][j + 1] = 'W';
				}
				cc[j] ^= 1;
				cc[j + 1] ^= 1;
			}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (c[i][j] == 'U') {
				if (!rc[i]) {
					ans[i][j] = 'W';
					ans[i + 1][j] = 'B';
				} else {
					ans[i][j] = 'B';
					ans[i + 1][j] = 'W';
				}
				rc[i] ^= 1;
				rc[i + 1] ^= 1;
			}

	bool ok = 1;
	for (int i = 1; i <= n; ++i)
		if (rc[i])
			ok = 0;

	for (int j = 1; j <= m; ++j)
		if (cc[j])
			ok = 0;

	if (!ok) {
		cout << -1 << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << ans[i][j];
		cout << '\n';
	}

}


main () {
	fastio
  int TT;
  TT = 1;
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}