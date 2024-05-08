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

ll res[N], s[N];
int n, k, prv[N];
pii a[N];
map < int, int > Cnt;
 
int cnt (int l, int r) {
	int L = lower_bound(a + 1, a + 1 + n, mp(l, 0)) - a;
	int R = upper_bound(a + 1, a + 1 + n, mp(r, inf)) - a - 1;
	if (L > R)
		return 0;
	return R - L + 1;
}

ll get (int l, int r) {
	return s[r] - s[l - 1];
}

main () {
	scanf("%d%d", &n, &k);
	k++;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].f);
		a[i].s = i;
		++Cnt[a[i].f];
	}

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i].f; 
		prv[i] = i;
		if (a[i].f == a[i - 1].f)
			prv[i] = prv[i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = inf, C1 = -1, C2 = -1, x = -1;

		while (l <= r) {
			int mid = (l + r) >> 1;	
			int c1 = cnt(a[i].f - mid, a[i].f - 1);
			int c2 = cnt(a[i].f, a[i].f + mid);

			if (c1 + c2 >= k) {
				C1 = c1;
				C2 = c2;
				x = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}

		if (C1 + C2 > k) {
			int y = min(C1 + C2 - k, Cnt[a[i].f - x]);
			C1 -= y;

			y = min(C1 + C2 - k, Cnt[a[i].f + x]);
			C2 -= y;
		}

			
		C2 = min(C2, k);
		C1 = min(C1, k - C2);
		if (C1)	
			res[a[i].s] = C1 * 1ll * a[i].f - get(prv[i] - C1, prv[i] - 1);
		res[a[i].s] += get(prv[i], prv[i] + C2 - 1) - C2 * 1ll * a[i].f;		
	}

	for (int i = 1; i <= n; ++i)
		printf("%lld ", res[i]);
}