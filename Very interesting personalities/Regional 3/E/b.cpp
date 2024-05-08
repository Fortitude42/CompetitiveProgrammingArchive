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
const int N = 1e7, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int s[M];

int get(ll x){
	vi d, dd;
	while(x){
		d.pb(x % 10);
		if(x % 10)
			dd.pb(x % 10);
		x /= 10;
	}
	
	
	reverse(all(dd));

	int g = 0;          
	            
	sort(all(d));
	do{
		int cur = 0;
		for(auto v : d)
			cur = cur * 10 + v;
	   	g = __gcd(g, cur);
	   	if(g == 1) break;
	}while(next_permutation(all(d)));
	
	return g;
}

int get(string d){
	
	sort(all(d));
	
	int g = 0;

	do{
		int cur = 0;
		for(auto v : d)
			cur = (cur * 10 + v) % 9;
	   	g = __gcd(g, cur);
	}while(next_permutation(all(d)));
	
	return g;
}
 
void solve() {
/*	for(int i = 1; i <= 200000; i++){
		int g = get(i);
		if(!s[g])
			s[g] = i;
	}

	for(int i = 1; i <= 30000; i++) {
		if(s[i])
			cout << i << " -> " << s[i] << " " << s[i] / i << "\n"; 
	}
*/
//	cerr << get(5055555555) << endl;
	cerr << get(222888888) << endl;              
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

