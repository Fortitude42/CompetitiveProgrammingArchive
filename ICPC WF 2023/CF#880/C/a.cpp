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
const int N = (1<<18), inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int k, n;
ll a[M];


int getRand() {
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)	
			res |= (1 << i);

	return res;
}
 
void solve() {
	cin >> k;
	n = (1 << (k + 1));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= a[i - 1];
	}

	

	while (1) {
		int i = uniform_int_distribution<int>(0, n)(rng);
		int j = uniform_int_distribution<int>(0, n)(rng);
		if (i == j) 
			continue;
		if (i > j)
			swap(i, j);

		ll val = a[i]^a[j];

		vector < pii > v;
		map < ll, vi > g;

		for (int it = 0; !sz(v) && it <= n; ++it) {
			if (it != j && g.count(val^a[it])) {
				for (auto y : g[val^a[it]])
					v.pb({y, it});
			}
 
			if (it != i && sz(g[a[it]]) < 2)
				g[a[it]].pb(it);
		}
 

		if (sz(v) >= 1) {
			vi pos = {i, j, v[0].f, v[0].s};
			sort(all(pos));
			++pos[0];
			++pos[2];
			for (auto x : pos)
				cout << x << ' ';
			cout << "\n";
			return;
		}
	}
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