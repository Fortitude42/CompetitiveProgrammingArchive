//by paradox & gege & parasat
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


unordered_map < int, int > dp[M][18];
queue < pair < int, pii > > q;
 
void solve() {

}

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

main () {
	int TT;
	TT = 1;
	dp[1][0][0] = 1;
	q.push({1, {0, 0}});

	while (sz(q)) {
		pair < int, pii > v = q.front();
		q.pop();


		int p = v.f, len = v.s.f, s = v.s.s;
		for (int x = 2; x * p <= N; ++x) {
			if (!dp[x * p][len + 1].count(s + x)){
				dp[x * p][len + 1][s + x] = 0;
				q.push(mp(x * p, mp(len + 1, s + x)));
			}
			add(dp[x * p][len + 1][s + x], dp[p][len][s]);
		}
	}
	
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
