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
const ll INF = 1e18;

 
int n;
bool p[M], used[M];
vi primes, small, big;

int res[100]; 

void calc(int pos, int col = 1){
	if(pos == sz1){
		vi vals;
		for(int i = 1; i <= col; i++){
			assert(res[i] > 1);
			vals.pb(res[i]);
		}
		sort(all(vals));
		int ptr = sz(big) - 1;
		for(auto x : vals){
			while(ptr > 0 && big[ptr] * x > n)
				ptr--;
			if(ptr){
			
			}
			else 
		}

		return;
	}
	for(int i = 1; i <= col + 1; i++){
		if(res[i] * small[pos] <= n){
			res[i] *= small[pos];
			calc(pos + 1, max(i, col));
			res[i] /= small[pos];
		}
	}
}
           
void solve() {
	cin >> n;

	for(int i = 1; i <= 100; i++)
		res[i] = 1;

	int toAdd = 0;

	for(int i = 2; i <= n; i++){
		if(!p[i]){
			if(2 * i > n) toAdd++;
			else{
				if(i * i <= n) small.pb(i);
				else big.pb(i);
				primes.pb(i);
			}

			for(int j = i * i; j <= n; j += i)
				p[j] = 1;
		}
	}

	int m = sz(primes);

	/*dp[0] = 0;
	for(int msk = 1; msk < (1 << m); msk++){
		int res = 1;
		for(int i = 0; i < m; i++)
			if(msk >> i & 1){
				res *= primes[i];
				if(res > n) break;
			}

		if(res <= n)
			dp[msk] = 1; 
		else
			dp[msk] = inf;

		for(int s = msk; s; s = (s - 1) & msk){
			dp[msk] = min(dp[msk], dp[s] + dp[s ^ msk]);
		}
	}

	cout << dp[(1 << m) - 1] << "<---\n";
    */

    int ans = m;
	
	int r = m - 1;
    
    for(int i = 0; i < sz(primes); i++){
		if(used[i]) break;
		
		while(i < r && primes[i] * primes[r] > n){
			r--;
		}
		                               x
		if(i < r){
			ans--;
		}
        
        used[r] = 1;
	} 

	cout << ans + toAdd << "\n";
}

main () {
	file("gcd");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

