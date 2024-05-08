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
 
int n, m, k, b[N][N*N], s[N][N*N], d[N][N], c[N][N], v, u, w, C[N][N], D[N][N];
int d1[N][N], d2[N][N];


bool check (int x) {
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j) 
			if (i != j){
			    if (d[i][j] < INF)
					d1[i][j] = d[i][j]*x - c[i][j]; 
				else
					d1[i][j] = INF;
			} else
				d1[i][j] = INF;


	for (int k = 1; k <= n; ++k)
 		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (d1[i][k] < INF && d1[k][j] < INF)
					d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);

	for (int i = 1; i <= n; ++i)
		if (d1[i][i] <= 0)
			return 1;


	return 0;	    	
}

main () {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= k; ++j) 
			scanf("%lld%lld", &b[i][j], &s[i][j]);		
 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				d[i][j] = INF;
 
	
	while (m--) {
		scanf("%lld%lld%lld", &v, &u, &w);
		d[v][u] = min(d[v][u], w);
	}
 
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int x = 1; x <= k; ++x)
				if (b[i][x] != -1 && s[j][x] != -1)
					c[i][j] = max(c[i][j], s[j][x] - b[i][x]);


	int l = 1, r = inf;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) 
			l = mid + 1;
		else 
			r = mid - 1;		 
		
	}				    

	cout << l - 1 << endl;
}