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

int n, i[3];
string a[3];
 
void solve() {
	cin >> n;
	cin >> a[0] >> a[1] >> a[2];

	i[0] = i[1] = i[2] = 0;
	string ans = "";

	while (sz(ans) < 3*n) {
		int cnt0 = 0, cnt1 = 0;
		int mx0 = -1, mx1 = -1;

		for (int j = 0; j < 3; ++j) {
			if (i[j] < 2*n && a[j][i[j]] == '0') {
				++cnt0;                            
				mx0 = i[j];
			}

			if (i[j] < 2*n && a[j][i[j]] == '1') {
				++cnt1;                		      
				mx1 = i[j];
			}
		}

		if (mp(cnt0, mx0) > mp(cnt1, mx1))
			ans.pb('0');
		else 
			ans.pb('1');

		for (int j = 0; j < 3; ++j) 
			if (i[j] < 2*n && a[j][i[j]] == ans.back())
				++i[j];
	}

	cout << ans << endl;
}

main () {
	fastio
	int TT;
	TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}