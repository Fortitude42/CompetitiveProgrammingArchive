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

const int N = 300500, inf = 2e9;
int n, a[N], cnt, ans;
main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	a[0] = -inf;
	a[n + 1] = inf;
	for(int i = 1, j = 1; i <= n; i = j){
		while(j <= n && a[i] == a[j])
			j++;

		if(j <= n){
			cnt += (a[i] > a[i - 1] && a[i] > a[j]);
			cnt += (a[i] < a[i - 1] && a[i] < a[j]);
		}
	}
	cnt++;
	while(cnt > (1 << ans))
		ans++; 
	cerr << cnt << endl;
	printf("%d", ans);
}