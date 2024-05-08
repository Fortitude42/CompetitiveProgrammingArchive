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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int d, p, a, m;

int powmod (int a, int b, int m) {
	int res = 1;
	while (b > 0)
		if (b & 1) {
			res = (res * a) % m;
			--b;
		}
		else {
			a = (a * a) % m;    	
			b >>= 1;
		}
	return res % m;
}
 
int solve (int a, int b, int m) {
	int n = (int) sqrt (m + .0) + 1;
	map<int,int> vals;
	for (int i=n; i>=1; --i)
		vals[ powmod (a, i * n, m) ] = i;
	for (int i=0; i<=n; ++i) {
		int cur = (powmod (a, i, m) * b) % m;
		if (vals.count(cur)) {
			int ans = vals[cur] * n - i;
			if (ans < m)
				return ans;
		}
	}
	return -1;
}

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}
 
int generator (int p) {
	vector<int> fact;
	int phi = p-1,  n = phi;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);
 
	for (int res=2; res<=p; ++res) {
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}
                          	
 
main () {
	cin >> d;
	while (d--) {
		cin >> p >> a >> m;
		int n = -INF;
		{
			int x = generator(p);

			if (x != -1) {
			int xy = ((a - powmod(x, m, p)) + p) % p;
			int y = solve(x, xy, p);
			if (y != -1) {

			int k1, k2, g;

			if (find_any_solution(p, -p + 1, y - x, k1, k2, g)) {
				n = k1 * p + x;
//				assert(k1 * p + x == k2 * (p - 1) + y);
			}
			}
			}
		}


/*		while (n < 0 && n > -INF) {
			n %= (p*(p - 1));		
			n += p*(p - 1);        
		}*/

		if (n == -INF)
			cout << "NO\n";
		else
			cout << "YES " << n << endl;
			

	}
}
