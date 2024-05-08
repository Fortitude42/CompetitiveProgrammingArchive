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
const int N = 64, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 4, maxn = 260, maxnn = 1e5;
const ll INF = 1e18;
 
int n, m, k, used[M][M], f[M][M];
int g[maxnn][maxn], where[maxn], res[maxn];


bool Gauss() {
	memset(where, -1, sizeof(where));

	int row = 1;
	for (int col = 1; col <= m; ++col) {
		int cur = -1;

		for (int i = row; i <= k; ++i)
			if (g[i][col]) {
				cur = i;
				break;
			}

		if (cur == -1)
			continue;


		for (int j = col; j <= m + 1; ++j)
			swap(g[row][j], g[cur][j]);

		if (g[row][col] == 2) 
			for (int j = col; j <= m + 1; ++j)
				g[row][j] = (3 - g[row][j]) % 3;
		
		for (int i = 1; i <= k; ++i) 
			if (i != row && g[i][col]) {
			    int coeff = g[i][col];
				for (int j = col; j <= m + 1; ++j)
					g[i][j] = (g[i][j] - coeff * g[row][j] % 3 + 3) % 3;
			}

		where[col] = row;
		++row;
	}

	for (int i = 1; i <= m; ++i)
		if (!res[i])
			res[i] = (where[i] == -1 || !g[where[i]][m + 1]) ? 3 : g[where[i]][m + 1];

	for (int i = 1; i <= k; ++i) {
		int s = 0;
		for (int j = 1; j <= m; ++j)
			s = (s + res[j] * g[i][j] % 3) % 3;
		if (s != g[i][m + 1])
			return 0;
	}

	return 1;
}


void solve() {
	k = 0;
	memset(used, 0, sizeof(used));
	memset(res, 0, sizeof(res));
	memset(g, 0, sizeof(g));


	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		used[a][b] = used[b][a] = i;
		f[a][b] = f[b][a] = c;
		if (c != -1)
			res[i] = c;
	}

	for (int a = 1; a <= n; ++a)
		for (int b = a + 1; b <= n; ++b)
			for (int c = b + 1; c <= n; ++c)
				if (used[a][b] && used[b][c] && used[a][c]) {
					k++;
					int s = 0;

					if (f[a][b] == -1)
						g[k][used[a][b]] = 1;
					else
						s = (s + 3 - f[a][b]) % 3;

					if (f[a][c] == -1)
						g[k][used[a][c]] = 1; 
					else
						s = (s + 3 - f[a][c]) % 3;

					if (f[b][c] == -1)
						g[k][used[b][c]] = 1;
					else
						s = (s + 3 - f[b][c]) % 3;

					g[k][m + 1] = s;
				}


	if (!Gauss()) 
		cout << -1 << endl;
	else {
		for (int i = 1; i <= m; ++i)
			cout << res[i] << ' ';
		cout << endl;
	}
}
 
main () {
	fastio

	int TT;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}
