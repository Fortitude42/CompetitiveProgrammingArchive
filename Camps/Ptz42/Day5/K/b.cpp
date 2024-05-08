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
const int N = 2e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, q, a[M][M], s[M][M], t[M][M][4];

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

int get(int xa, int ya, int xb, int yb) {
	--xa, --ya;
	return s[xb][yb] - s[xa][yb] - s[xb][ya] + s[xa][ya];
}

int getx(int x, int l, int r, int j) {
	return t[x][r][j] - t[x][l - 1][j];
}

int gety(int y, int l, int r, int j) {
	return t[r][y][j] - t[l - 1][y][j];
}

void solve() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			s[i][j] = 1;
			for (int x = 0; x < 4; ++x) {
				int toi = i + dx[x], toj = j + dy[x];
				if (in(toi, toj) && a[toi][toj] + 1 == a[i][j]) {
					s[i][j] = 0; 
					break;
				}
			}
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (i < n) {
				if (a[i][j] + 1 == a[i + 1][j])
					++t[i][j][0];
				if (a[i][j] - 1 == a[i + 1][j])
					++t[i][j][1];
			}

			if (j < m) {
				if (a[i][j] + 1 == a[i][j + 1])
					++t[i][j][2];
				if (a[i][j] - 1 == a[i][j + 1])
					++t[i][j][3];
			}
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			t[i][j][0] += t[i][j - 1][0];
			t[i][j][1] += t[i][j - 1][1];
			t[i][j][2] += t[i - 1][j][2];
			t[i][j][3] += t[i - 1][j][3];
		}

	while (q--) {
		int xa, ya, xb, yb;
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		int cnt = get(xa, ya, xb, yb);
		cnt += getx(xa - 1, ya, yb, 0) + getx(xb, ya, yb, 1);
		cnt += gety(ya - 1, xa, xb, 2) + gety(yb, xa, xb, 3);
		puts(cnt == 1 ? "YES" : "NO");
	}
			
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

