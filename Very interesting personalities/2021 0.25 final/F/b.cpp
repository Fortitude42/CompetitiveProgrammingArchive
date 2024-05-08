//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
   
using namespace std;
//using namespace __gnu_pbds;
   
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
#define se second
#define fi first
#define s second
#define f first
   
   
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
   
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
   
  
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 500, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;
  
vi g[M];
int cc[30][30], tmp[30][305];
int a[M][30], c[M], ans[M], s[30][N], z[30][N];
int n, m, k, dp[M][30][N], f[30], rf[30], dp1[M][30][N];

void add(int &x, int y) {
	x += y;

	if (x >= MOD)
		x -= MOD;

	if (x < 0)
		x += MOD;
}
   
int binpow(int a, int n) {
    int res = 1;
    while (n) {             
        if (n & 1)
            res = res * 1ll * a % MOD;
        a = a * 1ll * a  % MOD;
        n >>= 1;
    }
  
    return res;
}
  
void precalc() {
    f[0] = 1;
    for (int i = 1; i < 30; ++i)
        f[i] = f[i - 1] * 1ll * i % MOD;
  
    rf[29] = binpow(f[29], MOD - 2);
    for (int i = 28; i >= 0; --i)
        rf[i] = rf[i + 1] * 1ll * (i + 1) % MOD;
  
    for (int i = 0; i < 30; ++i) {
        cc[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            cc[i][j] = cc[i - 1][j] + cc[i - 1][j - 1]; 
            if (cc[i][j] >= MOD)
                cc[i][j] -= MOD;
        }
    }
}
  
void solve() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%lld", &a[i][j]);     
            if (a[i][j]) {
                ++c[i];
               	g[i].pb(j);
            }
        }
  
	for (int i = 1; i <= n; ++i) {
		memset(tmp, 0, sizeof(tmp));
		tmp[0][0] = 1;

		for (auto j : g[i])
			for (int jj = m; jj > 0; --jj)
				for (int x = k; x >= a[i][j]; --x)
					add(tmp[jj][x], tmp[jj - 1][x - a[i][j]]);
		

		for (auto j : g[i]) {
			for (int jj = 1; jj <= m; ++jj)
				for (int x = k; x >= a[i][j]; --x)
					add(tmp[jj][x], -tmp[jj - 1][x - a[i][j]]);
			
			for (int jj = 0; jj < sz(g[i]); ++jj)
				for (int x = 0; x + a[i][j] <= k; ++x)
					add(dp[i][j][x + a[i][j]], tmp[jj][x] * 1ll * f[jj] % MOD * f[sz(g[i]) - 1 - jj] % MOD); 
				
				
			for (int jj = m; jj > 0; --jj)
				for (int x = k; x >= a[i][j]; --x)
					add(tmp[jj][x], tmp[jj - 1][x - a[i][j]]);
		}
	}
  
  
  
    for (int j = 1; j <= m; ++j)
        for (int x = 0; x <= k; ++x)
            s[j][x] = 1;
  
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            for (int x = 0; x <= k; ++x) {
                dp1[i][j][x] = dp[i][j][x] + (!x ? 0 : dp1[i][j][x - 1]);
                if (dp1[i][j][x] >= MOD)
                    dp1[i][j][x] -= MOD;
  
                int cur = f[c[i]] - dp1[i][j][x];
                if (cur < 0)
                    cur += MOD;
  
                if (!cur && !z[j][x])
                    z[j][x] = i;
                else
                    s[j][x] = s[j][x] * 1ll * cur % MOD;
            }
        }
      
  
  
    int mult = 1, fmult = 1;
    for (int i = 1; i <= n; ++i) {
        mult = mult * 1ll * f[c[i]] % MOD;
        fmult = fmult * 1ll * rf[c[i]] % MOD;
    } 
  
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
            if (a[i][j]) {
                for (int x = 1; x <= k; ++x) {
                    int cur = s[j][x - 1];
                    int cur1 = f[c[i]] - dp1[i][j][x - 1];
                    if (cur1 < 0)
                        cur1 += MOD;
  
                    if (z[j][x - 1] == i);
                    else if (z[j][x - 1] > 0)    
                        cur = 0;
                    else
                        cur = cur * 1ll * binpow(cur1, MOD - 2) % MOD;
  
  
                    ans[i] += cur * 1ll * dp[i][j][x] % MOD;
                    if (ans[i] >= MOD)
                        ans[i] -= MOD;
                }
            }   
  
                  
  
    for (int i = 1; i <= n; ++i) {
        ans[i] = ans[i] * 1ll * fmult % MOD;
        printf("%lld\n", ans[i]); 
    }
}
  
main () {
    precalc();
  
    int TT;
    TT = 1;
//  scanf("%d", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        solve();
    }
}