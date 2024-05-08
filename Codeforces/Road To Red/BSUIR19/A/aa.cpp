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

int n, p[30];
double a, b, f[30], c[30], dp[30][30];
 
double cnk(int n, int k) {
	return f[n] / (f[k] * f[n - k]);
}

void solve() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
//	cin >> n;

	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		f[i] = f[i - 1] * i;

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * (i - 1);
		

	double ch = 0;
	for (int m = 1; m <= n; ++m) {
		c[m] = dp[n][n + 1 - m];
		ch += c[m];
	}


	double ans = 0;
	for (int i = 1; i <= n; ++i)
		if (p[i] != i) {
			ans += a;
			for (int j = i + 1; j <= n; ++j)
				if (p[j] == i) {
					swap(p[i], p[j]);
					break;
				}
		}

	for (int x = 1; x <= n; ++x) {
		double sum = 0, sum1 = 0;
		for (int i = 1; i <= x; ++i) {
			sum += (i - 1) * c[i];
			sum1 += c[i];
		}

		ans = min(ans, (b*f[n] + sum*a) / sum1);
	}

	cout << setprecision(12) << fixed;
	cout << ans << endl;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}