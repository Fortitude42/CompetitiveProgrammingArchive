#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define f first
#define s second

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef long long ll;


const int N = 2e5, MOD = 1e9 + 7, inf = 1e9;
const int M = N + 11;

int n, m, dp[4000][2];
int was[M];
vi g[M];


int f(vi v) {
	if (sz(v) <= 1)
		return 0;

	for (int i = 0; i <= sz(v); ++i)
		for (int j = 0; j < 2; ++j)
			dp[i][j] = inf;


	dp[0][v[0]] = 0;

	for (int i = 0; i + 1 < sz(v); ++i) {
	    dp[i][0] = min(dp[i][0], dp[i][1] + 1);
	    dp[i][1] = min(dp[i][1], dp[i][0] + 1);

		for (int j = 0; j < 2; ++j) {
			if (v[i + 1] == j)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]); 
			else {
				dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
				dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + 1);
			}
		}
	}

	return min(dp[sz(v) - 1][0] + v.back(), dp[sz(v) - 1][1] + 1 - v.back());
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		g[x].pb(i);
	}


	for (int i = 1; i <= m; ++i) {
		if (!sz(g[i])) {
			printf("-1 ");
			continue;
		}

		int ans = n - sz(g[i]);
		for (int j = 0; j < sz(g[i]); ++j) {
			int cur = g[i][j];
			int nxt = g[i][(j + 1) % sz(g[i])];

			if (cur < nxt) {
				vi v;
				for (int i = cur + 1; i <= nxt - 1; ++i)
					v.pb(was[i]);
				ans += f(v);
			} else {	
				vi v;
				for (int i = cur + 1; i <= n; ++i)
					v.pb(was[i]);
				for (int i = 1; i <= nxt - 1; ++i)
					v.pb(was[i]);
				ans += f(v);
				if (i == 3) {
					for (auto x : v)
						cerr << x << ' ';
				}
			}
		}

		for (auto x : g[i])
			was[x] = 1;

		printf("%d ", ans);
	}
}

main() {
	int TT = 1;
	//scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}