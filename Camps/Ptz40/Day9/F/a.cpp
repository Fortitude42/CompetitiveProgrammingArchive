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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

bool was[N];
vector < pii > g[N];
int n, m, q, v, u, R, l, r;
int w, B[40], d[N], s[N][40];

void write (int x) {
	for (int j = 30; j >= 0; --j)
		if (x & (1 << j))
			cerr << 1;
		else
			cerr << 0;	

	cerr << endl;
}
                
void add (int v) {

	for (int i = 30; i >= 0; --i)
		if ((v & (1 << i))) {
			if (!B[i]) {
				B[i] = v;
				break;
			}

			v ^= B[i];
		}
}


int get (int x) {
	for (int i = 30; i >= 0; --i)
		if (x & (1 << i))
			x ^= B[i];

	return x;
}

void dfs (int v, int p = 0) {
	was[v] = 1;

	for (auto x : g[v]) {
	    int to = x.f;
	    int w = x.s;

		if (!was[to]) {
			d[to] = d[v] ^ w;
			dfs(to, v);
		} else if (to != p) 
			add(d[to] ^ d[v] ^ w);
	}
		
}

int get (int l, int r, int j) {
	return s[r][j] - s[l - 1][j];
}


int f (int l, int r) {
	ll m = (r - l + 1);
	m = m * (m - 1) / 2;
	int res = 0;
	if (m & 1)
		res = R;

	for (int j = 0; j <= 30; ++j) {
		int n1 = get(l, r, j);
		int n0 = r - l + 1 - n1;

		if (((n0 & 1) * (n1 & 1)) & 1)
			res ^= (1 << j);			
	}
	
	return res;
}
 
main () {
	scanf("%d%d%d", &n, &m, &q);
	while (m--) {
		scanf("%d%d%d", &v, &u, &w);
		g[v].pb({u, w});
		g[u].pb({v, w});
	}

	dfs(1);

	for (int i = 1; i <= n; ++i)	 {
	    d[i] = get(d[i]);
		for (int j = 30; j >= 0; --j) 
			s[i][j] = s[i - 1][j] + ((d[i] >> j) & 1);
	}

	for (int j = 30; j >= 0; --j)
		if (!((R >> j) & 1))
			R ^= B[j];


	while (q--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", f(l, r));
	}

}