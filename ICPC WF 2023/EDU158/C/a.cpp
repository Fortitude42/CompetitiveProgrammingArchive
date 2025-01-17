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

int n, a[M], b[M]; 
vi ans, res;

bool check() {
	for (int i = 2; i <= n; ++i)
		if (a[i] != a[1])
			return 0;

	return 1;
}


void f(int x) {
	res.pb(x);
	for (int i = 1; i <= n; ++i) {
		a[i] = (a[i] + x) / 2;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	int mx = *max_element(a + 1, a + 1 + n);

	for (int j = 30; j >= 0; --j) {
		for (int i = 1; i <= n; ++i)
			a[i] = b[i];


		int x = (1 << j) - 1;
		int y = x - (mx & x);
		res.clear();
		while (!check()) {
			f(y);
			y = 0;
		}

		if (j == 30 || sz(ans) > sz(res))
			ans = res;
	}
	cout << sz(ans) << "\n";
	if (sz(ans) <= n && sz(ans) > 0) {
		for (auto x : ans)
			cout << x << ' ';
		cout << "\n";
	}
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