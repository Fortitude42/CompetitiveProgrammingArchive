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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], b[N], mn[N], mx[N], m = 4000, ans;
vi vals, v[3], u[3];
vpii c;

inline int get (int i, int j) {
	if (i > j)
		swap(i, j);
	return (a[i] + a[j]) * (j - i);
}

inline int getRand () {
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)
			res |= (1 << i);
	return res;
}

main () {
	srand(time(0));

	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);     
		vals.pb(a[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) 
		b[i] = lower_bound(all(vals), a[i]) - vals.begin();		

	for (int i = 0; i < sz(vals); ++i) {
		mn[i] = inf;                   
		mx[i] = -inf;
	}

	for (int i = 1; i <= n; ++i) {
		mx[b[i]] = max(mx[b[i]], i); 
		mn[b[i]] = min(mn[b[i]], i);
	}
		
	for (int i = 1; i <= n; ++i)
		c.pb(mp(b[i], i));

	sort(all(c));
	reverse(all(c));

	for (int i = 0; i < min(n, m); ++i) {
		v[0].pb(c[i].s);
		v[1].pb(i);
		u[0].pb(c[i].s);
		u[1].pb(n - 1 - i);
	}

	reverse(all(vals));
	for (int i = 0; i < min(sz(vals), m); ++i) {
		v[2].pb(mn[vals[i]]);
		u[2].pb(mx[vals[i]]);
	}

	
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			for (int x = 0; x < sz(v[i]); ++x)
				for (int y = 0; y < sz(u[j]); ++y) 
					ans = max(get(v[i][x], u[j][y]), ans);
				
				
	cout << ans << endl;		
}
    

