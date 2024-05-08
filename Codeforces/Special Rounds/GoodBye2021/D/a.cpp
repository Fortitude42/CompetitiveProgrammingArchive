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
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], x, prv[M], d[M], dp[M];
ll s[M], mx[M][20];
 
void build () {
	for (int i = 2; i < M; ++i)
		d[i] = d[i >> 1] + 1;

	for (int i = 1; i <= n; ++i)
		mx[i][0] = s[i];

	for (int j = 1; j < 20; ++j)
		for (int i = 0; i + (1 << j) - 1 <= n; ++i)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
}

ll get(int l, int r) {
	if (l > r)
		return -INF;

	int D = d[r - l + 1];
	return max(mx[l][D], mx[r - (1 << D) + 1][D]);
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	
	scanf("%d", &x);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + (a[i] - x);

	build();

	for (int i = 1; i <= n; ++i) {
		int l = 0, r = i - 1;
		prv[i] = i - 1;

		while (l <= r) {
			int mid = (l + r) >> 1;
			if (get(mid, i - 2) > s[i]) 
				l = mid + 1;
			else {
				r = mid - 1;
				prv[i] = mid;
			}	
		}
	}



	for (int i = 1; i <= n; ++i)
		s[i] = prv[i];

	build();


	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1];

		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (get(mid, i) < mid) {
				dp[i] = max(dp[i], dp[max(0, mid - 2)] + (i - mid + 1));
				r = mid - 1;
			} else
				l = mid + 1;
		}
	}

	cout << dp[n] << endl;
}

main () {
	int TT;
	TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}