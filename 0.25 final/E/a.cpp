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
 
typedef 	tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, c, a[N], b[N], w[N], cnt[N];
vpii g[N], gg[N];
set < int > q;
vi vals, ans;
bool was[N];

void dfs (int v, int cc = -1) {
	for (auto to : g[v])
		if (!was[to.s]) {
			was[to.s] = 1;
			dfs(to.f, to.s);
		}

	for (int i = 0; i < sz(g[v]); ++i) {
		int to = g[v][i].s;

	}


	while (sz(q)) {
		auto it = q.begin();
		if (*it == v)
			++it;

		if (it == q.end())
			break;
		int u = *it;

		for (auto x : gg[u]) 
			ans.pb(x.s);		

		q.erase(it);
	}

	if (cc != -1)
		ans.pb(cc);
}

main () {
	scanf("%d%d", &n, &c);

	vals.pb(c);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &w[i]);
		vals.pb(a[i]);
		vals.pb(b[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	c = lower_bound(all(vals), c) - vals.begin();
	q.insert(c);


	for (int i = 1; i <= n; ++i){ 
		a[i] = lower_bound(all(vals), a[i]) - vals.begin();
		b[i] = lower_bound(all(vals), b[i]) - vals.begin();	

		if (w[i])
			g[a[i]].pb(mp(b[i], i));
		else
			gg[a[i]].pb(mp(b[i], i));

		q.insert(a[i]);
		q.insert(b[i]);
		cnt[b[i]] += w[i];
	}

	int cnt1 = 0, cnt2 = 0;

	for (auto x : q)
		if (abs(cnt[x] - sz(g[x])) <= 1) {
			if (cnt[x] - sz(g[x]) == 0)
				continue;
			if (cnt[x] - sz(g[x]) == 1)
				++cnt1;
			if (cnt[x] - sz(g[x]) == -1)
				++cnt2;					
		} else {
			cout << "No\n";
			return 0;
		}

	if (cnt1 > 1 || cnt2 > 1) {
		cout << "No";
		return 0;
	}

	
	if (cnt1 == 1) {
		if (sz(g[c]) - cnt[c] != 1) {
			cout << "No\n";
			return 0;
		}
	}
		


	dfs(c);
	reverse(all(ans));

	if (sz(ans) != n)
		cout << "No\n";
	else {
		printf("Yes\n");
		for (auto x : ans)
			printf("%d ", x);
	}	
		
}