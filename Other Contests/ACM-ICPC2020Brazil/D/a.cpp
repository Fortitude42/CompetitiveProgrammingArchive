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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, k, a[N], b[N], c[N], d[N], z[N*3];

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

struct mat {
	int a[2][2];
	mat () {
		for (int i = 0; i < 2; ++i)	
			for (int j = 0; j < 2; ++j)
				a[i][j] = 0;
	}

	mat operator * (mat X) {
		mat res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					add(res.a[i][j], a[i][k] * 1ll * X.a[k][j] % mod);
		
		return res;
	}
};
 
main () {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] %= m;
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		b[i] %= m;
	}

	for (int i = 0; i < n; ++i) {
		c[i] = (a[i] - a[(i + 1) % n] + m) % m;
		d[i] = (-b[i] + b[(i + 1) % n] + m) % m;
	}
	
	vi v;
	for (int i = 0; i < n; ++i) 
		v.pb(c[i]);
	v.pb(-1);
	for (int i = 0; i < n; ++i)
		v.pb(d[i]);
	for (int i = 0; i < n - 1; ++i)
		v.pb(d[i]);

	int cnt = 0;
	for (int i = 1, l = 0, r = 0; i < sz(v); ++i) {
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);

		while (i + z[i] < sz(v) && v[z[i]] == v[i + z[i]])
			++z[i];                                     
		
		
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;    
		}

		if (z[i] == n)
			++cnt;
	}

	int ok = 1;
	for (int i = 0; i < n; ++i)
		if ((a[i] + b[i]) % m != (a[0] + b[0]) % m) 
			ok = 0;                                  
		
	
	cnt -= ok;
	
	int ans = 0;
	mat M, F;
	M.a[0][1] = 1;
	M.a[1][0] = n - 1;
	M.a[1][1] = n - 2;
	F.a[0][0] = 1;

	k--;

	while (k) {
		if (k & 1)
			F = F * M;
		M = M * M  ;
		k >>= 1;	
	}

//	cerr << cnt << ' ' << ok << endl;
//	for (int i = 0; i < 2; ++i, cerr << endl)
//		for (int j = 0; j < 2; ++j)	
//			cerr << F.a[i][j] << ' ';

//	for (int i = 0; i < 2; ++i, cerr << endl)
//		for (int j = 0; j < 2; ++j)	
//			cerr << F.a[i][j] << ' ';

	add(ans, F.a[0][0] * 1ll * cnt % mod);	
	add(ans, ok * 1ll * (n - 1) * F.a[0][1] % mod);
	add(ans, F.a[0][1] * 1ll * (n - 1 - cnt) % mod * cnt % mod);
	add(ans, F.a[0][1] * 1ll * cnt % mod * (cnt - 1) % mod);
	cout << ans << endl;
}