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
 

//const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int dx, dy, n, q;
int x[M], y[M], s[2003][2003];
 
void solve(int tt) {
	cin >> dx >> dy >> n >> q;
	if (!dx)
		exit(0);

	cout << "Case " << tt << ":\n";

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	while (q--) {
		for (int i = 1; i <= dx + dy; ++i)
			for (int j = 1; j <= dx + dy; ++j)
				s[i][j] = 0;

		int m;
		cin >> m;
		
		for (int i = 1; i <= n; ++i) {
			int lx = max(1, x[i] - y[i] - m + dy);
			int rx = min(dx + dy, x[i] - y[i] + m + dy);

			int ly = max(1, x[i] + y[i] - m);
			int ry = min(dx + dy, x[i] + y[i] + m);

			++s[lx][ly];
			--s[lx][ry + 1];
			--s[rx + 1][ly];
			++s[rx + 1][ry + 1];
		}

		for (int i = 1; i <= dx + dy; ++i)
			for (int j = 1; j <= dx + dy; ++j) {
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}

		pair < int, pii > ans = mp(inf, mp(0, 0));
		for (int i = 1; i <= dx; ++i)
			for (int j = 1; j <= dy; ++j) {
				int x = i - j + dy;
				int y = i + j;
				ans = min(ans, mp(-s[x][y], mp(j, i)));
			}

		cout << -ans.f << ' ' << "(" << ans.s.s << "," << ans.s.f << ")\n";

	}
	
}

main () {
	fastio
	for (int tt = 1; ; ++tt) {
		solve(tt);
	}
}
