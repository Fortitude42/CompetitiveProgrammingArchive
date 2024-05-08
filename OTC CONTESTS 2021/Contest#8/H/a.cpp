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
const int N = 6e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, e[M], res[5], col[M][2], k, mt[M]; 
int was[M], timer;
vi g[M], gg[M];

bool dfs(int v) {
	if (was[v] == timer)
		return 0;

	was[v] = timer;
	for (auto to : gg[v])
		if (mt[to] == -1) {
			mt[v] = to;
			mt[to] = v;
			return 1;
		}

	for (auto to : gg[v])
		if (dfs(mt[to])) {
			mt[v] = to;
			mt[to] = v;
			return 1;
		}

	return 0;
}

void dfs(int v, int j, int cc) {
	col[v][j] = k;
	for (auto to : g[v])
		if (!col[to][j] && e[to] != cc)
			dfs(to, j, cc);
}

void solve(int a, int b, int c) {
	k = 0;
	memset(col, 0, sizeof(col));
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= n; ++i) 
			if (!col[i][j] && e[i] == a) {
			    gg[++k].clear();
				dfs(i, j, c);			 
			}

		swap(b, c);
	}

	for (int i = 1; i <= n; ++i)
		if (e[i] == a) {
			gg[col[i][0]].pb(col[i][1]); 
			gg[col[i][1]].pb(col[i][0]);
		}
		
	memset(mt, -1, sizeof(mt));
	bool run;

	do {
		run = 0;
		++timer;
		for (int i = 1; i <= k; ++i)
			if (mt[i] == -1 && dfs(i))
				run = 1;
	} while (run);

	++timer;
	vi ans;

	for (int i = 1; i <= n; ++i) {	
		if (e[i] != a)
			continue;

		int c = col[i][0], cc = col[i][1];
		if (was[c] != timer && (mt[c] == -1 || mt[c] == cc)) {
			was[c] = timer;
			ans.pb(i);
			if (mt[c] != -1)
				was[mt[c]] = timer;
		}

		if (was[cc] != timer && mt[cc] == -1) {
			ans.pb(i);
			was[cc] = timer;
		}
	}

	cout << sz(ans) << ' ';
	for (auto x : ans)
		cout << x << ' ';
	cout << endl;
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> e[i];

	while (m--) {
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	solve(1, 2, 3);
	solve(2, 1, 3);
	solve(3, 1, 2);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}