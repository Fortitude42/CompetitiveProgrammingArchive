#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n;
vi v[10][N][2];

main () {
	fastio
	cin >> n;
	v[1][1][0].pb(1);
	v[1][1][1].pb(2);

	for (int i = 2; i <= n; ++i) {
		int x = 0;
		for (int j = 1; j <= (1 << (i - 1)) - 1; ++j) {
			++x;
			for (int y = 0; y < 2; ++y) {
				for (auto z : v[i - 1][j][y]) {
					v[i][x][y].pb(z);
					v[i][x][y].pb(z + (1 << (i - 1)));
				}
			}
		}

		for (int j = 1; j <= (1 << (i - 1)) - 1; ++j) {
			++x;
			for (int y = 0; y < 2; ++y) {
				for (int k = 0; k < sz(v[i - 1][j][y]); ++k) {
					v[i][x][y].pb(v[i - 1][j][y][k]);
					v[i][x][y].pb(v[i - 1][j][y ^ 1][k] + (1 << (i - 1)));
				}
			}
		}

		++x;
		for (int j = 1; j <= (1 << (i - 1)); ++j) {
			v[i][x][0].pb(j);
			v[i][x][1].pb(j + (1 << (i - 1)));
		}
	}

	cout << (1 << n) - 1 << endl;
	for (int i = 1; i <= (1 << n) - 1; ++i) {
		string S = "";
		for (int j = 1; j <= (1 << n); ++j)
			S += "A";

		for (auto j : v[n][i][0])
			S[j - 1] = 'B';
		cout << S << endl;
	}
}