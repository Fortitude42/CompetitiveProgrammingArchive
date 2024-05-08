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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vi g[N];
ll ans[N], t[N << 2];
vector < pair < int, pii > > e;
int n, k, p[N], mn[N], cnt[N << 2];

void update (int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		++cnt[v];
		t[v] += pos;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, v << 1, tl, tm);
	else
		update(pos, v << 1 | 1, tm + 1, tr);	

	t[v] = t[v << 1] + t[v << 1 | 1];
	cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
}

ll Get (int k, int v = 1, int tl = 1, int tr = n) {
	if (cnt[v] < k)
		return t[v];

	if (tl == tr) 
		return k * 1ll * tl;

	int tm = (tl + tr) >> 1;

	if (cnt[v << 1 | 1] >= k)
		return Get(k, v << 1 | 1, tm + 1, tr);

	return t[v << 1 | 1] + Get(k - cnt[v << 1 | 1], v << 1, tl, tm);	
}


int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
	mn[v] = min(mn[v], mn[u]);
}
 
main () {
	scanf("%d%d", &n, &k);
	for (int i = 1, v, u, w; i < n; ++i) {
		scanf("%d%d%d", &v, &u, &w);
		e.pb({w, {v, u}});
	}

	sort(all(e));
	for (int i = 1; i <= n; ++i)
		p[i] = mn[i] = i;

	for (auto x : e) {
		g[max(mn[get(x.s.f)], mn[get(x.s.s)])].pb(x.f);
		merge(x.s.f, x.s.s);
	}

	for (int i = 1; i <= n; ++i) {
		for (auto j : g[i]) {
			update(j);
//			cerr << j << endl;
		}
		printf("%lld\n", Get(k));
	}
}