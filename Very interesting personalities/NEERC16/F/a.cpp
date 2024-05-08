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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


double dp[M];
int n, sc[M], sw[M];
string t;

void solve() {
	cin >> t;
	n = sz(t);
	t = "#" + t;

	for (int i = 1; i <= n; ++i) {
		sc[i] = sc[i - 1] + (t[i] == 'C'); 
		sw[i] = sw[i - 1] + (t[i] == 'W');
	}

	dp[n + 1] = 0;
	double sumc = sc[n], sumw = sw[n];
	for (int i = n; i > 0; --i) {
		if (t[i] == 'W') {
			dp[i] = sumc / (n - i + 1);
			//dp[i] -= (sc[i] * (n - i + 1)) / (n - i + 1);
			dp[i] -= sc[i]; 
		} else { 
			dp[i] = sumw / (n - i + 1);
			//dp[i] -= (sw[i] * (n - i + 1)) / (n - i + 1);
			dp[i] -= sw[i]; 		
		}

		sumc += sc[i - 1] + dp[i];
		sumw += sw[i - 1] + dp[i];
	}
	
	cout << fixed << setprecision(11);
	cout << dp[1] << endl;
}

main () {
	file("foreign");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

