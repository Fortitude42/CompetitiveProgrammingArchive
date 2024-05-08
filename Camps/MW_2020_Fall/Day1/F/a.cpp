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
 
const int inf = 1e9, maxn = 2048, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m;
ll s[maxn];

struct query {
	int l, r, id;
	ll s;
	
	bool operator < (const query &x) const {
		return s < x.s;
	}

} b[N];

ll t[maxn][maxn], res[N];

void inc1 (int x, int y, ll z) {
	while (y < maxn) {
		t[x][y] = max(t[x][y], z);
		y |= y + 1;
	}
}

ll get1 (int x, int y) {
	ll res = -INF;
	while (y >= 0) {
		res = max(res, t[x][y]);
		y = (y & (y + 1)) - 1;
	}	
	return res;
}

void inc (int x, int y, ll z) {
	x = maxn - x - 1;

	while (x < maxn) {
		inc1(x, y, z);
		x |= x + 1;
	}
}

ll get (int x, int y) {
	x = maxn - x - 1;

	ll res = -INF;
	while (x >= 0) {
		res = max(res, get1(x, y));
		x = (x & (x + 1)) - 1;
	}
	return res;
}

vector < pair < ll, pii > > v;
 
main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}

	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%lld", &b[i].l, &b[i].r, &b[i].s);
		b[i].id = i;
	}

	sort(b + 1, b + 1 + m);

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			v.pb(mp(s[j] - s[i - 1], mp(i, j)));

	sort(all(v));

	int j = 0;
	for (int i = 0; i < maxn; ++i)
		for (int j = 0; j < maxn; ++j)
			t[i][j] = -INF;


	for (int i = 1; i <= m; ++i) {
		while (j < sz(v) && b[i].s >= v[j].f) {
			inc(v[j].s.f, v[j].s.s, v[j].f);
			++j;
		}

		res[b[i].id] = get(b[i].l, b[i].r);
	}
			            
	for (int i = 1; i <= m; ++i) {
	    if (res[i] == -INF)
	    	printf("NONE\n");
	    else
			printf("%lld\n", res[i]);
	}
}
