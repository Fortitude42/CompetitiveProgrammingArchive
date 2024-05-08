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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 

struct point {
	int x, y, r, id;
	bool operator < (const point &a) const {
		if (r != a.r)
			return r > a.r;
		return id < a.id;
	}
} a[N];

int n, res[N], bl;
vpii vals;
pii b[N];
vi m[N];

inline int getId (pii x) {
 	return lower_bound(all(vals), x) - vals.begin();
}

inline bool check (int i, int j) {
	return (a[i].x - a[j].x) * 1ll * (a[i].x - a[j].x) + (a[i].y - a[j].y) * 1ll * (a[i].y - a[j].y) <= (a[i].r + a[j].r) * 1ll * (a[i].r + a[j].r);
}


inline void build () {
	vals.clear();
	for (int i = 1; i <= n; ++i)
		if (!res[a[i].id]) {
			b[i] = mp(a[i].x / bl, a[i].y / bl);
			vals.pb(b[i]);
		}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 0; i < sz(vals); ++i)
		m[i].clear();

	for (int i = 1; i <= n; ++i)
		if (!res[a[i].id])
			m[getId(b[i])].pb(i);
}

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
		a[i].id = i;
	}

	sort(a + 1, a + 1 + n);
	        	
	bl = a[1].r;
	build();

	for (int i = 1; i <= n; ++i) 
		if (!res[a[i].id]) {
			if (a[i].r + a[i].r <= bl) {
				bl = a[i].r;
				build();
			}

			vector < point > V;
			point Mn;
			Mn.r = -inf;

			for (int c = -2; c <= 2; ++c)
				for (int d = -2; d <= 2; ++d) {
				    pii cur = mp(b[i].f + c, b[i].s + d);
					int z = getId(cur);	
					if (z == sz(vals) || vals[z] != cur)
						continue;
					for (auto j : m[z])
						if (!res[a[j].id] && check(i, j)) {
							if (a[j] < Mn) 
								Mn = a[j];
							V.pb(a[j]);
						}
				}

			if (Mn < a[i]) {
				res[a[i].id] = Mn.id; 
			    continue;
			}

			res[a[i].id] = a[i].id;
			for (auto j : V)
				res[j.id] = a[i].id;
		}
	
	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
}