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

int n;
vi vals;
map < int, int > cnt;
 
void solve() {
	cin >> n;
	for (int i = 1; i <= 3*n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
		vals.pb(x);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	while (1) {
		for (auto x : vals)
			if (cnt[x] == 1) {
				cout << "Y";
				return;
			}

		//there is no 1
		int mx = 0, y = -1;
		for (auto x : vals) 
			if (cnt[x] % 3 != 2 && mx < cnt[x]) {
				mx = cnt[x];
				y = x;
			}

		if (!mx) {
			for (auto x : vals) 
				if (mx < cnt[x]) {
					mx = cnt[x];
					y = x;
				}				
		}
		
		//no number left
		if (!mx) {
			cout << "N";
			return;
		}

		//both players take y
		cnt[y] -= 2;

		if (cnt[y] == 1) {
			cnt[y]--;
			continue;
		}

		int mxx = 0, yy = -1;
		for (auto x : vals) {
			if (cnt[x] % 3 != 0 && mxx < cnt[x]) {
				mxx = cnt[x];
				yy = x;
			}
		}

		if (!mxx) {
		for (auto x : vals) {
			if (mxx < cnt[x]) {
				mxx = cnt[x];
				yy = x;
			}
		}
		}

		assert(mxx > 0);
		--cnt[yy];
	}

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}