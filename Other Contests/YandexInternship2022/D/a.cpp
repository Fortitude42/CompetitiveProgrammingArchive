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
const int N = 500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, k;
bool u[M][M], uu[M][M];
int x[M*M], y[M*M];
queue < pii > q;
 
bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i]; 
		uu[x[i]][y[i]] = u[x[i]][y[i]] = 1;
	}

	for (int i = 0; i < k; ++i) {
		int X = x[(i + 1) % k], Y = y[(i + 1) % k];				

		while (X != x[i]) {
			u[X][Y] = 1;
			if (X > x[i])
				X--;
			else
				X++;	
		}

		while (Y != y[i]) {
			u[X][Y] = 1;
			if (Y > y[i])
				Y--;
			else
				Y++;	
		}
	}

	for (int i = 0; i < k; ++i) {
		int X = x[(i + 1) % k], Y = y[(i + 1) % k];

		if (x[i] == X) {
			if (y[i] < Y) {
				if (!u[x[i] - 1][y[i] + 1]) {
					u[x[i] - 1][y[i] + 1] = 1;
					q.push({x[i] - 1, y[i] + 1});
				}
			} else {
				if (!u[x[i] + 1][y[i] - 1]) {
					u[x[i] + 1][y[i] - 1] = 1;
					q.push({x[i] + 1, y[i] - 1}); 
				}
			}
		}
		
		if (y[i] == Y) {
			if (x[i] < X) {
				if (!u[x[i] + 1][y[i] + 1]) {
					u[x[i] + 1][y[i] + 1] = 1;
					q.push({x[i] + 1, y[i] + 1});
				}
			} else {
				if (!u[x[i] - 1][y[i] - 1]) {
					u[x[i] - 1][y[i] - 1] = 1;
					q.push({x[i] - 1, y[i] - 1});
				}

			}				
		}
	}

	while (sz(q)) {
		int x = q.front().f;
		int y = q.front().s;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int tox = x + dx[i], toy = y + dy[i];
			if (in(tox, toy) && !u[tox][toy]) {
				u[tox][toy] = 1;
				q.push({tox, toy});
			}
		}
	}

	int a = 0, b = 0, c = 0, d = 0;
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= m; ++y) {
			if (!u[x][y])
				continue;

			int cnt = 0, cnt1 = 0;
			for (int i = 0; i < 4; ++i) {
				int tox = x + dx[i], toy = y + dy[i];
				if (!in(tox, toy) || !u[tox][toy])
					++cnt;					
			}

			for (int i = -1; i <= 1; i += 2)
				for (int j = -1; j <= 1; j += 2)
					if (!in(x + i, y + j) || !u[x + i][y + j])
						++cnt1;
			
			if (!cnt && !cnt1) {
				++a;             
				continue;
			}

			if (cnt == 2) {
				++c;
				continue;
			}

			if (cnt == 1) {
				++b;
				continue;
			}

			++d;
		}
	
	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}