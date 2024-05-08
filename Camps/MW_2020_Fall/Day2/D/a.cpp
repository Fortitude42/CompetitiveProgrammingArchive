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

int n, x, a[N], b[N], ans, c[N];
pii f[N], g[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		n >>= 1;
		a = a * 1ll * a % mod;
	}

	return res;
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)			
		x += mod;
}

bool zero () {
	for (int i = 1; i <= n; ++i)
		if (a[i])
			return 0;

	return 1;
}
 
main () {
	while (scanf("%d%d", &n, &x) == 2) {
		for (int i = 1; i <= n; ++i) 
			scanf("%d", &a[i]);       

		for (int i = 1; i <= n; ++i) 
			scanf("%d", &b[i]);       
		
		if (zero()) {
			cout << binpow(x, n) << endl;
			continue;
		}

		int j = n, ans = 1;
		while (!a[j]) {
			ans = ans * 1ll * x % mod;
			--j;
		}

		ans = ans * 1ll * a[j] % mod;


		for (int i = 1; i < j; ++i) {
			if (a[i]) {
				c[i] = x * 1ll * binpow(a[i], mod - 2) % mod;
				ans = ans * 1ll * a[i] % mod;			
			} else 
				c[i] = x;
		}
			


		c[j] = binpow(a[j], mod - 2) * 1ll * x % mod;

		b[j] = (b[j] + c[j]) % mod;
		for (int i = 1; i < j; ++i) {
			int f = b[i] * 1ll * binpow(c[i], mod - 2) % mod;

//			ans = ans * 1ll * b[i] % mod;
//			ans = ans * 1ll * binpow(f, mod - 2) % mod;
			ans = ans * 1ll * c[i] % mod;

				
			if (a[i])
				b[j] = (b[j] + f * 1ll * c[j] % mod) % mod;
		}

		ans = ans * 1ll * b[j] % mod;
		cout << ans << endl;
	}
}