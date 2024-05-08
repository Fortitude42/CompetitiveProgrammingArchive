//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
const int N = 1e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
int n, m, tin[M], fup[M], timer, cnt;
set < int > cp, cur;
bool used[M];
vi g[M];

void dfs(int v, int p = 0) {
	fup[v] = tin[v] = ++timer;
	int children = 0;

	for (auto to : g[v]) {
		if (to == p)
			continue;
		if (!tin[to]) {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] >= tin[v] && p > 0)
				cp.insert(v); 			
			++children;
		} else
			fup[v] = min(fup[v], tin[to]);		
	}

	if (p == 0 && children > 1)
		cp.insert(v);
}

void dfs1(int v) {
	used[v] = 1;
	++cnt;
	for (auto to : g[v])
		if (!cp.count(to) && !used[to])
			dfs1(to);
		else if (cp.count(to))	
			cur.insert(to);
}

void solve(int tt) {
	scanf("%d%d", &n, &m);
	while (m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		++v, ++u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfs(1);
	int ans = 0;
	unsigned long long res = 1;

	for (int i = 1; i <= n; ++i)
		if (!cp.count(i) && !used[i]) {
			cur.clear();
			cnt = 0;
			dfs1(i); 
			if (sz(cur) == 1) {
				++ans;
				res = res * cnt; 
			}
		}

	if (!sz(cp)) {
		ans = 2;
		res = n * 1ll * (n - 1) / 2;
	}
	printf("Case %d: %d %llu\n", tt, ans, res);

	cp.clear();
	timer = 0;
	for (int i = 1; i <= n; ++i) {
		tin[i] = fup[i] = 0;
		g[i].clear();
		used[i] = 0;
	}
		
}

main () {
  int TT;
  TT = 1;
  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve(tt);
  }
}