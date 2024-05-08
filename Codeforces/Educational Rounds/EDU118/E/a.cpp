//by parasat
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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, xs, ys;
vi was[M], u[M];
queue < pii > q;

bool in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

bool check(int x, int y) {
	if (!in(x, y) || u[x][y] || was[x][y])
		return 0;

	int cnt = 0;

	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		if (in(tox, toy) && !u[tox][toy] && !was[tox][toy])
			++cnt;
	}

	return cnt <= 1;
}

 
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		was[i].resize(m + 1);
		u[i].resize(m + 1);
		scanf("\n");
		for (int j = 1; j <= m; ++j) {
			char c;
			scanf("%c", &c);
			was[i][j] = (c == '#');
			u[i][j] = 0;
			if (c == 'L') {
				xs = i;
				ys = j;
				u[i][j] = 1;
				q.push({i, j});
			}
		}
	}

	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int tox = x + dx[i], toy = y + dy[i];
			if (check(tox, toy)) {
				u[tox][toy] = 1;
				q.push({tox, toy});
			}				
		}
	}   


	for (int i = 1; i <= n; ++i, printf("\n"))
		for (int j = 1; j <= m; ++j) {
			if (was[i][j])
				printf("#");
			else if (i == xs && j == ys)	
				printf("L");
			else if (u[i][j])
				printf("+");
			else
				printf(".");
		}

}

main () {
	int TT;
	TT = 1;
  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}