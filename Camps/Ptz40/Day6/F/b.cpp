#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int N = 500500, mod = 998244353;
 
int n;
ll a[N], b[N];
ll bp(ll x, ll p){
	ll res = 1;
	while(p){
		if(p & 1)
			res = res * x % mod;
		x = x * x % mod;
		p >>= 1;			
	}
	return res;
}
ll inv(ll x){
	return bp(x, mod - 2);
}
main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		a[i] = a[i] + a[i];
	}                         
	stack < int > st;
	st.push(0);
	for(int i = 1; i + 1 < n; i++){
		st.push(i);
		while(st.size() >= 2){
			int j = st.top();
			st.pop();
			int q = st.top();
			ll x = a[j] + (j - q - 1) * (a[j] + a[q]) / 2 + (i + 1 - j - 1) * (a[i + 1] + a[j]) / 2;
			ll y = (i + 1 - q - 1) * (a[i + 1] + a[q]) / 2;
			if(x >= y){
				st.push(j);
				break;
			}
		}		
	}
	st.push(n - 1);

	int nxt = -1;
	ll ans = 0;
	while(!st.empty()){
		int i = st.top();
		st.pop();
		ans += a[i];
		if(nxt != -1)
        	ans += (nxt - i - 1) * (a[nxt] + a[i]) / 2;
		nxt = i;
	}
	ans %= mod;
	ans = ans * inv(2 * n) % mod;
	printf("%lld", ans);
}
