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
 
const int inf = 1e9, maxn = 1e6 + 48, mod = 998244353, N = 3012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 1e6;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, dp[N], f[N], rf[N], ff, rff[N];
int F[] = {1, 373341033, 45596018, 834980587, 623627864, 428937595, 442819817, 499710224, 833655840, 83857087, 295201906, 788488293, 671639287, 849315549, 597398273, 813259672, 732727656, 244038325, 122642896, 310517972, 160030060, 483239722, 683879839, 712910418, 384710263, 433880730, 844360005, 513089677, 101492974, 959253371, 957629942, 678615452, 34035221, 56734233, 524027922, 31729117, 102311167, 330331487, 8332991, 832392662, 545208507, 594075875, 318497156, 859275605, 300738984, 767818091, 864118508, 878131539, 316588744, 812496962, 213689172, 584871249, 980836133, 54096741, 417876813, 363266670, 335481797, 730839588, 393495668, 435793297, 760025067, 811438469, 720976283, 650770098, 586537547, 117371703, 566486504, 749562308, 708205284, 932912293, 939830261, 983699513, 206579820, 301188781, 593164676, 770845925, 247687458, 41047791, 266419267, 937835947, 506268060, 6177705, 936268003, 166873118, 443834893, 328979964, 470135404, 954410105, 117565665, 832761782, 39806322, 478922755, 394880724, 821825588, 468705875, 512554988, 232240472, 876497899, 356048018, 895187265, 808258749};

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		n >>= 1;
		a = a * 1ll * a % mod;
	}

	return res;
}

int get(int n) {
	int nn = (n / block) * block;
	int ans = F[nn / block];
	while (nn < n) {
		++nn;
		ans = ans * 1ll * nn % mod;
	}

	return ans;
}

void precalc() {
	f[0] = 1;
	rff[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * 1ll * i % mod; 
		rff[i] = binpow(f[i], mod - 2);
	}

	ff = get(m - 2);
	rf[0] = binpow(ff, mod - 2);
	for (int i = 1; i <= min(n, m - 2); ++i) {
		rf[i] = rf[i - 1] * 1ll * (m - i - 1) % mod;
//		assert(rf[i] == binpow(get(m - 2 - i), mod - 2));
//		rf[i] = binpow(get(m - 2 - i), mod - 2);
	}
}

inline void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}

int ank(int n, int k) {
	if (n < k)
		return 0;

	return ff * 1ll * rf[k] % mod;
}   

int cnk(int n, int k) {
	if (n < k)
		return 0;
	return f[n] * 1ll * rff[n - k] % mod * rff[k] % mod;
}

 
main () {
	cin >> n >> m;
	precalc();

	dp[0] = 1;
	for (int i = 0; i <= n; ++i) {
	    add(dp[i], !i ? 0 : dp[i - 1]);
		for (int j = 0; i + j + 1 <= n; ++j) {
			add(dp[i + j + 1], dp[i] * 1ll * ank(m - 2, j) % mod * cnk(n - i - 1, j) % mod); 
//			if (i + j + 1 == 5)
//				cerr << ank(m - 2, j) << ' ' << cnk(n - i - 1, j) << endl;
		}
	}
//	cerr << dp[5] << endl;
	cout << dp[n] << endl;			
}