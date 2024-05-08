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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


vi ans;
pii a[N];
int n, b[N];
set < int > q;
ll dpL[N], dpR[N]; 

int getPrv (int x) {
	if (!sz(q) || *q.begin() > x)
		return 0;
	auto it = q.lower_bound(x);
	--it;
	return *it;
}

int getNxt (int x) {
	if (!sz(q) || *q.rbegin() < x)
		return n + 1;

	return *q.lower_bound(x);
}

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		a[i] = mp(b[i], i);
	}

	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);

	for (int i = 1; i <= n; ++i) {
		int j = a[i].s;
		int x = getPrv(j), y = getNxt(j);
		dpL[j] = dpR[j] = INF;

		if (x != 0) {
			dpR[j] = max(0ll, (dpR[x] + b[x]) - (b[j] + (j - x)));
			dpL[j] = max(0ll, (dpR[x] + b[x]) - b[j] - 1);
		}		

		if (y != n + 1) {
			dpL[j] = min(dpL[j], max(0ll, (dpL[y] + b[y]) - (b[j] + (y - j))));
			dpR[j] = min(dpR[j], max(0ll, (dpL[y] + b[y]) - b[j] - 1));
		}

		if (!x && y == n + 1)
			dpL[j] = dpR[j] = 0;

		int cur = b[j] + (y - x - 2);
//		cerr << j << ' ' << dpL[j] << ' ' << dpR[j] << ' ' << cur << endl;

		if ((x == 0 && y == n + 1) || (x != 0 && b[x] + dpR[x] <= cur) || (y != n + 1 && b[y] + dpL[y] <= cur))
			ans.pb(j);         

		q.insert(j);
	}
	

	sort(all(ans));
	printf("%d\n", sz(ans));
	for (auto x : ans)
		printf("%d ", x);
}