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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, a[N], cnt1, cnt2, cnt3, f[N];
unordered_map < int, int > dp[N];

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}

void precalc () {
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;
} 


main () {     
	precalc();

/*	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 1)
			++cnt1;
		else if (a[i] == 2)	
			++cnt2;
		else
			++cnt3;
		sum += a[i];				
	}

	if (sum != 2*n - 2 || cnt1 - cnt3 != 2) {
		cout << 0 << endl;
		return 0;
	}*/
	cin >> cnt3 >> cnt2;

	int ans = 1;
	for (int i = 1; i <= cnt3; ++i)
		ans = ans * 1ll * (2*i - 1) % mod;
	


	for (int i = 1; i <= cnt2; ++i)
		ans = ans * 1ll * (cnt3*2 + i) % mod;
	cerr << ans << endl;				
	cout << ans * 1ll * f[cnt3] % mod << endl;
}                                         	