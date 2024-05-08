//template by paradox & gege & parasat
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
const int N = 2000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 117;
const ll INF = 1e18;

int n, ans = inf, timer, h[M*M];
set < pii > q;
 
int get(int w) {
	if (h[w] != -1)
		return h[w];

	cout << "? " << w << endl;
	cin >> h[w];
	q.insert(mp(w, h[w]));
	++timer;
	if (h[w])
	ans = min(ans, h[w]*w);

	if (timer == n + 30) {
		cout << "! " << ans << endl;
		exit(0);
	}

	return h[w];
}


void solve() {
	memset(h, -1, sizeof(h));
	cin >> n;
	int l = 1, r = N*n + n - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (get(mid) == 1) 
			r = mid - 1;
		else
			l = mid + 1;
	}

	int h = 2;
	while (h <= n) {
		int w = (ans - 1) / h;
		if (!w)
			break;
		int hh = get(w);
		if (!hh)
			break;
		h = max(h, hh);
	}

	cout << "! " << ans << endl;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}