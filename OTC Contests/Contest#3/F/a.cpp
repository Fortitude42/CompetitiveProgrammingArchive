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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, q, pos1[N];
ll a[N], b;

 
main () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &a[i]);	  
	
	for (int i = n + 1; i <= n + n ; ++i)
		a[i] = a[i - n];

	for (int i = 1; i <= n + n; ++i)
		a[i] += a[i - 1];

	while (q--) {
		scanf("%lld", &b);
		vi pos;
		for (int i = 1; i <= n; ) {
			pos.pb(i);
			int j = i;
			while (j <= n && a[j] - a[i - 1] <= b)
				++j;

			//i...j-1 -> segment
			i = j;
		}

		int l = 0, r = inf, ans = sz(pos);
		for (int i = 0; i < sz(pos) - 1; ++i) 
			if (r - l + 1 > pos[i + 1] - pos[i]) {
				l = pos[i];
				r = pos[i + 1] - 1;
			}

		if (r == inf) {
			cout << 1 << endl;
			continue;
		}




		for (int i = 1; i <= n + n; ++i)
			pos1[i] = 0;

		for (int i = l; i <= r + 1; ++i) {
			pos1[1] = i;
			int k = 1;
			while (pos1[k] <= n + i - 1) {
				++k;
				pos1[k] = max(pos1[k], pos1[k - 1]);
				while (pos1[k] <= n + i - 1 && a[pos1[k]] - a[pos1[k - 1] - 1] <= b)
					++pos1[k];
			}
						
			
			ans = min(ans, k - 1);
		}

//		cerr << endl << endl;
	
		cout << ans << endl;
	}
}