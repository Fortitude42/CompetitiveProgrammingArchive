#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, m, k, cmp, ans, cnt;
bool was[N][N], was1[N][N];
bool c[N][N];

bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;                        	
}


void dfs (int x, int y, int px = -1, int py = -1) {
	was1[x][y] = 1;

	int deg = 0;
	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		if (in(tox, toy) && was[tox][toy])
			++deg;

		if (in(tox, toy) && was[tox][toy] && (tox != px || toy != py)) {
			if (was1[tox][toy]) 
				cmp = inf;
			else
				dfs(tox, toy, x, y);
		}
	}

	if (deg == 1)
		++cnt;

}

main () {
	cin >> n >> m >> k;
	for (int mask = 0; mask < (1 << (n*m)); ++mask) {
		memset(was1, 0, sizeof(was1));
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (mask & (1 << (i*m + j))) 
					was[i][j] = 1;
				else
					was[i][j] = 0;

		
		cmp = 0, cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!was1[i][j] && was[i][j]) {
					dfs(i, j);
					++cmp;	
				}
		if (cmp > 1)
			continue;

		if (ans < cnt) {
			ans = cnt;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					c[i][j] = was[i][j];
		}
	}

	cout << ans << endl;
	for (int mask = 0; mask < (1 << (n*m)); ++mask) {
		memset(was1, 0, sizeof(was1));
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (mask & (1 << (i*m + j))) 
					was[i][j] = 1;
				else
					was[i][j] = 0;

		
		cmp = 0, cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (!was1[i][j] && was[i][j]) {
					dfs(i, j);
					++cmp;	
				}
		if (cmp > 1)
			continue;

		if (ans == cnt) {
			for (int i = 0; i < n; ++i, cout << endl)
				for (int j = 0; j < m; ++j)
					cout << was[i][j] << ' ';
			cout << endl;
		}
	}
		
}