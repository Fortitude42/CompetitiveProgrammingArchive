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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 5e4 + 11;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m;
vi g[N], gg[N];
 
void check (vi a) {
	for (int i = 1; i <= n; ++i) {
	    int cnt = 0;
		for (int j = 1; j <= m; ++j)            
			if (a[j] != g[i][j])
				++cnt;
		if (cnt > 2)
			return;
	}

	cout << "Yes\n";
	for (int j = 1; j <= m; ++j)
		cout << a[j] << ' ';

	exit(0);
}

void check1 (vi cur) {
	for (int i = 1; i <= n; ++i) {
		vi c;
		for (int j = 1; j <= m; ++j)
			if (cur[j] != g[i][j])
				c.pb(j);

		if (sz(c) == 3) {
			for (auto x : c) {
				vi cur1 = cur;
				cur1[x] = g[i][x];
				check(cur1);
			}
			return;
		}
	}
}

main () {
	fastio

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		g[i].resize(m + 1);
		for (int j =  1; j <= m; ++j) {          
			cin >> g[i][j];            
			if (g[1][j] != g[i][j])
				gg[i].pb(j);                 
		}

		if (sz(gg[i]) > 4) {
			cout << "No";
			return 0;
		}
	}


	check(g[1]);
	for (int j = 1; j <= n; ++j) 
		if (sz(gg[j]) == 4) {
			for (int mask = 0; mask < (1 << sz(gg[j])); ++mask) {
				if (__builtin_popcount(mask) != 2)
					continue;
				
				vi cur = g[1];   
				for (int x = 0; x < sz(gg[j]); ++x)
					if (mask & (1 << x)) {
						int pos = gg[j][x];
						cur[pos] = g[j][pos];
					}

				check(cur);
			}
	    	cout << "No";
	    	return 0;
		}

	for (int i = 1; i <= n; ++i)
		if (sz(gg[i]) == 3) {
			for (auto x : gg[i]) {
				vi cur = g[1];
				cur[x] = g[i][x];
				check1(cur);
				check(cur);
			}
			cout << "No";
			return 0;
		}
}