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


int p, k, c[N], cnt, d[N];
bool was[N];

void dfs (int v) {
	was[v] = 1;
	++cnt;

	if (was[v*1ll*k % p])
		return;

	dfs(v*1ll*k % p);
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}


main () {
	cin >> p >> k;
	int ans = 1;

	for (int x = 0; x < p; ++x)
		if (!was[x]) {
			cnt = 0;
			dfs(x);
			d[cnt] += cnt;
//			cerr << cnt << endl;
		}

	for (int x = p - 1; x > 0; --x)
		for (int y = x + x; y < p; y += x)
			add(d[y], d[x]);

	memset(was, 0, sizeof(was));

	for (int x = 0; x < p; ++x)
		if (!was[x]) {
			cnt = 0;
			dfs(x);
			if (!k && !x)
				continue;
			ans = ans * 1ll * d[cnt] % mod;
		}


	cout << ans << endl;
}