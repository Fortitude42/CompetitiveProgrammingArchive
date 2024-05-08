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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
vector < pair < pii, int > > g[1004];
 
void solve() {
	for (int i = 1; i <= 1000; ++i)
		g[i].clear();


	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, l, r;
		cin >> a >> l >> r;
		g[a].pb({{l, r}, i});
	}

	bool ok = 1;

	vi order;
	for (int x = 0; x <= 1000; ++x) {
		vi nw_order;

		for (auto y : g[x])
			if (y.f.f + y.f.s != sz(order)) {
				ok = 0;
				break;
			}

		if (!ok)
			break;

		sort(all(g[x]));
		int i = 0;

		for (int j = 0; j < sz(order); ++j) {
			while (i < sz(g[x]) && g[x][i].f.f == j) { 
				nw_order.pb(x);
				++i;
			}

			nw_order.pb(order[j]);
		}

		while (i < sz(g[x])) {
			nw_order.pb(x);
			++i;		
		}

		order = nw_order;
	}
	if (!ok) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";

	for (int i : order)
		cout << i << ' ';
	cout << endl;
}

main () {
	fastio
	int TT;
	TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}