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

int n, c[N], q, add[N << 2];
ll res[N], t[N << 2];
vpii g[N];


void push (int v, int tl, int tr, int tm) {
	if (add[v]) {
		t[v << 1] = add[v] * 1ll * (tm - tl + 1);
		t[v << 1 | 1] = add[v] * 1ll * (tr - tm);

		add[v << 1] = add[v];
		add[v << 1 | 1] = add[v];

		add[v] = 0;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		add[v] = x;
		t[v] = x * 1ll * (tr - tl + 1);
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
}   	


ll get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}
 

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);

	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		g[r].pb({l, i});
	}

	stack < int > st;
	for (int i = 1; i <= n; ++i) {
		while (sz(st) && c[st.top()] <= c[i])
			st.pop();

		int j = !sz(st) ? 1 : st.top() + 1;
		update(j, i, c[i]);

		for (auto x : g[i]) 
			res[x.s] = get(x.f, i);		

		st.push(i);
	}	

	for (int i = 1; i <= q; ++i)
		printf("%lld ", res[i]);
}