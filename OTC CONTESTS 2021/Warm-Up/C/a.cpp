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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, g[N][N], r[N], c[N], ans = inf, rr[N], cc[N];

main () {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> g[i][j];

	for (int x = 0; x <= g[1][1]; ++x) {
		r[1] = x;
		c[1] = g[1][1] - x;

		bool ok = 1;
		int res = g[1][1];
		for (int i = 2; i <= n; ++i) {
			r[i] = g[i][1] - c[1];     
			if (r[i] < 0)
				ok = 0;
			res += r[i];
		}

		for (int i = 2; i <= m; ++i) {
			c[i] = g[1][i] - r[1];
			if (c[i] < 0)
				ok = 0;
			res += c[i];
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (r[i] + c[j] != g[i][j])
					ok = 0;

		if (!ok)
			continue;
		if (res < ans) {
			ans = res;
			for (int i = 1; i <= n; ++i)
				rr[i] = r[i];

			for (int i = 1; i <= m; ++i)
				cc[i] = c[i];
		}
	}

	if (ans == inf)
		cout << -1 << endl;
	else {
		cout << ans << endl; 
		for (int i = 1; i <= n; ++i) {
			while (rr[i]--)
				cout << "row " << i << endl;
		}

		for (int j = 1; j <= m; ++j) {
			while (cc[j]--)
				cout << "col " << j << endl;
		}						
	}

}