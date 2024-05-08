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


int n, m, p[N], cnt[N];
set < int > q;
vi g[N];

int get(int v) {
	return p[v] == v ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])
		swap(v, u);
	p[u] = v;
	cnt[v] += cnt[u];		
}

void dfs (int v) {
	q.erase(v);
	int j = 0;
	while (sz(q)) {
		auto it = q.upper_bound(!j ? 0 : g[v][j - 1]);
		if (it == q.end())
			break;
		if (j < sz(g[v]) && *it >= g[v][j]) {
			++j;
			continue;
		}
		merge(v, *it);		
		dfs(*it);
	}
}
 
main () {
	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for (int i = 1; i <= n; ++i) {
		p[i] = i;                  
		cnt[i] = 1;
		sort(all(g[i]));
		q.insert(i);
	}

	for (int i = 1; i <= n; ++i)
		if (q.count(i))
			dfs(i);

	
	vi ans;
	for (int i = 1; i <= n; ++i)
		if (p[i] == i)
			ans.pb(cnt[i]);

	printf("%d\n", sz(ans));
	sort(all(ans));
	for (auto x : ans)
		printf("%d ", x);
}