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
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 444;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], k[M], bl[M], to[M];
ll cost[M];
pii b[M];
vi vals;

 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		vals.pb(a[i]);
		vals.pb(a[i] - 1);
		bl[i] = (i / block) + 1;
		b[i] = {a[i], i};
	}

	for (int i = 1; i <= n; ++i)
		scanf("%d", &k[i]);

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	reverse(all(vals));

	sort(b + 1, b + 1 + n);

	to[n + 1] = n + 1;
	cost[n + 1] = 0;
	bl[n + 1] = inf;

	for (int i = n; i > 0; --i)
		if (bl[i] == bl[i + 1]) {
			to[i] = to[i + 1];
			cost[i] = cost[i + 1] + a[i];
		} else {
			to[i] = i + 1;
			cost[i] = a[i];
		}

	int i = n;
	ll ans = 0;

	for (auto x : vals) {
		while (i > 0 && b[i].f == x) {
			for (int j = b[i].s; bl[j] == bl[b[i].s]; --j) {
				int y = min(n + 1, j + k[j]);
				ll add = a[j] * 1ll * k[j];

				if (a[j] < x) {
					y = j + 1;
					add = a[j];
				}

				if (bl[y] != bl[j]) {
					to[j] = y;
					cost[j] = add;
				} else {
					to[j] = to[y];
					cost[j] = cost[y] + add;
				}						
			}

			--i;
		}

		int i = 1;
		ll res = 0;
		while (i <= n) {
			res += cost[i];
			i = to[i];
		}

		ans = max(ans, res);
	}

	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

