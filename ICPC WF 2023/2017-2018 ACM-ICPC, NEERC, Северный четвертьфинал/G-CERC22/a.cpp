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
const int N = 10, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M];
int n=10, mt[M], p[M], deg[M];
int x[M][4];
bool used[M], bad[M];

bool in(int i, int j) {
	return x[i][0] >= x[j][2] && x[i][1] >= x[j][3];
}


bool dfs(int v) {
	if (used[v])	
		return 0;

	used[v] = 1;
	for (auto to : g[v])
		if (!bad[to+n] && mt[to] == -1) {
			p[v] = to;
			mt[to] = v;
			return 1;
		}

	for (auto to : g[v])
		if (!bad[to+n] && dfs(mt[to])) {
			p[v] = to;
			mt[to] = v;
			return 1;
		}

	return 0;
}


bool matching() {
	memset(p, -1, sizeof p);
	memset(mt, -1, sizeof mt);

	bool run = 1;
	while (run) {
		run = 0;
		memset(used, 0, sizeof used);
		for (int i = 0; i < n; ++i)
			if (!bad[i] && p[i] == -1 && dfs(i))
				run = 1;		
	}

	for (int i = 0; i < n; ++i)
		if (!bad[i] && p[i] == -1)
			return 0;

	return 1;
}

bool check() {
	for (int i = 0; i < n+n; ++i) {
		g[i].clear();
		deg[i] = 0;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (in(i, j)) {
				g[i].pb(j);
				++deg[i];
				++deg[j+n];
			}

	
	memset(bad, 0, sizeof bad);
	if (!matching())
		return 0;

	int mn = deg[0];
	for (int i = 1; i < n+n; ++i)
		mn = min(mn, deg[i]);

	for (int i = 0; i < n; ++i) 
		for (auto j : g[i]) {
			if (min(deg[i], deg[j + n]) != mn)
				continue;
			bad[i] = 1;
			bad[j + n] = 1;
			if (!matching())
				return 1;
			bad[i] = 0;
			bad[j + n] = 0;
		}

	return 0;
	
}            
            
void rec(int i=0) {
	int pos = i/4;
	int j = i%4;

	if (pos == n) {
		if (check()) {
			for (int i = 0; i < n; ++i, cout << endl)
				for (int j = 0; j < 4; ++j)
					cout << x[i][j] << ' ';
			exit(0);
		}

		return;
	}

	for (int val = 1; val <= n; ++val) {	
		x[pos][j] = val;
		rec(i + 1);
	}
}
 
void solve() {
	srand(time(0));
	while (1) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 4; ++j)
				x[i][j] = rand() % n + 1;
		if (check()) {
			for (int i = 0; i < n; ++i, cout << endl)
				for (int j = 0; j < 4; ++j)
					cout << x[i][j] << ' ';
			exit(0);
		}
	}

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}