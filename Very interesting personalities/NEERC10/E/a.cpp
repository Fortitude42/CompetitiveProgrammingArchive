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
const int N = 4e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 3;
const ll INF = 1e18;

int a[M], b[M];
int orda[M], ordb[M];
ll dp[M][M];
bool par[M][M];
int ans[M];
 
void solve() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		orda[i] = i;
	}

	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		ordb[i] = i;
	}

	sort(orda + 1, orda + 1 + n, [&](const int &i, const int &j) {
		return a[i] < a[j];
	});
	sort(ordb + 1, ordb + 1 + m, [&](const int &i, const int &j) {
		return b[i] < b[j];
	});
	
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (min(dp[i - 1][j - 1], dp[i - 1][j]) == INF)
				continue;
			if (dp[i - 1][j - 1] < dp[i - 1][j]) {
				dp[i][j] = dp[i - 1][j - 1] + abs(a[orda[i]] - b[ordb[j]]);
				par[i][j] = 1;
			} else {
				dp[i][j] = dp[i - 1][j] + abs(a[orda[i]] - b[ordb[j]]);
			}
		}
	}

	int i = n, j = m;
	while (i) {
		ans[orda[i]] = ordb[j];
		j -= par[i][j];
		i--;
	}

	printf("%lld\n", dp[n][m]);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

main () {
//	file("evacuation");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

