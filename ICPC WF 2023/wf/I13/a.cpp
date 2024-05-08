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
const int N = 500, inf = 2e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int a, b, n, m, mn[M][M][9][9], d[M];
int c[M][M], ans[M][M];

void build() {
	for (int i = 2; i <= N; ++i)
		d[i] = d[i >> 1] + 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			mn[i][j][0][0] = c[i][j];

	for (int dx = 0; dx < 9; ++dx)
		for (int dy = 0; dy < 9; ++dy) {
			if (!dx && !dy)
				continue;

			for (int i = 1; i + (1 << dx) - 1 <= n; ++i)
				for (int j = 1; j + (1 << dy) - 1 <= m; ++j) {
					if (!dx)
						mn[i][j][dx][dy] = min(mn[i][j][dx][dy - 1], mn[i][j + (1 << (dy - 1))][dx][dy - 1]);
					else
						mn[i][j][dx][dy] = min(mn[i][j][dx - 1][dy], mn[i + (1 << (dx - 1))][j][dx - 1][dy]);
				}
		}
}

inline int get(int xa, int ya, int xb, int yb) {
	int dx = d[xb - xa + 1];
	int dy = d[yb - ya + 1];
	return min({mn[xa][ya][dx][dy], 
				mn[xa][yb - (1 << dy) + 1][dx][dy], 
				mn[xb - (1 << dx) + 1][ya][dx][dy],
				mn[xb - (1 << dx) + 1][yb - (1 << dy) + 1][dx][dy]});
}

inline int find_min(int i, int j1, int j2, int mn) {
	int l = 1, r = i - 1, i1 = i;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (get(mid, j1, i, j2) == mn) {
			i1 = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}

	return i1;
}

inline int find_max(int i, int j1, int j2, int mn) {
	int l = i + 1, r = n, i2 = i;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (get(i, j1, mid, j2) == mn) {
			i2 = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

	return i2;
}
 
void solve() {
	cin >> a >> b >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> c[i][j];
			ans[i][j] = 0;
		}

	build();

	for (int i = 1; i <= n; ++i)
		for (int j1 = 1; j1 <= m; ++j1)
			for (int j2 = j1; j2 <= m; ++j2) {
				int mn = get(i, j1, i, j2);
				int i1 = find_min(i, j1, j2, mn);
				int i2 = find_max(i, j1, j2, mn);
				ans[i2 - i1 + 1][j2 - j1 + 1] = max(ans[i2 - i1 + 1][j2 - j1 + 1], mn);
			}

	for (int i = n; i > 0; --i)
		for (int j = m; j > 0; --j) {
			if (i + 1 <= n)
				ans[i][j] = max(ans[i][j], ans[i + 1][j]);
			if (j + 1 <= m)				 
				ans[i][j] = max(ans[i][j], ans[i][j + 1]);
		}

	ll res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if ((i <= a && j <= b) || (i <= b && j <= a)) {
				if (ans[i][j] == 0)
					continue;
				ll z = (ans[i][j]*1ll*n*m + 1ll*n*m - 1ll*i*j - 1) / (1ll*n*m - 1ll*i*j) - 1;
				res = max(res, z*i*j);
			}

	cout << res << "\n";
		
}

main () {
  int TT;
  TT = 1;
  fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}