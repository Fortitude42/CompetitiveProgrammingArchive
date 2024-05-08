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
const int N = (int)1e6 + 1, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;
 

int m, n, tin[N], tout[N], timer, ans[N];
vector<pair<int, int> > g[N];
long long d[N], x[N];
string name[N];

void dfs(int v, int c = 0, long long s = 0){
    if(g[v].empty()){
        tin[v] = tout[v] = ++timer;
        d[v] = c;
        x[v] = s;
        return;
    }    
    d[v] = LONG_LONG_MAX;
    tin[v] = ++timer;
    for(auto [to, w] : g[v]){
        //cout << "---> " << v << ' ' << to << ' ' << w << endl;
        dfs(to, w, s + w);
        d[v] = min(d[v], d[to]);
    }
    d[v] += c;
    tout[v] = timer;
}

set <pii> q;

int getp(int v) {
    auto it = q.lower_bound(mp(tin[v], -inf));
    
    if (it == q.begin())
        return -1;
    it--;
    int p = it->s;
    if (tin[p] <= tin[v] && tout[v] <= tout[p])
        return p;
    return -1;
}

int getson(int v) {
    auto it = q.lower_bound(mp(tin[v], inf));
    if (it == q.end())
        return -1;
    int son = it->s;
    if (tin[v] <= tin[son] && tout[son] <= tout[v])
        return son;
    return -1;
}

inline void add(int v){
    if (getson(v) != -1)
        return;
    
    while (1) {
        int p = getp(v);
        if (p == -1)
            break;
        q.erase(mp(tin[p], p));
    }
    
    //cout << v << ' ' << tin[v] << endl;
    q.insert(mp(tin[v], v));
}

int get(int v){
    int ans = sz(q) +  1;
    // if (getp(v) != -1)
    //     ans--;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> m >> n;
    vector<int> leafs, nodes;
    
    for(int i = 1; i <= m; i++){
        int par, l;
        cin >> name[i] >> par >> l;
        g[par].push_back({i + n, l});
        leafs.push_back(i + n);
    }
    for(int par, l, i = 1; i <= n; i++){
        cin >> par >> l;
        g[par].push_back({i, l});
    }
    for(int i = 0; i <= n + m; i++)
        nodes.push_back(i);
    
    dfs(0);
    
    sort(leafs.begin(), leafs.end(), [&](int u, int v){
        return x[u] > x[v];  
    });
    sort(nodes.begin(), nodes.end(), [&](int u, int v){
        return d[u] > d[v];
    });
    
    
    int j = 0;
    
    for(auto v : leafs) {
        while(j < sz(nodes) && d[nodes[j]] > x[v]){
            add(nodes[j++]);
        }
        ans[v] = get(v);
    }
    
    for(int i = 1; i <= m; i++)
        cout << name[i] << " " << ans[i + n] << "\n";
    
}