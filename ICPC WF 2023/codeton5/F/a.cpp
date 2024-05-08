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
const int N = 5000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, d[M], ans[M], cnt[M];
vi g[M];


void dfs(int v, int p = 0) {
	d[v] = d[p] + 1;
	cnt[d[v]]++;
	for (auto to : g[v])
		if (to != p) 
			dfs(to, v);		
}

 
void solve() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int root = 1; root <= n; ++root) {
		dfs(root);
		int sum = 0, k = 0;
		for (int j = 1; j <= n; ++j) {
			while (cnt[j] > 0) {
				k++;
				sum += (j - 1);
				ans[k] = max(ans[k], (n - 1)*k - 2*sum);
				cnt[j]--;
			}
		}			
	}

	for (int k = 0; k <= n; ++k)
		cout << ans[k] << ' ';
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}