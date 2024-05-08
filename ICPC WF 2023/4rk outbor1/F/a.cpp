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

int n, m, a[M][M];
bool p[M*M];


void precalc() {
	p[1] = 1;

	for (int i = 2; i <= N*N; ++i)
		if (!p[i]) {
			for (int j = i + i; j <= N*N; j += i)
				p[j] = 1;
		}
}
 
void solve() {
	cin >> n >> m;
	if (n*m == 1) {
		cout << "YES\n";
		cout << 1 << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = 0;

	vi pr, npr;
	for (int i = 1; i <= n*m; ++i)
		if (!p[i])
			pr.pb(i);
		else
			npr.pb(i);

	if ((sz(pr) - 1) % 2 != 0) {
		cout << "NO\n";
		return;
	}


	a[1][1] = 2;
	int x = 1;

	if ((sz(pr) - 1) % 4 == 2) {
		if (sz(pr) - 1 < 6 || n < 3  || m < 3) {
			cout << "NO\n";
			return;
		}

		a[1][2] = pr[x++];
		a[1][3] = pr[x++];
		a[2][1] = pr[x++];
		a[2][2] = pr[x++];
		a[3][1] = pr[x++];
		a[3][3] = pr[x++];
	}

	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j) {
			if (x == sz(pr) || a[i][j] || a[i + 1][j] || a[i + 1][j + 1] || a[i][j + 1])
				continue;
			a[i][j] = pr[x++];
			a[i][j + 1] = pr[x++];
			a[i + 1][j] = pr[x++];
			a[i + 1][j + 1] = pr[x++];
		}

	if (x != sz(pr)) {
		cout << "NO\n";
		return;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!a[i][j]) {
				assert(sz(npr) > 0);
				a[i][j] = npr.back();
				npr.ppb();
			}

	assert(!sz(npr));
	cout << "YES\n";
	for (int i = 1; i <= n; ++i, cout << "\n")
		for (int j = 1; j <= m; ++j)
			cout << a[i][j] << ' ';
}

main () {
	precalc();
//	fastio
  int TT;
  TT = 1;
  	cin >> TT;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}