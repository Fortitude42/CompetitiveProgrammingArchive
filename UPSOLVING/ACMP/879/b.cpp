//template by paradox & gege & parasat
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
const int N = 26*26*26, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
 
vi g[M], gr[M], order;
bool used[M], was[M];
int n, c[M], k, cnt[M], cnt1[M]; 
 
 
void dfs(int v) {
    was[v] = 1;
    for (auto to : g[v])
        if (!was[to])
            dfs(to);
 
    order.pb(v);
}
 
void dfs1(int v) {
    c[v] = k;
    for (auto to : gr[v])
        if (!c[to])
            dfs1(to);
}
 
 
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < 3; ++i) {
            x *= 26;
            x += (s[i] - 'A');
        }
 
        for (int i = sz(s) - 3; i < sz(s); ++i) {
            y *= 26;
            y += (s[i] - 'A');
        }
 
        used[x] = used[y] = 1;
        g[x].pb(y);
        gr[y].pb(x);
    }
 
    for (int i = 0; i <= N; ++i)
        if (used[i] && !was[i]) 
            dfs(i);
 
    reverse(all(order));
 
    for (auto i : order)
        if (used[i] && !c[i]) {
            k++;
            dfs1(i);
        }
 
 
    for (int i = 0; i <= N; ++i)
        for (auto j : g[i]) {
            if (c[i] == c[j])
                continue;
            ++cnt[c[i]];
            ++cnt1[c[j]];
        }
    if (k == 1 || n == 1) {
        cout << 0;
        return;
    }
 
    int C = 0, C1 = 0;
    for (int i = 1; i <= k; ++i) {
        if (!cnt[i])
            ++C; 
        if (!cnt1[i])
            ++C1;
    }
 
    cout << max(C, C1) << endl;
}           
 
main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}