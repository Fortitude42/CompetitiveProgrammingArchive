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

int n, m, q;


struct node {
	ll sum;
	node *l, *r;
	node (ll x) {
		l = r = NULL;
		sum = x;
	}

	node (node *L, node *R) {
		l = L, r = R;
		sum = (l ? l->sum : 0) + (r ? r->sum : 0);	
	}

};


typedef node * pnode;

pnode build (int tl = 1, int tr = n) {
	if (tl == tr) 
		return new node(0);
	int tm = (tl + tr) >> 1;
	return new node (build(tl, tm), build(tm + 1, tr));
}

ll get (pnode t, int l, int r, int tl = 1, int tr = n) {
	if (!t || l > r)
		return 0;
	if (l == tl && r == tr)
		return t->sum;
	int tm = (tl + tr) >> 1;                       
	return get(t->l, l, min(r, tm), tl, tm) + get(t->r, max(l, tm + 1), r, tm + 1, tr);
}

pnode update (pnode t, int pos, int x, int tl = 1, int tr = n) {
	if (tl == tr) 
		return new node(t->sum + x);
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return new node(update(t->l, pos, x, tl, tm), t->r);
	return new node(t->l, update(t->r, pos, x, tm + 1, tr));
}

vpii g[N];
pnode root[N];
int t[N << 2][4], add[N << 2], s[N], lf[N], rg[N];

ll get (int l, int r, int a, int b) {
	return get(root[r], a, b) - get(root[l - 1], a, b);
}


void build1 (int v = 1, int tl = 1, int tr = n) {
	t[v][0] = tl;
	t[v][1] = n + 1;
	t[v][2] = tr;
	t[v][3] = 0;
	add[v] = -1;

	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build1(v << 1, tl, tm);
	build1(v << 1 | 1, tm + 1, tr);
}

inline void push (int v, int tl, int tr, int tm) {
	if (add[v] != -1) {
		add[v << 1] = add[v];
		add[v << 1 | 1] = add[v];

		if (add[v]) {
			t[v << 1][0] = n + 1;
			t[v << 1][1] = tl;
			t[v << 1][2] = 0;
			t[v << 1][3] = tm;			

			t[v << 1 | 1][0] = n + 1;
			t[v << 1 | 1][1] = tm + 1;
			t[v << 1 | 1][2] = 0;
			t[v << 1 | 1][3] = tr;
		} else {
			t[v << 1][0] = tl;
			t[v << 1][1] = n + 1;
			t[v << 1][2] = tm;
			t[v << 1][3] = 0;			

			t[v << 1 | 1][0] = tm + 1;
			t[v << 1 | 1][1] = n + 1;
			t[v << 1 | 1][2] = tr;
			t[v << 1 | 1][3] = 0;
		}

		add[v] = -1;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;
			
	if (l <= tl && tr <= r) {
		if (!x) {
			t[v][0] = tl;
			t[v][1] = n + 1;
			t[v][2] = tr;
			t[v][3] = 0;
		} else {
			t[v][0] = n + 1;
			t[v][1] = tl;
			t[v][2] = 0;
			t[v][3] = tr;
		}
		add[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v][0] = min(t[v << 1][0], t[v << 1 | 1][0]);
	t[v][1] = min(t[v << 1][1], t[v << 1 | 1][1]);
	t[v][2] = max(t[v << 1][2], t[v << 1 | 1][2]);
	t[v][3] = max(t[v << 1][3], t[v << 1 | 1][3]);	
}

int getL (int l, int r, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return n + 1;

//	cerr << tl << ' ' << tr << ' ' << t[v][lvl] << endl;
	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	return min(getL(l, r, lvl, v << 1, tl, tm), getL(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

int getR (int l, int r, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	return max(getR(l, r, lvl, v << 1, tl, tm), getR(l, r, lvl, v << 1 | 1, tm + 1, tr));
}


 
main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &lf[i], &rg[i], &s[i]);
		g[lf[i]].pb({rg[i], s[i]});
	}

	root[0] = build();
	for (int i = 1; i <= n; ++i) {
		root[i] = root[i - 1];
		for (auto x : g[i])
			root[i] = update(root[i], x.f, x.s);		
	}


	build1();

	ll ans = 0;

	scanf("%d", &q);
	while (q--) {
		int tp, l, r;
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 0) {
			int L = l;
			while (1) {
				L = getL(L, n, 1);
				if (L > r)
					break;

				int R = min(r, getL(L, n, 0) - 1);

				int a = (L == 1 ? 0 : getR(1, L - 1, 3)) + 1;
				int b = (R == n ? n + 1 : getL(R + 1, n, 1)) - 1;
//				cerr << a << ' ' << b << endl;
				ans -= get(a, R, L, b);
				update(L, R, 0);
				L = R + 1;
			}
		} else {
			int L = l;
			while (1) {
				L = getL(L, n, 0);
				if (L > r)
					break;
				int R = min(r, getL(L, n, 1) - 1);
				int a = (L == 1 ? 0 : getR(1, L - 1, 3)) + 1;
				int b = (R == n ? n + 1 : getL(R + 1, n, 1)) - 1;

				ans += get(a, R, L, b);
				update(L, R, 1);
				L = R + 1;
			}
		}

		printf("%lld\n", ans);
	}
	
	
}