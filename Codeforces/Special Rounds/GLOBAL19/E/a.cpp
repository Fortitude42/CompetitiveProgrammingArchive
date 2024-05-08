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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, cnt[M], a[M]; 
vi vals, lens, g[M];
set < int > bad[M];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]); 
		vals.pb(a[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(all(vals), a[i]) - vals.begin();
		++cnt[a[i]];
	}

	for (int i = sz(vals) - 1; i >= 0; --i)
		if (cnt[i]) 
			g[cnt[i]].pb(i);
	
	for (int i = 1; i <= n; ++i)
		if (sz(g[i])) 
			lens.pb(i);
		
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		
		x = lower_bound(all(vals), x) - vals.begin();
		y = lower_bound(all(vals), y) - vals.begin();

		bad[x].insert(y);
		bad[y].insert(x);
	}

	ll ans = 0;
	for (int i = 0; i < sz(vals); ++i) {
		for (auto l : lens) {
			int ind = 0;
			while (ind < sz(g[l]) && (bad[i].count(g[l][ind]) || i == g[l][ind]))
				++ind;
			
			if (ind < sz(g[l])) {
				int j = g[l][ind];
				ans = max(ans, (vals[i] +  vals[j]) * 1ll * (cnt[i] + cnt[j]));
			}
		}
	}

	printf("%lld\n", ans);


	lens.clear();
	vals.clear();
	for (int i = 0; i <= n; ++i) {
		cnt[i] = 0;
		bad[i].clear();
		g[i].clear();
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