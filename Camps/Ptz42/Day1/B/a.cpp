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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M][M], row[M], col[M];
 
void solve() {
	cin >> n;
	vi c;
	for (int i = 1; i <= n*n; ++i)
		c.pb(i > (n*(n + 1) / 2));

	do {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				a[i][j] = c[i*n + j];
				row[i] += a[i][j];
				col[j] += a[i][j];
			}

		sort(row, row + n);
		sort(col, col + n);

		bool ok = 1;
		for (int i = 0; i < n; ++i)
			if (row[i] != i || col[i] != i) {
				ok = 0; 
				break;
			}

		if (!ok)
			continue;

		if (ok) {
			for (int i = 0; i < n; ++i, cout << endl)
				for (int j = 0; j < n; ++j)
					cout << a[i][j];
			cout << endl;
		}

	} while (next_permutation(all(c)));
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
