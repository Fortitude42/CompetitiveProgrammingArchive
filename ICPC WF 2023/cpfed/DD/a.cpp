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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int l[M], r[M], mx[M][2];
pii t[M << 3], tmp[M];
int n, q, g[M][2], m, up[M][18][2];
                        	
void build(int v = 1, int tl = 1, int tr = m) {
	t[v] = mp(0, 0);
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update(int pos, pii x, int v = 1, int tl = 1, int tr = m) {
	if (tl == tr) {
		t[v] = max(t[v], x);
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

pii get(int l, int r, int v = 1, int tl = 1, int tr = m) {
	if (l > r || tl > r || l > tr) 
		return mp(0, 0);

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));		
}

inline int check(const int &v, const int &u) {
	if (v == u)
		return 0;
	if (l[v] <= l[u] && r[u] <= r[v])
		return 1;
	if (l[u] <= l[v] && r[v] <= r[u])
		return 1;

	return inf;
}

inline int dist(int v, int u, int mask) {
	if (!v)
		return inf;
	
	int vv = v;

	int ans = check(v, u), d = 0;
	if (mask & 1) {
		for (int i = mx[v][0]; i >= 0; --i)
			if (r[up[v][i][0]] < r[u]) {
				v = up[v][i][0];
				d |= (1 << i);
//				ans = min(ans, 2*(d + check(v, u)));
			}

		ans = min(ans, (d + 1)*2 + check(up[v][0][0], u));
	}


	d = 0, v = vv;
	if (mask & 2) {
		for (int i = mx[v][1]; i >= 0; --i)
			if (l[up[v][i][1]] < l[u]) {
				v = up[v][i][1];
				d |= (1 << i);
//				ans = min(ans, 2*(d + check(v, u)));
			}

		ans = min(ans, (d + 1)*2 + check(up[v][0][1], u));
	}

	return ans;
}


 
void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &l[i], &r[i]);
	

	for (int i = 1; i <= n; ++i)
		tmp[i] = mp(r[i], i);
	sort(tmp + 1, tmp + 1 + n);
	m = 2*n;

	int j = 1;
	for (int r = 1; r <= m; ++r) {
		while (j <= n && tmp[j].f == r) {
			g[tmp[j].s][0] = get(l[tmp[j].s], r - 1).s;
			update(l[tmp[j].s], mp(l[tmp[j].s], tmp[j].s));
			++j;
		}
	}

	build();

	for (int i = 1; i <= n; ++i)
		tmp[i] = mp(l[i], i);
	sort(tmp + 1, tmp + 1 + n);
	j = 1;	
	for (int l = 1; l <= m; ++l)
		while (j <= n && tmp[j].f == l) {			
			g[tmp[j].s][1] = get(r[tmp[j].s] + 1, m).s;
			update(r[tmp[j].s], mp(r[tmp[j].s], tmp[j].s));
			j++;
		}

	
	for (int i = 1; i <= n; ++i) {
		up[i][0][0] = g[g[i][0]][1];
		up[i][0][1] = g[g[i][1]][0];
	}

	for (int j = 1; j < 18; ++j) 
		for (int i = 1; i <= n; ++i) {
			up[i][j][0] = up[up[i][j - 1][0]][j - 1][0];
			up[i][j][1] = up[up[i][j - 1][1]][j - 1][1];

			if (up[i][j][0] > 0)
				mx[i][0] = j;
			if (up[i][j][1] > 0)
				mx[i][1] = j;
		}
	
	
	while (q--) {
		int v, u;
		scanf("%d%d", &v, &u);

		if (r[v] > r[u])
			swap(v, u);
		int ans = min({dist(v, u, 3), 1 + dist(g[v][0], u, 2), 1 + dist(g[v][1], u, 1)});
		if (ans == inf)
			ans = -1;
		printf("%d\n", ans);
	}
}

main () {
  int TT;
  TT = 1;
//  fastio
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}