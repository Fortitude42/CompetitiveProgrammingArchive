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

int n, k;
ll w[70], a, b, c[53][53];

void precalc () {
	for (int i = 0; i < 53; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
}

 
ll get (ll a) {
	ll mask = 0, sum = 0;
	sum = 0;
	for (int i = n - 1; i >= 0; --i)
		if (sum + w[i] <= a) {
			mask |= (1ll << i);
			sum += w[i];
		}

	ll res = 0, cur = k;
	for (int i = n - 1; i >= 0 && cur >= 0; --i) 
		if (mask & (1ll << i)) {
			res += c[i][cur];
			cur--;
		}				

	if (__builtin_popcountll(mask) == k)
		++res;

	return res;		
}

main () {
	precalc();
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	cin >> a >> b;

	sort(w, w + n);

	cout << get(b) - get(a - 1) << endl;
}