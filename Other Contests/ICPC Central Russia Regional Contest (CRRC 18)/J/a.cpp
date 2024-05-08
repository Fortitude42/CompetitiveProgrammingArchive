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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

string a, b;
string c;
char d[N];

int dp[N][N], n, m;
 
main () {
	cin >> a >> b;
	for (int i = 0; i < sz(a); ++i) {
		if (a[i] != '*' && a[i] != '+') {
			if (i == sz(a) - 1 || a[i + 1] != '*')
				c += a[i];
			if (i < sz(a) - 1 && (a[i + 1] == '*' || a[i + 1] == '+')) {
				c += '*';                                                
				d[sz(c)] = a[i];
			}
		}						
	}
	/*
	cout << c << endl;
	for (int i = 0; i < sz(c); ++i)
		if (c[i] == '*')
			cout << d[i + 1];
	cout << endl;*/

	dp[0][0] = 1;
	m = sz(c);
	n = sz(b);

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j) {
			if (j > 0 && c[j - 1] == '*') {
				dp[i][j] |= dp[i][j - 1];
				if (i > 0 && d[j] == b[i - 1])
					dp[i][j] |= dp[i - 1][j];
			} else if (j > 0 && i > 0 && c[j - 1] == b[i - 1])
				dp[i][j] |= dp[i - 1][j - 1];
//			cout << dp[i][j] << ' ' << i << ' ' << j << endl;
		}

	puts(dp[n][m] ? "Yes" : "No");
}