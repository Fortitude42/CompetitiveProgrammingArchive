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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

queue < pair < pii, pii > > q[4];
int t, n, m, k, xs, ys, xe, ye;
vector < vi > d[2][55];
char c[N][N];

bool in (int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
} 

main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("\n");
			for (int j = 1; j <= m; ++j) {
				scanf("%c", &c[i][j]);
				if (c[i][j] == 'A')
					xs = i, ys = j;
				else if (c[i][j] == 'B')
					xe = i, ye = j;
			}								
		}

		
		for (int y = 0; y < 2; ++y)
			for (int i = 0; i <= k; ++i) {
				d[y][i].clear();
				d[y][i].resize(n + 1);	

				for (int j = 1; j <= n; ++j) {
					d[y][i][j].resize(m + 1);    
					for (int x = 1; x <= m; ++x)
						d[y][i][j][x] = inf;
				}
			}

		d[0][0][xs][ys] = 0;
		q[0].push(mp(mp(xs, ys), mp(0, 0)));

		int l = 0;
		while (sz(q[l]) || sz(q[(l + 1) % 4]) || sz(q[(l + 2) % 4]) || (sz(q[(l + 3) % 4]))) {
			while (sz(q[l])) {
				int x = q[l].front().f.f, y = q[l].front().f.s, z = q[l].front().s.f, tp = q[l].front().s.s;
				q[l].pop();

				if (d[tp][z][x][y] % 4 != l)
					continue;

				for (int i = 0; i < 4; ++i) {
					int tox = x + dx[i], toy = y + dy[i];
					if (!in(tox, toy) || c[tox][toy] == '#')
						continue;

					if (c[tox][toy] == 'D') {
						int za = (c[x][y] == 'D' && !tp);
						if (z + za < k && d[0][z][tox][toy] > d[tp][z][x][y] + 3) {
							d[0][z][tox][toy] = d[tp][z][x][y] + 3;
							q[d[0][z][tox][toy] % 4].push(mp(mp(tox, toy), mp(z, 0)));
						}

						if (z + za < k && d[1][z + 1][tox][toy] > d[tp][z][x][y] + 2) {
							d[1][z + 1][tox][toy] = d[tp][z][x][y] + 2;
							q[d[1][z + 1][tox][toy] % 4].push(mp(mp(tox, toy), mp(z + 1, 1)));
						}
						continue;
					}

					if (d[0][z][tox][toy] > d[tp][z][x][y] + 1) {
						d[0][z][tox][toy] = d[tp][z][x][y] + 1;
						q[d[0][z][tox][toy] % 4].push(mp(mp(tox, toy), mp(z, 0)));
					}
				}
			}
			
			l = (l + 1) % 4;
		}
		                
		int ans = inf;
		for (int x = 0; x < 2; ++x)
			for (int j = 0; j <= k; ++j)
				ans = min(ans, d[x][j][xe][ye]);

		if (ans == inf)
			printf("HAHAHUHU\n");
		else
			printf("%d\n", ans);	

	}
}