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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vi v;
char c;
bool used[N];
int n, m, a[N][N];


void precalc () {
	for (int i = 2; i < N / 2; ++i)
		if (!used[i]) {
			v.pb(i);
			for (int j = i + i; j < N / 2; j += i)
				used[j] = 1;
		}	
}

int get (int xa, int ya, int xb, int yb) {
	--xa, --ya;
	return a[xb][yb] - a[xa][yb] - a[xb][ya] + a[xa][ya];
}

int solve (int x) {
	int nn = (n + x - 1) / x;
	int mm = (m + x - 1) / x;
	int res = 0;

	for (int i = 1; i <= nn; ++i)
		for (int j = 1; j <= mm; ++j) {
			int xl = (i - 1)*x + 1, xr = i*x;
			int yl = (j - 1)*x + 1, yr = j*x;
			int cur = get(xl, yl, xr, yr);
			res += min(cur, x*x - cur);
//			cerr << xl << ' ' << yl << ' ' << xr << ' ' << yr << ' ' << cur << endl;
		}

	return res;
}
 
main () {
	precalc();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
	    scanf("\n");
		for (int j = 1; j <= m; ++j) {
			scanf("%c", &c);
			a[i][j] = c - '0';
		}                         
	}
		

	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];

	int ans = inf;
	for (auto x : v)	
		ans = min(ans, solve(x));
	cout << ans << endl;
}