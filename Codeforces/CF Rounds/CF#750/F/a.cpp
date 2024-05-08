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
 
const int inf = 1e9, maxn = 8200, mod = 1e9 + 7, N = 8200;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vi nw[N];
int n, fst[N];
bool dp[N][N];
 

main () {
	for (int i = 0; i < N; ++i)
		fst[i] = N - 1;

	dp[0][0] = 1;
	fst[0] = 0;
	for (int i = 1; i < N; ++i)
		nw[i].pb(0);

	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		while (sz(nw[x])) {
			int y = nw[x].back();
			nw[x].ppb();
			dp[x][y] = 1;

			y ^= x;
			while (fst[y] > x) {
				nw[fst[y]].pb(y);
				fst[y]--;
			}
		}
	}

	vi ans;
	for (int i = 0; i < N; ++i)
		if (fst[i] < N - 1)
			ans.pb(i);

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ';
}