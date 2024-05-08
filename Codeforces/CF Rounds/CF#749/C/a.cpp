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


int n, m, q, k, mx[N][20], d[N], w[N][20];
vi a[N], c[N];

void dfs(int x, int y) {
	if (x > n || y > m || c[x][y] || a[x][y])
		return;
	
	mx[y][0] = max(mx[y][0], k);
	c[x][y] = k;
	dfs(x + 1, y);
	dfs(x, y + 1);                   
}

void precalc() {
	for (int i = 2; i <= m; ++i)
		d[i] = d[i >> 1] + 1;


	for (int j = 1; j < 20; ++j)
		for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]); 
			w[i][j] = w[i][j - 1] | w[i + (1 << (j - 1))][j - 1];
		}
}

int get(int l, int r) {
	int D = d[r - l + 1];
	return max(mx[l][D], mx[r - (1 << D) + 1][D]);
}

bool get1(int l, int r) {
	if (l > r)
		return 0;
	int D = d[r - l + 1];
	return w[l][D] | w[r - (1 << D) + 1][D];	
}

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}
 
main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("\n");
		a[i].resize(m + 1);
		c[i].resize(m + 1);

		for (int j = 1; j <= m; ++j) {
			char c;
			scanf("%c", &c);
			a[i][j] = (c == 'X');
		}
	}

	for (int j = 1; j <= m; ++j) {
		k = 1;
		dfs(1, j);

		k = j;      
		for (int i = 2; i <= n; ++i)
			dfs(i, j);
	}

	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j) {
			if (a[i][j] + a[i - 1][j] + a[i][j - 1] == 3) 
				w[j][0] = 1;			
		}


	

	precalc();

	scanf("%d", &q);
	while (q--) {
		int ya, yb;
		scanf("%d%d", &ya, &yb);
		puts((get(ya, yb) <= ya && !get1(ya + 1, yb)) ? "YES" : "NO");
	}
}