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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, k, nxt[N], p[N], cnt[N];
int dp[N], cnt1[N], a[N];
vi g[N], gr[N];
bool bad[N];
vpii e;

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u) {
		bad[v] = 1;
		return;
	}

	if (cnt[v] < cnt[u])
		swap(v, u);

	p[u] = v;
	cnt[v] += cnt[u];
	bad[v] |= bad[u];
}


void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

main () {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) {
		p[i] = i;                 
		cnt[i] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		int c;
		scanf("%d", &c);
		for (int i = 1; i <= c; ++i) {
			scanf("%d", &a[i]);       
			if (i > 1) {
				e.pb({a[i], a[i - 1]});			 
				g[a[i]].pb(a[i - 1]);
				gr[a[i - 1]].pb(a[i]);
			}
		}
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j < sz(g[i]); ++j)
			if (g[i][j] != g[i][j - 1])
				bad[i] = 1;

		for (int j = 1; j < sz(gr[i]); ++j)
			if (gr[i][j] != gr[i][j - 1])
				bad[i] = 1;
	}

	sort(all(e));
	e.resize(unique(all(e)) - e.begin());

	for (auto x : e)
		merge(x.f, x.s);
		
	
	for (int i = 1; i <= k; ++i)
		if (p[i] == i && !bad[i])
			++cnt1[cnt[i]];
	

	vi vals;
	for (int i = 1; i <= k; ++i)
		if (cnt1[i]) 
			vals.pb(i);		

	dp[0] = 1;

	for (int i = 0; i <= m; ++i) {
		for (auto x : vals)
			if (i + x <= m)
				add(dp[i + x], dp[i] * 1ll * cnt1[x] % mod);
	}
		
	cout << dp[m] << endl;	
}