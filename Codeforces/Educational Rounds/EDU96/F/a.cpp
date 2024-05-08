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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, x[N], y[N], m, l[N], r[N];
ll a[N], z[N], b[N];
 
main () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) 
		cin >> x[i] >> y[i] >> z[i];
	

	int i = 1;
	while (i <= n) {
		b[++m] = y[i] - x[i];
		a[m] = z[i];
		while (i + 1 <= n && y[i] == x[i + 1]) {
			a[m] += z[i + 1];
			b[m] += y[i + 1] - x[i + 1];
			++i;
		}

		++i;
	}

	//i = 1... m, a[i] - a nummber of monters, b[i] - an amount of time
	for (int i = 1; i <= n; ++i)
		if (b[i] * k < a[i]) {
			cout << -1 << endl;
			return 0;
		}

	int rest = k;
	ll ans = 0;

	for (int i = 1; i <= m; ++i) {
		int fst = min(rest, a[i]);
		a[i] -= fst;
		rest -= fst;

		if (a[i]) {
			ans += (a[i] + k - 1) / k;
			rest = (k - a[i] % k);
		}		
	}

	cout << ans << endl;

}