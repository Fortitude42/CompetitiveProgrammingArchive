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
const int N = 2500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int l[M], r[M], c[M];
int ord[M];

ll dp[M];

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &l[i], &r[i], &c[i]);
		ord[i] = i;
	}

	sort(ord + 1, ord + 1 + n, [&](const int &i, const int &j) {
		if (r[i] != r[j])
			return r[i] < r[j];
		return l[i] < l[j];
	});
	
	for (int i = 0; i < M; i++)
		dp[i] = INF;
	dp[0] = 0;
	
	for (int i = 0; i < n; i++) {
		int curR = r[ord[i]];

		multiset<int> costs;
		ll cur = 0;

		for (int j = i + 1; j <= n; j++) {
			int id = ord[j];
			if (l[id] <= curR) {
				cur += c[id];
			} else {
				costs.insert(c[id]);
				if (sz(costs) > k) {
					cur += *costs.begin();
					costs.erase(costs.begin());
				}
			}

			dp[j] = min(dp[j], dp[i] + cur);
		}
	}

//	for (int i = 1; i <= n; i++)
//		cerr << dp[i] << ' ';
//	cerr << "\n";

	printf("%lld\n", dp[n]);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

