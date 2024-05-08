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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int m, nxt[M][20];
bool u[M][20];
string s, l, r; 

void solve() {
	cin >> s;
	cin >> m >> l >> r;

	for (int d = 0; d < 10; ++d)
		nxt[sz(s)][d] = sz(s);

	for (int i = sz(s) - 1; i >= 0; --i) {
		for (int d = 0; d < 10; ++d)
			nxt[i][d] = nxt[i + 1][d];

		nxt[i][s[i] - '0'] = i;
	}

	for (int i = 0; i <= sz(s); ++i)
		for (int j = 0; j <= m; ++j)
			u[i][j] = 0;


	u[0][0] = 1;
	for (int i = 0; i <= sz(s); ++i)
		for (int j = 0; j < m; ++j)
			if (u[i][j]) {
				if (j < m) {
					for (int d = l[j] - '0'; d <= r[j] - '0'; ++d) {
						u[nxt[i][d] + 1][j + 1] = 1;									
						if (nxt[i][d] == sz(s)) {
							cout << "YES\n";
							return;
						}
					}
				}
			}


	cout << "NO\n";
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