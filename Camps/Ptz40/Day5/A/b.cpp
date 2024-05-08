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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, p[12][N], timer;
queue < vi > q;
bool was[N], t[N];

void dfs (int mask) {
	for (int i = 0; i < m; ++i)
		if (mask & (1 << i)) {
			for (int j = 0; j < n; ++j)
				if (!was[p[i][j]]) {
//					++timer;
//					if (timer == 20)	
//						exit(0);
//					cerr << mask << ' ' << i << ' ' << j << endl;
					t[p[i][j]] = was[p[i][j]] = 1;
					dfs(mask ^ (1 << i));
					was[p[i][j]] = 0;
					break;
				}
		}
}
 
main () {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) {
			cin >> p[i][j];          
			--p[i][j];
		}
	

	dfs((1 << m) - 1);

	vi ans;
	for (int i = 0; i < n; ++i)
		if (t[i])
			ans.pb(i + 1);

	printf("%d\n", sz(ans));
	for (auto x : ans)
		printf("%d ", x);
}