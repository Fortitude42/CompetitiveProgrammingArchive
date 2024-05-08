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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int f[N], m, n; 

int fact (int x) {
	int res = 1;
	for (int i = 1; i <= x; ++i)
		res = res * 1ll * i % m;

	return res;			
}
int get (int x) {
	return x >= N ? 0 : f[x];
}

main () {
	cin >> n >> m;
	f[4] = 4 % m;
	for (int i = 5; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % m;

	int res;
	if (n == 1) 
		res = 0;
	else if (n == 2) 
		res = 1;
	else if (n == 3)
		res = 5;
	else
		res = 5 * get(n) % m;
	
	res = fact(min(n, m)) - 1 - res;
	if (res < 0)
		res += m;

	cout << res << endl;	
}