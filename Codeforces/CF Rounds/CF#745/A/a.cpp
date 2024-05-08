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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 412;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int t, n, m, s[N][N];
char c[N][N];

inline int get(int xa, int ya, int xb, int yb) {
	xa--, ya--;
	return s[xb][yb] - s[xa][yb] - s[xb][ya] + s[xa][ya];
}

inline int get1(int xa, int ya, int xb, int yb) {
	return (xb - xa + 1) * (yb - ya + 1) - get(xa, ya, xb, yb);
}

main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("\n");
			for (int j = 1; j <= m; ++j) {
				scanf("%c", &c[i][j]);     
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (c[i][j] == '1');
			}
		}

		int ans = 20;

		for (int i = 1; i <= n; ++i)
			for (int j = i + 4; j <= n; ++j) {
				vpii pos;
				for (int y = 1; y <= m; ++y) {
					int val = get1(i + 1, y, j - 1, y);
					if (val <= ans)
						pos.pb({y, val});            
				}

				for (int x = 0; x < sz(pos); ++x) {
					for (int y = x + 1; y < sz(pos); ++y) {
						if (pos[y].f - pos[x].f < 3)
							continue;

						int in = get(i + 1, pos[x].f + 1, j - 1, pos[y].f - 1);
						int left = pos[x].s;
						int up = get1(i, pos[x].f + 1, i, pos[y].f - 1);
						int down = get1(j, pos[x].f + 1, j, pos[y].f - 1);

						if (left + in + up + down > ans)
							break;

						int right = pos[y].s;
//						cerr << left << ' ' << right << ' ' << up << ' ' << down << ' ' << in << endl;
						ans = min(ans, left + right + up + down + in);
					}
				}
			}

		printf("%d\n", ans);
	}
}   	