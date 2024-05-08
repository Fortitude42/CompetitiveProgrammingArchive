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

int n, a[M];
int q, t[M], timer;
set < pair < pii, int > > s;
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s.insert(mp(mp(i, i), a[i]));	
	}


	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		++timer;
		while (1) {
			auto it = s.lower_bound(mp(mp(l, 0), 0));
			if (it == s.end() || it->f.f > r)
				break;

			pair < pii, int > cur = *it;
			s.erase(it);
			if (cur.f.s > r) 
				s.insert(mp(mp(r + 1, cur.f.s), cur.s));
			t[cur.s] = timer;
		}

		auto it = s.lower_bound(mp(mp(l, 0), 0));
		if (it != s.begin()) {
			it--;
			pair < pii, int > cur = *it;
			if (cur.f.s >= l) {
				s.erase(cur);
				assert(cur.f.f < l);
				s.insert(mp(mp(cur.f.f, l - 1), cur.s));
				if (cur.f.s > r)
					s.insert(mp(mp(r + 1, cur.f.s), cur.s));
				t[cur.s] = timer;
			}
		}


		int val = 0;
		while (t[val] == timer)
			++val;

		s.insert(mp(mp(l, r), val));
		cout << val << "\n";
	}
	

}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}