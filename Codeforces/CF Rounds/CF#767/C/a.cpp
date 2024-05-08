//template by paradox & gege & parasat
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

int t, n, a[M][M], b[M][M];
 
bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]); 
			b[i][j] = 0;
		}
	
	for (int s = 1; s <= n + n; ++s)
		for (int i = 1; i < min(n + 1, s); ++i) {
			int j = s - i;
			if (j > n)
				continue;

			if (i > 1) {
				int s = 0;
				for (int x = 0; x < 4; ++x) {
					int toi = i - 1 + dx[x], toj = j + dy[x];
					if (in(toi, toj))
						s ^= b[toi][toj];
				}

				if (!s)
					b[i][j] = 1;
			}			
		}



	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int s = 0;
			for (int x = 0; x < 4; ++x) {
				int toi = i + dx[x], toj = j + dy[x];
				if (in(toi, toj))
					s ^= b[toi][toj];
			}

			assert(s == 1);
		}


	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (b[i][j])
				res ^= a[i][j];

	cout << res << endl;
}

main () {
	int TT;
	TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}