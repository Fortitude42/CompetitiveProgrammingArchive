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
const int N = 4000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int h, w, g;
int a[M][52];
bool was[52][52][52][4][4];
 
void solve() {
	cin >> h >> w;
	g = __gcd(h, w);

	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j) {
			char c;
			cin >> c;
			if (c == 'w')
				a[i][j] = 0;
			if (c == 'b')
				a[i][j] = 1;
			if (c == 'r')
				a[i][j] = 2;
			if (c == 'g')
				a[i][j] = 3;
		}

	for (int i1 = 1; i1 <= h; ++i1)
		for (int j1 = 1; j1 <= w; ++j1)
			for (int j2 = 1; j2 <= w; ++j2)
				was[j1][j2][i1 % g][a[i1][j1]][a[i1][j2]] = 1;


	for (int i1 = 1; i1 <= h; ++i1)
		for (int j1 = 1; j1 <= w; ++j1)
			for (int j2 = 1; j2 <= w; ++j2)
				if (a[i1][j1] != a[i1][j2]) {
					int x = (((i1 + j2 - j1) % g) + g) % g;
					vi vals;
					for (int c = 0; c < 4; ++c)
						if (a[i1][j1] != c && a[i1][j2] != c)
							vals.pb(c);

					if ((was[j1][j2][x][vals[0]][vals[1]]) ||
						(was[j1][j2][x][vals[1]][vals[0]])) {
							cout << "possible";
							return;
						}
				}

	cout << "impossible";
	
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}