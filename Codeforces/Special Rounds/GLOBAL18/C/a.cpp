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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
int n;
string a, b;

void solve() {
	cin >> n >> a >> b;
	if (a == b) {
		cout << 0 << endl;
		return;
	}

	bool ok = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] == '1')
			ok = 1;

	if (!ok) {
		cout << -1 << endl;
		return;
	}
	int ans = inf;

	int ab = 0, aa = 0, bb = 0, ba = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '0' && b[i] == '0')
			++bb;
		else if (a[i] == '1' && b[i] == '0')
			++ab;
		else if (a[i] == '1' && b[i] == '1')	
			++aa;
		else
			++ba;
	}
		

	for (int x = 0; x <= 4*n; ++x) {
		if (x > 0) {
			if (!(x & 1)) {
				if (!ba && !bb)
					break;
				if (ba) {
					ba--;
					aa++;
				} else {
					bb--;
					ab++;
				}
			} else {
				if (!ab && !aa)
					break;

				if (ab) {
					ab--;
					++bb;
				} else {
					aa--;
					++ba;
				}
			}
		}
				
		if (!(x & 1) && !ba && !ab) {
			ans = x;
			break;
		}		
	}


	ab = 0, aa = 0, bb = 0, ba = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '0' && b[i] == '0')
			++bb;
		else if (a[i] == '1' && b[i] == '0')
			++ab;
		else if (a[i] == '1' && b[i] == '1')	
			++aa;
		else
			++ba;
	}
		

	for (int x = 0; x <= 4*n; ++x) {
		if (x > 0) {
			if (!(x & 1)) {
				if (!ba && !bb)
					break;
				if (!bb) {
					ba--;
					aa++;
				} else {
					bb--;
					ab++;
				}
			} else {
				if (!ab && !aa)
					break;

				if (!aa) {
					ab--;
					++bb;
				} else {
					aa--;
					++ba;
				}
			}
		}

				
		if ((x & 1) && !aa && !bb) {
			cout << min(ans, x) << endl;
			return;
		}		
	}


	cout << (ans == inf ? -1 : ans) << endl;
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