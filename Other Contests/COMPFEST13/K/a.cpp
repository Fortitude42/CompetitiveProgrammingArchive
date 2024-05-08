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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, r, c, k, xa, ya, xb, yb;

int binpow(int a, int n) {
	if (n < 0)
		exit(0);

	int res = 1;
	while (n) {
		if (n % 2 == 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n /= 2;
	}

	return res;
}

int solve(int n, int m, int r, int c) {
//	cerr << n << ' ' << m << ' ' << r << ' ' << c << endl;
	if (r > n || c > m)	
		exit(0);

	if (n == r && m == c)
		return binpow(k, n*m);

	int x = 2*r - n;
	int y = 2*c - m;
	if (x <= 0 || y <= 0)
		return binpow(k, n*m - r*c);

	return solve(r, c, x, y) * binpow(k, n*m - r*c*2 + x*y) % mod;
}
 
main () {
	cin >> n >> m >> k >> r >> c;
	cin >> xa >> ya >> xb >> yb;
	int lx = min(xa, xb);
	int rx = max(xa, xb) + r - 1;
	int ly = min(ya, yb);
	int ry = max(ya, yb) + c - 1;	
	cout << binpow(k, n*m - (rx - lx + 1)*(ry - ly + 1)) * solve(rx - lx + 1, ry - ly + 1, r, c) % mod;
}