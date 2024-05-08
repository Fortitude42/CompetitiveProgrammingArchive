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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const int S = (int)6e6 + 10;
const ll INF = 1e18;
    
int n, p[111], c[111];
vi g[M];
ll x, dp[S + 10];
bitset < S + 10 > u;

inline ll f(ll a, ll b){
    if(a > x / b) return x;
    return a * b;
}

inline void add(int s, ll mult){
   	//mult * a >= x
   	//a >= x / mult
	ll A = (x + mult - 1) / mult;

	for(int i = u._Find_first(); i <= S - s; i = u._Find_next(i)) {
        if (dp[S - i - s] >= A) {
        	dp[S - i] = x;
        	u[i] = 0;
        } else
        	dp[S - i] = max(dp[S - i], dp[S - i - s] * mult);
    }
}

void solve() {          
    dp[0] = 1;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        g[p[i]].pb(c[i]);
    }

	for (int i = 0; i < sz(u); ++i) 
		u[i] = 1;

    for(int i = 1; i < N; i++){
        if(!sz(g[i])) continue;
        sort(all(g[i]));
        int sum = 0;
        ll mult = 1;
        for(int j = 0; j + 1 < sz(g[i]); j += 2){
            sum += g[i][j];
            sum += g[i][j + 1];
            mult = f(mult, i);
            mult = f(mult, i);
            add(sum, mult);  
        }
    }
    for(int i = 1; i < S; i++){
        if(dp[i] >= x){
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
    
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}