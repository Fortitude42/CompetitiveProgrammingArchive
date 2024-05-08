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
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, s, d, c;
bitset < N > sw[N], tmp, tmp1;
unordered_map < bitset < N >, int > M;

main () {
	scanf("%d%d%d", &n, &s, &d);

	for (int i = 0; i < s; ++i) {
		scanf("%d", &c);
		for (int j = 0, x; j < c; ++j) {
			scanf("%d", &x);
			--x;
			sw[i][x] = 1;
		}
	}

	int m1 = min(20, s);
	int m2 = s - m1;

	for (int mask = 0; mask < (1 << m1); ++mask) {
		tmp.reset();

		for (int i = 0; i < m1; ++i)
			if (mask & (1 << i)) 
				tmp ^= sw[i];

		if (!M.count(tmp) || M[tmp] > __builtin_popcount(mask))
			M[tmp] = __builtin_popcount(mask);
	}	
	
	while (d--) {
		scanf("%d", &c);
		tmp.reset();
		for (int i = 0, x; i < c; ++i) {
			scanf("%d", &x);
			--x;
			tmp[x] = 1;
		}

		int ans = inf;


		for (int mask = 0; mask < (1 << m2); ++mask) {			
			tmp1 = tmp;

			for (int i = 0; i < m2; ++i)
				if (mask & (1 << i))
					tmp1 ^= sw[i + m1];

			if (M.count(tmp1))
				ans = min(ans, __builtin_popcount(mask) + M[tmp1]);
		}

		if (ans == inf)
			ans = -1;
		printf("%d\n", ans);
	}
}