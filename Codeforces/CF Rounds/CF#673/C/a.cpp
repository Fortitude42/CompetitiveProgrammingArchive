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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], b[N], p[N], res;
ll ans;


bool cmp (int i, int j) {
	if (b[i] != b[j])
		return b[i] < b[j];
	return i < j;	
}
 
main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);       
		p[i] = i;
	}

	for (int x = 30; x >= 0; --x) {
		sort(p + 1, p + 1 + n, cmp);
		ll bal0 = 0, bal1 = 0;
		for (int i = 1; i <= n; ) {
			int j = i, cnt0 = 0, cnt1 = 0;
			while (j <= n && b[p[i]] == b[p[j]]) {
				int bit = (a[p[j]] >> x) & 1;
				if (!bit) {					
					bal0 += cnt1;
					++cnt0;
				} else {
					bal1 += cnt0;
					++cnt1;
				}

				++j;
			}
			
			i = j;
		}

		
		if (bal0 <= bal1) 
			ans += bal0;	
		else {
			ans += bal1;
			res |= (1 << x);
		}

		for (int i = 1; i <= n; ++i)
			b[i] |= (1 << x) & a[i];
	}

	cout << ans << ' ' << res << endl;
}