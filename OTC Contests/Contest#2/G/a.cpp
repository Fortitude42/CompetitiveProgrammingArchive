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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, x[N], ans;
char c[N];
vi g[3];

int getPos (int x, int i) {
	return lower_bound(all(g[i]), x) - g[i].begin();
}

 
main () {
	cin >> n;
	int last1 = -1, last2 = -1, last3 = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> c[i];
		if (c[i] == 'R' || c[i] == 'P')
			g[0].pb(x[i]);
		if (c[i] == 'B' || c[i] == 'P')
			g[1].pb(x[i]);
		if (c[i] == 'P')
			g[2].pb(x[i]);
	}	

	if (!sz(g[2])) {
		int ans = 0;
		if (sz(g[0]))
			ans += g[0].back() - g[0][0];
		if (sz(g[1]))
			ans += g[1].back() - g[1][0];
		cout <<  ans  << endl;
		return 0;
	}

	for (int i = 0; i <= sz(g[2]); ++i) {
		if (!i) {
		    for (int x = 0; x < 2; ++x) 
				ans += g[2][i] - g[x][0];
			continue;
		} 

		if (i == sz(g[2])) {
			for (int x = 0; x < 2; ++x) 
				ans += g[x].back() - g[2][i - 1];			
			continue;
		}

		int mx1 = 0, mx2 = 0;
		
		int l = getPos(g[2][i - 1], 0), r = getPos(g[2][i], 0);
		for (int x = l; x < r; ++x)
			mx1 = max(mx1, g[0][x + 1] - g[0][x]);

		l = getPos(g[2][i - 1], 1), r = getPos(g[2][i], 1);
		for (int x = l; x < r; ++x)
			mx2 = max(mx2, g[1][x + 1] - g[1][x]);

		ans += min(2*(g[2][i] - g[2][i - 1]), 3*(g[2][i] - g[2][i - 1]) - mx1 - mx2);	
	}
 
	cout << ans << endl;
}      	