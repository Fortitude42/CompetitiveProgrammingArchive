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

int n, was[N][N];
char c[N][N];
stack < pii > st;


bool check (int x, int y) {
	return (!was[x][y] && c[x][y] == '1');
}


 
void rec (int x, int y, int z) {
	int lx = x, rx = x;

	if (!z || (!check(x, y - 1) && !check(x, y + 1))) {
		while (check(lx - 1, y))
			--lx;
		while (check(rx + 1, y))
			++rx;

		if (lx != rx) {
			for (int x = lx; x <= rx; ++x)
				if (x == lx && ((rx - lx + 1) & 1)) {
					was[x][y] = was[x + 1][y] = was[x + 2][y] = 5;
					x += 2; 
				} else {
					was[x][y] = was[x + 1][y] = 3;
					++x;
				}
		
			for (int x = lx; x <= rx; ++x) {
				if (check(x, y + 1))
					rec(x, y + 1, 0);
				if (check(x, y - 1))
					rec(x, y - 1, 0);
			}

		    return;
		}			
	}
	
	int ly = y, ry = y;

	while (check(x, ly - 1))
		--ly;

	while (check(x, ry + 1))
		++ry;

	for (int y = ly; y <= ry; ++y) {
		if (y == ly && ((ry - ly + 1) & 1)) {
			was[x][y] = was[x][y + 1] = was[x][y + 2] = 4;
			y += 2;
		} else {
			was[x][y] = was[x][y + 1] = 2;
			++y;
		}
	}

	for (int y = ly; y <= ry; ++y) {
		if (check(x + 1, y))
			rec(x + 1, y, 1);
		if (check(x - 1, y))
			rec(x - 1, y, 1);
	}
}

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("\n");
		for (int j = 1; j <= n; ++j)
			scanf("%c", &c[i][j]);
	}

	bool u = 0;


	for (int i = n; i > 0; --i)
		for (int j = 1; j <= n; ++j) 
			if (check(i, j)) {
			    if (u)
			    	return 0;
				rec(i, j, 0);    
				u = 1;
			}

	for (int i = 1; i <= n; ++i, printf("\n"))
		for (int j = 1; j <= n; ++j)
			printf("%d", was[i][j]);
}