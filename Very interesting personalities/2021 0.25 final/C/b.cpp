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
const int N = 3e5 + 10, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
 
const int K = 26;
const int U = 20;
 
int timer;
int g[M][K], par[M][U];
bool used[M];
int val[M];        
 
int tin[M], tout[M], tt;
 
void add(int v, string &s, int p = 0, int i = 0) {
 
    par[v][0] = p;
    for (int i = 1; i < U; i++)
        par[v][i] = par[par[v][i - 1]][i - 1];
 
    if (sz(s) == i) {
        val[v]++;
        return;
    }
 
    int to = s[i] - 'a';
    if (!g[v][to])
        g[v][to] = ++timer;
    add(g[v][to], s, v, i + 1);
}
 
set<pii> st;
 
int t[M];
 
int sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        res += t[r];
    return res;
}
 
void upd(int i, int delta) {
    for (; i <= N; i = (i | (i+1)))
        t[i] += delta;
}
 
int get(int v) {
    return sum(tout[v]) - sum(tin[v] - 1);
}
 
void dfs(int v, int k) {
 
    tin[v] = ++tt;
    upd(tin[v], val[v]);
 
    for (int to = 0; to < K; to++)
        if (g[v][to])
            dfs(g[v][to], k);
 
    tout[v] = tt;
 
    int cnt = get(v);
    if (cnt <= k)
        st.insert({-cnt, v});
}
 
void dfsUsed(int v) {
    if (used[v])
        return;
 
    used[v] = true;
    for (int to = 0; to < K; to++)
        if (g[v][to])
            dfsUsed(g[v][to]);
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    timer = 1;
 
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        add(1, s);
    }
 
    dfs(1, k);
    int ans = 0;
 
    while (!st.empty()) {
        int v = st.begin()->se;
        st.erase(st.begin());
         
        if (used[v])
            continue;                                         
 
        ans++;
        dfsUsed(v);
        upd(tin[v], -get(v));
 
        int u = v;
        for (int i = U - 1; i >= 0; i--)
            if (par[u][i] && get(par[u][i]) <= k)
                u = par[u][i];
         
        if (u != v)
            st.insert({-get(u), u});
    }
 
    cout << ans << "\n";
}
 
main () {
    fastio;
    int TT;
    TT = 1;
//  scanf("%d", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        solve();
    }
}