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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, x[M], y[M], s[M][2];
vi vals[2];
 
void solve() {
	file("intel");
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		vals[1].pb(x[i]);
		vals[0].pb(y[i]);
	}

	for(int i = 0; i < 2; ++i) {
		sort(all(vals[i]));
		vals[i].resize(unique(all(vals[i])) - vals[i].begin());
	}

	for (int i = 0; i < n; ++i) {
		x[i] = lower_bound(all(vals[1]), x[i]) - vals[1].begin();
		y[i] = lower_bound(all(vals[0]), y[i]) - vals[0].begin();
	}

	vector < pair < int, pii > > g[2];
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		if (x[i] == x[j])
			g[0].pb(mp(x[i], mp(y[i], y[j])));
		else
			g[1].pb(mp(y[i], mp(x[i], x[j])));	
	}

	ll ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (auto &j : g[i])
			if (j.s.f > j.s.s)
				swap(j.s.f, j.s.s);
		
		for (int j = 0; j < sz(g[i]); ++j) {
			memset(s, 0, sizeof s);
			for (int x = 0; x < sz(g[i]); ++x) {
				if (g[i][j].f == g[i][x].f)
					continue;
				int k = g[i][j].f < g[i][x].f;

				int l = max(g[i][j].s.f, g[i][x].s.f);
				int r = min(g[i][j].s.s, g[i][x].s.s);
				if (l > r)
					continue;

				++s[l][k];
				--s[r][k];
			}

			for (int x = 0; x < sz(vals[i]); ++x) {
				if (x > 0) {
					s[x][0] += s[x - 1][0];
					s[x][1] += s[x - 1][1];
				}
				if (s[x][0] > 0 && s[x][1] > 0)
					ans += vals[i][x + 1] - vals[i][x];
			}							
		}
	}

	cout << ans << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}