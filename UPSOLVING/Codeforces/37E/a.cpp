//template by paradox & gege & parasat
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
const int N = 50, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
char c[M][M], cc[M][M];
int n, m, col[M][M], k;
set < int > q[M*M];

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}


bool check() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (cc[i][j] == 'B')
				return 0;

	return 1;
}


void dfs(int i, int j, char c) {
	cc[i][j] = c;
	for (int x = 0; x < 4; ++x) {
		int toi = i + dx[x], toj = j + dy[x];
		if (in(toi, toj) && cc[toi][toj] != c)
			dfs(toi, toj, c);
	}
}   

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];

	
	int ans = inf;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			for (int x = 1; x <= n; ++x)
				for (int y = 1; y <= m; ++y)
					cc[x][y] = c[x][y];

			int res = 0;
			while (!check()) {
				dfs(i, j, 'W' + 'B' - cc[i][j]);
				++res;
//				cerr << i << ' ' << j << endl;
//				for (int x = 1; x <= n; ++x, cerr << endl)
//					for (int y = 1; y <= m; ++y)
//						cerr << cc[x][y];
//				cerr << endl;
			}

			ans = min(ans, res);
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