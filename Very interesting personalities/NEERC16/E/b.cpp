//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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

vector<pair<char, pii>> upds;
int queries[M];
map<ll, int> pos;
ll p[M];

ll ans[M];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		char c;
		int t, k;
		cin >> c >> t >> k;
		upds.pb({c, {t, k}});
	}

	for (int i = 1; i <= q; i++) {
		int bal;
		cin >> bal;
		deque<pair<ll, ll>> q;
		ll ans = 0, cur = bal;
		for (auto it : upds) {
			int k = it.se.se;
			int t = it.se.fi;

			if (it.fi == '+') {
				while (!q.empty() && k) {
					pair<ll, ll> f = q.front();
					q.pop_front();
					if (f.fi <= k) {
						ans += 1LL * f.fi * (t - f.se);
						k -= f.fi;
					} else {
						ans += 1LL * k * (t - f.se);
						f.fi -= k;
						k = 0;
						q.push_front(f);
					}
				}
				cur += k;
			} else {
				if (k <= cur) {
					cur -= k;
				} else {
					k -= cur;
					cur = 0;
					q.push_back({k, t});
				}
			}
		}

		if (!q.empty())
			cout << "INFINITY\n";
		else
			cout << ans << "\n";
	}
}

main () {
//	file("expect");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

