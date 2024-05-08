//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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
const ll INF = 1e18;


ll x, q[M], pw[20];
int n, k[M];
bool used[M];
vector<pii> g[20];
 
void solve() {
	cin >> x >> n;

	pw[0] = 1;
	for(int i = 1; i <= 18; i++)
		pw[i] = pw[i - 1] * 10ll;

	for(int i = 1; i <= n; i++){
		cin >> k[i] >> q[i];
		g[k[i]].pb({q[i] * pw[k[i]], i});
	}

	vector<pair<int, int> > vals;  

	for(int d = 0; d < 19; d++){
		int need = x / pw[d] % 10 * pw[d];
	
	    vector<int> cur;
    	for(int i = 1; i <= n; i++){
    		if(!used[i]) continue;
    		cur.pb(i);
    	}    
    	
    	for(auto x : cur){
    		int f = min(q[x], need / pw[d - k[x]]);
    		q[x] -= f;
    		need -= f * pw[k[x]];
    	}

        vector<pii> nxt;

        for(auto x : vals)
        	if(!used[x.s])
        		nxt.pb(x);
        		        
        for(auto i : g[d])
    		nxt.pb(i);
    	
    	sort(all(nxt));
    	reverse(all(nxt));

    	int sum = 0;

    	for(auto x : mb){
    		if(sum + x.f <= need){
    			sum += x.f;
    			used[x.s] = 1;
    			q[x.s] = 0;
    		}
    		else{
    			int d = (sum + x.f) - need;
    			int d1 = q[x.s] - d;
                q[x.s] = d;
    			used[x.s] = 1; 
    			
    			break;
    		}
        }
    	
    	if(x < sum){
    		cout << "-1\n";
    		return;
    	}       
    	
    	if(x <= 0) break;

        vals = nxt;
    }                 


    vi ans;

    for(int i = 1; i <= n; i++)
    	if(used[i])
    		ans.pb(i);

   	cout << sz(ans) << endl;
   	for(auto x : ans)
   		cout << x << " ";

}

main () {

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

