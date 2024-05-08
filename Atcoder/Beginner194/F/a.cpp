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

int n, k, c[30][30], j;
bool was[30];
vi digits;
string s;

inline void add (int &x, int y) {
	x += y;

	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}

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


inline int f (int n, int i, int j) {;
	if (n == 0) {
		if (i == 0)
			return 1;
		return 0;
	}

	return c[16 - j][i] * 1ll * (binpow(i + j, n) - 2 * (!i ? 0 : binpow(i + j - 1, n)) + (i <= 1 ? 0 : binpow(i + j - 2, n))) % mod;
}


inline void precalc () {
	for (int i = 0; i < 30; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			if (c[i][j] >= mod)
				c[i][j] -= mod;
		}
	}
}

inline int get (char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	return c - 'A' + 10;
}

main () {
	precalc();
//	cerr << f(2, 2, 2);
//	return 0;
	fastio
	cin >> s >> k;

	int ans = 0;

	n = sz(s);
	for (int i = 0; i < n; ++i) {	
		int j = 0;
		for (auto x : digits)
			if (x < get(s[i]))
				++j;

		if (sz(digits) <= k) {
			add(ans, j * 1ll * f(n - 1 - i, k - sz(digits), sz(digits)) % mod);
			cerr << n - 1 - i << ' ' << k - sz(digits) << ' ' << sz(digits) << ' ' << f(n - 1 - i, k - sz(digits), sz(digits)) << endl;
		}
	
		int x = get(s[i]);
		if (!i)
			x--;

		if (sz(digits) < k)
			add(ans, (x - j) * 1ll * f(n - 1 - i, k - sz(digits) - 1, sz(digits) + 1) % mod);		

		if (i) 
			add(ans, 15ll * f(n - 1 - i, k - 1, 1) % mod);		
		
		if (!was[get(s[i])]) {
			was[get(s[i])] = 1;
			digits.pb(get(s[i]));
		}
	}

	if (sz(digits) == k)
		add(ans, 1);

	cout << ans << endl;
}