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

int n, m;
int a[M];
int s1[M], s2[M];
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	s1[0] = 0;
	for (int i = 1; i < n; ++i) {
		s1[i] = s1[i - 1];
		if (i == 1 || a[i] - a[i - 1] > a[i + 1] - a[i])
			s1[i]++;
		else
			s1[i] += a[i + 1] - a[i];
	}

	s2[n + 1] = 0;
	for (int i = n; i > 1; --i) {
		s2[i] = s2[i + 1];
		if (i == n || a[i] - a[i - 1] < a[i + 1] - a[i])
			s2[i]++;
		else
			s2[i] += a[i] - a[i - 1];
	}

	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (x < y)
			cout << s1[y - 1] - s1[x - 1] << "\n";
		else
			cout << s2[y + 1] - s2[x + 1] << "\n";
	}
}

main () {
  int TT;
  TT = 1;
  	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}