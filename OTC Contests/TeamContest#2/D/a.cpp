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
 
const int inf = 1e9, maxn = 1e7 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, v, u, w, p[N], cnt[N];
vector < pair < int, pii > > e;
vpii g[maxn];
ll ans;

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u, int w) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])
		swap(v, u);

	ans += cnt[v] * 1ll * cnt[u] * w;
	cnt[v] += cnt[u];
	p[u] = v;
}

 
main () {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &v, &u, &w);
		g[w].pb({v, u});
	}

	for (int i = 1; i <= n; ++i) {
		p[i] = i;                 
		cnt[i] = 1;
	}
	

	for (int i = maxn - 1; i >= 0; --i) {
		for (auto x : g[i])
			if (get(x.f) == get(x.s)) {
				cout << "-1\n" << endl;
				return 0;
			}		

		for (auto x : g[i])
			if (get(x.f) != get(x.s)) {
				merge(x.f, x.s, i);    
//				e.pb({i, x});
			}
	}

	for (int i = 1; i <= n; ++i)
		if (get(1) != get(i)) {
			merge(1, i, 1);    
//			e.pb({1, {1, i}});
		}

/*
	ans = 0;
	sort(all(e));
	reverse(all(e));

	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		cnt[i] = 1;
	}

	for (auto x : e)
		merge(x.s.f, x.s.s, x.f);*/

	cout << ans << endl;
}