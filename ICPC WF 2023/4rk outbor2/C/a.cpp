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
const int mxd = 270 + 5;

int t, dp[30][2][2][2*mxd], par[30][2][2][2*mxd];
int a[30], b[30];
string sa, sb;


int rec(int pos, int c1, int c2, int delta) {
	if (pos == 30) {
		delta += c1 - c2;
		if (delta == mxd)
			return 1;
		return 0;
	}

	int &res = dp[pos][c1][c2][delta];
	if (res != -1)
		return res;
	
	for (int d = 0; d < 10; ++d) {
		int da = (a[pos] + c1 + d) % 10;
		int ca = (a[pos] + c1 + d) / 10;

		int db = (b[pos] + c2 + d) % 10;
		int cb = (b[pos] + c2 + d) / 10;

		if (rec(pos + 1, ca, cb, delta + da - db)) {
			par[pos][c1][c2][delta] = d;
			return res = 1;
		}
	}

	return res = 0;
}
 
void solve() {	
	memset(dp, -1, sizeof dp);
//	memset(par, -1, sizeof par);
	cin >> sa >> sb;
	reverse(all(sa));
	reverse(all(sb));

	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);

	for (int i = 0; i < sz(sa); ++i)
		a[i] = sa[i] - '0';


	for (int i = 0; i < sz(sb); ++i)
		b[i] = sb[i] - '0';

	if (!rec(0, 0, 0, mxd)) {
		cout << "NO\n";
		return;
	}

	string res = "";

	int pos = 0, c1 = 0, c2 = 0, delta = mxd;
	while (pos < 30) {
		int d = par[pos][c1][c2][delta];
		res += ('0' + d);
		
		int da = (a[pos] + c1 + d) % 10;
		int ca = (a[pos] + c1 + d) / 10;

		int db = (b[pos] + c2 + d) % 10;
		int cb = (b[pos] + c2 + d) / 10;

		pos++;
		c1 = ca;
		c2 = cb;
		delta += da - db;
	}

	while (sz(res) > 1 && res.back() == '0')
		res.ppb();
	reverse(all(res));

	cout << "YES\n";
	cout << res << "\n";
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