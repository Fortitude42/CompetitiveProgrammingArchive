#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
vi vals;
int n, h[N], w[N], p[N], sum, ans;
map < int, vi > g;
bool was[N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}

	return res;
}

int f (int x) {
	x %= mod;
	return x * (x + 1) % mod * binpow(2, mod - 2) % mod;
}

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u) {
	v = get(v), u = get(u);
	if (rand() & 1)
		swap(v, u);
	p[u] = v;
	sum -= f(w[v]);
	sum -= f(w[u]);
	w[v] += w[u];
	sum += f(w[v]);
	sum %= mod;
}




main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		vals.pb(h[i]);
		p[i] = i;
	}

	vals.pb(0);

	for (int i = 1; i <= n; ++i) {
		cin >> w[i];               
		g[h[i]].pb(i);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	reverse(all(vals));
		
	for (int i = 0; i < sz(vals) - 1; ++i) {
		for (auto j : g[vals[i]]) {
			sum += f(w[j]);
			was[j] = 1;
			if (was[j - 1])
				merge(j, j - 1);
			if (was[j + 1])
				merge(j, j + 1);
//			cerr << i << ' ' << j << endl;	
		}

//		cerr << sum << ' ' << ff(vals[i]) << ' ' << ff(vals[i + 1]) << endl;
                               
		ans += sum % mod * ((f(vals[i]) - f(vals[i + 1])) % mod) % mod;
		ans %= mod;
	}

	cout << (ans + mod) % mod << endl;
}