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

 
int a, b, c, l[M], r[M];
ll k;

void solve() {
	cin >> a >> b >> c >> k;

	ll tot = 0;
	for (int i = l[a]; i <= r[a]; ++i) {
		int lf = max(l[b], l[c] - i);
		int rg = min(r[b], r[c] - i);

		if (lf > rg)
			continue;

		int cur = rg - lf + 1;
//		cerr << i << ' ' << lf << ' ' << rg << ' ' << tot << ' ' << cur << endl;
		if (tot + cur >= k) {
			cout << i << " + " << lf + (k - tot - 1) << " = " << i + lf + k - tot - 1 << "\n";
			return;
		}

		tot += cur;
	}

	cout << -1 << "\n";
}

main () {
	l[1] = 1, r[1] = 9;
	for (int i = 2; i <= 7; ++i) {
		l[i] = r[i - 1] + 1;
		r[i] = r[i - 1]*10 + 9;
	}
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}