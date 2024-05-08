//by paradox & gege & parasat
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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, l, k, cnt[30];
char c[M][M];
string s;
vi v;
 
void solve() {
	cin >> n >> l >> k >> s;
	for (int i = 0; i < sz(s); ++i)
		++cnt[s[i] - 'a'];

	for (int i = k - 1; i >= 0; --i)
		v.pb(i);

	for (int i = 0; i < l; ++i)
		for (int j = 0; j < n; ++j)
			c[j][i] = '#';

	for (int i = 0; i < l; ++i) {
		int cur = sz(v) - 1;
		for (int j = 0; j < 26; ++j)
			while (cnt[j] > 0 && cur >= 0) {
				c[v[cur]][i] =  (j + 'a');
				--cnt[j];
				--cur;
			}
		
		while (c[v.back()][i] != c[v[0]][i])
			v.ppb();
	}

	for (int i = 0; i < l; ++i)
		for (int j = 0; j < n; ++j) 
			if (c[j][i] == '#') {
				for (int x = 0; x < 26; ++x)
					if (cnt[x] > 0) {
						c[j][i] = (x + 'a');
						cnt[x]--;
						break;
					}
			}

	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < l; ++j)
			cout << c[i][j];
}

main () {
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

