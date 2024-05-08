//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, a[M][M], b[M][M], good[M*M], bad[M*M];
int c[M][M], k, col[M*M];
vi gg[M*M];


//https://github.com/ADJA/algos/blob/master/Graphs/Dinic.cpp
/********************************************************************************
    MaxFlow Dinic algorithm with scaling. 
    O(N * M * log(MC)), where MC is maximum edge capacity.
    
    Based on problem 2784 from informatics.mccme.ru 
    http://informatics.mccme.ru/mod/statements/view3.php?chapterid=2784#1
********************************************************************************/

struct edge {
    int a, b, f, c;
};

const int MAXN = 10050;
vector <edge> e;
int pt[MAXN]; // very important performance trick
vector <int> g[MAXN];
long long flow = 0;
queue <int> q;
int d[MAXN];
int lim;
int s, t;

void add_edge(int a, int b, int c) {                                                                           
    edge ed;

    //keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge 

    ed.a = a; ed.b = b; ed.f = 0; ed.c = c;
    g[a].push_back(e.size());
    e.push_back(ed);

    ed.a = b; ed.b = a; ed.f = c; ed.c = c;
    g[b].push_back(e.size());
    e.push_back(ed);
}

bool bfs() {
    for (int i = s; i <= t; i++)
        d[i] = inf;
    d[s] = 0; 
    q.push(s);
    while (!q.empty() && d[t] == inf) {
        int cur = q.front(); q.pop();
        for (size_t i = 0; i < g[cur].size(); i++) {
            int id = g[cur][i];
            int to = e[id].b;

            //printf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);

            if (d[to] == inf && e[id].c - e[id].f >= lim) {
                d[to] = d[cur] + 1;
                q.push(to);
            }
        }
    }
    while (!q.empty()) 
        q.pop();
    return d[t] != inf;
}

bool dfs(int v, int flow) {
    if (flow == 0) 
        return false;
    if (v == t) {
        //cout << v << endl;
        return true;
    }
    for (; pt[v] < g[v].size(); pt[v]++) {
        int id = g[v][pt[v]];
        int to = e[id].b;

        //printf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);

        if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
            int pushed = dfs(to, flow); 
            if (pushed) {
                e[id].f += flow;
                e[id ^ 1].f -= flow;
                return true;
            }               
        }
    }
    return false;
}

void dinic() {
    for (lim = (1 << 30); lim >= 1;) {
        if (!bfs()) {
            lim >>= 1;
            continue;
        }

        for (int i = s; i <= t; i++) 
            pt[i] = 0;

        int pushed;

        while (pushed = dfs(s, lim)) { 
            flow = flow + lim;
        }

        //cout << flow << endl;
    }
}

bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs1(int x, int y) {
	c[x][y] = k;
	bad[k] += (a[x][y] ^ b[x][y]);
	good[k] += (a[x][y] ^ b[x][y] ^ 1);
	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		if (in(tox, toy)) {
		    if (!c[tox][toy] && a[tox][toy] == a[x][y])
				dfs1(tox, toy);   
			else if (c[tox][toy] > 0 && c[tox][toy] != c[x][y]) {
				gg[c[tox][toy]].pb(c[x][y]);
				gg[c[x][y]].pb(c[tox][toy]);
			}
		}
	}
}
 
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("\n");
		for (int j = 0; j < m; ++j) {
			char c;
			scanf("%c", &c);
			a[i][j] = c - '0';
		}
	}


	for (int i = 0; i < n; ++i) {
		scanf("\n");
		for (int j = 0; j < m; ++j) {
			char c;
			scanf("%c", &c);
			b[i][j] = c - '0';
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!c[i][j]) {
			    ++k;
				dfs1(i, j);    
				col[k] = a[i][j];
			}

	for (int i = 1; i <= k; ++i) {
		sort(all(gg[i]));           
		gg[i].resize(unique(all(gg[i])) - gg[i].begin());
	}

	s = 0, t = k + 1;
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		if (!col[i]) {
			for (auto j : gg[i])
				add_edge(i, j, inf);				 
		}

		if (bad[i] <= good[i])
			ans += bad[i];
		else {
			ans += good[i];
			if (!col[i]) 
				add_edge(s, i, bad[i] - good[i]);
			else
				add_edge(i, t, bad[i] - good[i]); 
		}	
	}

	dinic();
	cout << ans + flow;
}



main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

