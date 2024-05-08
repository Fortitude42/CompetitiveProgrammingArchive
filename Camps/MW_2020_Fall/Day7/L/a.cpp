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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vpii p[N];
int n, k, a[N];
vi pos[N], dp[N];


 
main () {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);       
		pos[a[i]].pb(i);
	}

	pos[0].pb(0);

	for (int i = 0; i <= k; ++i) {
		dp[i].resize(sz(pos[i]), inf);
		p[i].resize(sz(pos[i]));
	}


	int ans = inf, ii = -1, jj = -1, xx = -1;

	dp[0][0] = 0;
	for (int i = 0; i < k; ++i) {
		int x = 0;
		for (int j = 0; j < sz(pos[i]); ++j) {
			if (j && dp[i][j] > dp[i][j - 1] + 1) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
				p[i][j] = mp(i, j - 1);
			}

			while (x < sz(pos[i + 1]) && pos[i + 1][x] < pos[i][j])
				++x;

			if (ans > dp[i][j] + sz(pos[i + 1]) - x) {
				ii = i;
				jj = j;
				xx = x;
				ans = dp[i][j] + sz(pos[i + 1]) - x;
			}

			if (x < sz(pos[i + 1]) && dp[i + 1][x] > dp[i][j]) {
				dp[i + 1][x] = dp[i][j];
				p[i + 1][x] = mp(i, j);
			}
		}
	}

//	cerr << ii << ' ' << jj << ' ' << xx << endl;



	vi res;
	for (int i = xx; i < sz(pos[ii + 1]); ++i)
		res.pb(pos[ii + 1][i]);

	while (ii > 0) {
		int i1 = p[ii][jj].f, j1 = p[ii][jj].s;
		if (i1 == ii) 
			res.pb(pos[i1][j1]);

		ii = i1, jj = j1;
	}

	sort(all(res));

	printf("%d\n", sz(res));
	for (auto x : res)
		printf("%d ", x);
}