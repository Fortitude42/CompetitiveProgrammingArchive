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
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 6e4 + 11;

struct edge {
	int from, to, cap, flow;
	edge(){};
	edge(int a, int b, int c, int d) {
		from = a;
		to = b;
		cap = c;
		flow = d;
	}
};
 
vector < edge > e;
vector < int > g[N];
int sz, d[N], ptr[N];
 
inline void add_edge(int x, int y) {
//	cerr << "edge " << x << " " << y << "\n";
	g[x].pb(sz(e));
	e.pb(edge(x, y, 1, 0));
	g[y].pb(sz(e));
	e.pb(edge(y, x, 0, 0));
}
 
inline bool bfs(int x, int y) {
	for (int i = x; i <= y; i++)
		d[i] = inf;
	d[x] = 0;
	queue < int > q;
	q.push(x);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto i : g[v]) {
			if (d[e[i].from] + 1 < d[e[i].to] && e[i].flow < e[i].cap) {
				d[e[i].to] = d[e[i].from] + 1;
				q.push(e[i].to);
			}
		}
	}
	return (d[y] != inf);
}
 
int dfs(int v, int fin, int flow = inf) {
	if (v == fin || !flow)
		return flow;
	while (ptr[v] < sz(g[v])) {
		int i = g[v][ptr[v]];
		if (d[e[i].from] + 1 == d[e[i].to] && e[i].flow < e[i].cap) {
			int cur = dfs(e[i].to, fin, min(flow, e[i].cap - e[i].flow));
			if (cur) {
				e[i].flow += cur;
				e[i ^ 1].flow -= cur;
				return cur;
			}
		}
		ptr[v]++;
	}
	return 0;
}
 
inline int max_flow(int x, int y) {
	int res = 0;
	while (bfs(x, y)) {
		memset(ptr, 0, sizeof(ptr));
		while (1) {
			int add = dfs(x, y);
			if (!add)
				break;
			res += add;
		}
	}
	return res;
}

int n, m, C[N], k[2], col[N][2], p[N][2];
vector < int > gg[N], ans[3];
bool was[N][2];


void dfs (int v, int j, int a, int b) {
	col[v][j] = k[j];
	for (auto to : gg[v])
		if ((C[to] == a || C[to] == b) && !col[to][j])
			dfs(to, j, a, b);
}

void solve (int a, int b, int c, int j) {
	memset(col, 0, sizeof(col));
	memset(was, 0, sizeof(was));
	memset(p, -1, sizeof(p));
	memset(ptr, 0, sizeof(ptr));
	e.clear();

	k[0] = k[1] = 0;
	for (int i = 0; i < N; ++i)
		g[i].clear();
	

	for (int i = 1; i <= n; ++i) {
		if (!col[i][0] && C[i] != c) {
		    ++k[0];
			dfs(i, 0, a, b);
		}

		if (!col[i][1] && C[i] != b) {
			++k[1];
			dfs(i, 1, a, c);
		}
	}


	for (int i = 1; i <= n; ++i)
		if (C[i] == a) {
			add_edge(col[i][0], col[i][1] + k[0]);
//			cerr << col[i][0] << ' ' << col[i][1] << endl;
		}

//	cerr << endl;
		
		

	for (int i = 1; i <= k[0]; ++i)
		add_edge(0, i);

	for (int i = k[0] + 1; i <= k[0] + k[1]; ++i)
		add_edge(i, k[0] + k[1] + 1);


	max_flow(0, k[0] + k[1] + 1);
	
	for (int i = 1; i <= k[0]; i++) {
		for (auto j : g[i]) {
			int to = e[j].to;
			if (k[0] < to && to <= k[0] + k[1] && e[j].flow == 1) {
				p[i][0] = to - k[0];                               
				p[to - k[0]][1] = i;
//				cerr << "sdfsdf " << i << ' ' << to - k[0] << endl;
			}
		}
	}
//	cerr << endl;	

	for (int i = 1; i <= n; ++i) 
		for (int x = 0; x < 2; ++x) {
//			cerr << col[i][x] << ' ' << was[col[i][x]][x] << endl;
			if (C[i] != a || was[col[i][x]][x] || (p[col[i][x]][x] != -1 && p[col[i][x]][x] != col[i][x ^ 1]))
				continue;
//			cerr << i << ' ' << x << ' ' << col[i][x] << endl;
			was[col[i][x]][x] = 1;
			if (p[col[i][x]][x] != -1)
				was[p[col[i][x]][x]][x^1] = 1;
			ans[j].pb(i);
		}
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &C[i]);

	while (m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		gg[v].pb(u);
		gg[u].pb(v);
	}

	solve(1, 2, 3, 0);
	solve(2, 1, 3, 1);
	solve(3, 1, 2, 2);

	for (int j = 0; j < 3; ++j) {
		printf("%d ", sz(ans[j]));
		for (auto x : ans[j])
			printf("%d ", x);
		printf("\n");
	}
	return 0;
}
