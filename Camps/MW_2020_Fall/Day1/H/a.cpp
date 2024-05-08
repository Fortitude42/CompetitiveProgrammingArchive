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

int n, h[N];
vi a, b;
ll ans;

ll get (int i, int j) {
	return (h[i] + h[j]) * 1ll * (j - i);
}

void calc (int l = 0, int r = sz(a) - 1, int tl = 0, int tr = sz(b) - 1) {
	if (l > r)
		return;

	int m = (l + r) >> 1, tm = -1;
	ll res = -INF;
	for (int i = tl; i <= tr; ++i)
		if (a[m] < b[i] && get(a[m], b[i]) > res) {
			res = get(a[m], b[i]);
			tm = i;
		}

	calc(l, m - 1, tl, tm);
	calc(m + 1, r, tm, tr);
	ans = max(ans, res);
}
 
main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);

	for (int i = 1; i <= n; ++i) {
		if (sz(a) && h[a.back()] >= h[i])
			continue;
		a.pb(i);
	}

	for (int i = n; i > 0; --i) {
		if (sz(b) && h[b.back()] >= h[i])	
			continue;
		b.pb(i);
	}
	reverse(all(b));

//	for (auto x : a)
//		cerr << x << ' ';

//	cerr << endl;

//	for (auto x : b)
//		cerr << x << ' ';

	calc();
	cout << ans << endl;
}
