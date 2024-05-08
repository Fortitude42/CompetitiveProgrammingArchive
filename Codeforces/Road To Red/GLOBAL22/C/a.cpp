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
const int N = 1e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 11;
const ll INF = 1e18;

int dp[2][2][M][M];
 
int rec(int f1, int f2, int c1, int c2) {
	int &res = dp[f1][f2][c1][c2];
	if (res != -1)
		return res;

	if (!c1 && !c2)
		return (1^f1^f2);
	
	if (c1 > 0) {
		int nf1 = f1;
		if (!f2)
			nf1 ^= 1;
		if (!rec(nf1, f2 ^ 1, c1 - 1, c2))
			return res = 1;
	}

	if (c2 > 0) {
		if (!rec(f1, f2 ^ 1, c1, c2 - 1))
			return res = 1;
	}

	return res = 0;
}

int n;
void solve() {
	cin >> n;
	int c1 = 0, c2 = 0;
	while (n--) {
		int x;
		cin >> x;
		if (x & 1)
			++c1;
		else
			++c2;	
	}

	puts(rec(0, 0, c1, c2) ? "Alice" : "Bob");
}

main () {
	memset(dp, -1, sizeof(dp));
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}