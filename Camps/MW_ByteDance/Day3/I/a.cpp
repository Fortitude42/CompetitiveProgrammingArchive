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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, prv[N], a[N], b[N];
ll dp[N], s[N];
vpii V;

ll get (int l, int r) {
	return s[r] - (!l ? 0 : s[l - 1]);
}

main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
	    scanf("%d", &a[i]);
	

	for (int i = 1; i <= m; ++i) 
	    scanf("%d", &b[i]);
	

	int i = 1, j = 1;
	while (1) {
		if (i == n + 1 && j == m + 1)
			break;
		if (i == n + 1 || (j != m + 1 && b[j] <= a[i])) {
			V.pb({b[j], 1});
			++j;
		} else {
			V.pb({a[i], 2});				
			i++;
		}
	}
	
	
 
 
	memset(prv, -1, sizeof(prv));
 
	for (int i = 0; i < sz(V); ++i) {
		s[i] = (!i ? 0 : s[i - 1]) + V[i].f;
		int j = i;
		while (j + 1 < sz(V) && V[i].s == V[j + 1].s) {
			++j; 
			s[j] = s[j - 1] + V[j].f;
		}
 
		for (int x = i; x <= j; ++x) {
			dp[x] = INF;
 
			if (i) {
				dp[x] = dp[x - 1] + V[x].f - V[i - 1].f;
				if (x == i)
					prv[x] = i - 1;
				else
					prv[x] = prv[x - 1] - 1;
 
				if (prv[x] >= 0 && V[x].s == V[prv[x]].s)
					prv[x] = -1;
					
 
				if (prv[x] >= 0)
					dp[x] = min(dp[x], (!prv[x] ? 0 : dp[prv[x] - 1]) + get(i, x) - get(prv[x], i - 1));
			}
 
			if (j + 1 < sz(V))
				dp[x] = min((!x ? 0 : dp[x - 1]) + V[j + 1].f - V[x].f, dp[x]);			
		}
		i = j;
	}
 
/*	for (int i = 0; i < n + m; ++i)
		cerr << V[i].f << ' ' << V[i].s << endl;
*/ 
 
    cout << dp[n + m - 1] << endl;
	return 0;
}