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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int t, n, m;
vpii c, d;
pii a[N];

bool cmp (pii a, pii b) {
	int k1 = a.f, k2 = b.f;
	k1 = max(k1, a.f - a.s + b.f);
	k2 = max(k2, b.f - b.s + a.f);
	return k1 < k2;
}

		 
main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);		

		c.clear();
		d.clear();


		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i].f, &a[i].s);
			a[i].s = min(a[i].s, m);
			if (a[i].f <= a[i].s)
				c.pb(a[i]);
			else
				d.pb(a[i]);	
		}

		sort(all(c));
		sort(all(d), cmp);

		ll h = m;

		bool ok = 1;
		
		for (int i = 0; i < sz(c); ++i) {
			if (c[i].f > h) {
				ok = 0;
				break;
			}

			h -= c[i].f;
			h += c[i].s;
		}

		
		if (!ok) {
			puts("NO");
			continue;
		}

		for (int i = 0; i < sz(d); ++i) {
			if (d[i].f > h) {
				ok = 0;
				break;
			}

			h -= d[i].f;
			h += d[i].s;
		}

		puts(ok ? "YES" : "NO");
	}
}