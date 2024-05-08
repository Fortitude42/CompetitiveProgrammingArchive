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
const int N = 2e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, cnt[M], cnt1[M];
vi Sz;
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int c;
		scanf("%d", &c);
		++cnt[c];
	}

	for (int i = 1; i <= n; ++i)
		if (cnt[i] > 0) {
			Sz.pb(cnt[i]);  
			++cnt1[cnt[i]];
		}

	sort(all(Sz));
	Sz.resize(unique(all(Sz)) - Sz.begin());

	int ans = inf;
	for (int s = 1; s <= Sz[0] + 1; ++s) {
		int tot = 0;
		for (auto cnt : Sz) {
			int m = (cnt + s - 1) / s;
			int x = (s - cnt % s) % s;
			if (x > m) {
				tot = -1;
				break;
			}
			tot += m * cnt1[cnt];
		}

		if (tot != -1)
			ans = min(ans, tot);
	}

	printf("%d\n", ans);

	Sz.clear();
	for (int i = 1; i <= n; ++i)
		cnt[i] = cnt1[i] = 0;
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

