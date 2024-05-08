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

int n, m, k, cnt[31], a[M];


 
void solve() {
	ll sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	pair < ll, int > ans = {sum, 0};
	if (k > 0) {
		for (int b = 0; b < m; ++b) {
			memset(cnt, 0, sizeof(cnt));
			ll curs = sum;
			int curx = (1 << b);

			int sz = 0;

			for (int i = 1; i <= n; ++i) 
				if (!(a[i] & (1 << b))) {
					curs += (1ll << b);
					++sz;
					for (int bb = 0; bb < b; ++bb)
						if (a[i] & (1 << bb))
							++cnt[bb];
				}
			
			

			vector < pair < ll, int > > v;
			for (int bb = 0; bb < b; ++bb)
				if (cnt[bb] < sz - cnt[bb])
					v.pb(mp((1ll << bb) * (sz - 2*cnt[bb]), bb));

			sort(all(v));
			reverse(all(v));
			for (int i = 0; i < sz(v) && i < k - 1; ++i) {
				curs += v[i].f;
				curx |= (1 << v[i].s);
			}

			ans = max(ans, mp(curs, -curx));
		}
	}

	cout << -ans.s << endl;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}