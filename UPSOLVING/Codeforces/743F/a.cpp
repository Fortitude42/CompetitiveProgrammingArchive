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
const int N = 2e5 + 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, q, mx[M << 2], mx1[M << 2], c_mx[M << 2]; 
ll s[M << 2], add[M << 2];

void upd(int v) {
	if (mx[v << 1] == mx[v << 1 | 1]) {
		mx[v] = mx[v << 1];
		c_mx[v] = c_mx[v << 1] + c_mx[v << 1 | 1];
		mx1[v] = max(mx1[v << 1], mx1[v << 1 | 1]);
	} else if (mx[v << 1] > mx[v << 1 | 1]) {
		mx[v] = mx[v << 1];
		c_mx[v] = c_mx[v << 1];
		mx1[v] = max(mx1[v << 1], mx[v << 1 | 1]);
	} else {
		mx[v] = mx[v << 1 | 1];
		c_mx[v] = c_mx[v << 1 | 1];
		mx1[v] = max(mx[v << 1], mx1[v << 1 | 1]);
	}

}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		mx[v] = tl;
		mx1[v] = -1;
		c_mx[v] = 1;
		s[v] = 1;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	upd(v);
	s[v] = s[v << 1] + s[v << 1 | 1];
}

void push(int v) {
	if (mx[v << 1] > mx[v]) 
		mx[v << 1] = mx[v];
	

	if (mx[v << 1 | 1] > mx[v]) 
		mx[v << 1 | 1] = mx[v]; 			
}

void push2(int v, int tl, int tr, int tm) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		s[v << 1] += add[v] * (tm - tl + 1);
		s[v << 1 | 1] += add[v] * (tr - tm);

		add[v] = 0;
	}
}

void update2(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;


	if (l <= tl && tr <= r) {
		s[v] += x * 1ll * (tr - tl + 1);
		add[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push2(v, tl, tr, tm);
	
	update2(l, r, x, v << 1, tl, tm);
	update2(l, r, x, v << 1 | 1, tm + 1, tr);

	s[v] = s[v << 1] + s[v << 1 | 1];
}

ll get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return s[v];

	int tm = (tl + tr) >> 1;
	push2(v, tl, tr, tm);

	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r || mx[v] <= x)
		return;

	if (l <= tl && tr <= r && mx1[v] < x) {
		update2(x + 1, mx[v], -c_mx[v]);
		mx[v] = x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	
	update(l, r, x, v << 1, tl, tm);						
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	
	upd(v);
}

void update1(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		mx[v] = x;
		mx1[v] = -1;
		c_mx[v] = 1;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v);
	
	if (pos <= tm)
		update1(pos, x, v << 1, tl, tm);
	else
		update1(pos, x, v << 1 | 1, tm + 1, tr);

	upd(v);
}

int get1 (int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return mx[v];

	int tm = (tl + tr) >> 1;
	push(v);

	if (pos <= tm)
		return get1(pos, v << 1, tl, tm);

	return get1(pos, v << 1 | 1, tm + 1, tr);
}



void solve() {
	scanf("%d%d", &n, &q);
	build();
	while (q--) {
		int p;
		scanf("%d", &p);
		if (p == 1) {
			int c, g;
			scanf("%d%d", &c, &g);
			update(1, c - 1, c - 1);

			int prvW = get1(c);
			update2(c, prvW, -1);
			update2(c, g, 1);
			update1(c, g);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", get(l, r));
		}

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