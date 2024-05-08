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


pii a[N];
int n, m, p[N], cnt[N];
stack < pair < int, pii > > st;
vector < pair < int, pii > > e;
 
int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

inline void merge(int v, int u, int i) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])	
		swap(v, u);

	st.push({i, {v, u}});
	cnt[v] += cnt[u];
	p[u] = v;
}

bool check(int x) {
	for (int i = 1; i <= n; ++i) {
		cnt[i] = 1;
		p[i] = i;
	}

	int v = 1;
	ll s = x;
	for (int i = 0; i < sz(e); ++i)
		merge(e[i].s.f, e[i].s.s, i);

	for (int i = 1; i <= n; ++i) {
		while (sz(st) && e[st.top().f].f < s) {
			int v = st.top().s.f, u = st.top().s.s;
			cnt[v] -= cnt[u];
			p[u] = u;
			st.pop();
		}

		if (get(v) != get(a[i].s))
			return 0;

		v = a[i].s;
		s += a[i].f;	
	}

	return 1;
}

main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].f);      
		a[i].s = i;
	}
	sort(a + 1, a + 1 + n);

	while (m--) {
		int a, b, w;                        
		scanf("%d%d%d", &a, &b, &w);
		e.pb({w, {a, b}});
	}

	sort(all(e));
	reverse(all(e));

	int l = 1, r = inf, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;	
	}


	printf("%d\n", res);
}