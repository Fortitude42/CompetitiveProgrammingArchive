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
const int N = 5000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, t[M], d[M], tt[M], dd[M], mn[M], pref[M], val[M]; 
bool used[M];

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> d[i];
		sum += t[i];
		if (sum > inf) {
			cout << "*";
			return;
		}			
	}

	vector < pii > ord;
	for (int i = 1; i <= n; ++i)
		ord.pb({d[i], i});

	sort(all(ord));
	vi ans;
	while (sz(ans) < n) {
		mn[0] = inf*2;
		int m = 0;

		for (int i = 1; i <= n; ++i)
			if (!used[ord[i - 1].s]) {
				++m;
				dd[m] = d[ord[i - 1].s];
				val[m] = ord[i - 1].s;
				tt[m] = t[ord[i - 1].s];
				pref[m] = pref[m - 1] + tt[m];				
				mn[m] = min(mn[m - 1], dd[m] - pref[m]);
			}

		if (mn[m] < 0) {
			cout << "*";
			return;
		}

		int j = inf;
		for (int i = 1; i <= m; ++i)
			if (mn[i - 1] - tt[i] >= 0)
				j = min(j, val[i]);

		ans.pb(j);
		used[j] = 1;

		for (int i = 1; i <= n; ++i)
			d[i] -= t[j];
	}
	for (auto x : ans)
		cout << x << ' ';

}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}