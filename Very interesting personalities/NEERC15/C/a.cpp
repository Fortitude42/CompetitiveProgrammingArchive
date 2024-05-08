//by paradox & gege & parasat
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, k, a[M], b[M], p[M], cnt[M], par[M], par1[M]; 
int tin[M], timer, cnt1[M], col[M], C, sz[M];
vi g[M], gg[M];
bool bad[M];

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
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

void F(int v, int u) {
	int prv = -1;
	while (v != u) {		
		if (prv != -1)
			merge(prv, par[v]);
		prv = par[v];
		v = par1[v];
	}
}


void dfs(int v, int p = 0) {
	sz[v] = 1;
	tin[v] = ++timer;
	for (auto x : g[v]) {
		if (x == p)
			continue;

		int to = (a[x]^b[x]^v);				
		if (!tin[to]) {
			par[to] = x;
			par1[to] = v;
			dfs(to, x);
			sz[v] += sz[to];
		} else if (tin[to] < tin[v]) {
		    merge(p, x);
			F(v, to); 
		}
	}
}

void dfs1(int v) { 
	col[v] = C;
	++cnt1[C];
	for (auto x : g[v])
		if (!bad[x]) {
			int to = (a[x] ^ b[x] ^ v);
			if (!col[to])
				dfs1(to);
		}
}

void solve() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int kk;
		scanf("%d", &kk);
		int u = -1;
		while (kk--) {
			int v;
			scanf("%d", &v);
			if (u != -1) {
				k++;
				a[k] = v;
				b[k] = u;
				g[v].pb(k);
				g[u].pb(k);
			}
			u = v;
		}
	}


	for (int i = 1; i <= k; ++i) {
//		cout << a[i] << ' ' << b[i] << ' ' << i << endl;
		p[i] = i;
		cnt[i] = 1;
	}


	dfs(1);
	for (int i = 1; i <= k; ++i)
		if (cnt[get(i)] > 1) {
			bad[i] = 1;
			gg[get(i)].pb(i);		
		}
				

	ll sum = 0;
	for (int i = 1; i <= n; ++i) 
		if (!col[i]) {
			++C;
			dfs1(i);
			sum += (cnt1[C] - 1) * 1ll * (cnt1[C] - 2) / 2;
		}

	ll ans = 0;
	for (int i = 1; i <= k; ++i) {
		if (!bad[i]) {
			if (tin[a[i]] < tin[b[i]])
				swap(a[i], b[i]);
			ans += sz[a[i]] * 1ll * (n - sz[a[i]]) - 1;
			continue;
		}

		if (i != get(i))
			continue;
			
		vi v;
		for (auto e : gg[i]) {
			v.pb(a[e]);
			v.pb(b[e]);
		}

		sort(all(v));
		v.resize(unique(all(v)) - v.begin());

		int n = sz(v);
		ll sum1 = sum;

		for (auto ver : v) {
			n += cnt1[col[ver]] - 1; 
			sum1 -= (cnt1[col[ver]] - 1) * 1ll * (cnt1[col[ver]] - 2) / 2;
		}

		ans += cnt[i] * 1ll * ((n - 1) * 1ll * (n - 2) / 2 - 1);
		ans += cnt[i] * 1ll * sum1;
	}

	cout << ans << endl;
}

main () {
//	file("cactus");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
