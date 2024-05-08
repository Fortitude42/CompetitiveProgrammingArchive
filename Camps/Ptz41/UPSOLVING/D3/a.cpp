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
 
const int inf = 1e9, maxn = 1e3 + 48, mod = 1e9 + 7, N = 4012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


pii  val[N*N/4];
queue < pii > q;
int n, c[N][N/2];
bitset < N / 2 > was[N], was1[N], used[N], used1[N];
 
inline void f(int l, int r) {
	was[l][r / 2] = 1;
	was1[l][r / 2] = 0;
	used[r][l / 2] = 1;
	used1[r][l / 2] = 0;
}

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; j += 2) {
			scanf("%d", &c[i][j / 2]);	 
			val[c[i][j / 2]] = {i, j};
			was1[i][j / 2] = 1;
			used1[j][i / 2] = 1;
		}


	for (int x = 1; 4*x <= (n*n); ++x) {
		int l = val[x].f, r = val[x].s;
		if (!was[l][r / 2] && (l == r - 1 || was[l + 1][(r - 1) / 2])) {
			q.push({l, r});
			f(l, r);
		}

				
		while (sz(q)) {
			l = q.front().f, r = q.front().s;
			q.pop();
			if (l == 1 && r == n) {
				cout << x << endl;
				return 0;
			}

			if (!was[l - 1][(r + 1) / 2] && l > 1 && r < n && c[l - 1][(r + 1) / 2] <= x) {
				q.push({l - 1, r + 1});
				f(l - 1, r + 1);
			}

			was[n + 1] = (was1[l] & was[r + 1]);

			for (int i = was[n + 1]._Find_next(r / 2); i < sz(was[n + 1]); i = was[n + 1]._Find_next(i)) {
				assert(!was[l][i]);
				f(l, i*2 + (r % 2));
				q.push({l, i*2 + (r % 2)});
			}

			used[n + 1] = (used1[r] & used[l - 1]);
			for (int i = used[n + 1]._Find_first(); i*2 + (l % 2) < l; i = used[n + 1]._Find_next(i)) {
				assert(!was[i*2 + (l % 2)][r / 2]);
				f(i*2 + (l % 2), r);
				q.push({i*2 + (l % 2), r});
			}
		}
	}
}