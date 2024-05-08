//by paradox & gege & parasat
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
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int l[50], r[50], u[50], d[50], l1[50], r1[50], u1[50], d1[50];
int k, kk, n, m, cc[50][50], cur[50], color[50][50];
char c[50][50][50], t[4*50][4*50];
bool was[50];
vi C[50];
  
bool in(int x, int y) {
	return x > 0 && y > 0 && x <= 3*n - 2 && y <= 3*m - 2;
} 

void dfs(int x, int y, int z, int col) {
	cc[x][y] = col;
	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		if (in(tox, toy) && !cc[tox][toy] && c[z][tox][toy] == '.')
			dfs(tox, toy, z, col);
	}
}

int get(int x, int y) {
	x--, y--;
	return (x*m) + y;
}

void rec(int x, int y) {
//	cerr << x << ' ' << y << ' ' << tp << endl;
	if (y == kk + 1) {
		y = 1;
		++x;
		if (x == kk + 1) {		
			cout << m*kk << ' ' << n*kk << endl;
			for (int i = 1; i <= kk; ++i) 
				for (int j = 1; j <= kk; ++j) {
					int x = color[i][j];
					for (int ii = 1; ii <= 3*n - 2; ++ii)
						for (int jj = 1; jj <= 3*m - 2; ++jj)
							if (c[x][ii][jj] != '.')
								t[(i - 1)*n + ii - n + 1][(j - 1)*m + jj - m + 1] = c[x][ii][jj];
				}
			for (int i = 1; i <= kk*n; ++i, cout << endl)
				for (int j = 1; j <= kk*m; ++j)
					cout << t[i][j];
			exit(0);
		}
	}

	bool lf = (y == 1);
	bool rg = (y == kk);
	bool up = (x == 1);
	bool dw = (x == kk);

	int tp;
	if (lf && up)
		tp = 1;
	else if (rg && up)	
		tp = 2;
	else if (lf && dw)
		tp = 3;
	else if (rg && dw)	
		tp = 4;
	else if (lf)
		tp = 5;
	else if (up)
		tp = 6;
	else if (rg)
		tp = 7;
	else if (dw)	
		tp = 8;
	else
		tp = 9;	


//	random_shuffle(all(C[tp]));
	for (auto z : C[tp]) {
		if (was[z])
			continue;
		if (!lf && (r[color[x][y - 1]] != l1[z] || l[z] != r1[color[x][y - 1]]))
			continue;
		if (!up && (d[color[x - 1][y]] != u1[z] || u[z] != d1[color[x - 1][y]]))
			continue;

		was[z] = 1;
		color[x][y] = z;
		rec(x, y + 1);
		was[z] = 0;
		color[x][y] = 0;
	}
}

void solve() {
	cin >> k >> m >> n;
	kk = sqrt(k);

	for (int x = 1; x <= k; ++x) {
		for (int i = 1; i <= 3*n - 2; ++i)
			for (int j = 1; j <= 3*m - 2; ++j)
				cin >> c[x][i][j];

		memset(cc, 0, sizeof(cc));
		for (int i = 1; i <= 3*n - 2; ++i)
			for (int j = 1; j <= 3*m - 2; ++j) {
				bool x = (i < n || i > 2*n - 1);
				bool y = (j < m || j > 2*m - 1);
				if (x && y)
					cc[i][j] = 5;
			}

		for (int i = n; i <= 2*n - 1; ++i)
			for (int j = 1; j <= m - 1; ++j) {
				if (cc[i][j] || c[x][i][j] != '.')
					continue;
				dfs(i, j, x, 1);
			}

		for (int i = 1; i <= n - 1; ++i)
			for (int j = m; j <= 2*m - 1; ++j) {
				if (cc[i][j] || c[x][i][j] != '.')
					continue;
				dfs(i, j, x, 2);
			}

		for (int i = n; i <= 2*n - 1; ++i)
			for (int j = 2*m; j <= 3*m - 2; ++j) {
				if (cc[i][j] || c[x][i][j] != '.')
					continue;
				dfs(i, j, x, 3);
			}

		for (int i = 2*n; i <= 3*n - 2; ++i)
			for (int j = m; j <= 2*m - 1; ++j) {
				if (cc[i][j] || c[x][i][j] != '.')
					continue;
				dfs(i, j, x, 4);
			}		
		

		for (int i = n; i <= 2*n - 1; ++i)
			for (int j = 1; j <= m - 1; ++j) 
				if (!cc[i][j])
					l[x] |= (1 << get(i - n + 1, j + 1)); 				  
				
			
		for (int i = 1; i <= n - 1; ++i)
			for (int j = m; j <= 2*m - 1; ++j) 
				if (!cc[i][j])
					u[x] |= (1 << get(i + 1, j - m + 1)); 
				
		for (int i = n; i <= 2*n - 1; ++i)
			for (int j = 2*m; j <= 3*m - 2; ++j)
				if (!cc[i][j])
					r[x] |= (1 << get(i - n + 1, j - 2*m + 1));
				
		for (int i = 2*n; i <= 3*n - 2; ++i)
			for (int j = m; j <= 2*m - 1; ++j) 
				if (!cc[i][j])
					d[x] |= (1 << get(i - 2*n + 1, j - m + 1));

		for (int i = n; i <= 2*n - 1; ++i) 
			for (int j = m; j <= 2*m - 1; ++j) {
				int cur = (1 << get(i - n + 1, j - m + 1));

				if (cc[i][j] == 1) 
					l1[x] |= cur;
				if (cc[i][j] == 2)
					u1[x] |= cur;
				if (cc[i][j] == 3)
					r1[x] |= cur;
				if (cc[i][j] == 4)
					d1[x] |= cur;
			}

		if (x == 8)
			cerr << l[x] << ' ' << r[x] << ' ' << u[x] << ' ' << d[x] << endl;
	}


	for (int x = 1; x <= k; ++x) {
		int tp;
		if (!l[x] && !u[x] && !l1[x] && !u1[x])
			tp = 1;
		else if (!r[x] && !u[x] && !r1[x] && !u1[x])
			tp = 2;
		else if (!l[x] && !d[x] && !l1[x] && !d1[x])
			tp = 3;
		else if (!r[x] && !d[x] && !r1[x] && !d1[x])
			tp = 4;
		else if (!l[x] && !l1[x]) 	
			tp = 5;
		else if (!u[x] && !u1[x])	
			tp = 6;
		else if (!r[x] && !r1[x])	
			tp = 7;
		else if (!d[x] && !d1[x])	
			tp = 8;
		else
			tp = 9;

		C[tp].pb(x);
	}

	rec(1, 1);
	
}

main () {
	//file("ascii");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                                      