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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 3e4 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
string s;
vpii g[N];
int n, dp[N], p[N], F[N];

int f(int i, int j) {
	if (s[i] == '?' && s[j] == '?')
		return 1;
	if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
		return -1;
	return 0;
}

void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int get(int l, int r) {
	return F[r] - F[l - 1];
}

main () {
	p[0] = 1;
	for (int i = 1; i < N; ++i)
		p[i] = p[i - 1] * 1ll * 26 % mod;

	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; ++i) 
		F[i] = F[i - 1] + (s[i - 1] == '?');
	
	dp[0] = 1;
	for (int i = 0; i < n - 1 - i; ++i) {
		int a = i, b = i, bal = 0;
		int x = n - 1 - i, y = n - 1 - i;

		while (a >= 0 && b < x) {
			if (f(a, x) == -1 || f(b, y) == -1)
				break;

			bal += f(a, x);
			bal += (a < b && f(b, y));
			add(dp[b + 1], dp[a] * 1ll * p[bal] % mod);
			a--, b++;
			x--, y++;
		}

		if (i < n - 1) {
			a = i, b = i + 1, bal = 0;
			x = n - 2 - i, y = n - i - 1;

			while (a >= 0 && b < x) {
				if (f(a, x) == -1 || f(b, y) == -1)
					break;

				bal += f(a, x);
				bal += f(b, y);
				add(dp[b + 1], dp[a] * 1ll * p[bal] % mod);
				a--, b++;
				x--, y++;
			}
		}
	}



	int ans = (n & 1) ? 0 : dp[n / 2];
	for (int i = 0; i + 1 <= n - i; ++i) {
		add(ans, dp[i] * 1ll * p[get(i + 1, n - i)] % mod); 
//		cerr << i << ' ' << dp[i] << ' ' << p[get(i + 1, n - i)] << endl;
	}

	cout << ans << endl;
}