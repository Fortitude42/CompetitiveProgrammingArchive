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

 
void solve() {
	int n;
	scanf("%d", &n);
	int m = n;
	vi dv;
	for (int i = 2; n / i >= i; i++) {
		if (n % i)
			continue;
		dv.pb(i);
		while (n % i == 0)
			n /= i;
	}
	if (n > 1)
		dv.pb(n);

	if (sz(dv) == 1) {
		printf("NO\n");
		return;
	}
	
	vector<pii> ans;
	n = m;

	if (dv[0] == 2) {
		int pren = n - 1 - dv[1];
		ans.pb({pren / 2, n / 2});
		ans.pb({1, n / dv[1]});
	} else if (2ll * dv[0] * dv[1] <= n) {
//		cerr << "hard!\n";
		for (int k = 1; k < dv[0]; k++) {
			if (dv[1] * k % dv[0] == dv[0] - 1) {
				ans.pb({k, n / dv[1]});
				int k2 = (n - 1 - dv[1] * k) / dv[0];
				ans.pb({k2, n / dv[0]});
				break;
			}
		}
		assert(!ans.empty());
	} else {
		dv[1] = dv.back();
		for (int i = 1; dv[1] < (n - 1) / i; i++) {
			if ((n - 1 - i * dv[1]) % dv[0])
				continue;
			int j = (n - 1 - i * dv[1]) / dv[0];
			ans.pb({j, n / dv[0]});
			ans.pb({i, n / dv[1]});
			break;
		}
	}

	

	if (ans.empty()) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	printf("%d\n", sz(ans));
	for (pii &it : ans)
		printf("%d %d\n", it.fi, it.se);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

