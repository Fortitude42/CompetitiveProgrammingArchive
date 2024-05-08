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
const int N = 1e3, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, m, cnt[M], dp[M][M], a[M], dp1[M][M]; 
queue < int > q;
vi g[M];

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		g[i].clear(); 
		cnt[i] = 0;
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = 0; 
			dp1[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i][1] = a[i];
		dp1[i][1] = a[i];
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		++cnt[y];
	}


	for (int i = 1; i <= n; ++i)
		if (!cnt[i])
			q.push(i);

	int t = -1;
	while (sz(q)) {
		int v = q.front();
		t = v;
		q.pop();

		for (auto to : g[v]) {
			for (int j = 1; j <= n; ++j) {
				add(dp[to][j + 1], dp[v][j]);  
				dp1[to][j + 1] = min(MOD, dp1[to][j + 1] + dp1[v][j]);
			}

			--cnt[to];
			if (!cnt[to])
				q.push(to);
		}			
	}

	int lst = 0, lst1 = 0;
	ll pref = 0;
	for (int i = 1; i <= n; ++i) {
		pref += dp1[t][i];
		
		if (pref > 0)
			lst1 = i;
		else
			lst = i;	

		pref = max(0ll, pref - 1);
	}
	
	if (lst1 < n) {
		cout << lst1 << endl;
		return;
	}

	int sum = lst;
	
	for (int i = lst + 1; i <= n; ++i)
		add(sum, dp[t][i]);

	cout << sum << endl;
}

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}