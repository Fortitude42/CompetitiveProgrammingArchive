#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = (1 << 12) + 11;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, a[20], dp[44][N], cmask[50];
set < pair < int, pii > > q;

main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		for (int i = 0; i < 40; ++i)
			for (int mask = 0; mask < (1 << n); ++mask)
				dp[i][mask] = INF;
		
		for (int i = 0; i < 40; ++i) {
			cmask[i] = 0;
			for (int j = 0; j < n; ++j)
				if (a[j] & (1ll << i))
					cmask[i] |= (1ll << j);
		}


		dp[0][cmask[0]] = 0;
		q.insert(mp(dp[0][cmask[0]], mp(0, cmask[0])));
		
		while (sz(q)) {
			pair < int, pii > cur = *q.begin();
			q.erase(q.begin());
			
			int c = cur.f;
			int i = cur.s.f;
			int mask = cur.s.s;
			if (c == 4)
				break;

			if (i == 4 && __builtin_popcount(mask) % 2 == 0) {
				cout << c << endl;
				break;
			}
						

			for (int j = 0; j < n; ++j)
				if (!(mask & (1 << j))) {
					if (dp[i][mask | (1 << j)] > c + (1ll << i)) {
						q.erase(mp(dp[i][mask | (1 << j)], mp(i, mask | (1 << j))));
						dp[i][mask | (1 << j)] = c + (1ll << i);
						q.insert(mp(dp[i][mask | (1 << j)], mp(i, mask | (1 << j))));
					}
				}

			for (int tmask = mask; tmask >= 0; tmask = (tmask - 1) & mask) {
				if ((__builtin_popcount(mask ^ tmask) & 1) == 0) {
					int cur = c + __builtin_popcount(tmask) * (1ll << i);
					if (dp[i + 1][cmask[i + 1] ^ tmask] > cur) {
						q.erase(mp(dp[i + 1][cmask[i + 1] ^ tmask], mp(i + 1, cmask[i +  1] ^ tmask)));
						dp[i + 1][cmask[i + 1] ^ tmask] = cur;
						q.insert(mp(dp[i + 1][cmask[i + 1] ^ tmask], mp(i + 1, cmask[i +  1] ^ tmask)));
					}
				}

				if (tmask == 0)
					break;
			}			
		}

		q.clear();
	}
}