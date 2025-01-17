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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, l, r;
ll d[M];
vector<pii> g[M], edges; 

void solve() {
	cin >> n >> m >> l >> r;

	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
		edges.pb({u, v});
	}

	for(int i = 0; i < n; i++)
		d[i] = INF;
  	d[0] = 0;
  	
  	priority_queue<pair<ll, int> > q;
  	q.push({d[0], 0});

  	while(sz(q)){
  		int v = q.top().s;
  		ll cur = -q.top().f;
  		
  		q.pop();
  		
  		if(d[v] != cur) continue;
  	
  		for(auto it : g[v]){
  			int to = it.f, w = it.s;
  			if(d[to] > d[v] + w){
  				d[to] = d[v] + w;
  				q.push({-d[to], to});
  			}
 		}
  	}

  	int ans = 0;
	for(auto x : edges){
	    if(2 * min(d[x.f], d[x.s]) < r)
			ans++;
	}

	cout << ans << "\n";
}

main () {
	fastio;
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

