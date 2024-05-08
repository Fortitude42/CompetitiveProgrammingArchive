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
 
const int inf = 1e9, maxn = (1 << 20) + 30, mod = 1e9 + 7, N = 22;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, p[N];
vi g[N], res[N];
bool was[maxn];
 
void dfs (int v) {
	res[v].pb(v);



	for (auto to : g[v]) {
		dfs(to);          
		int cur = sz(res[v]);
		bool rev = 1;

		for (auto x : res[to]) {
//			cerr << v << ' ' << to << ' ' << rev << endl;
			res[v].pb(x);
			if (!rev) {
				for (int i = 1; i < cur; ++i)
					res[v].pb(res[v][i]);
			} else {
				for (int i = cur - 1; i > 0; --i)
					res[v].pb(res[v][i]);
			}
			
			rev ^= 1;
		}
	}

	
}

main () {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> p[i];             
		--p[i];
		g[p[i]].pb(i);
	}

	dfs(0);
/*	int mask = 0;
	for (auto x : res[0]) {
		mask ^= (1 << x);
		assert(!was[mask]);
		was[mask] = 0;
		for (int i = 1; i < n; ++i)
			if ((mask & (1 << i)) && !(mask & (1 << p[i]))) {
			    cerr << mask << ' ' << i << endl;
			    return 0;
				assert(0);                                   
			}
	}*/


	printf("%d\n", sz(res[0]) - 1);
	for (int i = 1; i < sz(res[0]); ++i)
		printf("%d ", res[0][i] + 1);
}