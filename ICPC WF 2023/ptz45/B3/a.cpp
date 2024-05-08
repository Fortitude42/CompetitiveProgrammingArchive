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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

ll t[M << 2][2], lz[M << 2][2], dp[M];
int n, m, l[M], r[M], p[M], w[M];

void push(int v) {
	if (lz[v][0]) {
		lz[v << 1][0] += lz[v][0];
		t[v << 1][0] += lz[v][0];

		lz[v << 1 | 1][0] += lz[v][0];
		t[v << 1 | 1][0] += lz[v][0];

		lz[v][0] = 0;
	}

	if (lz[v][1]) {
		lz[v << 1][1] = max(lz[v << 1][1], lz[v][1]);
		t[v << 1][1] = max(t[v << 1][1], lz[v][1]);

		lz[v << 1 | 1][1] = max(lz[v << 1 | 1][1], lz[v][1]);
		t[v << 1 | 1][1] = max(t[v << 1 | 1][1], lz[v][1]);

		lz[v][1] = 0;
	}
}


void build(int v = 1, int tl = 0, int tr = m) {
	t[v][0] = t[v][1] = lz[v][0] = lz[v][1] = 0;
	if (tl == tr) {
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update(int l, int r, int lvl, ll x, int v = 1, int tl = 0, int tr = m) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		if (!lvl) {
			t[v][lvl] += x;
			lz[v][lvl] += x;		
		} else {
			t[v][lvl] = max(t[v][lvl], x);
			lz[v][lvl] = max(lz[v][lvl], x);
		}
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, lvl, x, v << 1, tl, tm);
	update(l, r, lvl, x, v << 1 | 1, tm + 1, tr);

	t[v][lvl] = max(t[v << 1][lvl], t[v << 1 | 1][lvl]);
} 

ll get(int l, int r, int lvl, int v = 1, int tl = 0, int tr = m) {
	if (l > r || tl > r || l > tr) 
		return -INF;

	if (l <= tl && tr <= r)
		return t[v][lvl];

	push(v);
	int tm = (tl + tr) >> 1;
	return max(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

void solve() {
	cin >> n >> m;
	build();
	set < pii > toadd, added;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i] >> w[i] >> p[i];
		update(l[i], r[i], 1, w[i]);
		toadd.insert(mp(l[i], i));
	}


	ll ans = 0;
	for (int rg = 1; rg <= m; ++rg) {	
//		cerr << " ---- > " << rg << endl;
		while (sz(toadd) > 0) {
			int i = toadd.begin()->s;
			if (l[i] <= rg) {
				toadd.erase(toadd.begin());
				added.insert(mp(r[i], i));
				update(0, l[i] - 1, 0, -p[i]);
//				cerr << "-> " << 0 << ' ' << l[i] - 1 << ' ' << -p[i] << endl;
				continue;
			}

			break;
		}
		        
		while (sz(added) > 0) {
			int i = added.begin()->s;
			if (r[i] < rg) {
				update(0, l[i] - 1, 0, p[i]);
//				cerr << "-> " << 0 << ' ' << l[i] - 1 << ' ' << p[i] << endl;
				added.erase(added.begin());
				continue;
			}

			break;
		}


		dp[rg] = get(0, rg - 1, 0) + get(rg, rg, 1);
		update(rg, rg, 0, dp[rg]);
		ans = max(ans, dp[rg]);
//		cerr << rg << ' ' << dp[rg] << endl;
	}

	cout << ans << "\n";

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