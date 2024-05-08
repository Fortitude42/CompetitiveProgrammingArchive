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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], lz[M << 2], mx[M << 2];
ll t[M << 2];

void build(int v = 1, int tl = 1, int tr = n) {
	lz[v] = -1;
	t[v] = inf*1ll*(tr - tl + 1);
	mx[v] = inf;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}


void push(int v, int tl, int tr, int tm) {
	if (lz[v] != -1) {
		lz[v << 1] = lz[v];
		lz[v << 1 | 1] = lz[v];

		mx[v << 1] = lz[v];
		mx[v << 1 | 1] = lz[v];

		t[v << 1] = (tm - tl + 1) * 1ll * lz[v];
		t[v << 1 | 1] = (tr - tm) * 1ll * lz[v];

		lz[v] = -1;
	}
}


void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v] = (tr - tl + 1)*1ll*x;
		lz[v] = x;
		mx[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	update(l, r, x, v << 1, tl, tm); 
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = t[v << 1] + t[v << 1 | 1];
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}


ll getsum(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r) 
		return t[v];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	return getsum(l, r, v << 1, tl, tm) + getsum(l, r, v << 1 | 1, tm + 1, tr);
}


int getpos(int x, int v = 1, int tl = 1, int tr = n) {
	if (mx[v] < x)
		return 0;
	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	if (mx[v << 1 | 1] >= x)
		return getpos(x, v << 1 | 1, tm + 1, tr);

	return getpos(x, v << 1, tl, tm);
}
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	build();

	vi st;

	ll ans = 0;
	for (int l = n - 1; l > 0; --l) {
		while (sz(st) > 0 && a[st.back()] >= a[l + 1])
			st.ppb();

		st.pb(l + 1);
		
		for (auto i : st) {
			int j = getpos(max(a[i] + l, a[l] + i));
			update(i, j, max(a[i] + l, a[l] + i));
		}

		ans += getsum(l + 1, n);
	}

	cout << ans << endl;

}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}