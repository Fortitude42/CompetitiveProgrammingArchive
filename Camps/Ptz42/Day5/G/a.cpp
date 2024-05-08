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
const int N = (1 << 19), inf = 1e9, MOD = 998244353;
const int M = N + 17;
const int K = 20;
const ll INF = 1e18;

int n, a[M], cnt[M], g[M];

/*int C(int n, int k){
	if(n < 0 || k < 0 || n < k) return 0;
	if(n == k) return 1;
	return C(n - 1, k - 1) + C(n - 1, k);
}*/

int dp[M][K], dp1[M][K];

int C(int x){
	if(x <= 0) return 0;
	return x;
}


inline void add(int &a, int b){
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
}

const int tot = (1 << K) - 1;

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		cnt[x ^ tot]++;
	}

	for(int b = 0; b < K; b++)
		for(int msk = 0; msk < (1 << K); msk++)
			if(msk >> b & 1)
				cnt[msk] += cnt[msk ^ (1 << b)];
				                      /*
	for(int i = 0; i < (1 << 10); i++){
		for(int j = i; ; j = (j - 1) & i){
			g[j] += cnt[i];
			if(!j) break;
		}
	}
	                                    */

	for(int k = 1; k <= n; k++){
		if(k == 1){
			for(int d = 0; d < K; d++){
				for(int i = 0; i < (1 << K); i++){
					if(__builtin_popcount(i) & 1){
						add(dp[k][d], -C(cnt[i ^ tot] - d));
					}else{
						add(dp[k][d], C(cnt[i ^ tot] - d));
					}
				}
			}
		}else{
			for(int d = K - 1; d >= 0; d--){
				add(dp[k][d], dp[k - 1][d + 1]);
				add(dp[k][d], dp[k][d + 1]);
			}
		}
		cout << dp[k][0] << "\n";
	}
	cout << "\n";
}

main () {
	fastio;
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

