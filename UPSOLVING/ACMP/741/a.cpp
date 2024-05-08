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
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, tin[M], fup[M], timer;
int cnt[M*2], a[M*2], b[M*2], p[M*2];
vi g[M];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

void dfs(int v, int p = 0) {
	tin[v] = fup[v] = ++timer;

	for (auto x : g[v]) {
		if (x == p)
			continue;
	
		int to = (a[x] ^ b[x] ^ v);
		
		if (!tin[to]) {
			dfs(to, x);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] < tin[v])
				merge(x, p);
		} else {
			fup[v] = min(fup[v], tin[to]); 
			if (tin[v] > tin[to])
				merge(x, p);
		}
	}

}

 
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {  
		scanf("%d%d", &a[i], &b[i]);
		g[a[i]].pb(i);
		g[b[i]].pb(i);
		p[i] = i;
	}

	for (int i = 1; i <= n; ++i)
		if (!tin[i])
			dfs(i);

	vector < pair < pii, int > > ans;
	int k = 0;
	for (int i = 1; i <= m; ++i) {
		ans.pb({{a[i], b[i]}, ++cnt[get(i)]});
		k = max(k, cnt[get(i)]);
	}

	cout << k << endl;
	for (auto x : ans)
		cout << x.f.f << ' ' << x.f.s << ' ' << x.s << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}