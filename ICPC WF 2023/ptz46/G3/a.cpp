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
const int N = 3000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int maxn = 1e5 + 11;

int n, m, k, d[M][M], d1[M][M];
int x[maxn], y[maxn];
char c[M][M];
vector < pii > g[maxn];

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

 
void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i];
		d1[x[i]][y[i]] = k - i;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];

	deque < pii > q;
	memset(d, -1, sizeof d);


	d[x[0]][y[0]] = 0;
	q.pb(mp(x[0], y[0]));

	for (int dist = 0; dist <= k; ++dist) {
		while (sz(g[dist]) > 0) {
			int x = g[dist].back().f;
			int y = g[dist].back().s;
			g[dist].ppb();
			q.push_front(mp(x, y));
		}

		while (sz(q)) {
			int x = q.front().f, y = q.front().s;
			if (d[x][y] != dist)
				break;

			q.pop_front();


			for (int i = 0; i < 4; ++i) {
				int tox = x + dx[i], toy = y + dy[i];
				if (in(tox, toy) && d[tox][toy] == -1 && c[tox][toy] == '.') {
					if (d[x][y] + 1 >= d1[tox][toy]) {
						d[tox][toy] = d[x][y] + 1;
						q.pb(mp(tox, toy));
					} else {
						d[tox][toy] = d1[tox][toy];
						g[d[tox][toy]].pb(mp(tox, toy));
					}
				}
			}
		}
	}


	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		q.pop_front();


		for (int i = 0; i < 4; ++i) {
			int tox = x + dx[i], toy = y + dy[i];
			if (in(tox, toy) && d[tox][toy] == -1 && c[tox][toy] == '.') {
				if (d[x][y] + 1 >= d1[tox][toy]) {
					d[tox][toy] = d[x][y] + 1;
					q.pb(mp(tox, toy));
				} else {
					assert(0);
				}
			}
		}
	}

	unsigned long long ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (d[i][j] != -1)
				ans += d[i][j] * 1ull * d[i][j];
/*
	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= m; ++j)
			cout << d[i][j] << ' ';
*/
	cout << ans << "\n";
			
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