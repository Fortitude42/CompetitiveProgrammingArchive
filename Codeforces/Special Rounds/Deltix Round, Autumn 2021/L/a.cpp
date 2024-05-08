//by parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, -1, 1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
char c[M][M];
vector < pii > curSet;
int n, m, k, mn[M][M][4];

bool in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void build() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int x = 0; x < 4; ++x)
				mn[i][j][x] = inf;

	for (auto x : curSet)
		for (int j = 0; j < 4; ++j)
			mn[x.f][x.s][j] = x.f * dx[j] + x.s * dy[j];


	for (int i = 1; i <= n; ++i) {
		int ii = n - i + 1;

		for (int j = 1; j <= m; ++j) {
			if (i > 1) {
				mn[i][j][0] = min(mn[i][j][0], mn[i - 1][j][0]);
				mn[ii][j][2] = min(mn[ii][j][2], mn[ii + 1][j][2]);
			}

			if (j > 1) {
				mn[i][j][0] = min(mn[i][j][0], mn[i][j - 1][0]); 
				mn[ii][j][2] = min(mn[ii][j][2], mn[ii][j - 1][2]);
			}
		}                         

		for (int j = m; j > 0; --j) {
			if (i > 1) {
				mn[i][j][1] = min(mn[i][j][1], mn[i - 1][j][1]); 
				mn[ii][j][3] = min(mn[ii][j][3], mn[ii + 1][j][3]);
			}

			if (j < m) {
				mn[i][j][1] = min(mn[i][j][1], mn[i][j + 1][1]); 
				mn[ii][j][3] = min(mn[ii][j][3], mn[ii][j + 1][3]);
			}
		}
	}

	curSet.clear();
}

int get(int i, int j) {
	int Mn = inf;
	for (int x = 0; x < 4; ++x) 
		Mn = min(Mn, mn[i][j][x] - i*dx[x] - j*dy[x]); 

	return Mn;
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("\n");
		for (int j = 1; j <= m; ++j) {
			scanf("%c", &c[i][j]);     
			if (c[i][j] == '.')
				curSet.pb({i, j});
		}
	}
	build();


	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (c[i][j] == 'x' && get(i, j) > k) 
				curSet.pb({i, j});                 
			

			

	build();
	bool Ok = 1;
	for (int i = 1; i <= n && Ok; ++i)
		for (int j = 1; j <= m && Ok; ++j)
			if (c[i][j] == 'x' && get(i, j) > k)
				Ok = 0;

	puts(Ok ? "TAK" : "NIE");
}

main () {
	int TT;
	TT = 1;
  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}