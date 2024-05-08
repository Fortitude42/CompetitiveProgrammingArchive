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
 
int n, q, x[N], y[N], ans, pw[N];
pair < ll, int > a[N], b[N];
vpii t[N];
vi v;
 
void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}
 
void inc (int x, pii y) {
	x = N - 1 - x;
	while (x < N) {
		t[x].pb(y);		
		x |= (x + 1);
	}
}
 
void get (int x, int y) {
	x = N - 1 - x;
	while (x >= 0) {
		for (int j = 0; j < sz(t[x]) && t[x][j].f >= y; ++j)
			v.pb(t[x][j].s);
		x = (x & (x + 1)) - 1;
	}
}
 
 
main () {
	pw[0] = 1;
	for (int i = 1; i < N; ++i)
		pw[i] = pw[i - 1] * 1ll * 5782344 % mod;
 
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]); 
		y[i] += y[i];
		a[i] = {(ll)x[i] + y[i], i};
		b[i] = {(ll)x[i] - y[i], i};
	}
 
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
 
	for (int i = 1; i <= n; ++i) {
		x[a[i].s] = i;
		y[b[i].s] = i;
	}
 
	for (int i = 1; i <= n; ++i) {
		inc(x[i], {y[i], i});     		
	}
//	cerr << x[2] << ' ' << y[2] << endl;
 
	for (int i = 0; i < N; ++i) {
		sort(all(t[i]));
		reverse(all(t[i]));
	}
 
		
	while (q--) {
		int c, d;
		scanf("%d%d", &c, &d);
		x[n + 1] = (-1 - (ans + c) % mod), y[n + 1] = (ans + d) % mod;
		y[n + 1] += y[n + 1];
 
		v.clear();
		int X = lower_bound(a + 1, a + 1 + n, mp((ll)x[n + 1] + y[n + 1], 0)) - a;
		int Y = lower_bound(b + 1, b + 1 + n, mp((ll)x[n + 1] - y[n + 1], 0)) - b;
 
		get(X, Y);
		sort(all(v));
 
		ans = 0;
		for (int i = 0; i < sz(v); ++i) {
			add(ans, pw[i] * 1ll * v[i] % mod);
//			cerr << v[i] << ' ';
		}
//		cerr << endl;
		printf("%d\n", ans);
	}
	
	
}