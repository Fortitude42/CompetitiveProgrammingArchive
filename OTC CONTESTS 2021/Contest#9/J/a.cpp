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
const int N = 1e5 + 2e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

ll K, dp[4][M];
set < pair < ll, pii > > q;
int d[4];
 
void upd(int i, int k, ll x) {
	if (dp[i][k] > x) {
		q.erase(mp(dp[i][k], mp(i, k)));
		dp[i][k] = x;
		q.insert(mp(dp[i][k], mp(i, k)));
	}
}

void solve() {
	cin >> K;
	int s = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> d[i]; 
		s += d[i];
	}

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < s; ++j)
			dp[i][j] = INF*3;


	dp[1][0] = 0;
	q.insert(mp(0, mp(1, 0)));

	while (sz(q)) {
		int i = q.begin()->s.f;
		int k = q.begin()->s.s;
		q.erase(q.begin());
		
		upd((i + 3) % 4, (k + d[(i + 3) % 4]) % s, dp[i][k] + d[(i + 3) % 4]);
		upd((i + 1) % 4, (k + d[i]) % s, dp[i][k] + d[i]);
	}

	ll ans = INF*3;
	for (int i = 1; i < 2; ++i)
		for (int j = 0; j < s; ++j)
			ans = min(ans, dp[i][j] + (dp[i][j] <= K ? (((K - dp[i][j] + s - 1) / s) * s) : 0));

	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}