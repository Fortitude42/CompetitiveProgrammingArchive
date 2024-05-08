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
const int N = 3000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a, b, dp[M][M][2], nxt[M], prv[M];
string s;

int get(int l, int r) {
	return nxt[l] <= r ? b : a;
}


int rec(int l, int r, int tp) {
	int &res = dp[l][r][tp];
	if (res != -1)	
		return res;

	if (l >= r)
		return res = 0;

	res = inf;
	for (int i = l; i <= r; ++i) {
		if (!tp) {

			res = min(res, max(rec(l, i, 1), rec(i + 1, r, 0)) + get(l, i));

		} else {
			if (!l && r == n - 1 && max(rec(l, i - 1, 1), rec(i, r, 0)) + get(i, r) == 1905)
				cerr << i << ' ' << rec(l, i - 1, 1) << ' ' << rec(i, r, 0) << ' ' << get(i, r) << endl;
			res = min(res, max(rec(l, i - 1, 1), rec(i, r, 0)) + get(i, r));
		}
	}
	return res;
}
 
void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> n >> a >> b >> s;
	nxt[n] = n;
	for (int i = n - 1; i >= 0; --i)
		nxt[i] = s[i] == 'B' ? i : nxt[i + 1];

	prv[0] = s[0] == 'B' ? 0 : -1;
	for (int i = 1; i < n; ++i)
		prv[i] = s[i] == 'B' ? i : prv[i - 1];

//	cerr << rec(0, 3, 1) << endl;
	cout << rec(0, n - 1, 1) << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}