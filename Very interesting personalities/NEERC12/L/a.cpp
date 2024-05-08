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
 

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, a[M][M][3];

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}


void L(int x, int y, int j) {
	int d = 1;
	while (x != n || y != m) {	
		a[x][y][j] = 1;
		for (int i = -1; i < 3; ++i) {
			int dd = (d + 4 + i) % 4;
			int tox = x + dx[dd], toy = y + dy[dd];
			if (in(tox, toy) && !a[tox][toy][2]) {
				x = tox;
				y = toy;
				d = dd;
				break;
			}
		}
	}
}

void R(int x, int y, int j) {
	int d = 2;
	while (x != n || y != m) {	
		a[x][y][j] = 1;
//		cerr << x << ' ' << y << ' ' << d << endl;
		for (int i = 5; i > 0; --i) {
			int dd = (d + 4 + i) % 4;
			int tox = x + dx[dd], toy = y + dy[dd];
			if (in(tox, toy) && !a[tox][toy][2]) {
				x = tox;
				y = toy;
				d = dd;
				break;
			}
		}
	}
}

int get(int xa, int ya, int xb, int yb, int x) {
	xa--, ya--;
	return a[xb][yb][x] - a[xa][yb][x] - a[xb][ya][x] + a[xa][ya][x];
}

void solve() {
	cin >> m >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			a[i][j][2] = (c == '#');
		}

	L(1, 1, 0);
	R(1, 1, 1);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int x = 0; x < 3; ++x)
				a[i][j][x] += a[i][j - 1][x] + a[i - 1][j][x] - a[i - 1][j - 1][x];

	
	pair < int, pii > res = mp(inf, mp(-1, -1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1)
				continue;
			int l = 1, r = min(n, m);
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (i + mid - 1 > n || j + mid - 1 > m) {
					r = mid - 1;
					continue;
				}

				if ((i + mid - 1 == n && j + mid - 1 == m) || 
					get(i, j, i + mid - 1, j + mid - 1, 2) > 0) {
					r = mid - 1;
					continue;
				}
				if (get(i, j, i + mid - 1, j + mid - 1, 0) > 0 && get(i, j, i + mid - 1, j + mid - 1, 1) > 0) {
					r = mid - 1;
					res = min(res, mp(mid, mp(i, j)));
					continue;
				}

				l = mid + 1;
			}
		}

	if (res.f == inf)
		cout << "Impossible";
	else
		cout << res.f << ' ' << res.s.s << ' ' << res.s.f << endl;
}

main () {
//	file("labyrinth");
	fastio

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

