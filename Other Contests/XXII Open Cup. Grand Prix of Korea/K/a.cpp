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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, q, p[3][M], c[M], k;
pii t[3][M << 2];
bool was[M];
vi order;

void build(int v = 1, int tl = 1, int tr = n) {
	for (int j = 0; j < 3; ++j)
		t[j][v] = {inf, inf};

	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update(int pos, int lvl, pii x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[lvl][v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, lvl, x, v << 1, tl, tm);
	else
		update(pos, lvl, x, v << 1 | 1, tm + 1, tr);
	t[lvl][v] = min(t[lvl][v << 1], t[lvl][v << 1 | 1]);		
}

pii get(int l, int r, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return {inf, inf};
	
	if (l <= tl && tr <= r)
		return t[lvl][v];

	int tm = (tl + tr) >> 1;
	return min(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

void dfs(int v) {
	was[v] = 1;
	for (int j = 0; j < 3; ++j) 
		update(p[j][v], j, {inf, inf}); 

	for (int j = 0; j < 3; ++j) {
		bool stop;	
		do {
			stop = 1;
			pii cur = get(p[j][v] + 1, n, j);
			if (-cur.f > p[(j + 1) % 3][v]) {
				dfs(cur.s);
				stop = 0;
			}
		} while (!stop);
	}

	order.pb(v);
}

void dfs1(int v) {
	c[v] = k;
	
	for (int j = 0; j < 3; ++j)
		update(p[j][v], j, {inf, inf});

	for (int j = 0; j < 3; ++j) {
		bool stop;	
		do {
			stop = 1;
			pii cur = get(1, p[j][v] - 1, j);
			if (cur.f < p[(j + 1) % 3][v]) {
				dfs1(cur.s);
				stop = 0;
			}
		} while (!stop);
	}	
	
}
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j)
			scanf("%d", &p[j][i]);
		

	build();
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < 3; ++j) 
			update(p[j][i], j, {-p[(j + 1) % 3][i], i});

	for (int i = 1; i <= n; ++i)
		if (!was[i])
			dfs(i);
	reverse(all(order));


	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < 3; ++j) 
			update(p[j][i], j, {p[(j + 1) % 3][i], i});
	
	for (auto i : order)
		if (!c[i]) {
		    ++k;
			dfs1(i);
		}


	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		puts(c[a] <= c[b] ? "YES" : "NO");
	}
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}