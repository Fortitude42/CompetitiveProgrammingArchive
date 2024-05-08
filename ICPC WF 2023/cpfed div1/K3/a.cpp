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
const int N = 300, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const double eps = 1e-5;

int n;
ll s[M][M];
pair < double, int > mx[M][M];
int xs[2], ys[2];

inline bool check(const double &x) {
	for (int xb = n, xa = n - 1; xb > 0; --xb, --xa) {
		if (xb == n) {
			for (int ya = 0; ya < n; ++ya)
				for (int yb = ya + 1; yb <= n; ++yb) {
					mx[ya][yb] = mp(s[xb][yb] - s[xb][ya] - 2*x*xb - 2*x*yb + 2*x*ya, xb);
					if (mx[ya][yb].f + 2*x*xa + s[xa][ya] - s[xa][yb] >= 0) {
						xs[0] = xa + 1;
						xs[1] = xb;
						ys[0] = ya + 1;
						ys[1] = yb;
						return 1;
					}
				}
		} else {
			for (int ya = 0; ya < n; ++ya)
				for (int yb = ya + 1; yb <= n; ++yb) {
					mx[ya][yb] = max(mx[ya][yb], mp(s[xb][yb] - s[xb][ya] - 2*x*xb - 2*x*yb + 2*x*ya, xb));
					if (mx[ya][yb].f + 2*x*xa + s[xa][ya] - s[xa][yb] >= 0) {
						xs[0] = xa + 1;
						xs[1] = mx[ya][yb].s;
						ys[0] = ya + 1;
						ys[1] = yb;
						return 1;
					}
				}		
		}
	}
	return 0;
}
                                
void solve(int tt) {	
	scanf("%d", &n);
	if (!n)
		exit(0);

	int mx = -inf;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int x;
			scanf("%d", &x);
			mx = max(mx, x);
			s[i][j] = x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}

	double l = mx/4.0, r = max(mx/4.0, mx*1ll*n/4.0);
	while (fabs(r - l) >= eps) {
		double mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}

	check(l);
	printf("Case #%d: The maximal value is %.7lf, rectangle corners are (%d, %d) and (%d, %d).\n", 
	tt, l, ys[0], xs[0], ys[1], xs[1]);
}

main () {
  int TT;
  TT = inf;
//  fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve(tt);
  }
}