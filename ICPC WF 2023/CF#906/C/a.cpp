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

int n, m, k, dp[12][M], t[12][M << 2];
vector < pii > g[M];


void update(int pos, int lvl, int x, int v = 1, int tl = 0, int tr = n) {
	if (tl == tr) {
		t[lvl][v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, lvl, x, v << 1, tl, tm);
	else
		update(pos, lvl, x, v << 1 | 1, tm + 1, tr);
	t[lvl][v] = max(t[lvl][v << 1], t[lvl][v << 1 | 1]);
}


int get(int l, int r, int lvl, int v = 1, int tl = 0, int tr = n) {
	if (l > r || tl > r || l > tr)
		return -inf;

	if (l <= tl && tr <= r)
		return t[lvl][v];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

 
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		g[l].pb({-l, 1});
		g[r + 1].pb({-l, -1});
	}


	multiset < int > q;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (auto x : g[i]) {
			if (x.s > 0)
				q.insert(x.f);
			else
				q.erase(q.find(x.f));
		}

		auto it = q.begin();
		vi pos;
		while (it != q.end() && sz(pos) <= k) {
			pos.pb(-*it);
			it++;
		}

		pos.pb(-1);


		for (int j = 0; j <= k; ++j) {
			dp[j][i] = -inf;
			int lst = i - 1;

			for (int x = 0; x <= min(sz(pos) - 1, j); ++x) {
				int l = pos[x], r = min(i - 1, lst);
				int cur = get(l, r, j - x);
				if (cur >= 0)
					dp[j][i] = max(dp[j][i], cur + 1);

				lst = pos[x];
			}

			ans = max(ans, dp[j][i]);
			update(i, j, dp[j][i]);
		}
	}
	cout << ans << "\n";

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			update(i, j, -inf);

	for (int i = 1; i <= n + 1; ++i)
		g[i].clear();
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