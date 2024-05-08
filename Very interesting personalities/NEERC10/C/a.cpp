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
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M], gg[M], f[M];
vector < vi > cycle[M];
unordered_set < int > was[M];
int tin[M], timer, lim;
int n, m, k, par[M], p[M];




void addCycle(int v, int u) {
	vi cur;
	
	was[v].insert(u);
	was[u].insert(v);

	while (v != u) {
		was[v].insert(par[v]);
		was[par[v]].insert(v);
		cur.pb(v);
		v = par[v];
	}

	cycle[u].pb(cur);
}

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	par[v] = p;

	for (auto to : g[v]) {
		if (to == p)
			continue;

		if (!tin[to])
			dfs(to, v);
		else if (tin[to] < tin[v])//to is upper than v
			addCycle(v, to);
	}

	if (p && !was[v].count(p))
		gg[p].pb(v);	
}


int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

inline void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (sz(f[v]) < sz(f[u]))
		swap(v, u);

	p[u] = v;
	while (sz(f[u])) {
		f[v].pb(f[u].back());
		f[u].ppb();
	}
}

void dfs1(int v) {
	for (auto to : gg[v]) {
		dfs1(to);           
		if (sz(f[get(to)]) < lim)
			merge(v, to);
	}

	for (auto c : cycle[v]) {
		int l = 0, sum = 0, R = 0;
		vi dp(sz(c)), prv(sz(c));
		for (int r = 0; r < sz(c); ++r) {
			dfs1(c[r]);

			sum += sz(f[get(c[r])]);
			
			while (sum > lim) {
				sum -= sz(f[get(c[l])]);
				l++;
			}

			if (sum == lim) {
				dp[r] = (!l ? 0 : dp[l - 1]) + 1;
				prv[r] = !l ? -1 : prv[l - 1];
			} else {
				dp[r] = 0; 
				prv[r] = r;
			}

			if (dp[r] > dp[R]) 
				R = r;
		}
		if (dp[R] > 0) {
//			if (v == 1)
//				cerr << dp[R] << ' ' << c[prv[R] + 1] << ' ' << c[R] << endl;
			for (int i = prv[R] + 1; i <= R; ++i) 
				if (i > prv[R] + 1 && sz(f[get(c[i - 1])]) < lim)
					merge(c[i], c[i - 1]);				
		}

		for (int i = 0; i < sz(c); ++i)
			if (!dp[R] || i <= prv[R] || i > R)
				merge(v, c[i]);		
	}

}
 
void solve() {
	cin >> n >> m >> k;
	while (m--) {
		int s, prv = -1;
		cin >> s;
		while (s--) {
			int x;
			cin >> x;
			if (prv != -1) {
				g[x].pb(prv);
				g[prv].pb(x);
			}

			prv = x;
		}
	}

	lim = n / k;
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		f[i].pb(i);                
		p[i] = i;
	}

	dfs1(1);
	vector < vi > ans;
	for (int i = 1; i <= n; ++i)
		if (sz(f[i]) == lim) 
			ans.pb(f[i]);


	if (sz(ans) != k) {
		cout << -1 << endl;
		return;
	}


	for (auto x : ans) {
		sort(all(x));
		for (auto y : x)
			cout << y << ' ';
		cout << endl;	
	}
}

main () {
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
