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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

using std::size_t;
using std::vector; using std::reverse;
using std::pair; using std::tie;

struct kosaraju
{
    using graph_t = vector<vector<size_t>>;

    const graph_t& graph;
    size_t n;
    vector<bool> vis;

    kosaraju(const graph_t& _graph) : graph(_graph), n(graph.size()), vis(n) {}

    void marker_dfs(size_t u, const graph_t& G, vector<size_t>& out)
    {
        vis[u] = true;
        for(size_t v : G[u])
            if(not vis[v])
                marker_dfs(v, G, out);
        out.push_back(u);
    }

    pair<vector<vector<size_t>>, vector<size_t>>
    operator() ()
    {
        vector<size_t> order; order.reserve(n);
        fill(vis.begin(), vis.end(), false);
        for(size_t u = 0; u < n; u++)
            if(not vis[u])
                marker_dfs(u, graph, order);

        graph_t graph_T(n);
        for(size_t u = 0; u < n; u++)
            for(size_t v : graph[u])
                graph_T[v].push_back(u);

        fill(vis.begin(), vis.end(), false);
        reverse(order.begin(), order.end());
        vector<vector<size_t>> scc;
        vector<size_t> scc_idx(n);
        for(size_t u : order)
        {
            if(vis[u]) continue;
            scc.emplace_back();
            marker_dfs(u, graph_T, scc.back());
            for(auto i : scc.back())
                scc_idx[i] = scc.size() - 1;
        }
        return {scc, scc_idx};
    }

    graph_t make_scc_graph(const vector<vector<size_t>>& scc, const vector<size_t>& scc_idx)
    {
        fill(vis.begin(), vis.end(), false);
        graph_t scc_graph(scc.size());
        for(size_t i = 0; i < scc.size(); i++)
        {
            vis[i] = true;
            for(auto u : scc[i])
              for(auto v : graph[u])
                if(not vis[scc_idx[v]])
            {
                vis[scc_idx[v]] = true;
                scc_graph[i].push_back(scc_idx[v]);
            }
            vis[i] = false;
            for(auto e : scc_graph[i])
                vis[e] = false;
        }
        return scc_graph;
    }
    
    graph_t make_scc_graph()
    {
        vector<vector<size_t>> scc;
        vector<size_t> scc_idx;
        tie(scc, scc_idx) = operator() ();
        return make_scc_graph(scc, scc_idx);
    }
};

using std::vector;
using std::size_t;
using std::reverse;

    struct solution_2sat { bool exists; vector<bool> value; };

struct solver_2sat
{
    size_t n;
    vector<vector<size_t>> imp_graph;

    solver_2sat(size_t _n) : n(_n), imp_graph(2*n) {}

    static constexpr size_t as_index(int p)
    {
        return p < 0 ? 2*(-p-1) + 1 : 2*(p-1);
    }

    int new_variable()
    {
        imp_graph.emplace_back();
        imp_graph.emplace_back();
        return imp_graph.size() / 2;
    }
    void add_implication(int a, int b)
    {
        imp_graph[as_index(a)].push_back(as_index(b));
    }
    void add_or_clause(int a, int b)
    {
        add_implication(-a, b);
        add_implication(-b, a);
    }
    void add_xnor_clause(int a, int b)
    {
        add_or_clause(a, -b);
        add_or_clause(-a, b);
    }
    void add_xor_clause(int a, int b)
    {
        add_or_clause(a, b);
        add_or_clause(-a, -b);
    }
    void add_and_clause(int a, int b)
    {
        add_or_clause(a, b);
        add_or_clause(-a, b);
        add_or_clause(a, -b);
    }
    void force_true(int a)
    {
        add_or_clause(a, a);
    }
    void force_false(int a)
    {
        return force_true(-a);
    }
    void at_most_one(const vector<int>& ind)
    {
        if(ind.size() <= 1) return;
        int curr = -ind[0];
        for(size_t i = 2; i < ind.size(); i++)
        {
            auto next = new_variable();
            add_or_clause(curr, -ind[i]);
            add_or_clause(curr, next);
            add_or_clause(-ind[i], next);
            curr = -next;
        }
        add_or_clause(curr, -ind[1]);
    }

    solution_2sat solve()
    {
        auto pscc = kosaraju{imp_graph}();
        auto scc = pscc.first; auto scc_idx = pscc.second;
        const size_t s = scc.size();
        for(size_t u = 0; u < 2*n; u += 2)
        {
            if(scc_idx[u] == scc_idx[u^1])
                return {false, {}};
        }

        vector<bool> is_set(s), truth_value(s);
        for(size_t u = s; u --> 0; )
        {
            if(not is_set[u])
                is_set[u] = true, truth_value[u] = true;
            for(size_t i : scc[u])
            {
                size_t v = scc_idx[i^1];
                is_set[v] = true; truth_value[v] = not truth_value[u];
            }
        }
        vector<bool> out(n);
        for(size_t i = 0; i < n; i++)
            out[i] = truth_value[scc_idx[2*i]];
        return {true, out};
    }
};

      
bool del[M], ndel[M];
int n, a[M];
vi a1, a2;
 
void rec(int i = 1) {
	if (del[i]) {
		a1.pb(i);
		rec(i + 1);
		return;
	}

	if (!sz(a2) || (sz(a1) && a1.back() == a2.back())) {
		if ()

		ndel[i] = 1;
		a1.pb();
		a2.pb(i);
		rec(i + 1);
		
	}

}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	

	rec();
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}