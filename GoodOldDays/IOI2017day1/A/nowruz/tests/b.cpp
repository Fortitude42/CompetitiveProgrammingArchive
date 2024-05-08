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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1062;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);

int was[N][N], was1[N][N], was2[N][N];
queue < pii > q;
int n, m, k, ans, res;
vpii VV;
char c;

bool in (int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

int get (int x, int y) {
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		res += was1[tox][toy];
	}

	return res;
}

main () {
	file("10");
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("\n");
		for (int j = 1; j <= m; ++j) {
			scanf("%c", &c);
			if (c == '.')
				was[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (was[i][j] && !was2[i][j]) {
				q.push(mp(i, j));
				while (sz(q)) {
					int x = q.front().f, y = q.front().s;
					q.pop();
					for (int z = 0; z < 4; ++z) {
						int tox = x + dx[z], toy = y + dy[z];
						if (in(tox, toy) && was[tox][toy] && !was2[tox][toy]) {
							was2[tox][toy] = 1;
							q.push(mp(tox, toy));
						}
					}
				}


				q.push(mp(i, j));
				was1[i][j] = 1;
				vpii V;
				while (sz(q)) {
					int x = q.front().f, y = q.front().s;
					V.pb({x, y});
					q.pop();
					for (int z = 0; z < 4; ++z) {
						int tox = x + dx[z], toy = y + dy[z];
						if (in(tox, toy) && !was1[tox][toy] && was[tox][toy] && get(tox, toy) <= 1) {
							was1[tox][toy] = 1;
							q.push(mp(tox, toy));
						}
					}
				}

				res = 0;
				for (auto x : V)
					if (get(x.f, x.s) == 1)
						++res;

				if (res > ans) {
					ans = res;
					VV = V;
				}
			}


	memset(was1, 0, sizeof(was1));
	for (auto x : VV)
		was1[x.f][x.s] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!was[i][j])
				printf("#");
			else if (was1[i][j])	
				printf(".");
			else
				printf("X");
		}
		
		printf("\n");	
	}
	cerr << ans << endl;
					
}	