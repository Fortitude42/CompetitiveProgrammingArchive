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

int n;
vector < pair < int, ll > > v;
 
 
struct line {
	int k;
	ll b;
	line () {
		k = b = 0;
	}		
	line (int k1, ll b1) {
		k = k1, b = b1;	
	}
};
 
vector < line > lines;
 
 
db inter (line A, line B) {
	return (1.0 * (B.b - A.b) / (1.0 * (A.k - B.k)));	
}
 
void add (line cur) {
	while (lines.size() > 1 && inter(cur, lines.back()) < inter(lines.back(), lines[lines.size() - 2]))
		lines.ppb();
	lines.pb(cur);
}
 
 
ll get (int x) {
	int l = 1, r = lines.size() - 1, res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (inter(lines[mid], lines[mid - 1]) <= x + 0.0) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;
	}
 
	return x*lines[res].k + lines[res].b;
}


main () {
	scanf("%lld", &n);
	v.pb({1, 0});
	while (n--) {
		int a, b, x;
		scanf("%lld%lld%lld", &a, &b, &x);
		v.pb({a, x});
		v.pb({b, x});
	}

	sort(all(v));
	int n = sz(v);

	for (int i = 1; i < n; ++i)  
		v[i].s += v[i - 1].s;

	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1 || v[i].f != v[i + 1].f)
			add(*new line(4*v[i].f, -v[i].s*2)); 			
	}



	ll ans = -INF*8;

	for (int i = 0; i < n; ++i) {
		ans = max(ans, -2*(v.back().s - v[i].s) - get(v[i].f)); 
	}



	cout << fixed << setprecision(6) << (ans + 0.0) / 4;
}