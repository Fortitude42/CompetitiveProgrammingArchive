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


int t, n, a[N], b[N], c[N], d[N];
bool ok;
 
main () {
	cin >> t;
	while (t--) {
		ok = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];              
			b[i] = a[i];
		}

		bool ok1 = 1;
		for (int i = 1; i < n; ++i) {
			if (a[i] > a[i + 1]) 
				break;
			
			a[i + 1] -= a[i];
		}

		if (!a[n]) {
			cout << "YES\n";
			continue;
		}

		for (int i = 1; i <= n; ++i)
			a[i] = b[i];

		for (int i = 0; i <= n + 1; ++i)
			c[i] = d[i] = 0;


		for (int i = 1; i < n; ++i) {
			if (c[i - 1] == -inf)
				c[i] = -inf;
	
			if (c[i] != -inf)
				c[i] = a[i];

			if (a[i] > a[i + 1])
				c[i + 1] = -inf;
			else
				a[i + 1] -= a[i];
		}

		for (int i = 1; i <= n; ++i)
			a[i] = b[i];

		for (int i = n; i > 1; --i) {
			if (d[i + 1] == -inf)
				d[i] = -inf;
		
			if (d[i] != -inf)
				d[i] = b[i];

			if (b[i - 1] < b[i])
				d[i - 1] = -inf;
			else
				b[i - 1] -= b[i];
		}




		for (int i = 1; i < n; ++i) {
			if (c[i - 1] == -inf || d[i + 2] == -inf)
				continue;

			vi v;
			v.pb(c[i - 1]);
			v.pb(a[i + 1]);
			v.pb(a[i]);
			v.pb(d[i + 2]);
			
			if (i == 2) {
				for (auto x : v)
					cerr << x << ' ';
				cerr << endl;
			}

			while (sz(v) > 1) {
				if (v.back() > v[sz(v) - 2])
					break;

				v[sz(v) - 2] -= v.back();
				v.ppb();
			}

/*			if (i == 2) {
				for (auto x : v)
					cerr << x << ' ';
				cerr << endl;
			}*/

			if (sz(v) == 1 && !v[0]) {
				ok = 1;
				break;
			}
		}

		puts(ok ? "YES" : "NO");
	}
}