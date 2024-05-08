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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int ans[M];
 
void solve() {
	int n;
	ll k;
	scanf("%d %lld", &n, &k);
	n += 1;

	vector<int> an;

	for (int a = 1; a <= n; a++) {
		ll A = 2;
		ll B = 2ll * (a - n);
		ll C = 1ll * (n - a) * (n - a) - n + a - 2ll * k + 1ll * a * (a - 1);

		ll D = B * B - 4ll * A * C;
		
		ll DD = sqrtl(D);
		if (DD * DD != D)
			continue;
		
		int b = (-B + DD) / (2 * A);
		int c = (-B - DD) / (2 * A);
		if (b < 0 || c < 0 || a + b + c != n)
			continue;
		
		if (b < c)
			swap(b, c);
	
	    vector<int> cur = {a, b, c};
		an = cur;
	}

	if (an.empty()) {
		printf("-1\n");
		return;
	}

	int cur = 0;
	for (int cnt : an) {
		if (!cnt)
			continue;
		ans[cur++] = 1;
		while (--cnt)
			ans[cur++] = 0;
	}

	for (int i = 1; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
