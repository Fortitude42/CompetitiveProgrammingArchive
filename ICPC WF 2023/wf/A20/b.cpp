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
const int N = 1e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int R, C;
vector < int > ans(5);



void solve() {
	ans[0] = inf;

	cin >> R >> C;

	vector < pii > coords = {
		mp((R + 1)/2 - 1, (C + 1)/2 - 1),
		mp((R + 1)/2 - 1, C/2),
		mp(R/2 - 1, (C + 1)/2 - 1),
		mp(R/2, C/2)
	};

	for (int p = 0; p < C; ++p) {
		int l = 0, r = R - 1, s = 0;
		while (s < 80) {
			++s;
			int rl = (p*1ll*R + l) / C;
			int cl = (p*1ll*R + l) % C;
			int rr = (p*1ll*R + r) / C;
			int cr = (p*1ll*R + r) % C;


			if (l == r) {
				for (auto coord : coords) {
					int cur = abs(coord.f - rl) + abs(coord.s - cl);

					if (cur < ans[0]) {
						ans[0] = cur;
						ans[1] = p + 1;
						ans[2] = rl + 1;
						ans[3] = cl + 1;
						ans[4] = s;
					}
				}
			}
			l = rl;
			r = rr;
		}
	}

	cerr << ans[0] << endl;
	for (int i = 1; i < sz(ans); ++i)
		cout << ans[i] << ' ';

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}