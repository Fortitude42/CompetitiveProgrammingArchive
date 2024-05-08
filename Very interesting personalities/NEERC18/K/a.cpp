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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



char c[M];
int q, a[M], b[M], d[M];
ll t[M << 2], add[M << 2], s[M];

void push(int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1]  += add[v];

		t[v << 1] += add[v];
		t[v << 1 | 1] += add[v];

		add[v] = 0;
		return;
	}
}

void update(int l, int r, ll x, int v = 1, int tl = 0, int tr = M - 1) {
	if (l > r || l > tr || tl > r) 
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		add[v] += x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

ll get(int l, int r, int v = 1, int tl = 0, int tr = M - 1) {
	if (l > r || tl > r || l > tr)
		return -INF;

	if (l <= tl && tr <= r)
		return t[v];

	push(v);
	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

void inc(int pos, int x) {
	while (pos < M){ 
		s[pos] += x;
		pos |= pos + 1;
	}
} 

ll get(int r) {
	ll res = 0;
	while (r >= 0) {
		res += s[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

void solve() {
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("\n%c%d", &c[i], &a[i]);
		if (c[i] == '+')
			scanf("%d", &d[i]);
	}

	update(0, M - 1, -INF);

	for (int i = 1; i <= q; ++i) {
		if (c[i] == '+') {
			update(a[i], a[i], INF);
			update(a[i], a[i], a[i]);
			update(a[i] + 1, M - 1, -d[i]);
			inc(a[i], d[i]);
		}

		if (c[i] == '-') {
			int j = a[i];
			update(a[j], a[j], -INF);
			update(a[j], a[j], -a[j]);
			update(a[j] + 1, M - 1, d[j]);
			inc(a[j], -d[j]);
		}

		if (c[i] == '?') {
			ll sj = get(a[i]);
			ll mx = get(0, a[i]);
			ll prv = mx + sj;
			printf("%lld\n", max(0ll, prv - a[i]));
		}
	}

	
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

