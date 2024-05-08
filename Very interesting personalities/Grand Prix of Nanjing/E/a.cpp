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
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, q, a[M];
int l[M], r[M], x[M], res[M];
vector < pair < pii, pii > > g[M];

inline void Add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

struct matrix {
	int a[4][4];	

	matrix () {
		memset(a, 0, sizeof(a));
	}

	matrix(int k) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 4; ++i)
			a[i][i] = 1;

		a[0][1] = k;
		a[0][2] = a[0][3] = k*1ll*k % MOD;
		a[1][2] = a[1][3] = 2*k % MOD;
		a[2][3] = 1;
	}

	bool operator != (const matrix &x) {
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (a[i][j] != x.a[i][j])
					return 1;
		return 0;
	}

	matrix operator * (const matrix &x) {
		matrix res;

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k)
					res.a[i][j] = (res.a[i][j] + a[i][k] * 1ll * x.a[k][j]) % MOD;

		return res;
	}
};

matrix zero;

struct node {
	int a[4];
	node(){
		memset(a, 0, sizeof(a));
	}

	node(int x, int y, int z, int k) {
		a[0] = x;
		a[1] = y;
		a[2] = z;
		a[3] = k;
	}

	node operator * (const matrix &x) {
		node res;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				res.a[i] = (res.a[i] + a[j] * 1ll * x.a[j][i]) % MOD;

		return res;				
	}
};



node t[M << 2];
matrix add[M << 2];

void build(int v = 1, int tl = 1, int tr = n) {
	add[v] = zero;

	if (tl == tr) {
		t[v] = node(1, a[tl], a[tl] * 1ll * a[tl] % MOD, a[tl] * 1ll * a[tl] % MOD);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	
	for (int i = 0; i < 4; ++i) {
		t[v].a[i] = t[v << 1].a[i] + t[v << 1 | 1].a[i];
		if (t[v].a[i] >= MOD)
			t[v].a[i] -= MOD;
	}
}

inline void push(int v) {
	if (add[v] != zero) {
		add[v << 1] = add[v << 1] * add[v];
		t[v << 1] = t[v << 1] * add[v];

		add[v << 1 | 1] = add[v << 1 | 1] * add[v];
		t[v << 1 | 1] = t[v << 1 | 1] * add[v];
		add[v] = zero;
	}
}


void update(int l, int r, int k, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		matrix cur = matrix(k);
		t[v] = t[v] * cur;
		add[v] = add[v] * cur;
		return;
	}
	
	int tm = (tl + tr) >> 1;
	push(v);

	update(l, r, k, v << 1, tl, tm);
	update(l, r, k, v << 1 | 1, tm + 1, tr);

	for (int i = 0; i < 4; ++i) {
		t[v].a[i] = t[v << 1].a[i] + t[v << 1 | 1].a[i];
		if (t[v].a[i] >= MOD)
			t[v].a[i] -= MOD;
	}
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v].a[3];

	push(v);
	int tm = (tl + tr) >> 1;

	int res = get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
	
	if (res >= MOD)
		res -= MOD;

	return res;
}


void solve() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);        
	    Add(a[i], 0);
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &x[i]); 
	    Add(x[i], 0);
	}

	for (int i = 1; i <= q; ++i) {
		int l, r, x, y;
		scanf("%d%d%d%d", &l, &r, &x, &y);
		if (x > 0)
			g[x - 1].pb(mp(mp(l, r), mp(i, -1)));
		g[y].pb(mp(mp(l, r), mp(i, 1)));
	}

	build();
	for (int i = 0; i <= m; ++i) {
		if (i > 0) {
			update(l[i], r[i], x[i]);
			update(1, l[i] - 1, 0);
			update(r[i] + 1, n, 0);
		}


		for (auto x : g[i]) 
			Add(res[x.s.f], x.s.s * get(x.f.f, x.f.s));
	}

	for (int i = 1; i <= q; ++i)
		printf("%d\n", res[i]);
}

main () {
	for (int i = 0; i < 4; ++i)
		zero.a[i][i] = 1;

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

