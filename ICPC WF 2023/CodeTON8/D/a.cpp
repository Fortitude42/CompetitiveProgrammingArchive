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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, k;
int a[M][M], ind[M];
vector < int > dp[M];
 
void solve() {
	cin >> n >> k;
	++n;

	for (int i = 2; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			cin >> a[i][j];

	dp[0] = {0};
	dp[1] = {0};

	for (int r = 2; r <= n; ++r) {
		dp[r].clear();

		memset(ind, 0, sizeof ind);

		set < pii > q;
		for (int l = r + 1; l > 1; --l) 
			q.insert(mp(-dp[l - 2][0] - a[l][r], l));

		while (sz(q) > 0 && sz(dp[r]) < k) {
			int l = q.begin()->s;
			dp[r].pb(-q.begin()->f);

			q.erase(q.begin());

			++ind[l - 2];
			if (ind[l - 2] < sz(dp[l - 2]))
				q.insert(mp(-dp[l - 2][ind[l - 2]] - a[l][r], l));
		}
	}

	assert(sz(dp[n]) == k);
	for (auto x : dp[n])
		cout << x << ' ';
	cout << "\n";
}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}