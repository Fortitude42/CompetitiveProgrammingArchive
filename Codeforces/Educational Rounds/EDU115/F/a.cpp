#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = (1 << 20) + 123;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, mn[22], tot[22], dp[N], m[22];
string s[22];
vi cnt[22];

inline int get(int i, int totsum) {
	if (m[i] < totsum)
		return 0;

	return cnt[i][m[i] - totsum];
}
    
main () {
	fastio
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];

		m[i] = sz(s[i]);
		mn[i] = inf;
		cnt[i].resize(2*m[i] + 1);

		for (auto c : s[i]) {
			if (c == '(')
				++tot[i];
			else
				--tot[i];

			mn[i] = min(mn[i], tot[i]);
			
			if (tot[i] == mn[i]) 
				++cnt[i][m[i] + tot[i]];			
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	int ans = 0;

	for (int mask = 0; mask < (1 << n); ++mask) {
		if (dp[mask] == -1)
			continue;

		ans = max(ans, dp[mask]);

		int totsum = 0;
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				totsum += tot[i];

		if (totsum < 0)
			continue;

		for (int i = 0; i < n; ++i)
			if (!(mask & (1 << i))) {
				int cur = dp[mask] + get(i, totsum);
				ans = max(ans, cur);
				if (totsum + mn[i] >= 0)
					dp[mask | (1 << i)] = max(dp[mask | (1 << i)], cur);
			}
	}

	cout << ans;
}