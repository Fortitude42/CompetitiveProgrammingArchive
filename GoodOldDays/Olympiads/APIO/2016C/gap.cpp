#include "gap.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 1300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
ll a, b, ans, res, nn;
 
 
long long findGap(int T, int n) {
    nn = n;
	srand(time(0));
	
	if (T == 1) {
		ll l = 0, r = INF;
		vector < ll > v;
		while (l <= r) {
			if (sz(v) >= n)
				break;
			MinMax(l, r, &a, &b);			
			v.pb(a);
			v.pb(b);
			l = a + 1;
			r = b - 1;
		}
 
		sort(all(v));
		ll ans = 0;
		for (ll i = 1; i < sz(v); ++i)
			ans = max(ans, v[i] - v[i - 1]);
		return ans;
	}
 
	MinMax(0, INF, &a, &b);
	if (n == 2) 
		return b - a;
	
	ll ans = (b - a + n - 1) / n;
	ll l = a + 1, r, prv = a;

	while (n--) {
		r = min(INF, l + ans);
		if (l > r)
			break;
		MinMax(l, r, &a, &b);
		if (a != -1) {
			ans = max(ans, a - prv);
			prv = b;
			r = b;
		}

		l = r + 1;
	}


	return ans;
}