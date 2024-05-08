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
 

const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int dx, dy, k;
int b, a[M][M];
bool u[M][M];
vector < pii > g[M][M][2];

 
void solve() {
	memset(a, -1, sizeof a);

	cin >> dx >> dy >> k;
	while (k--) {
		int wx, wy, b;
		cin >> wx >> wy >> b;
		memset(u, 0, sizeof u);
		while (b--) {
			int x, y;
			cin >> x >> y;
			u[x][y] = 1;
		}


		for (int x = 1; x <= dx; ++x)
			for (int y = 1; y <= dy; ++y)
				if (u[x][y]) {
					assert(a[x][y] != 0);
					a[x][y] = 1;

					if (x - wx <= dx && x - wx > 0 && y - wy > 0 && y - wy <= dy) {
						assert(a[x - wx][y - wy] != 1);
						a[x - wx][y - wy] = 0;
					}
				} else {
					if (x - wx <= 0 || y - wy <= 0 || x - wx > dx || y - wy > dy) {
						assert(a[x][y] != 1);
						a[x][y] = 0;
					} else {
						g[x - wx][y - wy][0].pb({x, y});
						g[x][y][1].pb({x - wx, y - wy});
					}
				}
	}

	queue < pii > q;
	for (int x = 1; x <= dx; ++x)
		for (int y = 1; y <= dy; ++y)
			if (a[x][y] != -1) 
				q.push({x, y});
	
	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		q.pop();
		int val = a[x][y];

		for (auto to : g[x][y][val]) {
			int tox = to.f, toy = to.s;
			assert(a[tox][toy] != (val^1));
			if (a[tox][toy] == -1) {
				q.push({tox, toy});
				a[tox][toy] = val;
			}
		}
	}


	for (int y = 1; y <= dy; ++y) {
		for (int x = 1; x <= dx; ++x)
			cout << (a[x][y] == 1 ? '#' : '.');
		cout << "\n";
	}

	cout << "\n";

	for (int y = 1; y <= dy; ++y) {
		for (int x = 1; x <= dx; ++x)
			cout << (a[x][y] != 0 ? '#' : '.');
		cout << "\n";
	}
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