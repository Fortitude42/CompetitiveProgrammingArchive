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

int n, k, res[M];
pii a[M];

 
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].f;
		a[i].s = i;
	}

	for (int i = 1; i <= k; ++i) {
		res[i] = 0;
	}

	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);

	int l = a[1].s, r = a[1].s;
	for (int i = 1; i <= n; ++i) {
		l = min(l, a[i].s);
		r = max(r, a[i].s);
		res[a[i].f] = max(res[a[i].f], r - l + 1);
	}

	for (int i = 1; i <= k; ++i)
		cout << res[i]*2 << ' ';
	cout << "\n";

	
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