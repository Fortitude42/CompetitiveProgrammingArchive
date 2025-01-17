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
const int N = 1e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

bool ans[M][M];
bool col[M], row[M];
 
void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == 1) {
		if (!k) {
			printf("YES\n.\n");
		} else {
			printf("NO\n");
		}
		return;
	}

	int cur = n * n - 2;
	ans[1][1] = true;
	col[1] = row[1] = true;
	ans[2][n - 1] = true;
	row[2] = col[n - 1] = true;

	for (int i = 1; i <= n; i++) {
		if (row[i])
			continue;
		for (int j = 1; j <= n; j++) {
			if (col[j])
				continue;

			row[i] = true;
			col[j] = true;
			ans[i][j] = true;
			cur--;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!row[i])
			ans[i][1] = true, cur--;
		if (!col[i])
			ans[1][i] = true, cur--;
	}

	if (cur < k) {
		printf("NO\n");
		return;
	}

	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!ans[i][j] && cur > k) {
				ans[i][j] = true;
				cur--;
			}
			printf(ans[i][j] ? "." : "#");
		}
		printf("\n");
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
