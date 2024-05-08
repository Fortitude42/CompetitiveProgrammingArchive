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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, m, k, p, c[N][N], f[N], dp[N][N][N];

void precalc() {
	f[0] = 1 % p;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % p;

	for (int i = 0; i < N; ++i) {
		c[i][0] = 1 % p;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; 
			while (c[i][j] >= p)
				c[i][j] -= p;
		}
	}
}

inline void add(int &x, int y) {
	x += y;
	if (x >= p)
		x -= p;
}

int calc(int n, int dep, int k) {
	int &res = dp[n][dep][k];
	if (res != -1)
		return res;

	if (!n) 
		return res = !k; 	

	if (dep == m)
		return res = (k == 1) * f[n];

	if (dep + n < m)
		return (k == 0 ? f[n] : 0);

	res = 0;
	for (int a = 1; a <= n; ++a)
		for (int x = 0; x <= min(a - 1, k); ++x) 
			add(res, 1ll * calc(a - 1, dep + 1, x) * calc(n - a, dep + 1, k - x) % p * c[n - 1][a - 1] % p);

	return res;
}

main () {
	cin >> n >> m >> k >> p;
	precalc();
	for (int nn = 0; nn <= n; ++nn)
		for (int dep = n; dep > 0; --dep)
			for (int kk = 0; kk <= k; ++kk) {
				if (!nn) {
					dp[nn][dep][kk] = (!kk ? 1 : 0);
					continue;
				}

				if (dep == m) {
					dp[nn][dep][kk] = (kk == 1 ? f[nn] : 0);
					continue;
				}

				if (dep + nn < m) {
					dp[nn][dep][kk] = (!kk ? f[nn] : 0);
					continue;
				}

				for (int a = 1; a <= nn; ++a)
					for (int x = 0; x <= min(a - 1, kk); ++x) 
						add(dp[nn][dep][kk], 1ll * dp[a - 1][dep + 1][x] * dp[nn - a][dep + 1][kk - x] % p * c[nn - 1][a - 1] % p);
			}

//	cout << calc(n, 1, k);
	cout << dp[n][1][k] << endl;
}