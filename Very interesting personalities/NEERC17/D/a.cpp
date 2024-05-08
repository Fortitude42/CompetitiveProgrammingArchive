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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vector<pair<pii, int>> ans;

void solve1(int a, int b, int c) {
	for (int x = 1; x <= N && ans.empty(); x++) {
		for (int y = 1; y <= N && ans.empty(); y++) {
			for (int z = 1; z <= N && ans.empty(); z++) {
				int ca = x + y - 1;
				int cb = x + z - 1;
				int cc = y + z - 1;
				if (ca > a || cb > b || cc > c)
					continue;
				if (a > x * y || b > x * z || c > y * z)
					continue;
				
				ans.pb({{1, 1}, 1});
				for (int i = 2; i <= max({x, y, z}); i++) {
					if (i <= x)
						ans.pb({{i, 1}, 1});
					if (i <= y)
						ans.pb({{1, i}, 1});
				   	if (i <= z)
				   		ans.pb({{1, 1}, i});
				}
				
				int ix, iy, iz;
				
				ix = 2; iy = 2;
				while (ca < a) {
					ans.pb({{ix, iy}, 1});
					if (iy == y) {
						iy = 2;
						ix++;
					} else {
						iy++;
					}
					ca++;
				}
				ix = 2; iz = 2;
				while (cb < b) {
					ans.pb({{ix, 1}, iz});
					if (iz == z) {
						iz = 2;
						ix++;
					} else {
						iz++;
					}
					cb++;
				}
				iy = 2; iz = 2;
				while (cc < c) {
					ans.pb({{1, iy}, iz});
					if (iz == z) {
						iz = 2;
						iy++;
					} else {
						iz++;
					}
					cc++;
				}
			}
		}
	}
}
 
void solve() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	for (int i = 0; i < min({a, b, c}); i++) {
		solve1(a - i, b - i, c - i);
		if (!ans.empty()) {
			for (int j = 0; j < i; j++) {
				ans.pb({{-100 + j, -100 + j}, -100 + j});
			}
			break;
		}
	}

	if (ans.empty()) {
		printf("-1\n");
		return;
	}

	set<pii> xy, xz, yz;
	for (auto it : ans) {
		xy.insert(it.fi);
		xz.insert({it.fi.fi, it.se});
		yz.insert({it.fi.se, it.se});

		assert(abs(it.fi.fi) <= 100);
		assert(abs(it.fi.se) <= 100);
		assert(abs(it.se) <= 100);
	}
	assert(sz(xy) == a);
	assert(sz(xz) == b);
	assert(sz(yz) == c);

	assert(sz(ans) <= 1e6);

	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d %d\n", it.fi.fi, it.fi.se, it.se);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

