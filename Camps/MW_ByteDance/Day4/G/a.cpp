#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


bool res[103][103], ans[11][11], dp[103][103][103], tmp[103][103];
string s[11];
vi g[103];
int n, m;
ll len;


bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
} 

void write (string s) {
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << s[i*m + j];
	exit(0);
}


 
main () {
	cin >> n >> m >> len;
	for (int i = 0; i < n; ++i) 
		cin >> s[i];
	
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) {
			for (int x = 0; x < 4; ++x) {
				int toi = i + dx[x], toj = j + dy[x];
				if (in(toi, toj))
					g[i*m + j].pb(toi*m + toj);
			}

			int jj = j - 1;
			if (i & 1)
				jj = j + 1;
			if (in(i - 1, jj))
				g[i*m + j].pb((i - 1)*m + jj);
			if (in(i + 1, jj))
				g[i*m + j].pb((i + 1)*m + jj);
		}

	for (int i = 0; i < n * m; i++) {
		res[i][i] = 1;
		for (auto j : g[i])
			dp[i][j][0] = 1;
	}

	for (int pw = 0; pw < 64; pw++) {
		if (pw)
		for (int i = 0; i < n * m; i++)
			for (int j = 0; j < n * m; j++)
				for (int k = 0; k < n * m; k++)
					dp[i][j][pw] ^= (dp[i][k][pw - 1] & dp[k][j][pw - 1]);

		if ((len >> pw) & 1) {
			memset(tmp, 0, sizeof(tmp));
			for (int i = 0; i < n * m; i++)
				for (int j = 0; j < n * m; j++)
					for (int k = 0; k < n * m; k++)
						tmp[i][j] ^= (res[i][k] & dp[k][j][pw]);

			for (int i = 0; i < n*m; ++i)
				for (int j = 0; j < n*m; ++j)
					res[i][j] = tmp[i][j];
					
		}
	}

	//0...n*m - 1
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '*') {
				for (int ii = 0; ii < n; ++ii)
					for (int jj = 0; jj < m; ++jj)
						ans[ii][jj] ^= res[i*m + j][ii*m + jj];
			}

	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << (ans[i][j] ? '*' : '.');
}
