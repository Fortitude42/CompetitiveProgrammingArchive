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


int n, a[M];
ll ans[M], dp[M][20];

ll calc_sum(int msk, int b){
	if(b == -1) return a[msk];
	ll &res = dp[msk][b];
	if(res != -1){
		cout << res << " <------\n";
		return res;
	}
	res = 0;
	if(msk >> b & 1)
		res += calc_sum(msk, b - 1);
   	else
    	res += calc_sum(msk, b - 1) + calc_sum(msk ^ (1 << b), b - 1);
    return res;
}

void calc_ans(int msk, int b, ll res = 0){
	cout << msk << " ---> " << res << "\n";
	if(b == -1){
		ans[msk] += res + (__builtin_popcount(msk) % 2 ? a[msk] : 0);
		return;
	}
	if(msk >> b & 1)
		calc_ans(msk, b - 1, res);
   	else{
   		if(__builtin_popcount(msk) & 1){
   			calc_ans(msk, b - 1, res + calc_sum(msk ^ (1 << b), b - 1));
   			calc_ans(msk ^ (1 << b), b - 1, res + calc_sum(msk, b - 1));
   		}else{
    		calc_ans(msk, b - 1, res);
    		calc_ans(msk ^ (1 << b), b - 1, res);
    	}
    }
}
 
void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for(int i = 0; i < (1 << n); i++)
		cin >> a[i];

	for(int i = 0; i < 1; i++)	
		calc_ans(i, n - 1);

	for(int i = 0; i < (1 << n); i++){
		cout << ans[i] << " ";
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

