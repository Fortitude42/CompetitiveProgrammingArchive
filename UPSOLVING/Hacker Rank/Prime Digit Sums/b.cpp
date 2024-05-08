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
const pii base= mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 4e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int dp[2][420], res[M], id[M], q;
vi vals, s;


bool prime(int x) { 
    if (x < 2)
        return 0;

    for (int y = 2; y*y <= x; ++y)
        if (x % y == 0)
            return 0;

    return 1;
}


void solve() {	
    memset(id, -1, sizeof(id));
    for (int i = 0; i < 10000; ++i){
        vi cur;
        int j = i;
        while (sz(cur) < 4) {
            cur.pb(j % 10);
            j /= 10;
        }

        if (!prime(cur[0] + cur[1] + cur[2]) || !prime(cur[0] + cur[1] + cur[2] + cur[3]) || !prime(cur[1] + cur[2] + cur[3]))
            continue;
        
        dp[0][sz(vals)] = 1;
        id[i] = sz(vals);
        vals.pb(i);
        s.pb(cur[0] + cur[1] + cur[2] + cur[3]);
    }


    for (int n = 3; n <= N; ++n) {
    	memset(dp[(n + 1) & 1], 0, sizeof(dp[(n + 1) & 1]));

	       for (int j = 0; j < sz(vals); ++j) {
    	        if (!dp[n & 1][j])
	                continue;

    	        if (vals[j] >= 1000) {
	                res[n] += dp[n & 1][j];
            	    if (res[n] >= MOD)
        	            res[n] -= MOD;
    	        }
            
            
	            for (int d = 0; d < 10; ++d) {
            	    if (!prime(s[j] + d))
        	            continue;

    	            int to = d*1000 + (vals[j] / 10);

	                if (id[to] == -1)
                	    continue;

            	    int y = id[to];
        	        dp[(n + 1) & 1][y] += dp[n & 1][j];
    	            if (dp[(n + 1) & 1][y] >= MOD)
	                    dp[(n + 1) & 1][y] -= MOD;
            	}
        	}        
    }

    cin >> q;
	for (int i = 1; i <= q; ++i) {
		int n;
		cin >> n;
		cout << res[n] << endl;
	}
}

int main () {
	fastio

  int TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}