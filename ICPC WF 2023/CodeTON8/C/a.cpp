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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, x, y;
int a[M];

 
void solve() {
	cin >> n >> x >> y;
	for (int i = 1; i <= x; ++i)
		cin >> a[i];


	sort(a + 1, a + 1 + x);
	int ans = x - 2;

	vi d[2];

	for (int i = 1; i < x; ++i) {
		int j = a[i + 1] - a[i] - 1;
		d[j & 1].pb(j);		
	}


	int j = a[1] - a[x] + n - 1;
	d[j & 1].pb(j);


	for (int jj = 1; jj >= 0; --jj) {
		sort(all(d[jj]));
		for (auto x : d[jj]) {
			if (x == 1)
				continue;
			int xx = x / 2;
			int cur = min(xx, y);
			ans += 2*cur;
			y -= cur;
			xx -= cur;
			if (jj == 1 && xx == 0)
				++ans;
		}
	}

	for (int i = 2; i <= x; ++i)
		if (a[i] == a[i - 1] + 2)
			++ans;

	if (a[x] + 2 - n == a[1])
		++ans;



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