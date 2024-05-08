#include <bits/stdc++.h>                                           

 
using namespace std;
 
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
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 450;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, q;
map<int, bool> good[M];
map<int, int> d[M];
 
void solve() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= q; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        good[x][y] = 1;
    }    
    queue<pii> q;
    d[1][1] = 0;
    q.push({1, 1});
    while(sz(q)){
        int x = q.front().f, y = q.front().s;
        q.pop();
        int power = x + y + good[x].count(y);
        for(int tox = x + 1; tox <= min(n, power); tox++){
            if(!d[tox].count(y)){
                d[tox][y] = d[x][y] + 1;
                q.push({tox, y});
            }
        }
        for(int toy = y + 1; toy <= min(m, power); toy++){
            if(!d[x].count(toy)){
                d[x][toy] = d[x][y] + 1;
                q.push({x, toy});
            }
        }
    }
    printf("%d\n", d[n][m]);
}

int main () {
    int TT;
    TT = 1;
    for (int tt = 1; tt <= TT; ++tt) {
        solve();
    }
}