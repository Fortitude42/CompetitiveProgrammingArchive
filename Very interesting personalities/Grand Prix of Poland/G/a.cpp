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
const int N = 2e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

ll h, a[M];
int n, q;
char c[M];
bool OK;

struct segment{ 
	ll a, b, y, r;
	segment() {}
	segment(ll A, ll B, ll Y, ll R) {
		a = A;
		b = B;
		y = Y;
		r = R;
	}
};
segment Empty = segment(0, 0, INF, 0), cur;
segment t[M << 2];

segment merge(const segment &s, const segment &t) {
	segment res;
	res.y = INF;
	res.r = INF;
	res.b = INF;

	res.a = s.a;
	
	if (s.y != INF) {
		if (s.y <= t.a)
			res.a = s.r;
		else if (s.y <= t.r) {
			res.y = t.y;
			res.r = s.r;
		} else {
			res.y = s.y + t.b;
			res.r = s.r;
		}
	}

	if (s.b != INF) {
		if (s.r + 1 <= t.a - s.b) {
			res.a = max(res.a, t.a - s.b); 
		}

		if (s.r + 1 <= t.r - s.b) {
			res.y = t.y;
			res.r = t.r - s.b;
		}

		if (t.b != INF) {
			res.r = max(s.r, t.r - s.b);
			res.b = s.b + t.b;
		}
	}
	res.r = min(INF, res.r);
	res.b = min(INF, res.b);
	res.y = min(INF, res.y);
	return res;
}

void update(int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		if (c[pos] == 'B')
			t[v] = segment(a[pos], -a[pos], INF, a[pos]);
		

		if (c[pos] == 'K') 
			t[v] = segment(a[pos] - 1, INF, a[pos], INF);
		

		if (c[pos] == 'C')
			t[v] = segment(0, 0, a[pos], a[pos]);

		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, v << 1, tl, tm);
	else
		update(pos, v << 1 | 1, tm + 1, tr);

	t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

inline bool check(const segment &v) {
	return v.a < h;
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return n + 1;


	int tm = (tl + tr) >> 1;
	if (l <= tl && tr <= r) {
		segment curr = merge(cur, t[v]);
		if (check(curr)) {
		    cur = curr;
			return n + 1; 
		}


		if (tl == tr) {
			cur = curr;
			return tl;
		}

		if (!check(merge(cur, t[v << 1]))) 
			return get(l, r, v << 1, tl, tm);

		cur = merge(cur, t[v << 1]);
		return get(l, r, v << 1 | 1, tm + 1, tr);
	}

	int a = get(l, r, v << 1, tl, tm);
	return a == n + 1 ? get(l, r, v << 1 | 1, tm + 1, tr) : a;
}


void solve() {
	scanf("%d%d%lld", &n, &q, &h);
	for (int i = 1; i <= n; ++i) {
		scanf("\n%c%lld", &c[i], &a[i]); 
		update(i);
	}


	while (q--) {
		char tp;
		int pos;
		scanf("\n%c%d", &tp, &pos);
		if (tp == 'Z') {
			scanf(" %c%lld", &c[pos], &a[pos]);
			update(pos);
		} else {
			cur = Empty;
			int i = get(pos, n);
			printf("%d\n", i == pos ? -1 : i - 1);
		}
	}
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}