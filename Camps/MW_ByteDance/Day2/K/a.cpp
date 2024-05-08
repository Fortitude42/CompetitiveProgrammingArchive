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
 
const int inf = 1e9, maxn = 1e5 + 48, mod = 1e9 + 7, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int r, c, q, prv[N], s[maxn][N], sum[maxn];
char t[N];
vi g[N];

inline int getPrv (int m, int x) {
    if (!sz(g[m]) || g[m][0] > x)
        return 0;
        
    int j = upper_bound(all(g[m]), x) - g[m].begin();
    return g[m][j - 1];
}

inline int getNxt (int m, int x) {
    if (!sz(g[m]) || g[m].back() < x)
        return inf;
        
    return *lower_bound(all(g[m]), x);
}

inline int get1 (int l, int r, int a, int b) {
    return s[r][b] - (a < 0 ? 0 :s[r][a]) - s[l][b] + (a < 0 ? 0 : s[l][a]);
}
 
inline ll get (int m, int l, int r, int a, int b) {
    l = getPrv(m, l - 1);
    r = getPrv(m, r);
    
    if (l > r)
        return 0;

        
	ll res = 0;
	int y = (b - a + 1) / m;
	res += y * 1ll * (sum[r] - sum[l]);

	if ((b - a + 1) % m == 0)
		return res;

	a %= m;
	b %= m;

	if (a > b) {
		res += get1(l, r, a - 1, m - 1);
		a = 0;
	}

	res += get1(l, r, a - 1, b);
	return res;
}

main () {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; ++i) {
		scanf("\n%s", t);
		int m = strlen(t);
		
		g[m].pb(i);
		sum[i] = sum[prv[m]];
		for (int j = 0; j < m; ++j) {
			s[i][j] = s[prv[m]][j] + (!j ? 0 : s[i][j - 1]) - (!j ? 0 : s[prv[m]][j - 1]) + t[j] - '0';
			sum[i] += t[j] - '0';
		}
		
		prv[m] = i;
	}


	
	

	scanf("%d", &q);
	while (q--) {
		int l, r, a, b;
		scanf("%d%d%d%d", &l, &a, &r, &b);

		ll ans = 0;
		b--;
		a--;
		for (int x = 1; x <= 100; ++x)
			ans += get(x, l, r, a, b);
		printf("%lld\n", ans);
	}
}