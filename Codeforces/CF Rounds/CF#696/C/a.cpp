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
 
const int inf = 1e9, maxn = 2e6 + 11, mod = 1e9 + 7, N = 2e3 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int T, n, a[N], t[N], timer;
vi g[maxn];

 
main () {
	fastio
	cin >> T;
	while (T--) {
		cin >> n;
		n += n;
		for (int i = 1; i <= n; ++i) 
			cin >> a[i];              
		
		
			
		sort(a + 1, a + 1 + n);

		vpii ans;

		for (int i = 1; i < n; ++i) {
			vpii res;

			for (int j = 1; j <= n; ++j)
				g[a[j]].clear();

			for (int j = 1; j <= n; ++j)
				if (j != i && j != n)
					g[a[j]].pb(j);

			++timer;
			t[i] = t[n] = timer;
			int x = a[n];
			res.pb({a[i], a[n]});

			for (int j = n; j > 0; --j) 
				if (t[j] != timer) {
					g[a[j]].ppb();
					if (a[j] > x || !sz(g[x - a[j]])) 
						break;                        

					int y = g[x - a[j]].back();
					g[a[y]].ppb();

					t[j] = t[y] = timer;
					res.pb({a[j], a[y]});
					x = a[j];
				}

			if (sz(res)*2 == n) {
				ans = res;     
				break;
			}
		}

		for (int i = 1; i <= n; ++i)
			g[a[i]].clear();


		if (!sz(ans)) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		cout << ans[0].f + ans[0].s << endl;
		for (auto x : ans)
			cout << x.f << ' ' << x.s << endl;
	}                                                                
}