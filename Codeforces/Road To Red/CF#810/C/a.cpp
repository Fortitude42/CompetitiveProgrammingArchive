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
const int N = 2e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int dp[M][8][8];
string s;

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int rec(int pos, int mask1, int mask2) {
	int &res = dp[pos][mask1][mask2];
	if (res != -1)
		return res;

	if (pos == sz(s))
		return res = (mask2 == 7);
		
	
	res = 0;
	for (int mask = 0; mask < 8; ++mask) {		

		int nmask1 = mask1;	
		for (int i = 0; i < 3; ++i) {
			int b1 = (mask >> i) & 1, b2 = (mask1 >> i) & 1;
			if (!b2 && s[pos] == '0' && b1) {
				nmask1 = -1;
				break;
			}

			if (!b1 && s[pos] == '1')
				nmask1 |= (1 << i);
		}

		if (nmask1 == -1)
			continue;
		
		int nmask2 = mask2;
		for (int i = 0; i < 3; ++i) {
			bool un = 1;
			for (int j = 0; j < 3; ++j)
				if (i != j && ((mask >> i) & 1) == ((mask >> j) & 1)) {
					un = 0; 
					break;
				}

			if (un)
				nmask2 |= (1 << i);
		}

		add(res, rec(pos + 1, nmask1, nmask2));
	}

	return res;
} 

void solve() {
	memset(dp, -1, sizeof(dp));
	fastio
	cin >> s;
	cout << rec(0, 0, 0);
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}