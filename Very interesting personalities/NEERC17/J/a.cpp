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
const int N = 3e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, k;
ll ans = INF, d[M];
vector < pii > g[M];
set < pair < ll, int > > q;

void calc(int x) {
	for (int i = 2; i <= n; ++i)
		d[i] = INF;

	q.insert(mp(d[1], 1));
	while (sz(q)) {
		int v = q.begin()->s;
		q.erase(q.begin());

		for (auto u : g[v]) {
			int to = u.f, w = max(0, u.s - x);
			if (d[to] > d[v] + w) {
				q.erase(mp(d[to], to));
				d[to] = d[v] + w;
				q.insert(mp(d[to], to));
			}
		}
	}

	ans = min(ans, d[n] + k*1ll*x);
}
 
void solve() {
	cin >> n >> m >> k;
	vi vals;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb({b, c});
		g[b].pb({a, c});
		vals.pb(c);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	
	calc(0);
	for (auto x : vals)	
		calc(x);

	cout << ans << endl;
}   

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

