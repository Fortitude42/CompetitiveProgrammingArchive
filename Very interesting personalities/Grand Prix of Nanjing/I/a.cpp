//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int h, n, m;
pii a[M];
map < int, vi > g;
map < int, int > dp, lst;

int get(int x, int l, int r) {
	if (!g.count(x))
		return 0;

	int L = lower_bound(all(g[x]), l) - g[x].begin();
	int R = upper_bound(all(g[x]), r) - g[x].begin() - 1;

	if (L > R)
		return 0;
	return R - L + 1;
}

int get1(int x, int y) {
	return (0ll + (0ll + x - y + h/2) % h + h) % h;
}

int get2(int x, int y) {
	return (0ll + (0ll + x + y - h/2) % h + h) % h;
}
                                                            
void solve() {
	g.clear();
	dp.clear();
	lst.clear();

	scanf("%lld%lld", &h, &n);
	h += h;

	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].f, &a[i].s);

	scanf("%lld", &m);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		g[get1(x, y)].pb(x);
		g[get2(x, y)].pb(x);
	}

	for (auto &x : g) 
		sort(all(x.s));

	sort(a + 1, a + 1 + n);

	for (int i = n; i >= 0; --i) {
		int d1 = get1(a[i].f, a[i].s);
		int d2 = get2(a[i].f, a[i].s);

		//d1->d2
		int val = 0;

		if (!lst.count(d1)) 
			val = max(val, get(d1, a[i].f, inf + inf));
		else 
			val = max(val, dp[d1] + get(d1, a[i].f, lst[d1]));
		
		if (!lst.count(d2))
			val = max(val, get(d2, a[i].f, inf + inf));
		else
			val = max(val, dp[d2] + get(d2, a[i].f, lst[d2]));

		dp[d1] = dp[d2] = val;
		lst[d1] = lst[d2] = a[i].f;

//		cerr << i << ' ' << d1 << ' ' << d2 << ' ' << val << endl;
	}

	printf("%lld\n", dp[get1(0, 0)]);
}

main () {
	int TT;
	TT = 1;
	scanf("%lld", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
