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
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 450;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], b[N], c[N], d[N], p[N];
vpii g[block], gg[N];
queue < int > q;
vi x, y;
 
main () {
	scanf("%d", &n);
	memset(p, -1, sizeof(p));

	
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		x.pb(a[i]);
		y.pb(b[i]);
		x.pb(c[i]);
		y.pb(d[i]);
		if (!a[i] && !b[i]) {
			q.push(i);
			p[i] = 0;
		}
	}

	sort(all(x));
	sort(all(y));

	x.resize(unique(all(x)) - x.begin());
	y.resize(unique(all(y)) - y.begin());

	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(all(x), a[i]) - x.begin();
		b[i] = lower_bound(all(y), b[i]) - y.begin();
		c[i] = lower_bound(all(x), c[i]) - x.begin();
		d[i] = lower_bound(all(y), d[i]) - y.begin();
		g[a[i] / block].pb(mp(b[i], i));
		gg[a[i]].pb(mp(b[i], i));
	}
	

	for (int i = 0; i < block; ++i) {
		sort(all(g[i]));             
		reverse(all(g[i]));
	}

	for (int i = 0; i < N; ++i) {
		sort(all(gg[i]));        
		reverse(all(gg[i]));
	}


	while (sz(q)) {
		int v = q.front();
		q.pop();
		int bl = c[v] / block;
		for (int x = 0; x < bl; ++x) {
			while (sz(g[x])) {
				if (g[x].back().f > d[v]) 
					break;
				if (p[g[x].back().s] == -1) {
					q.push(g[x].back().s);
					p[g[x].back().s] = v;
				}
				g[x].ppb();
			}
		}

		for (int x = bl*block; x <= c[v]; ++x) {
			while (sz(gg[x])) {
				if (gg[x].back().f > d[v])
					break;
				if (p[gg[x].back().s] == -1) {
					p[gg[x].back().s] = v;
					q.push(gg[x].back().s);
				}
				gg[x].ppb();
			}
		}
	}

	if (p[n] == -1) {
		cout << -1 << endl;
		return 0;
	}

	vi ans;
	while (n) {
		ans.pb(n);
		n = p[n];
	}

	reverse(all(ans));
	printf("%d\n", sz(ans));
	for (auto x : ans)
		printf("%d ", x);

}