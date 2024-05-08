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

string s;
vi g[M], vs;
bool used[M];
pii dp[30][3][4], tmp[3][4];//dp[v][c][mask]: v-vertex, c-color, mask-mask of colors we have
int cnt[30][3], k, r, c[30], tot[3];

bool small(char c) {
	return c >= 'a' && c <= 'z';
}

void dfs(int v, int p = 29) {
	assert(!used[v]);
	used[v] = 1;
	for (int col = 1; col <= 2; ++col)
		for (int mask = 0; mask < 4; ++mask)
			dp[v][col][mask] = mp(inf, inf);
	

	for (int col = 1; col <= 2; ++col) {
		dp[v][col][col] = mp(cnt[v][3-col], 0);
		dp[v][col][0] = mp(cnt[v][1] + cnt[v][2], 0);
	}

	for (auto to : g[v])
		if (to != p) {
			dfs(to, v);
			for (int col = 1; col <= 2; ++col)
				for (int mask = 0; mask < 4; ++mask)
					tmp[col][mask] = mp(inf, inf);

			for (int col = 1; col <= 2; ++col)
				for (int mask = 0; mask < 4; ++mask) {
					if (dp[to][col][mask] == mp(inf, inf))
						continue;
					for (int col1 = 1; col1 <= 2; ++col1)
						for (int mask1 = 0; mask1 < 4; ++mask1) {
							if (dp[v][col1][mask1] == mp(inf, inf))
								continue;
							tmp[col1][mask|mask1] = min(tmp[col1][mask|mask1], 
							mp(dp[to][col][mask].f + dp[v][col1][mask1].f, dp[to][col][mask].s + dp[v][col1][mask1].s + (col != col1)));
						}
						
				}

			for (int col = 1; col <= 2; ++col)
				for (int mask = 0; mask < 4; ++mask)
					dp[v][col][mask] = tmp[col][mask];			
		}
}
 
void solve(int tt) {
	cout << "Case " << tt << ": ";
	vs.clear();
	tot[1] = tot[2] = 0;
	for (int i = 0; i < 30; ++i) {
		cnt[i][1] = cnt[i][2] = 0;
		g[i].clear();
		used[i] = 0;
	}

	while (s != "0") {
		if (!small(s[0]))
			swap(s[0], s[1]);

		//s0 is small
		vs.pb(s[0] - 'a');

		if (small(s[1])) {
			vs.pb(s[1] - 'a');
			g[s[0] - 'a'].pb(s[1] - 'a');
			g[s[1] - 'a'].pb(s[0] - 'a');
		} else {
			++cnt[s[0] - 'a'][1+(s[1] < 'N')];		
			++tot[1+(s[1] < 'N')];
		}
		cin >> s;					
	}


	sort(all(vs));
	vs.resize(unique(all(vs)) - vs.begin());

	vi roots;
	for (auto i : vs)
		if (!used[i]) {
			dfs(i);
			roots.pb(i);
//			cerr << i << endl;
		}

	pii mn[4][30] = {mp(inf, inf)};
	pii mn1[4][30] = {mp(inf, inf)};

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 30; ++j)
			mn[i][j] = mp(inf, inf);



	for (int i = 0; i < sz(roots); ++i) {
		int v = roots[i];

		if (!i) {
			for (int col = 1; col <= 2; ++col)
				for (int mask = 0; mask < 4; ++mask)
					mn[mask][min(1, mask)] = min(mn[mask][min(1, mask)], dp[v][col][mask]);
			continue;
		} 

		for (int x = 0; x < 4; ++x)
			for (int c = 0; c < 30; ++c)
			mn1[x][c] = mp(inf, inf);

		for (int mask1 = 0; mask1 < 4; ++mask1) {
			for (int c1 = 0; c1 < 30; ++c1) {
			if (mn[mask1][c1] == mp(inf, inf))
				continue;
			
			for (int col = 1; col <= 2; ++col)
				for (int mask = 0; mask < 4; ++mask) {
					if (dp[v][col][mask] == mp(inf, inf))
						continue;
					mn1[mask|mask1][c1 + min(mask, 1)] = min(mn1[mask|mask1][c1 + min(mask, 1)], 
					mp(mn[mask1][c1].f + dp[v][col][mask].f, mn[mask1][c1].s + dp[v][col][mask].s));
				}
			}
		}

		for (int x = 0; x < 4; ++x)
			for (int c = 0; c < 30; ++c)
				mn[x][c] = mn1[x][c];
	}

	pii ans = mp(inf, inf);
	for (int mask = 0; mask < 4; ++mask) {
		bool ok = 1;
		for (int i = 1; i <= 2; ++i)
			if (tot[i] > 0 && !(mask & i)) {
				ok = 0;
				break;
			}

		if (!ok)
			continue;
		for (int c = 0; c < 30; ++c) {
			if (mn[mask][c] == mp(inf, inf)) 
				continue;
//			cout << mn[mask][c].f << endl;
//			cout << mask << ' ' << c << ' '<< mn[mask][c].s + (mn[mask][c].s + c) - __builtin_popcount(mask) << endl << endl;
			ans = min(ans, mp(mn[mask][c].f*2, mn[mask][c].s + (mn[mask][c].s + c) - __builtin_popcount(mask)));
		}

	}

	if (ans == mp(inf, inf))
		cout << "impossible\n";
	else	
		cout << ans.f << ' ' << ans.s << "\n";

	

}

main () {
	int tt = 0;
	while (cin >> s)
		solve(++tt);
}