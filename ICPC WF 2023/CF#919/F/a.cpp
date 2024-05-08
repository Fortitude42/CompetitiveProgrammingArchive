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


int n, m, k, xv, yv;
vector < char > c[M];
vector < int > d[M];
vector < bool > bad[M];
queue < pii > q;


bool in(int i, int j) {
	return i > 0 && j > 0 && i <= n && j <= m;
}


bool check(int x, int y, int l) {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			bad[i][j] = 0;


	bad[x][y] = 1;
	q.push({x, y});
	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		q.pop();


		for (int i = 0; i < 4; ++i) {
			int tox = x + dx[i], toy = y + dy[i];
			if (in(tox, toy) && d[tox][toy] >= l && c[tox][toy] != '#' && !bad[tox][toy]) {
				bad[tox][toy] = 1;
				q.push({tox, toy});
			}
		}
	}

//	for (int i = 1; i <= n; ++i, cerr << endl)
//		for (int j = 1; j <= m; ++j)
//			cerr << bad[i][j];

	assert(!bad[xv][yv]);
	q.push({xv, yv});
	bad[xv][yv] = 1;
	
	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		if (x == 1 || x == n || y == 1 || y == m) {
			while (sz(q) > 0)
				q.pop();
			return 0;
		}

		q.pop();


		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy) {
				int tox = x + dx, toy = y + dy;
				if (in(tox, toy) && !bad[tox][toy]) {
					bad[tox][toy] = 1;
				q.push({tox, toy});
			}
		}
	}

	return 1;
}
 
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		c[i].resize(m + 1);
		d[i].resize(m + 1, -1);
		bad[i].resize(m + 1);
		for (int j = 1; j <= m; ++j)  {
			cin >> c[i][j];				
			if (c[i][j] == '#')
				xv = i, yv = j;
		}
	}

	assert(xv > 0);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (c[i][j] == 'v') {
				q.push({i, j});
				d[i][j] = 0;
			}



	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		q.pop();


		for (int i = 0; i < 4; ++i) {
			int tox = x + dx[i], toy = y + dy[i];
			if (!in(tox, toy) || d[tox][toy] != -1)
				continue;
			d[tox][toy] = d[x][y] + 1;
			q.push({tox, toy});
		}
	}


/*	for (int i = 1; i <= n; ++i,cerr << endl)
		for (int j = 1; j <= m; ++j)
			cerr << d[i][j] << ' ';
*/

	while (k--) {
		int x, y;
		cin >> x >> y;
		int l = 1, r = d[x][y], res = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(x, y, mid)) {
				res = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}

		cout << res << "\n";
	}
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