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
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, dp[N][N][2], r, c;
bool f[N][N];


bool bad (int l, int r) {
	if (r - l > 10 || ((r - l) & 1) || f[l][r])
		return 1;
	return 0;
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int rec (int l, int r, int tp) {
	if (l > r)
		return 1;

	if (bad(l, r))
		tp = 1;

	int &res = dp[l][r][tp];

	if (res !=- 1)
		return res;

	res = rec(l, r - 1, 0);
	
	for (int lf = r - 2; lf >= l && lf >= r - 10; lf -= 2) {
		if ((lf == l && tp) || bad(lf, r))
			continue;
		add(res, rec(lf, r, 1) * 1ll * rec(l, lf, 0) % mod);
	}
	return res;
}

main () {
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;

	while (k--) {
		cin >> c >> r;
		for (int lf = 0; lf < c - r; ++lf)
			for (int rg = c - r + 1; rg < r + c && rg - lf <= 10; ++rg) 
				f[lf][rg] = 1;				

		for (int lf = c - r + 1; lf < r + c; ++lf)
			for (int rg = r + c + 1; rg <= n && rg - lf <= 10; ++rg)
				f[lf][rg] = 1;
				
		f[c - r][r + c] = 1;
	}
	cout << rec(0, n, 0) << endl;
//	cout << rec(2, 4, 0) << endl;
}