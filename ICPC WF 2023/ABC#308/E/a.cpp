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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, prefm[M][3], suffx[M][3];
int a[M];
string s;
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> s;
	s = "#" + s;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			prefm[i][j] = prefm[i - 1][j];
		if (s[i] == 'M')
			prefm[i][a[i]]++;
	}

	for (int i = n; i > 0; --i) {
		for (int j = 0; j < 3; ++j)
			suffx[i][j] = suffx[i + 1][j];
		if (s[i] == 'X')
			suffx[i][a[i]]++;
	}


	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != 'E')
			continue;
		for (int m = 0; m < 3; ++m)
			for (int x = 0; x < 3; ++x) {
				ll v = prefm[i][m] * 1ll * suffx[i][x];
				if (!v)
					continue;
				int mex = 0;
				while (mex == m || mex == x || mex == a[i])
					++mex;
				ans += v*mex;
			}
	}

	cout << ans << endl;

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