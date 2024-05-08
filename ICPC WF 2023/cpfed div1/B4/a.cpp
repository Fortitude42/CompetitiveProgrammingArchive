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
const int N = 1000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[M];
bool used[M*4];
int n, m, deg[M], a[M*2], b[M*2];
vector < pair < pii, pii > > edges;

struct FlowEdge {
    int v, u, id;
    int cap, flow = 0;
    FlowEdge(int v, int u, int id, int cap) : v(v), u(u), id(id), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e9;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int cap, int id) {
//    	cerr << v << ' ' << u << ' ' << cap << endl;
        edges.emplace_back(v, u, id, cap);
        edges.emplace_back(u, v, id, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
 

bool check(int x, bool ch=0) {
	Dinic d = Dinic(n + m + 2, 0, n + m + 1);
	for (int i = 1; i <= n; ++i) 
		d.add_edge(0, i, deg[i], -1);
	

	for (int i = 0; i <= x; ++i) 
		d.add_edge(edges[i].s.f, n + edges[i].f.s, 1, i);
	
	for (int i = 1; i <= m; ++i)
		d.add_edge(n + i, n + m + 1, 1, -1);

	int cur = d.flow();	
	if (cur == m) {
		if (ch) {
			memset(used, 0, sizeof used);
			for (auto e : d.edges) {
				if (e.flow > 0 && e.id != -1)
					used[e.id] = 1;				
			}
		}
		d.adj.clear();
		d.level.clear();
		d.ptr.clear();
		d.edges.clear();
		return 1;
	}
	d.adj.clear();
	d.level.clear();
	d.ptr.clear();
	d.edges.clear();
	return 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int l, p;

		cin >> a[i] >> b[i] >> l >> p;
		edges.pb(mp(mp(l, i), mp(a[i], b[i])));
		edges.pb(mp(mp(p, i), mp(b[i], a[i])));
		++deg[a[i]], ++deg[b[i]];
	}

	for (int i = 1; i <= n; ++i) {
		if (deg[i] & 1) {
			cout << "NIE\n";
			return;
		}
		deg[i] >>= 1;
	}


	sort(all(edges));
	int l = 0, r = sz(edges) - 2, res = sz(edges) - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}

	check(res, 1);
	for (int i = 0; i < sz(edges); ++i)
		if (used[i])
			g[edges[i].s.f].pb(edges[i].f.s);
		

	memset(used, 0, sizeof used);
	
	stack < int > st, st1;
	st.push(1);

	vi ans;
	while (sz(st)) {
		int v = st.top();
		while (sz(g[v])) {
			int i = g[v].back();
			if (used[i]) {
				g[v].ppb();
				continue;
			}
			break;
		}

		if (!sz(g[v])) {
			if (sz(st1)) {
				ans.pb(st1.top());
				st1.pop();
			}
			st.pop();
			continue;
		}

		int i = g[v].back();
		used[i] = 1;
		st1.push(i);
		st.push(a[i]^b[i]^v);
	}

	cout << edges[res].f.f << endl;
	reverse(all(ans));
	for (auto x : ans)
		cout << x << ' ';
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}