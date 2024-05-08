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

int t, n, m, k, v, u, cnt[N];
unordered_map < int, int > used[N];
set < pii > q;
bool was[N];
vi g[N]; 
vpii e;


void del (int v) {
	was[v] = 1;
	q.erase(mp(cnt[v], v));

	for (auto u : g[v])
		if (!was[u]) {
			q.erase(mp(cnt[u], u));
			--cnt[u];
			q.insert(mp(cnt[u], u));
		}
}

vi solve () {
	for (int i = 1; i <= n; ++i)
		was[i] = cnt[i] = 0;

	for (auto x : e) {
		++cnt[x.f];
		++cnt[x.s];
	}

	q.clear();
	for (int i = 1; i <= n; ++i)
		q.insert(mp(cnt[i], i));

	while (sz(q)) {
		int v = q.begin()->s;
		if (cnt[v] >= k)
			break;
		del(v);
	}

	vi res;
	if (sz(q) < k)
		return res;

	for (auto x : q)
		res.pb(x.s);

	return res;		
}

bool check (vi v) {
	if (sz(v) != k)
		return 0;

	for (auto x : v)
		for (auto y : v)
			if (x != y && !used[x].count(y))
				return 0;

	return 1;
}

vi solve1 () {
	for (int i = 1; i <= n; ++i)
		was[i] = cnt[i] = 0;

	for (auto x : e)
		++cnt[x.f], ++cnt[x.s];

	q.clear();
	for (int i = 1; i <= n; ++i)
		q.insert(mp(cnt[i], i));

	while (sz(q)) {
		int v = q.begin()->s;
		if (cnt[v] >= k - 1)
			break;
		del(v);
	}
	
	while (sz(q)) {
		int v = q.begin()->s;
		if (cnt[v] < k - 1) {
			del(v);	
			continue;
		}


		vi cur;
		cur.pb(v);

		for (auto u : g[v])
			if (!was[u])
				cur.pb(u);

		assert(sz(cur) == k);

		if (!check(cur)) {
			del(v);
		} else
			return cur;
	}

	return {};
}

main () {
	cin >> t;
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);

		e.clear();
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			used[i].clear();
		}


		while (m--) {
			scanf("%d%d", &v, &u);
			g[v].pb(u);
			g[u].pb(v);
			e.pb({v, u});
			used[v][u] = used[u][v] = 1;
		}

		vi res1 = solve();

		if (sz(res1)) {
			printf("1 %d\n", sz(res1));
			for (auto x : res1)
				printf("%d ", x);
			printf("\n");
			continue;
		}
		
		res1 = solve1();
		if (sz(res1)) {
			printf("2\n");
			for (auto x : res1)
				printf("%d ", x);
			printf("\n");
			continue;
		}

		printf("-1\n");
	}                  	
}