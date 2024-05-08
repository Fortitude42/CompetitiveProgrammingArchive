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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int dp[M][M], opt[M][M], n;
map < char, char > F;
string s; 

int rec(int l, int r) {
	int &res = dp[l][r];
	if (res != -1)
		return res;

	if (l > r)
		return res = 0;

	if (s[r] == '[' || s[r] == '(')
		return res = rec(l, r - 1) + 1;
	
	res = rec(l, r - 1) + 1;
	for (int x = l; x < r; ++x) {
		int cur = ((F[s[x]] == s[r]) ? rec(l, x - 1) : (rec(l, x) + 1)) + rec(x + 1, r - 1);
		if (res > cur) {
			res = cur;
			opt[l][r] = x;
		}
	}

	return res;
}

void write(int l, int r) {
	if (l > r)
		return;

	if (s[r] == '[' || s[r] == '(') {
		write(l, r - 1);
		cout << s[r] << F[s[r]];
		return;
	}

	if (opt[l][r] == -1) {
		cout << F[s[r]];
		write(l, r - 1);
		cout << s[r];
		return;
	}

	int x = opt[l][r];
	if (s[x] == F[s[r]]) {
		write(l, x - 1);
		cout << s[x];
		write(x + 1, r - 1);
		cout << s[r];
		return;
	}

	write(l, x);
	cout << F[s[r]];
	write(x + 1, r - 1);
	cout << s[r];
}

void solve() {
	F['('] = ')';
	F['['] = ']';
	F[')'] = '(';
	F[']'] = '[';

	memset(dp, -1, sizeof(dp));
	memset(opt, -1, sizeof(opt));
	cin >> s;
	n = sz(s);
	rec(0, n - 1);
	write(0, n - 1);
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}