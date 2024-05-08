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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e3 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, a[N][N], x, C[N << 1];
vi g[2][N << 1];
char c;
bool ok;

void dfs (int v) {
	for (int j = 0; j < 2; ++j) 
		for (auto to : g[j][v]) {
			if (C[to] == -1) {
				C[to] = C[v] ^ j;
				dfs(to);
			} else if ((C[to] ^ C[v]) != j) 
				ok = 0;			
		}	
}


 
main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("\n");
			for (int j = 1; j <= n; ++j) {
				scanf("%c", &c);
				a[i][j] = c - '0';
			}
		}
		scanf("\n");

		for (int j = 0; j < 2; ++j)
			for (int i = 1; i <= n + n; ++i) {
				g[j][i].clear();              
				C[i] = -1;
			}

		for (int i = 1; i <= n; ++i) {
			scanf("\n");
			for (int j = 1; j <= n; ++j) {
				scanf("%c", &c);
				a[i][j] ^= (c - '0');
				g[a[i][j]][i].pb(j + n);
				g[a[i][j]][j + n].pb(i);
			}
		}
		
		ok = 1;
		C[1] = 0;
		dfs(1);
		puts(ok ? "YES" : "NO");
	}
}