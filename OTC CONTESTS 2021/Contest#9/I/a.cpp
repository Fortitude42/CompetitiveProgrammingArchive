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
const int N = 1e5 + 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, h, a[M], b[M], t[M << 3], add[M << 3];
vi vals;

void push(int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		t[v << 1] += add[v];
		t[v << 1 | 1] += add[v];

		add[v] = 0;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (l > r || tl > r || l > tr) 
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
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

 
void solve() {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]); 
		b[i] = max(0, h - b[i]);
		vals.pb(b[i]);
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); 
		vals.pb(a[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	for (int i = 1; i <= m; ++i) {
		b[i] = lower_bound(all(vals), b[i]) - vals.begin();
		update(0, b[i], -1);

		a[i] = lower_bound(all(vals), a[i]) - vals.begin();
		update(0, a[i], 1);
	}

	int ans = 0;
	for (int i = 1; i + m - 1 <= n; ++i) {
		if (t[1] >= 0) 
			++ans;

		if (i + m <= n) {
			a[i + m] = lower_bound(all(vals), a[i + m]) - vals.begin();
			update(0, a[i], -1);
			update(0, a[i + m], 1);
		}
	}

	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;	
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}