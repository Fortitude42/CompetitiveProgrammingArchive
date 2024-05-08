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
const int N = 5e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, mx[M][M], t[M], timer, rg[M][M];
bool used[M];
int d[M], a[M];
 
void solve() {	
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			rg[i][j] = inf;
					

	for (int l = 1; l <= n; ++l) {		
		++timer;
		for (int r = l; r <= n; ++r) {
			mx[l][r] = mx[l][r - 1];
			t[a[r]] = timer;
			while (t[mx[l][r]] == timer)
				++mx[l][r];
			rg[mx[l][r]][l] = min(rg[mx[l][r]][l], r);
//			cout << l << ' ' << r << ' ' << mx[l][r] << endl;
		}
	}

	for (int mx = 0; mx <= n; ++mx)
		for (int l = n - 1; l > 0; --l)
			rg[mx][l] = min(rg[mx][l], rg[mx][l + 1]);

	for (int i = 0; i <= n; ++i) {
		d[i] = inf;
		used[i] = 0;
	}

	d[0] = 0;
	int ans = 0;

	while (1) {
		int j = -1;
		for (int i = 0; i <= n; ++i)
			if (!used[i] && (j == -1 || d[i] < d[j]))
				j = i;

		if (j == -1 || d[j] == inf)
			break;

//		cerr << j << ' ' << d[j] << endl;

		used[j] = 1;
		if (d[j] + 1 <= n) {
			for (int mx = 0; mx <= n; ++mx)
				d[j^mx] = min(d[j^mx], rg[mx][d[j] + 1]);
		}
		ans = max(ans, j);
	}
	
	cout << ans << endl;
}

main () {
  int TT;
  TT = 1;
  	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}