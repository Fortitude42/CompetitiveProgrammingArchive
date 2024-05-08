//template by paradox & gege & parasat
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

ll k, dp[20][2][11]; 
vi s;

ll calc(int len, int f, int d) {
	ll &res = dp[len][f][d];
	if (!len)
		return res = 1; 
	
	
	if (res != -1)
		return res;

	res = 0;
	for (int dd = 0; dd < 10; ++dd) {
		if ((f && dd > s[len - 1]) || (d == 1 && dd == 3))
			continue;

		res += calc(len - 1, (f && dd == s[len - 1]), dd);
	}

	return res;
}

ll get(ll x) {
	s.clear();
	while (x) {
		s.pb(x % 10);
		x /= 10;
	}

	memset(dp, -1, sizeof(dp));

	ll res = 0;
	for (int i = 0; i <= s.back(); ++i)
		res += calc(sz(s) - 1, (i == s.back()), i); 	
	res--;

	return res;
}

void solve() {
	cin >> k;

	ll l = 1, r = INF*5, res = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (get(mid) >= k) {
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}

	cout << res << endl;
}

main () {
	fastio
	//file("hotel");
	int TT;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}