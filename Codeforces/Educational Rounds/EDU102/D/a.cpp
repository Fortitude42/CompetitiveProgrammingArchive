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

int t, n, m, l, r, pr[N], mn[N][2], mx[N][2];
string s;
 

main () {
	fastio
	cin >> t;
	while (t--) {
		cin >> n >> m >> s;

		s = "#" + s;
		for (int i = 1; i <= n; ++i)
			pr[i] = pr[i - 1] + (s[i] == '+' ? 1 : -1);
		
		
		mn[0][0] = mx[0][0] = pr[0];
		mn[n + 1][1] = mx[n + 1][1] = pr[n];

		for (int i = 1; i <= n; ++i) {
			mn[i][0] = min(pr[i], mn[i - 1][0]);
			mx[i][0] = max(pr[i], mx[i - 1][0]);
		}

		for (int i = n; i > 0; --i) {
			mn[i][1] = min(mn[i + 1][1], pr[i]);
			mx[i][1] = max(mx[i + 1][1], pr[i]);
		}
			
		while (m--) {
			cin >> l >> r;
			if (l == 1 && r == n) {
				cout << 1 << endl;
				continue;
			}

			int L = min(mn[l - 1][0], mn[r + 1][1] - pr[r] + pr[l - 1]);
			int R = max(mx[l - 1][0], mx[r + 1][1] - pr[r] + pr[l - 1]);
//			cerr << L << ' ' << R << endl;
//			cerr << mx[l - 1][0] << ' ' << mx[r + 1][1] << ' ' << -pr[r] + pr[l - 1] << endl;
			cout << R - L + 1 << endl;
		}


			
	}
}