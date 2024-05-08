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

int a, b, c, d;
string s;

 
void solve() {
	cin >> a >> b >> c >> d >> s;
	int x = 0, y = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == 'A')
			++x;
		else
			++y;
	}


	if (x != a + c + d || y != b + c + d)  {
		puts("NO"); 
		return;
	}

	int sum = 0;
	vi A, B;
	for (int i = 0; i < sz(s); ++i) {
		string t = s.substr(i, 1);
		while (i + 1 < sz(s) && s[i + 1] != s[i]) {
			t += s[i + 1];
			i++;
		}

		if (sz(t) & 1) {
			sum += (sz(t) / 2);
			continue;
		}
		int k = sz(t) / 2;

		if (t[0] == 'A') 
			A.pb(k);
		else
			B.pb(k);
	}

	sort(all(A));
	sort(all(B));

	for (auto x : A) {
		int y = min(x, c);
		c -= y;
		x -= y;
		if (x > 0)
			d -= min(d, x - 1);
	}

	for (auto x : B) {
		int y = min(x, d);
		d -= y;
		x -= y;
		if (x > 0)
			c -= min(c, x - 1);
	}

	puts(c + d <= sum ? "YES" : "NO");
}

main () {
	fastio
	int TT;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}