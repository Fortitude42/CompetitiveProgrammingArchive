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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, l[M], r[M], t[M << 2], lz[M << 2], sum, ans[M];
vi g[M];
 
void build(int v = 1, int tl = 1, int tr = n) {
	t[v] = inf;
	lz[v] = -1;

	if (tl == tr) 
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void push(int v) {
	if (lz[v] != -1) {
		lz[v << 1] = t[v << 1] = lz[v];
		lz[v << 1 | 1] = t[v << 1 | 1] = lz[v];
		lz[v] = -1;
	}
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return inf;

	if (l <= tl && tr <= r)
		return t[v];

	push(v);
	int tm = (tl + tr) >> 1;
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		lz[v] = t[v] = x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void add(int i) {
	for (int x = l[i]; x <= r[i]; ++x)
		assert(get(x, x) == inf);

	sum += (r[i] - l[i] + 1);
	update(l[i], r[i], i);
}

void del(int i) {
	for (int x = l[i]; x <= r[i]; ++x)
		assert(get(x, x) == i);

	sum -= (r[i] - l[i] + 1);
	update(l[i], r[i], inf);
}


void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		g[r[i] - l[i] + 1].pb(i);
	}

	build();

	for (int x = n; x > 0; --x) {
		for (auto i : g[x]) {
			while (1) {
				int y = get(l[i], r[i]);
				if (y == inf) {
					add(i);
					break;
				}

				if (y < i)
					break;
				del(y);
			}
		}

		assert(sum >= 0 && sum <= n);
		ans[x] = sum;
	}


	for (int x = 1; x <= n; ++x)
		printf("%d\n", ans[x]);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}