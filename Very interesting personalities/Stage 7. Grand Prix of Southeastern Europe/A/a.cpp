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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
ll e[M][M], r[M], c[M], s[M][M];
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%lld", &e[i][j]);

	for (int i = 2; i < n; ++i) {
		r[i] = ((e[i + 1][1] - e[i][1]) - (e[i][1] - e[i - 1][1])) / 2;
		c[i] = ((e[1][i + 1] - e[1][i]) - (e[1][i] - e[1][i - 1])) / 2;
	}


	for (int x = 1; x <= n; x += (n - 1))
		for (int y = 1; y <= n; y += (n - 1)) {
			s[x][y] = e[n + 1 - x][n + 1 - y];
			for (int i = 2; i < n; ++i) {
				s[x][y] -= abs(n + 1 - x - i) * r[i]; 
				s[x][y] -= abs(n + 1 - y - i) * c[i];
			}
			s[x][y] /= (n - 1);
		}

	
	ll tot = s[1][1] + s[n][n];//r1 + rn + c1 + cn
	ll f = 0;//r1 + rn - c1 - cn
	for (int i = 2; i < n; ++i) {
		f += c[i];
		f -= r[i];
	}   	

	ll totr = (tot + f) / 2;//r1 + rn
	ll d11 = (totr - s[n][1]);//r1 - c1

	r[1] = (d11 + s[1][1]) / 2;
	r[n] = totr - r[1];
	c[1] = s[1][1] - r[1];
	c[n] = s[1][n] - r[1];

	for (int x = 1; x <= n; ++x, printf("\n"))
		for (int y = 1; y <= n; ++y) {
			ll cur = min(r[x], c[y]);
			printf("%lld ", cur);
			r[x] -= cur;
			c[y] -= cur;
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