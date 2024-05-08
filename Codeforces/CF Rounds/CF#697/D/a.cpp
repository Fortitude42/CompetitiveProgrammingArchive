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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

ll m;
int t, n, a[N], b[N];
vector < ll > c, d;
 
main () {	
	fastio
	cin >> t;
	while (t--) {
		c.clear();
		d.clear();

		cin >> n >> m;

		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		for (int i = 1; i <= n; ++i) {
			cin >> b[i];              
			if (b[i] == 1)
				c.pb(a[i]);
			else
				d.pb(a[i]);
		}

		sort(all(c));
		sort(all(d));

		reverse(all(c));
		reverse(all(d));

		for (int i = 1; i < sz(c); ++i)
			c[i] += c[i - 1];

		for (int i = 1; i < sz(d); ++i)
			d[i] += d[i - 1];

		int ans = inf;
		for (int i = -1; i < sz(c); ++i) {
			ll s = m - (i == -1 ? 0 : c[i]);
			if (s <= 0) 
				ans = min(ans, i + 1);
			else {
				if (sz(d) && d.back() >= s) {
					int j = lower_bound(all(d), s) - d.begin();
					ans = min(ans, (i + 1) + (j + 1) * 2);
				}
			}
		}

		if (ans == inf)
			ans = -1;
		cout << ans << endl;
	}
}