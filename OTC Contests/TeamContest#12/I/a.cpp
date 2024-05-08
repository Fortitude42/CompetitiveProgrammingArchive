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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, s[N][N];
char c[N][N];

int get (int xa, int ya, int xb, int yb) {
	--xa, --ya;
	return s[xb][yb] - s[xb][ya] - s[xa][yb] + s[xa][ya];
} 

bool in (int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

bool checka (int i, int j, int x, int y) {
	
}


bool checkb (int i, int j, int x, int y) {

}


bool checkc (int i, int j, int x, int y) {
	
}

main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("\n");
		for (int j = 1; j <= m; ++j) {
			scanf("%c", &c[i][j]);    
			s[i][j] = (c[i][j] == '#') + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; ++i) {
	    int J = m + 1;
		for (int j = m; j > 0; --j)
			if (s[i][j] == '#')
				nxt[i][j] = J;
			else
				J = j;
	}

	for (int j = 1; j <= m; ++j) {
	    int I = n + 1;
		for (int i = n; i > 0; --i)
			if (s[i][j] == '#')
				nxt1[i][j] = I;
			else
				I = i;
	}

	
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			if (s[i][j] == '.' && s[i + 1][j + 1] == '#') {
				int ii = nxt1[i + 1][j + 1], jj = nxt[i + 1][j + 1];
				if (!in(ii, jj))
					continue;
				
				int h = ii - i - 1, w = jj - j - 1;
				int x = 2*w - h;
				int y = w - 2*x;
				if (x <= 0 || y <= 0)
					continue;

				a += checka(i, j, x, y);
				b += checkb(i, j, x, y);
				c += checkc(i, j, x, y);
			}
	
}