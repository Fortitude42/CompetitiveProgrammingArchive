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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = (1 << 18) + 11;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

ll t;
vpii g[N];
queue < int > q;
int n, l, x[N], d[N], y[N], a[N], b[N];

 
main () {
	scanf("%d%d%lld", &n, &l, &t);
	for (int i = 1; i <= l; ++i) {
		scanf("%d%d", &a[i - 1], &b[i - 1]);
		g[b[i - 1]].pb({a[i - 1], i});
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);        
		y[i] = x[i];
	}

	ll tt = t / l, tm = t % l;
//	cerr << tt << ' ' << tm << endl;

	for (int j = 7; j < 8; ++j) {
		memset(d, -1, sizeof(d));
		for (int i = 1; i <= n; ++i)
			if (x[i] & (1 << j)) {
				q.push(i);         
				d[i] = 0;
				cerr << i << endl;
			}

		while (sz(q)) {
			int v = q.front();
			q.pop();

			for (auto x : g[v]) {
				if (d[x.f] > -1 || d[v] > tt || (d[v] == tt && x.s > tm))
					continue;
				d[x.f] = d[v] + 1;
				q.push(x.f);
			}
		}

		for (int i = 1; i <= n; ++i)
			if (d[i] > -1)
				x[i] |= (1 << j);
	}

	for (int i = 0; i < t; ++i) 
		y[a[i % l]] |= y[b[i % l]];
	

	for (int i = 1; i <= n; ++i)
		printf("%d ", x[i]);
	printf("\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", y[i]);

	for (int i = 1; i <= n; ++i)
		cerr << x[i] << ' ';
	cerr << endl;
	for (int i = 1; i <= n; ++i)
		cerr << y[i] << ' ';
}