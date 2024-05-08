#include "wombats.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1012;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int h[5000][200], v[5000][200], n = 5000, m = 200, L = 20, bl = n / L, opt[200][200];
ll t[2000][200][200];
 
void update (int pos, int v = 1, int tl = 0, int tr = bl - 1) {
	if (tl == tr) {
		for (int j = 0; j < m; ++j)
			for (int x = 0; x < m; ++x)
				t[v][j][x] = INF;
		
		for (int j = 0; j < m; ++j) {
			t[v][j][j] = 0;
			for (int i = tl*L; i < (tl + 1)*L ; ++i) {
				for (int x = 0; x + 1 < m; ++x)
					t[v][j][x + 1] = min(t[v][j][x + 1], t[v][j][x] + h[i][x]);
				
				for (int x = m - 1; x > 0; --x)
					t[v][j][x - 1] = min(t[v][j][x - 1], t[v][j][x] + h[i][x - 1]);

				for (int x = 0; x < m; ++x) 
					t[v][j][x] += ::v[i][x]; 				
			}
		}

		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, v << 1, tl, tm);
	else
		update(pos, v << 1 | 1, tm + 1, tr);
	
	for (int i = 0; i < m; ++i)	
		for (int j = m - 1; j >= 0; --j) {
 			int optl = !i ? 0 : opt[i - 1][j], optr = j == m - 1 ? m - 1 : opt[i][j + 1];
			t[v][i][j] = INF;

			for (int x = optl; x <= optr; ++x)
				if (t[v][i][j] > t[v << 1][i][x] + t[v << 1 | 1][x][j]) {
					t[v][i][j] = t[v << 1][i][x] + t[v << 1 | 1][x][j];
					opt[i][j] = x;
				}
		}
}

void init(int r, int c, int H[5000][200], int V[5000][200]) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			h[i][j] = inf*2;
			v[i][j] = 0;
			if (i < r && j + 1 < c)
				h[i][j] = H[i][j];
			if (i + 1 < r && j < c)
				v[i][j] = V[i][j];
		}

	for (int i = 0; i < bl; ++i)
		update(i);
}
 
void changeH(int p, int q, int w) {
	h[p][q] = w;
	update(p / L);
}
 
void changeV(int p, int q, int w) {
	v[p][q] = w;
	update(p / L);
}
 
int escape(int a, int b) {
	return t[1][a][b];
}