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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
int n, m, q, t[M << 2][4], res[M];
pair < pii, int > b[M];
pii a[M];

void build(int v = 1, int tl = 1, int tr = n) {
	for (int x = 0; x < 4; ++x)
		t[v][x] = inf;

	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update(int pos, int x, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v][lvl] = min(t[v][lvl], x);
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, lvl, v << 1, tl, tm);
	else
		update(pos, x, lvl, v << 1 | 1, tm + 1, tr);

	t[v][lvl] = min(t[v << 1][lvl], t[v << 1 | 1][lvl]);
}

int get(int l, int r, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return inf;

	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	return min(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}


inline void add(int i) {
	update(a[i].s, a[i].f + a[i].s, 0);//l + r
	update(a[i].s, a[i].f - a[i].s, 1);//r - l
	update(a[i].s, -a[i].f + a[i].s, 2);//l - r
	update(a[i].s, -a[i].f - a[i].s, 3);//-l -r
}

bool cmp(pair < pii, int > a, pair < pii, int > b) {
	return mp(mp(a.f.s, a.f.f), a.s) < mp(mp(b.f.s, b.f.f), b.s);
}

bool cmp1(pii a, pii b) {
	if (a.s != b.s)
		return a.s < b.s;

	return a.f < b.f;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &a[i].f, &a[i].s);
		if (a[i].f < a[i].s)
			swap(a[i].f, a[i].s);
	}

	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &b[i].f.f, &b[i].f.s);
		if (b[i].f.f < b[i].f.s)
			swap(b[i].f.f, b[i].f.s);
		b[i].s = i;
		res[i] = min(b[i].f.f - b[i].f.s, n - (b[i].f.f - b[i].f.s));
	}

	sort(a + 1, a + 1 + m);
	sort(b + 1, b + 1 + q);
	build();

	int j = 1;
	for (int i = 1; i <= q; ++i) {
		while (j <= m && a[j].f <= b[i].f.f) {\
			update(a[j].s, -a[j].f + a[j].s, 2);//l - r
			j++;
		}

		res[b[i].s] = min(res[b[i].s], get(b[i].f.s, b[i].f.f, 2) + b[i].f.f - b[i].f.s + 1);
	}

	build();

	j = m;
	for (int i = q; i > 0; --i) {
		while (j > 0 && a[j].f >= b[i].f.f) 
			add(j--);

		res[b[i].s] = min(res[b[i].s], get(b[i].f.s, b[i].f.f, 0) - (b[i].f.f + b[i].f.s) + 1);
		res[b[i].s] = min(res[b[i].s], get(b[i].f.s, b[i].f.f, 3) + (n + b[i].f.f + b[i].f.s) + 1);
		res[b[i].s] = min(res[b[i].s], get(b[i].f.f, n, 2) + (n - b[i].f.f + b[i].f.s) + 1);
		res[b[i].s] = min(res[b[i].s], get(1, b[i].f.s, 1) + (b[i].f.s - b[i].f.f) + 1);
	}

	sort(b + 1, b + 1 + q, cmp);
	build();

	j = 1;
	for (int i = 1; i <= q; ++i) {             
		while (j <= m && a[j].f <= b[i].f.s) {
			update(a[j].s, -a[j].f + a[j].s, 2);//l - r 
			j++;
		}

		res[b[i].s] = min(res[b[i].s], get(1, b[i].f.s, 2) + (n + b[i].f.s - b[i].f.f) + 1);
	}

	build();
	sort(a + 1, a + 1 + m, cmp1);
	j = 1;
	for (int i = 1; i <= q; ++i) {             
		while (j <= m && a[j].s <= b[i].f.s) {
			update(a[j].f, a[j].f + a[j].s, 0);//l + r
			update(a[j].f, -a[j].f - a[j].s, 3);//-l -r
			j++;
		}

		res[b[i].s] = min(res[b[i].s], get(b[i].f.s, b[i].f.f, 3) + b[i].f.f + b[i].f.s + 1);
		res[b[i].s] = min(res[b[i].s], get(b[i].f.s, b[i].f.f, 0) + n - (b[i].f.f + b[i].f.s) + 1);
	}


	for (int i = 1; i <= q; ++i)
		printf("%d\n", res[i]);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

