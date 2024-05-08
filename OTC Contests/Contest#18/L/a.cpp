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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, x[N], c[N][N], dp[N][N];
pii p[N][N];
vpii A;

main () {
	file("hobbit");
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
		A.pb(mp(x[i], i));
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &c[i][j]);

	sort(all(A));
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = inf*2;

	dp[0][0] = 0;
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < n; ++b) {

			int to = max(a, b) + 1;
			int aa = !a ? 0 : A[a - 1].s, bb = !b ? 0 : A[b - 1].s, too = A[to - 1].s;

			if (dp[to][b] > dp[a][b] + c[aa][too]) {
				dp[to][b] = dp[a][b] + c[aa][too];
				p[to][b] = mp(a, b);
			}

			if (dp[a][to] > dp[a][b] + c[bb][too]) {
				dp[a][to] = dp[a][b] + c[bb][too];
				p[a][to] = mp(a, b);
			}
		}

	int j = 0;

	for (int b = 0; b < n; ++b) {
		int nn = A[n - 1].s, bb = !b ? 0 : A[b - 1].s;
		if (dp[n][n] > dp[n][b] + c[nn][bb]) {
			j = b;
			dp[n][n] = dp[n][b] + c[nn][bb];
			p[n][n] = mp(n, b);
		}
	}

	int x = n, y = j;
	vi b, f;
	while (x > 0 || y > 0) {
		int xx = p[x][y].f, yy = p[x][y].s;
		if (x == xx) 
			b.pb(y);
		else
			f.pb(x);

		x = xx;
		y = yy;
	}

	reverse(all(f));

	cout << A[n - 1].f * 2 << ' ' << dp[n][n] << endl;
	for (auto x : f)
		cout << A[x - 1].s << ' ';
	for (auto x : b)
		cout << A[x - 1].s << ' ';



}