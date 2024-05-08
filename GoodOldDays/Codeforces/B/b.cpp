#include <bits/stdc++.h>
 
#define f first
#define s second     
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef pair<int, int> pii;
 
const int N = 100500, LOG = 17, inf = 1e9;
 
vector< int > g[N];
int n, q, ans, tin[N], tout[N], timer, sz[N], up[LOG][N], depth[N];
pii dp1[N], dp2[N];
 
bool upper(int v, int u){
	return tin[v] <= tin[u] && tin[u] <= tout[v];
}
int lca(int v, int u){
	if(upper(v, u))
		return v;
	if(upper(u, v))
		return u;
	for(int i = LOG - 1; i >= 0; i--)
		if(!upper(up[i][v], u))
			v = up[i][v];
	return up[0][v];
}
int dist(int v, int u){
	return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}
pii Merge(pii a, pii b){
	if(a == mp(0, 0))
		return b;
	if(b == mp(0, 0))
		return a;
	int v[] = {a.f, a.s, b.f, b.s};
	pii c = a;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < i; j++)
			if(dist(c.f, c.s) < dist(v[i], v[j]))
				c = {v[i], v[j]};
	return c;
}
void dfs0(int v, int p){
	tin[v] = ++timer;
	depth[v] = depth[p] + 1;
	up[0][v] = p;
	for(int i = 1; i < LOG; i++)
		up[i][v] = up[i - 1][ up[i - 1][v] ];
	sz[v] = 1;
	for(auto to : g[v]){
		if(to == p)
			continue;
		dfs0(to, v);
		sz[v] += sz[to];
	}
	tout[v] = timer;
}
void dfs1(int v, int p){
	dp1[v] = {v, v};	
	for(auto to : g[v]){
		if(to == p)
			continue;
		dfs1(to, v);
		dp1[v] = Merge(dp1[v], dp1[to]);	
	}
}
void dfs2(int v, int p){
	pii tmp;
	
	reverse(g[v].begin(), g[v].end());	
	tmp = Merge(dp2[v], {v, v});
	for(auto to : g[v]){
		if(to == p)
			continue;
		dp2[to] = Merge(dp2[to], tmp);
		tmp = Merge(dp1[to], tmp);
	}
	reverse(g[v].begin(), g[v].end());	
	
	tmp = Merge(dp2[v], {v, v});
	for(auto to : g[v]){
		if(to == p)
			continue;
		dp2[to] = Merge(dp2[to], tmp);
		dfs2(to, v);
		tmp = Merge(dp1[to], tmp);
	}
	
}
bool check(int v, int u, int k){
	pii d1, d2;
	int sz1, sz2;
	int l = lca(v, u);
	int d = dist(v, u);
	if(k < depth[v] - depth[l]){
		int w = v;
		for(int i = 0; i < LOG; i++)
			if((k >> i) & 1)
				w = up[i][w];		
		d1 = dp1[w], d2 = dp2[w];
		sz1 = sz[w], sz2 = n - sz[w];
	}else{
		int w = u;
		for(int i = 0; i < LOG; i++)
			if(((d - k - 1) >> i) & 1)
			w = up[i][w];
		d1 = dp2[w], d2 = dp1[w];
		sz1 = n - sz[w], sz2 = sz[w];
	}
	int r1 = sz1 + sz1 - max(dist(d1.f, v), dist(d1.s, v));
	int r2 = sz2 + sz2 - max(dist(d2.f, u), dist(d2.s, u));
	ans = min(ans, max(r1, r2));
	return r1 < r2;
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}          
	dfs0(1, 1);
	dfs1(1, 1);
	dfs2(1, 1);
	while(q--){
		int v, u;
		scanf("%d%d", &v, &u);
		int d = dist(v, u);
		int lb = 0, rb = d - 1;
		ans = inf;
		while(lb <= rb){
			int mid = (lb + rb) >> 1;
			if(check(v, u, mid))
				lb = mid + 1;
			else
				rb = mid - 1;
		}                                  
		check(v, u, min(max(lb, 0), d - 1));
		check(v, u, min(max(lb - 1, 0), d - 1));
		printf("%d\n", ans - 2);
	}
}