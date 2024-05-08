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

int n, p;
int a[M], b[M];

 
void solve() {
	cin >> n >> p;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	
	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	set < pii > q1, q2;
	ll ans = 0;

	a[0] = n;
	b[0] = p;

	q1.insert(mp(a[0], 0));
	for (int i = 1; i <= n; ++i)
		q2.insert(mp(b[i], i));

	while (sz(q2) > 0) {
		int i = q1.begin()->s;
		q1.erase(q1.begin());

		ans += b[i];
		--a[i];
		if (a[i] > 0)
			q1.insert(mp(b[i], i));

		int j = q2.begin()->s;
		q2.erase(q2.begin());
		q1.insert(mp(b[j], j));
	}

	cout << ans << "\n";
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