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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353 , N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, a[N], b[N], pos[N], t; 
set < int > q;
bool bad[N];

int getNxt (int v) {
	if (*q.rbegin() <= v)
		return -1;

	return *q.upper_bound(v);
}

int getPrv (int v) {
	if (*q.begin() >= v)
		return -1;

	auto it = q.lower_bound(v);
	--it;

	return *it;
}

main () {
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);       
			pos[a[i]] = i;
			bad[i] = 0;	
		}

		q.clear();

		for (int i = 1; i <= k; ++i) {
			scanf("%d", &b[i]);       
			b[i] = pos[b[i]];	
			bad[b[i]] = 1;
		}

		for (int i = 1; i <= n; ++i)
			q.insert(i);

		int ans = 1;	
		

		for (int i = 1; i <= k; ++i) {
			int v = getPrv(b[i]), u = getNxt(b[i]);
			int cnt = (v != -1 && !bad[v]) + (u != -1 && !bad[u]);
//			cerr << v << ' ' << u << ' ' << cnt << endl;

			ans = ans * 1ll * cnt % mod;
			bad[b[i]] = 0;

			if (!cnt)
				break;

			if (v != -1 && !bad[v])
				q.erase(v);
			else
				q.erase(u);	
		}

		cout << ans << endl;
	}
}