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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, k, f[M][4], g[M], s1;
string s[M];
int p[M];


void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}


void dec(int &x, int y) {
	x -= y;
	if (x < 0)
		x += MOD;
}
 
void solve() {
	fastio
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	p[0] = 1;
	for (int i = 1; i < n; ++i)
		p[i] = p[i - 1] * 1ll * 71 % MOD;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			add(f[j][s[i][j] - 'A'], p[i]);

	for (int j = 0; j < m; ++j)
		for (int i = 0; i < 4; ++i)
			add(g[j], f[j][i]);

	for (int i = 0; i < n; ++i)
		add(s1, p[i]);
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			add(sum, g[j]);
			dec(sum, f[j][s[i][j] - 'A']);
		}

		int s2 = s1 - p[i];
		if (s2 < 0)
			s2 += MOD;
		s2 = s2 * 1ll * k % MOD;
		if (sum == s2) {
			cout << i + 1 << "\n";
			return;
		}
			
	}
}



main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}