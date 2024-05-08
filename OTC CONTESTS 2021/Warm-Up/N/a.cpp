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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int d, n, m, x[N], p[N], y[N];
vpii a;

main () {
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &x[i], &p[i]); 
		a.pb({p[i], i});
	}

	set < int > q;
	sort(all(a));
	for (auto b : a) {
		auto it = q.lower_bound(x[b.s]);
		y[b.s] = it == q.end() ? d : *it;
		q.insert(x[b.s]);
	}
	y[0] = d;

	a.clear();
	for (int i = 1; i <= m; ++i)
		a.pb({x[i], i});

	a.pb({0, 0});
	a.pb({d, 0});
	
	sort(all(a));
	ll ans = 0;

	int cur = n;
	for (int i = 0; i < sz(a) - 1; ++i) {
		if (a[i + 1].f - a[i].f > n) {
			cout << -1;
			return 0;
		}

		int w = min(n - cur, max(0, y[a[i].s] - a[i].f - cur));
//		cerr << a[i].f << ' ' << a[i].s << ' ' << y[a[i].s] << ' ' << w << endl;
		ans += p[a[i].s] * 1ll * w;
		cur += w;
		cur -= a[i + 1].f - a[i].f;
	}

	cout << ans << endl;
}