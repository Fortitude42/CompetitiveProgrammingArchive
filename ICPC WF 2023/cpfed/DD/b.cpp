#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5, mod = 1e9 + 9;
int n, q, nxt[N][2], up[N][19];
bool used[N];
struct Seg {
	int l, r, i;
} a[N], b[N];
vector <int> g[N], order;
pair <int, int> t[N * 8];
void upd(int p, pair <int, int> x, int v = 1, int tl = 1, int tr = 2 * n) {
	if (tl == tr) {
		t[v] = max(t[v], x);
		return;
	}
	int tm = (tl + tr) / 2;
	if (p <= tm) upd(p, x, v * 2, tl, tm);
	else upd(p, x, v * 2 + 1, tm + 1, tr);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}
pair <int, int> get(int l, int r, int v = 1, int tl = 1, int tr = 2 * n) {
	if (l > tr || r < tl) return {0, 0};
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) / 2;
	return max(get(l, r, v * 2, tl, tm), get(l, r, v * 2 + 1, tm + 1, tr));
}
bool upper(Seg x, Seg y) {
	return x.l <= y.l && y.r <= x.r;
}
void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v]) {
		if (!used[to])
			dfs(to);
	}
	order.push_back(v);
}
int query(int u, int v) {
		if (u == v) {
			return 0;
		}
		if (upper(b[u], b[v]) || upper(b[v], b[u])) {
			return 1;
		}
		if (b[u].r > b[v].r) 
			swap(u, v);
		int ans = mod;
		int cur = u, dist = 0;
		for (int i = 18; i >= 0; i--) {
			if (up[cur][i] && b[up[cur][i]].r < b[v].l)
				cur = up[cur][i], dist += (1 << (i + 1));
			else if (up[cur][i] && b[nxt[up[cur][i]][1]].l < b[v].l)
				cur = up[cur][i], dist += (1 << (i + 1));
		}
		bool t = 0;
		map <int, int> used;
		int CNT = 0;
		while (!used[cur]) {
			assert(++CNT <= 10);
			used[cur] = 1;
			if (!cur)
				break;
			if (v == cur) {
				ans = dist;
				break;
			}
			if (upper(b[v], b[cur]) || upper(b[cur], b[v])) {
				ans = dist + 1;
				break;
			}
			++dist;
			if (!t) {
				cur = nxt[cur][1];
				if (b[cur].l <= b[v].r && b[cur].r > b[v].r) break;
				if (b[cur].l > b[v].r) break;
			}
			else cur = nxt[cur][0];
			t ^= 1;
		}
	return ans;
}
int main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i].l >> a[i].r, a[i].i = i, b[i] = a[i];
	sort(a + 1, a + 1 + n, [] (Seg x, Seg y) {
		return x.r - x.l > y.r - y.l;
	});	
	for (int i = 1; i <= n; ++i) {
		auto mx = get(1, a[i].l);
		if (mx.first >= a[i].r)
			nxt[a[i].i][0] = mx.second;
		upd(a[i].l, {a[i].r, a[i].i});
	}
	for (int i = 1; i <= n * 8; ++i) t[i] = {0, 0};
	for (int i = n; i > 0; i--) {
		auto mx = get(a[i].l, a[i].r);
		if (mx.first >= a[i].l)
			nxt[a[i].i][1] = mx.second;
		else nxt[a[i].i][1] = a[i].i;
		upd(a[i].r, {a[i].l, a[i].i});
	}
	for (int i = 1; i <= n; ++i) 
		g[i].push_back(nxt[nxt[i][1]][0]);
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}
	for (auto v : order) {
		if (!g[v].empty())
			up[v][0] = g[v][0];
		for (int i = 1; i < 19; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		if (u == v) {
			cout << "0\n";
			continue;
		}
		if (upper(b[u], b[v]) || upper(b[v], b[u])) {
			cout << "1\n";
			continue;
		}
		if (b[u].r > b[v].r) 
			swap(u, v);
		int ans = query(u, v);
		ans = min(ans, query(nxt[u][0], v) + 1);
		if (ans == mod) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}
