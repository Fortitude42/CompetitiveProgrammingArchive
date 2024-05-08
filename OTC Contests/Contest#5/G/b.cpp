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

int n, k, v, u, len[N], cnt[N];
int tin[N], tout[N], timer, b[N], ans;
multiset < int > q, qq;
set < int > pos, pos1;
bool was[N];
vi g[N];

int getl (int x) {
	auto it = pos1.lower_bound(x);
	if (it == pos1.begin())
		return 1;

	--it;
	return *it + 1;
}

int getr (int x) {
	auto it = pos1.upper_bound(x);
	if (it == pos1.end())
		return n;

	return *it - 1;
}

void add (int x) {
	cout << " + " << x << endl;
	pos1.erase(x);
	int prv = -1, nxt = -1;

	auto it = pos.lower_bound(x);
	if (it != pos.end())
		nxt = *it;

	if (it != pos.begin()) {
		--it;
		prv = *it;
	}

	if (prv != -1 && nxt != -1) 
		q.erase(q.find(nxt - prv));

	if (prv != -1)
		q.insert(x - prv);

	if (nxt != -1)
		q.insert(nxt - x);
		
	pos.insert(x);


	was[x] = 1;
	int lf = getl(x), rg = getr(x);
	if (was[x - 1]) 
		qq.erase(qq.find(x - 1 - lf));
	

	if (was[x + 1]) 
		qq.erase(qq.find(rg - x - 1));

	qq.insert(rg - lf);			
}

void del (int x) {
	cout << " - " << x << endl;
	pos1.insert(x);
	pos.erase(x);
	
	int prv = -1, nxt = -1;
	auto it = pos.lower_bound(x);
	if (it != pos.end()) 
		nxt = *it;

	if (it != pos.begin()) {
		it--;
		prv = *it;
	}
	
	if (prv != -1)
		q.erase(q.find(x - prv));

	if (nxt != -1)
		q.erase(q.find(nxt - x));

	if (prv != -1 && nxt != -1)
		q.insert(nxt - prv);

	was[x] = 0;
	int lf = getl(x), rg = getr(x);

	if (was[x - 1]) 
		qq.insert(x - 1 - lf);
	

	if (was[x + 1]) 
		qq.insert(rg - x - 1);
	
	qq.erase(qq.find(rg - lf));
}

void dfsSz (int v, int p = 0) {
	cnt[v] = 1;
	tin[v] = ++timer;
	b[timer] = v;

	for (auto to : g[v])
		if (to != p) {
			dfsSz(to, v);
			cnt[v] += cnt[to];
		}

	tout[v] = timer;
}


void dfs (int v, int p = 0, int cl = 0) {
	int big = -1;

	for (auto to : g[v])
		if (to != p && (big == -1 || cnt[big] < cnt[to])) 
			big = to;
	
	for (auto to : g[v])
		if (to != p && to != big)
			dfs(to, v, 1);

	if (big != -1)
		dfs(big, v, 0);

	for (auto to : g[v])
		if (to != p && to != big)
			for (int x = tin[to]; x <= tout[to]; ++x)
				add(b[x]);

	add(v);

	if (cnt[v] <= k && sz(qq)) 
		ans = max(ans, *qq.rbegin() + 1);
	

	if (n - cnt[v] <= k && sz(q)) 
		ans = max(ans, *q.rbegin() - 1);
	
	if (cl) 
		for (int x = tin[v]; x <= tout[v]; ++x)
			del(b[x]);	
}
 
main () {
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}

	dfsSz(1);

	for (int i = 1; i <= n; ++i)
		pos1.insert(i);

	dfs(1);

	cout << ans << endl;
}