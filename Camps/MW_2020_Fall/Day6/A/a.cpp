#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


string s; 
vi v;
int sum, cnt, ans;


int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2)
			res = res * a % mod;
		n /= 2;
		a = a * a % mod;
	}

	return res;
}

bool prime (int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return 0;

	return 1;
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}

void rec (int s = 0, int st = 0, int coeff = 1) {
	coeff = coeff * binpow(sz(v), mod - 2) % mod;

	for (auto x : v)
		if (prime(s*10 + x))
			rec(s*10 + x, st + 1, coeff);
		else 
			add(ans, coeff * (st + 1) % mod);		
}


main () {
	cin >> s;
	for (int i = 1; i < 10; ++i)
		if (s[i - 1] == '1')
			v.pb(i);

	rec();
	cout << ans % mod;
}