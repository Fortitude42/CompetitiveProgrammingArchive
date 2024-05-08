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

int n = 9;
queue < pii > q;
map < pii, int > d;
set < pii > blocked;
map < pii, vector < pair < int, pii > > > g;
 
bool in(int x, int y) {
	if (x >= n || x <= -n || y >= n || y <= -n)
		return 0;

	if (x >= 0) 
		return y >= -(n - 1) + x;
	return y <= (n - 1) + x;
}

bool border(int x, int y) {
	if (!in(x, y))
		return 0;

	if (x == n - 1 || x == -n + 1)
		return 1;

	if (x >= 0) 
		return (y == -(n - 1) + x || y == n - 1); 
	
	return (y == (n - 1) + x) || (y == -n + 1);
}

void solve() {
	for (int i = -n + 1; i < n; ++i)
		for (int j = -n + 1; j < n; ++j) {
			if (!border(i, j))
				continue;              
			d.clear();
			d[mp(i, j)] = 0;
			q.push({i, j});

			while (sz(q)) {
				int x = q.front().f, y = q.front().s;
				g[mp(x, y)].pb(mp(d[mp(x, y)], mp(i, j)));
				q.pop();

				for (int i = -1; i <= 1; ++i)
					for (int j = -1; j <= 1; ++j) {
						if ((i == 1 && j == -1) || (i == -1 && j == 1))
							continue;

						int tox = x + i, toy = y + j;
						if (in(tox, toy) && !d.count(mp(tox, toy))) {
							d[mp(tox, toy)] = d[mp(x, y)] + 1;
							q.push({tox, toy});
						}
				}				
			}				
		}
			
	for (int x = -n + 1; x < n; ++x)		
		for (int y = -n + 1; y < n; ++y) {
			if (!g.count(mp(x, y))) 
				continue;

			sort(all(g[mp(x, y)]));

		}

	int x = 0, y = 0;
	while (1) {
		int Nx = -inf, Ny = -inf;
		for (int i = -1; i <= 1; ++i)
			for (int j = -1; j <= 1; ++j) {
				if ((!i && !j) || (i == 1 && j == -1) || (i == -1 && j == 1))
					continue;
				int tox = x + i, toy = y + j;
				if (!in(tox, toy) || blocked.count(mp(tox, toy)))
					continue;
				Nx = tox, Ny = toy;
			}

		if (Nx == -inf)
			break;

		int bx = -inf, by = -inf;
		for (auto z : g[mp(x, y)]) {
			int cx = z.s.f, cy = z.s.s;
			if (!blocked.count(mp(cx, cy))) {
				bx = cx;
				by = cy;
				break;
			}
		}

		if (bx == -inf) {
			bx = Nx;
			by = Ny;
		}

		blocked.insert({bx, by});
		cout << bx << ' ' << by << endl;
		cin >> x >> y;
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
