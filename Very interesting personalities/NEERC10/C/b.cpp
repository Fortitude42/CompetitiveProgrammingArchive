#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
#define pb push_back

const int mxn = 50006;

int n, m, k;
int lim;

vi e[mxn]; int dfn[mxn], cnt;
vi edge[mxn]; vector<vi> ring[mxn];
int cactus(int x, int p) {
	dfn[x] = ++cnt; int a = 0;
	for (auto i : e[x]) if (i != p)
		if (!dfn[i]) {
			int t = cactus(i, x);
			if (t && t != x) assert(!a), a = t;
		} else if (dfn[i] < dfn[x]) {
			assert(!a), a = i;
			ring[i].pb({i});
		}
	if (a) ring[a].back().pb(x);
	if (!a && p) edge[p].pb(x);
	return a;
}

list<int> f[mxn];
void append(int x, int y) { f[x].splice(f[x].end(), f[y]); }

int g[mxn], gp[mxn];
void dfs(int x) {
	for (auto i : edge[x]) {
		dfs(i);
		if (f[i].size() < lim)
			append(x, i);
	}
	for (auto &r : ring[x]) {
		for (auto i : r) if (i != x) dfs(i);
		int m = r.size();
		int p = 1;
		int sz = 0;
		gp[0] = g[0] = 0;
		int mx = 0;
		for (int i = 1; i < m; ++i) {
			sz += f[r[i]].size();
			while (sz > lim)
				sz -= f[r[p++]].size();
			if (sz == lim) {
				g[i] = g[p - 1] + lim;
				gp[i] = gp[p - 1];

				if (x == 1)
					cerr << i << ' ' << p << ' ' << g[i] << ' ' << g[p - 1] << endl;
			} else {
				g[i] = 0;
				gp[i] = i;
			}
			if (g[i] > g[mx])
				mx = i;
		}

		if (g[mx]) {
			if (x == 1)
				cerr << g[mx] << ' ' << r[mx] << ' ' << r[gp[mx] + 1] << endl;
			for (int i = mx; i > gp[mx]; --i)
				if (f[r[i]].size() < lim)
					append(r[i - 1], r[i]);
			for (int i = 1; i < m; ++i) if (!(gp[mx] < i && i <= mx))
				append(x, r[i]);
		} else {
			for (auto i : r) if (i != x)
				append(x, i);
		}
	}
}

int main() {
	
	cin >> n >> m >> k;
	lim = n / k;
	while (m--) {
		int l;
		scanf("%d", &l);
		int x = 0, y;
		while (l--) {
			scanf("%d", &y);
			if (x) e[x].pb(y), e[y].pb(x);
			x = y;
		}
	}
	
	cactus(1, 0);
	
	for (int i = 1; i <= n; ++i)
		f[i] = {i};
	
	dfs(1);
	
	for (int i = 1; i <= n; ++i) if (!f[i].empty() && f[i].size() != lim) {
		puts("-1");
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) if (!f[i].empty()) {
		f[i].sort();
		for (auto j : f[i])
			printf("%d ", j);
		puts("");
	}
	
	return 0;
}