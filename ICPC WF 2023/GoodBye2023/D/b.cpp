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

void solve() {
	cin >> n;
	if (n == 1) {
		cout << 1 << "\n";
		return;
	}

	vector < string > s;
	string l[] = {"169", "961"};
	for (int d = 0; 3 + 2*d <= n; ++d) {
		for (int i = 0; i < 2; ++i) {
			string t;
			for (int j = 0; j < 3; ++j) {
				t.pb(l[i][j]);
				if (j < 2) {
					for (int x = 0; x < d; ++x)
						t.pb('0');
				}
			}

			if (sz(t) > n)
				break;
			while (sz(t) < n)
				t.pb('0');
			s.pb(t);
		}
		
	}

	string t = "196";
	while (sz(t) < n)
		t += '0';
	s.pb(t);

	assert(sz(s) >= n);
	for (int i = 0; i < min(n, sz(s)); ++i)
		cout << s[i] << "\n";

}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}