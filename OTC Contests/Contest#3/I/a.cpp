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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int tin[N], tout[N], timer, c[N], e[N];
int n, v, u, w, cnt[N], t[N << 2];
set < pii > q;
ll d[N], ans;
vpii g[N];
vi comps;

void dfs (int v, int p = 0) {
	cnt[v] = 1;
	for (auto to : g[v])
		if (to.f != p) {
			dfs(to.f, v);
			cnt[v] += cnt[to.f];
		}		
}


void dfs1 (int v, int p = 0, int x = 0) {
	if (!x) {
		c[v] = v;
		e[v] = 2;
		q.insert(mp(2, v));
	} else
		c[v] = x;

	tin[v] = ++timer;
	ans += d[v];
	cnt[v] = 1;

	for (auto to : g[v])
		if (to.f != p) {
			d[to.f] = d[v] + to.s;
			dfs1(to.f, v, !x ? to.f : x);
			cnt[v] += cnt[to.f];
			if (!x) {
			    e[to.f] = cnt[to.f]*2;
				q.insert(mp(e[to.f], to.f));		
			}
		}

	tout[v] = timer;

	if (!x)
		tout[v] = 1;
}

void update (int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return inf;
	
	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}
            	
int Find (int v) {
	for (auto to : g[v])
		if (cnt[to.f] < cnt[v] && cnt[to.f] + cnt[to.f] > n)
			return Find(to.f);

	return v;
}
  
main () {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> v >> u >> w;
		g[v].pb({u, w});
		g[u].pb({v, w});
	}

	if (n == 1) {
		cout << 0 << endl << 1 << endl;
		return 0;
	}

	dfs(1);
	v = Find(1);
	dfs1(v);
	
	for (int i = 1; i <= n; ++i)
		update(tin[i], i);


	vi res;
	for (int i = 1; i <= n; ++i) {
		int j = -1;
		if ((*q.rbegin()).s == c[i] || (*q.rbegin()).f != n - i + 1 || (*q.rbegin()).s == v) {
			j = min(get(1, tin[c[i]] - 1), get(tout[c[i]] + 1, n));
			if (i == v)
				j = min(j, i);
		} else {
			int x = (*q.rbegin()).s;
			j = get(tin[x], tout[x]);
		}


		q.erase(mp(e[c[i]], c[i]));
		q.erase(mp(e[c[j]], c[j]));

		e[c[i]]--;
		e[c[j]]--;
		res.pb(j);

		q.insert(mp(e[c[i]], c[i]));
		q.insert(mp(e[c[j]], c[j]));

		update(tin[j], inf);
	}
	
	cout << ans*2 << endl;
	for (auto x : res)
		cout << x << ' ';
}