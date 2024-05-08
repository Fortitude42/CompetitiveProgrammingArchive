//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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

int n, y, a[M], dp[M], t[M << 2][2];


void build(int v = 1, int tl = 1, int tr = n) {
    t[v][0] = t[v][1] = INF;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}
void update(int pos, int lvl, int x, int v = 1, int tl = 1, int tr = n) {
	t[v][lvl] = min(t[v][lvl], x);
	if (tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, lvl, x, v << 1, tl, tm);
	else
		update(pos, lvl, x, v << 1 | 1, tm + 1, tr);
}

int get(int l, int r, int lvl, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return INF;

	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	return min(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}
 
void solve() {
	cin >> n >> y;
	for (int i = 1; i <= n + 1; ++i)
		cin >> a[i];

	dp[0] = a[1];
	build();
	int j = 0;

	for (int i = 1; i <= n; ++i) {
		update(i, 0, dp[i - 1] - a[i]);
		update(i, 1, dp[i - 1] - 3*a[i]);
		
		while (2*a[j] < 2*a[i] - y)
			j++;

		dp[i] = min(get(0, j - 1, 1) + 2*a[i], get(j, i, 0) + y) + a[i + 1];
	}

	cout << dp[n] << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

