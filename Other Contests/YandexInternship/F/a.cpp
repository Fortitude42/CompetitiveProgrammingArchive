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

int n, xa[N], ya[N], xb[N], yb[N];
set < pii > q[4];
ll res[N];


ll add (int x, int y, int i) {
	if (!x || !y)
		return 0;

	if (!sz(q[i])) {
		q[i].insert(mp(x, y));
		return x * 1ll * y;
	}

	if ((*q[i].rbegin()).f >= x) {
		pii nxt = *q[i].lower_bound(mp(x, y));
		if (nxt.s >= y)
			return 0;
	}

	ll res = 0;
	auto it = q[i].lower_bound(mp(x, inf));
	int yy = 0, xx = x;
	if (it != q[i].end())
		yy = it->s;

	while (1) {
		it = q[i].lower_bound(mp(x, inf));
		if (it == q[i].begin()) {
			res += xx * 1ll * (y - yy);
			break;
		}

		it--;
		res += (xx - it->f) * 1ll * (y - yy);
		if (it->s > y) 
			break;
		xx = it->f;
		yy = it->s;
		q[i].erase(it);
	}

	q[i].insert(mp(x, y));

/*	if (!i) {
		cerr << x << ' ' << y << endl;
	for (auto x : q[i])
		cerr << x.f << ' ' << x.s << endl;
	cerr << endl;                         }*/
	return res;
} 

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i]);
		xa[i] = -xa[i];
		ya[i] = -ya[i];
	}             

	for (int i = n; i > 0; --i) {
		res[i] += add(xa[i], ya[i], 0);
		res[i] += add(xa[i], yb[i], 1);
		res[i] += add(xb[i], ya[i], 2);
		res[i] += add(xb[i], yb[i], 3);
	}

	for (int i = 1; i <= n; ++i) {
		printf("%lld\n", res[i]);
//		cerr << res[i] << endl;
	}

} 