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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, q, h[N], d[N], add[N << 2];
ll t[N << 2], s[N], res[N];
pii mx[N][20];
vpii g[N][2];

void push (int v, int tl, int tr, int tm) {
	if (add[v]) {
		add[v << 1] = add[v];
		add[v << 1 | 1] = add[v];


		t[v << 1] = add[v] * 1ll * (tm - tl + 1);
		t[v << 1 | 1] = add[v] * 1ll * (tr - tm);

		add[v] = 0;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v] = x * 1ll * (tr - tl + 1);
		add[v] = x;
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


void build () {
	for (int i = 1; i <= n; ++i) {
		if (i > 1)
			d[i] = d[i >> 1] + 1;
		mx[i][0] = mp(h[i], i);
	}
	
	for (int j = 1; j < 20; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);	
}

int get1 (int l, int r) {
	int D = d[r - l + 1];
	return max(mx[l][D], mx[r - (1 << D) + 1][D]).s;
}


void solve (int j) {
	update(1, n, 0);

	stack < pii > st;
	
	for (int l = n; l > 0; --l) {
		int r = l;


		while (sz(st) && h[st.top().f] <= h[l]) {
			r = st.top().s;
			st.pop();
		}

		st.push({l, r});
		update(l, r, h[l]);
/*		cerr << l << ' ' << r << ' ' << h[l] << endl;
		for (int i = 1; i <= n; ++i)
			cerr << get(i, i) << ' ';
		cerr << endl;*/
		
		for (auto x : g[l][j]) { //l...x.f
			res[x.s] += get(l, x.f) - s[x.f] + s[l - 1];		
//			cerr << l << ' ' << x.f << ' ' << get(l, x.f) << ' ' << s[x.f] << ' ' << s[l - 1] << endl;
		}
	}
}

main () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &h[i]);       
	build();

	
	for (int i = 1; i <= q; ++i) {
		int l, r, j;
		scanf("%d%d", &l, &r);
		j = get1(l, r);
		g[l][0].pb({j, i});//l...j
		if (j < r)
			g[n - r + 1][1].pb({n - j, i});//j+1...r
	}

	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + h[i];
	solve(0);

	reverse(h + 1, h + 1 + n);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + h[i];
	solve(1);
		


	for (int i = 1; i <= q; ++i)
		printf("%lld\n", res[i]);	
}