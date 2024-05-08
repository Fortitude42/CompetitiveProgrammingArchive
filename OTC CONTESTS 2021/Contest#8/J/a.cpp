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
const int N = 5e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

pii p[31][M];
int n, m, ans[31];
pair < ll, int > c[31];
ll dp[31][M];
 
ll get(int l, int r) {	
	return c[r].f - c[l - 1].f;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i].f;             
		c[i].s = i;
	}


	sort(c + 1, c + 1 + n);
	for (int i = 1; i <= n; ++i)
		c[i].f += c[i - 1].f;

	for (int j = 0; j <= m; ++j)
		for (int i = 0; i <= n; ++i)
			dp[i][j] = INF;

	dp[0][m] = 0;				

	for (int i = 1; i <= n; ++i)
		for (int s = 0; s <= m; ++s)
			if (dp[i - 1][s] < inf)
				for (int j = i; j <= n; ++j)
					for (int x = 1; x*(n - i + 1) <= s; ++x)
						if (dp[j][s - x*(n - i + 1)] > dp[i - 1][s] + get(i, j) * (n - j)) {
							dp[j][s - x*(n - i + 1)] = dp[i - 1][s] + get(i, j) * (n - j);
							p[j][s - x*(n - i + 1)] = mp(i, x);
						}
					

	cout << dp[n][0] << endl;
	int s = 0, m = n;

	while (n > 0) {
		int i = p[n][s].f, x = p[n][s].s;

		for (int j = i; j <= m; ++j)
			ans[j] += x;

		s += x*(m - i + 1);
		n = i - 1;
	}

	vi res(m + 1);
	for (int i = 1; i <= m; ++i)
		res[c[i].s] = ans[i];

	for (int i = 1; i <= m; ++i)
		cout << res[i] << ' ';

}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}