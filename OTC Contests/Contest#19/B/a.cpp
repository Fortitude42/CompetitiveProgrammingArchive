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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, m, xa, ya, xb, yb;
 
int get (int l, int r, int a, int b) {
	if (l > a) {
		swap(l, a); 
		swap(r, b);
	}

	if (a > r)
		return 0;
	return min(r, b) - a + 1;
}

main () {
	cin >> t;
	while (t--) {
		cin >> n >> m >> xa >> ya >> xb >> yb;
		int l = min(xa, xb) - 1;
		int r = n - max(xa, xb);
		int u = min(ya, yb) - 1;
		int d = m - max(ya, yb);
		ll area = n * 1ll * m;
		area -= (l + r + 1) * 2ll * (u + d + 1);
//		cerr << xa - l << ' ' << xa + r << ' ' << xb - l << ' ' << xb + r << endl;
//		cerr << ya - u << ' ' << ya + d << ' ' << yb - u << ' ' << yb + d << endl;
		area += get(xa - l, xa + r, xb - l, xb + r) * 1ll * get(ya - u, ya + d, yb - u, yb + d);
		cout << area << endl;
	}
}