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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e7 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, f[N], rf[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		a = a * 1ll * a % mod;
		n >>= 1;
	}

	return res;
}

void precalc () {
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}

int cnk (int n, int k) {
	if (n < k || n < 0)
		return 0;

	return f[n] * 1ll * rf[k] % mod * rf[n - k] % mod;
}

void add (int &x, int y) {
	x += y;

	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}

int F (int n, int s) {
	if (!s) 
		return 1;
  	return cnk(s + n - 1, n - 1);
}

int F1 (int n, int s) {
	if (s < 0)
		return 0;
	if (!s)
		return 1;
	
	int ans = 0;
	for (int x = 0; x <= n; ++x) {
		int cur = 1ll * cnk(n, x) * cnk(s + n - 10*x - 1, n - 1) % mod;
		if (!cur)
			break;
		add(ans, (x & 1) ? -cur : cur);
	}

	return ans;
}
 
main () {
	precalc();

	cin >> n;
	int odd = ((n / 2) + 1) / 2, even = (n / 2) / 2;
	int ans1 = 0, ans2 = 0;

	for (int s = 0; s <= odd*9; ++s) {
		int cur = F1(odd, s);
		int cur1 = F1(odd, s - 1);
		cout << cur - cur1 << endl;

		add(ans1, cur * 1ll * cur % mod);
	}

	for (int s = 0; s <= even*9; ++s) {
		int cur = F1(even, min(s, even*9 - s));
		add(ans2, cur * 1ll * cur % mod);
	}

//	cerr << ans1 << ' ' << ans2 << endl;

	cout << ans1 * 1ll * ans2 % mod << endl;
}