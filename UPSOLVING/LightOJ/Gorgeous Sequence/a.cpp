//template by paradox & gege & parasat
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <ctime>
#include <map>      
#include <set>      

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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 

int n, m, a[M], mx[M << 2], mx1[M << 2], c_mx[M << 2];
ll s[M << 2];

inline void upd(int v) {
	s[v] = s[v << 1] + s[v << 1 | 1];

	if (mx[v << 1] == mx[v << 1 | 1]) {
		mx[v] = mx[v << 1];
		c_mx[v] = c_mx[v << 1] + c_mx[v << 1 | 1];
		mx1[v] = max(mx1[v << 1], mx1[v << 1 | 1]);
		return;
	}

	if (mx[v << 1] > mx[v << 1 | 1]) {
		mx[v] = mx[v << 1];
		c_mx[v] = c_mx[v << 1];
		mx1[v] = max(mx1[v << 1], mx[v << 1 | 1]);
		return;
	}

	mx[v] = mx[v << 1 | 1];
	c_mx[v] = c_mx[v << 1 | 1];
	mx1[v] = max(mx[v << 1], mx1[v << 1 | 1]);
}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		s[v] = mx[v] = a[tl];
		c_mx[v] = 1;
		mx1[v] = -1;
		return;
	}

	int tm = (tl + tr) >> 1;
	
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);

	upd(v);
}

inline void push(int v) {
	if (mx[v << 1] > mx[v]) {
		s[v << 1] -= c_mx[v << 1] * 1ll * (mx[v << 1] - mx[v]);
		mx[v << 1] = mx[v];
	}

	if (mx[v << 1 | 1] > mx[v]) {
		s[v << 1 | 1] -= c_mx[v << 1 | 1] * 1ll * (mx[v << 1 | 1] - mx[v]);
		mx[v << 1] = mx[v];
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r || mx[v] <= x)
		return;

	if (l <= tl && tr <= r && mx1[v] < x) {
		s[v] -= (mx[v] - x) * 1ll * c_mx[v];
		mx[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	upd(v);
}

int get_mx (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return -inf;

	if (l <= tl && tr <= r)
		return mx[v];

	push(v);
	int tm = (tl + tr) >> 1;

	return max(get_mx(l, r, v << 1, tl, tm), get_mx(l, r, v << 1 | 1, tm + 1, tr));
}

ll get_sum (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return s[v];

	push(v);
	int tm = (tl + tr) >> 1;
	return get_sum(l, r, v << 1, tl, tm) + get_sum(l, r, v << 1 | 1, tm + 1, tr);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	build();
	while (m--) {
		int tp, l, r;
		scanf("%d%d%d", &tp, &l, &r);
		if (!tp) {
			int x;
			scanf("%d", &x);
			update(l, r, x);
		} else if (tp == 1)
			printf("%d\n", get_mx(l, r));
		else
			printf("%lld\n", get_sum(l, r));
	}
}

int main () {
  int TT;
  TT = 1;
  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}