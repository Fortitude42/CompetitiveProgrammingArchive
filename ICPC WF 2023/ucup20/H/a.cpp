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
const int N = 1000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;                     	

//vector < pii > v = {{15, 0}, {0, 15}, {12, 9}, {9, 12}};
vector < pii > v = {{0, 2}, {2, 0}};
//vector < pii > v = {{3, 21}, {21, 3}, {15, 15}};

bool used[M][M]; 

bool in(int x, int y) {
	return x > 0 && y > 0 && x <= N && y <= N;
}

void bfs(int x, int y) {
	queue < pii > q;
	used[x][y] = 1;
	q.push({x, y});

	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		q.pop();
		for (auto [dx, dy] : v) {
			for (int cx = -1; cx <= 1; cx += 2)
				for (int cy = -1; cy <= 1; cy += 2) {
				    int tox = x + cx*dx, toy = y + cy*dy;
					if (in(tox, toy) && !used[tox][toy]) {
						q.push({tox, toy});
						used[tox][toy] = 1;
					}
				}
		}
	}
}

void solve() {
	int k = 0;
	for (int x = 1; x <= N; ++x)
		for (int y = 1; y <= N; ++y)
			if (!used[x][y]) {
				k++;
				bfs(x, y);
			}

	cout << k << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}