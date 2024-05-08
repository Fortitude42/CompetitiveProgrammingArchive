#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, q, a[M], mx[M << 2], ss[M];
vi g[M];

void update(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		mx[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return 0;

	if (l <= tl && tr <= r)
		return mx[v];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

struct node {
	int sum;
	node *l, *r;
	node (int x) {
		l = r = NULL;
		sum = x;
	}

	node (node *L, node *R) {
		l = L, r = R;
		sum = (l ? l->sum : 0) + (r ? r->sum : 0);	
	}

};


typedef node * pnode;

inline pnode build (int tl = 1, int tr = n) {
	if (tl == tr) 
		return new node(0);
	int tm = (tl + tr) >> 1;
	return new node (build(tl, tm), build(tm + 1, tr));
}

int get (pnode t, int l, int r, int tl = 1, int tr = n) {
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


pnode root[M];

inline int get1(const int &l, const int &r, const int &a, const int &b) {
	return get(root[r], a, b) - get(root[l - 1], a, b);
}

 
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		g[a[i]].pb(i);
	}

	root[0] = build();
	for (int r = 1; r <= n; ++r) {
		root[r] = root[r - 1];
		ss[r] = ss[r - 1];
		for (int i = 0; i < sz(g[r]); ++i) {
			if (!i) {
				ss[r]++;
				continue;
			}
			int tmp = get(g[r][i - 1], g[r][i]);
			if (tmp > 0)
				root[r] = update(root[r], tmp, 1);
		}

		for (auto i : g[r])
			update(i, r);
	}




	while (q--) {
		int l, r;
		cin >> l >> r;
		int ans = get1(l, r, l, n) + ss[r] - ss[l - 1];
		cout << ans << '\n';
	}
}

main () {
	fastio
  int TT;
  TT = 1;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}