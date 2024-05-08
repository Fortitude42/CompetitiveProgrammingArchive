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


int n, k; 
          

void solve() {
	cin >> n >> k;
	if (k == n || n - k == 2) {
		cout << -1 << endl;
		return;
	}
	if (!k && (n == 4 || n == 5)) {
		cout << n << endl;
		for (int i = 1; i <= n; ++i)
			cout << i << ' ' << (i % n) + 1 << endl;
		return;
	}
	vector < pii > ans;
	
	if (!k && n == 6) {
		cout << 7 << endl;
		for (int i = 1; i <= 5; ++i)
			cout << i << ' ' << (i % 5) + 1 << endl;
		cout << 1 << ' ' << 6 << endl;
		cout << 3 << ' ' << 6 << endl;
		return;
	}


	for (int i = 1; i <= n; ++i)
		if (i != k + 1)
			ans.pb({i, k + 1});
	
	for (int i = k + 2; i + 1 <= n; i += 2)
		ans.pb({i, i + 1});

	if ((n - k - 1) & 1)	
		ans.pb({n - 1, n});

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
}

main () {
	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

