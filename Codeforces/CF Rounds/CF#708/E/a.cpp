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
 
const int inf = 1e9, maxn = 1e7 + 11, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int t, n, k, a[N], lp[maxn], prv[N], p[N]; 
map < vi, int > lst, nxt;
set < vi > q;
vector < vi > vv[N];
vi v, g[N];

void precalc () {
	for (int i = 2; i < maxn; ++i)
		if (!lp[i]) {
			lp[i] = i;
			if (i < maxn / i)
				for (int j = i * i; j < maxn; j += i)
					lp[j] = i;
		}
}

inline void f (int x) {
	v.clear();
	while (x > 1) {
		int y = lp[x], cnt = 0;
		while (!(x % y)) {
			x /= y;
			cnt++;
		}

		if (cnt & 1)
			v.pb(y);
	}
	sort(all(v));
}

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;
	if (sz(vv[v]) < sz(vv[u]))
		swap(v, u);
	p[u] = v;
}

int get (int v, int u) {
	
}

main () {
	fastio
	precalc();

	cin >> t;
	while (t--) {
		int ans = 0;
		lst.clear();

		cin >> n >> k;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			vv[i].clear();
			f(a[i]);
			if (i == 1 || q.count(v)) {
				++ans;
				q.clear();
			}
			p[i] = ans;
			q.insert(v);
		}

		lst.clear();

		while (k--)  {
			pair < int, pii > mn;
			mn.f = inf;

			for (int i = 1; i <= ans; ++i)
				if (get(i) != get(i + 1)) {
					mn = min(mn, mp(get(get(i), get(i + 1)), mp(get(i), get(i + 1))));
				}
				
		}
		


		cout << ans << endl;
	}
}