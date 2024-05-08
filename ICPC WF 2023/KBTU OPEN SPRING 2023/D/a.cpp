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

 
int k, x;
vi ans;
set < int > q1, q2;

void rec() {
	if (!sz(ans)) {
		q1.erase(x);
		ans.pb(x);
		rec();
		return;
	}

	if (sz(ans) == k) {
		cout << k << endl;
		for (auto x : ans)
			cout << x << ' ';
		exit(0);
	}
	
	int l = 0, r = k + 1;
	while (1) {			
		l = *q1.upper_bound(l);
		if (q2.count(abs(ans.back() - l))) {
			q1.erase(l);
			q2.erase(abs(ans.back() - l));
			ans.pb(l);
			rec();

			q1.insert(l);
			ans.ppb();
			q2.insert(abs(ans.back() - l));
		}

		auto it = q2.lower_bound(r);
		it--;
		r = *it;

		if (q2.count(abs(ans.back() - r))) {
			q1.erase(r);
			q2.erase(abs(ans.back() - r));
			ans.pb(r);
			rec();

			q1.insert(r);
			ans.ppb();
			q2.insert(abs(ans.back() - r));
		}
	}
}

void solve() {
	cin >> k >> x;
	k = (1 << k);
	for (int i = 1; i <= k; ++i) {
		q1.insert(i);
		if (i < k)
			q2.insert(i);
	}
	rec();
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}