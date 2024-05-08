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
const int N = 5e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M];
int d[M][M];
vi ver[M][M], ifans[M][M];
int canbe[M], timer;
int cnt[M];

void bfs(int v, int n) {
	for (int to = 1; to <= n; to++)
		d[v][to] = MOD;

	d[v][v] = 0;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int to : g[u]) {
			if (d[v][to] > d[v][u] + 1) {
				d[v][to] = d[v][u] + 1;
				q.push(to);
			}
		}
	}
}

int go(int v) {
	cout << v << "\n";
	fflush(stdout);
	string s;
	int u;
	cin >> s;
	if (s == "FOUND")
		return -1;
	cin >> u;
	return u;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k, u;
		cin >> k >> u;
		for (int j = 1; j < k; j++) {
			int v;
			cin >> v;
			g[v].pb(u);
			g[u].pb(v);
			u = v;
		}
	}

	for (int v = 1; v <= n; v++)
		bfs(v, n);
	
	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			for (int to : g[v])
				if (d[v][u] == d[v][to] + d[to][u]) {
					ver[v][u].pb(to);
					ifans[v][to].pb(u);
				}

	for (int it = 1; it <= n; it++) {
		vi ans;
		for (int v = 1; v <= n; v++)
			ans.pb(v);

		bool foundAns = false;
		while (sz(ans) > 1) {
			int curV = 0, curSub = MOD;
			for (int root : ans) {
				for (int to : g[root])
					cnt[to] = 0;
				for (int an : ans)
					for (int i = 0; i < sz(ver[root][an]); i++)
						cnt[ver[root][an][i]]++;
		
				int mx = 0;
				for (int to : g[root])
					mx = max(mx, cnt[to]);
				
				if (mx < curSub) {
					curSub = mx;
					curV = root;
				}
			}

			int to = go(curV);
			if (to == -1) {
				foundAns = true;
				break;
			}
			
			++timer;
			for (int u : ifans[curV][to])
				canbe[u] = timer;;
			
			vi newAns;
			for (int u : ans)
				if (canbe[u] == timer)
					newAns.pb(u);
			swap(ans, newAns);
		}

		if (!foundAns) {
			int res = go(ans[0]);
			assert(res == -1);
		}
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
