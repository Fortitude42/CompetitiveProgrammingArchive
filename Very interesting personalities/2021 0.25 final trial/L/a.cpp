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
const int N = 300, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
 
 
int n, m;
bool u[M][M];
  
bool checkq(int x, int y) {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j) 
            if (!i || i == 2 || (i == 1 && j != 1) || ((i == 3 || i == 4) && j == 2)) {
                if (!u[x + i][y + j])
                    return 0;
            }
         
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j) 
            if (!i || i == 2 || (i == 1 && j != 1) || ((i == 3 || i == 4) && j == 2)) {
                u[x + i][y + j] = 0;
            }   
 
    return 1;
}
 
bool checkf(int x, int y) {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j) 
            if (!i || (i == 2 && j != 2) || ((i == 1 || i == 3 || i == 4) && !j)) {
                if (!u[x + i][y + j])
                    return 0;
            }

	if (u[x + 1][y + 1])
		return 0;
 
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j) 
            if (!i || (i == 2 && j != 2) || ((i == 1 || i == 3 || i == 4) && !j)) {
                u[x + i][y + j] = 0;           	
            }
 
    return 1;
}
 
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("\n");
        for (int j = 1; j <= m; ++j) {
            char c;
            scanf("%c", &c);           
            u[i][j] = (c == '#');
        }
    }
 
    int cntf = 0, cntq = 0;
    for (int i = n - 4; i > 0; --i)
        for (int j = m - 2; j > 0; --j) {
            cntf += checkf(i, j);
            cntq += checkq(i, j);
        }
 
 
    printf("%d %d\n", cntq, cntf);
}
 
main () {
    int TT;
    TT = 1;
//  scanf("%d", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        solve();
    }
}