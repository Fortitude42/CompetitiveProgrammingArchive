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
const int N = 5e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int a[M], cnt[M];
 
pii dp[M];

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		//scanf("%d", &x);
		x = rand() % 10;
		cnt[x]++;
	}

	for (int i = 1; i <= m; i++)
		cnt[i] += cnt[i - 1];

	for(int pen = -100; pen <= 0; pen++){
		for(int i = 0; i <= m; i++)
			dp[i] = {-inf, -inf};
		dp[0] = {0, 0};
		for (int i = 0; i <= m; i++) {
			for (int j = i; j <= m; j++)
				dp[j] = max(dp[j], {dp[j - i].f + pen + cnt[i], dp[j - i].s + 1});
		}
		cout << dp[m].s << " " << dp[m].f << "\n";
	}

	/*double ans = (double) dp[m] / n;
	printf("%.9lf", ans);*/
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
