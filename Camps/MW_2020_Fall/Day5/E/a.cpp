#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const int inf = (int)1e9;
const ll mod1 = 1190494759ll;
const ll mod2 = 1400305337ll;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;

queue < int > q;
map < int, int > cnt[N];
bool done[N], ok1[N], ok2[N], was[N];
int n, m, col, u[N], d[N], id[N];
vector < int > ord, g[N], gr[N], gn[N], gg[N], order;

void dfs(int v) {
	u[v] = 1;
	for (auto to : g[v])
		if (!u[to]) dfs(to);
	ord.pb(v);
}

void dfs1(int v) {
	u[v] = col;
	for (auto to : gr[v])
		if (!u[to])
			dfs1(to);
}

void dfs2 (int v) {
	was[v] = 1;
	for (auto to : gg[v])
		if (!was[to])
			dfs2(to);

	order.pb(v);
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		gr[y].pb(x);
	}
	for (int i = 1; i <= n; i++)
		if (!u[i]) dfs(i);
	rev(all(ord));
	memset(u, 0, sizeof(u));
	for (auto v : ord) {
		if (!u[v]) {
			col++;
			dfs1(v);
		}
	}

	if (col == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= col; i++)
		ok1[i] = ok2[i] = 1;

	for (int i = 1; i <= n; i++) {
		for (auto j : g[i]) {
			if (u[i] != u[j]) {
				ok1[u[j]] = 0;
				ok2[u[i]] = 0;
				gn[u[i]].pb(u[j]);
				++cnt[u[i]][u[j]];
				gg[u[j]].pb(u[i]);
			}
		}
	}
	int st, fn, cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= col; i++) {
		if (ok1[i]) {
			cnt1++;
			st = i;
		}
		if (ok2[i]) {
			cnt2++;
			fn = i;
		}
	}

	if (cnt1 != 1 || cnt2 != 1) {
		cout << -1;
		return 0;
	}

	memset(d, -1, sizeof(d));
	for (int i = 1; i <= n; ++i)
		if (u[i] == st) {
			d[i] = 0;
			q.push(i);
		}

	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : g[v])
			if (d[to] == -1) {
				d[to] = d[v] + 1;
				q.push(to);
			}
	}

	memset(ok1, 0, sizeof(ok1));
	memset(ok2, 0, sizeof(ok2));

	q.push(st);
	ok1[st] = 1;
	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : gn[v])
			if (!ok1[to]) {
				ok1[to] = 1;
				q.push(to);
			}
	}

	q.push(fn);
	ok2[fn] = 1;
	while (sz(q)) {
		int v = q.front();
		q.pop();
		for (auto to : gg[v]) 
			if (!ok2[to]) {
				ok2[to] = 1;
				q.push(to);
			}
	}

	
	for (int i = 1; i <= col; ++i) {
	    gg[i].clear();
		for (auto j : gn[i])
			if (ok1[i] && ok2[j]) 
				gg[i].pb(j);        
	}


	memset(was, 0, sizeof(was));
	for (int i = 1; i <= col; ++i)
		if (!was[i])
			dfs2(i);

	reverse(all(order));
	for (int i = 0; i < sz(order); ++i)
		id[order[i]] = i;

	int mx = -1;
	for (int i = 0; i < sz(order) - 1; ++i) {
		int v = order[i];
		for (auto to : gg[v]) 
			mx = max(mx, id[to]);
		

		for (auto to : gg[v])
			if (cnt[v][to] == 1 && to == order[i + 1] && mx < i + 1) {
				cout << -1 << endl;
				return 0;
			}
	}
	
	int mn = inf;
	for (int i = 1; i <= n; ++i)
		if (u[i] == fn)
			mn = min(mn, d[i]);

	if (mn == inf)
		mn = -1;

	cout << mn << endl;		
	return 0;
}
