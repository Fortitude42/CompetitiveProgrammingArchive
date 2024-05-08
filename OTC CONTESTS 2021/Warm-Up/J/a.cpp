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

int n, m, a[N], b[N], w[N], ans;
vi g[N], t[N];

void inc(int x, int y, int z) {
//	cerr << "- " << x << ' ' << y << ' ' << z << endl;
	while (y < sz(t[x])) {
		t[x][y] = max(t[x][y], z);
		y |= y + 1;
	}
}

int get(int x, int y) {
	int res = 0;
//	cerr << x << ' ' << y << ' ';
	while (y >= 0) {
		res = max(res, t[x][y]);
		y = (y & (y + 1)) - 1;
	}
//	cerr << res << endl;

	return res;
}

main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &w[i]);
		g[b[i]].pb(w[i]);
	}

	for (int i = 1; i <= n; ++i) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		t[i].resize(sz(g[i]));
	}

	for (int i = 1; i <= m; ++i) {
		int j1 = lower_bound(all(g[a[i]]), w[i]) - g[a[i]].begin() - 1;
		int j2 = lower_bound(all(g[b[i]]), w[i]) - g[b[i]].begin();
		int val = get(a[i], j1) + 1;
		ans = max(ans, val);
		inc(b[i], j2, val);
	}
	cout << ans << endl;
}
