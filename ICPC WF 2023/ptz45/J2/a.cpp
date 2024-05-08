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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, col[M][M], k;
bool ok[M*M];
char c[M][M];
vector < pii > pos[M*M];

void dfs(int x, int y) {
	col[x][y] = k;
	pos[k].pb({x, y});
	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		if (!col[tox][toy] && c[tox][toy] == '#') 
			dfs(tox, toy);		
	}
} 

const int E = 20;
const double EE = 0.4;


bool check() {
	int xs = pos[k][0].f, ys = pos[k][0].s;
	
	random_shuffle(all(pos[k]));
	int mx = 0;
	double mx1 = 0;
	
	for (auto p : pos[k]) {
		int xe = p.f, ye = p.s;

		int cnt = 0;

		int X = abs(xs - xe);
		int Y = abs(ys - ye);
		if (!X && !Y)
			continue;

		if (X > Y) {
			double kk = (ys - ye + 0.0) / (xs - xe);
			double b = ys - kk*xs;

			int l = min(xs, xe);
			int r = max(xs, xe);

			for (int x = l; x <= r; ++x) {
				int y = (int)(kk*x + b);
				if (col[x][y] != k && col[x][y + 1] != k)
					++cnt;
			}

			mx = max(mx, cnt);
//			if (cnt >= E)
				mx1 = max(mx1, (cnt + 0.0) / (r - l + 1));			
			continue;
		} 

		double kk = (xs - xe + 0.0) / (ys - ye);
		double b = xs - kk*ys;

		int l = min(ys, ye);
		int r = max(ys, ye);

		for (int y = l; y <= r; ++y) {
			int x = (int)(kk*y + b);
			if (col[x][y] != k && col[x + 1][y] != k)
				++cnt;
		}

		mx = max(mx, cnt);
//		if (cnt >= E)
			mx1 = max(mx1, (cnt + 0.0) / (r - l + 1));			
	}

	cerr << k << ' ' << mx1 << ' ' << mx << endl;
	        
	return mx1 <= EE;
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];

	
	int ans = 0;	
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			if (!col[i][j] && c[i][j] == '#') {
				++k;
				dfs(i, j);
				if (!check())
					ans += 5;
				else
					ans++;
			}

	cout << ans - 5 << endl;
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}