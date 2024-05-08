#include "split.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

using namespace std;

int n, m, cnt[N], tin[N], tout[N], timer, par[N];
int A, B, C, a, b, c;
pair < int, pii > T;
vi g[N], res;

void dfs (int v) {
	tin[v] = ++timer;
	cnt[v] = 1;
	for (auto to : g[v])
		if (!cnt[to]) {
			dfs(to);   
			cnt[v] += cnt[to];
			par[to] = v;
		}

	tout[v] = timer;
}


bool upper (int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}


bool check (int v) {
	if ((!T.s.s && upper(T.s.f, v)) || (T.s.s && !upper(T.s.f, v)))
		return 0;
	return 1;
}

void dfs1 (int v, int c, int &x) {
	if (!x)
		return;

	--x;			
	res[v] = c;
	for (auto to : g[v])
		if (check(to) && !res[to]) 
			dfs1(to, c, x);		
}

void dfs2 (int v, int c, int &x) {
	if (!x)
		return;
	--x;
	res[v] = c;
	for (auto to : g[v])
		if (!res[to])
			dfs2(to, c, x);
}

vi solve (int r) {
	res.resize(n, 0);
	for (int i = 0; i < n; ++i)
		cnt[i] = 0;

	timer = 0;
	dfs(r);
	
	T = {inf, {inf, inf}};

	for (int i = 0; i < n; ++i) {
		if (cnt[i] >= a)
			T = min(T, mp(cnt[i], mp(i, 0)));
		if (n - cnt[i] >= a)
			T = min(T, mp(n - cnt[i], mp(i, 1)));
	}

	if (n - T.f < b)  
		return res;	
			
	int root = 0;
	while (!check(root))
		++root;
	int a1 = a, b1 = b;

	dfs1(root, B, b1);
	dfs2(!T.s.s ? T.s.f : par[T.s.f], A, a1);
	
	for (int i = 0; i < n; ++i)
		if (!res[i])
			res[i] = C;

	return res;

}


vi find_split(int _n, int _a, int _b, int _c, vi p, vi q) {
	n = _n;
	m = sz(p);
	for (int i = 0; i < m; ++i) {
		g[p[i]].pb(q[i]);
		g[q[i]].pb(p[i]);
	}
	
	A = 1, B = 2, C = 3;
	a = _a, b = _b, c = _c;

	if (a > b && a > c) {
	    swap(A, C);
		swap(a, c);      
	}
	
	if (b > a && b > c) {
		swap(b, c);      
		swap(B, C);
	}

	if (a > b) {
		swap(a, b);
		swap(A, B);
	}

	if (n > 2500)
		return solve(0);
	
	for (int i = 0; i < n; ++i) {
		vi v = solve(i);
		if (v[0])
			return v;
	}

	return solve(0);		
}

