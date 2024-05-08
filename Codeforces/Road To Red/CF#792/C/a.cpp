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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m;
vi a[M];


void Swap(int j1, int j2) {
	for (int i = 1; i <= n; ++i)
		swap(a[i][j1], a[i][j2]);
}

bool check() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
			if (a[i][j] > a[i][j + 1])
				return 0;
	return 1;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		a[i].resize(m + 1);
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
			if (a[i][j] > a[i][j + 1]) {
				int jj = j;
				for (int j1 = 1; j1 < j; ++j1)
					if (a[i][j1] > a[i][j + 1]) {
						jj = j1;
						break;
					}

				Swap(j + 1, jj);
				if (check()) {
					cout << j + 1 << ' ' << jj << endl;
					return;
				}
				Swap(j + 1, jj);

				jj = j + 1;
				for (int j1 = m; j1 > j; --j1)
					if (a[i][j1] < a[i][j]) {
						jj = j1;
						break;
					}

				Swap(j, jj);
				if (check()) {
					cout << j << ' ' << jj << endl;
					return;
				}
				
				cout << -1 << endl;
				return;
			}
	cout << 1 << ' ' << 1 << endl;
}

main () {
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}