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
const int N = 3e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
char s[M][M];
int t[M*2][2];

void inc(int pos, int i) {
	while (pos <= 2*n) {
		t[pos][i] ^= 1;
		pos |= (pos + 1);
	}
}

int get(int r, int i) {
	int res = 0;
	while (r >= 0) {
		res ^= t[r][i];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

 
void solve() {
	cin >> n;
	for (int i = 0; i <= 2*n; ++i)
		t[i][0] = t[i][1] = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) 
			cin >> s[i][j];

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int cur = (get(i + j, 0) ^ get(i - j + n, 1));
			if ((cnt ^ cur) & 1) {
				s[i][j] = '0' + '1' - s[i][j];			
			}
		}

		for (int j = 1; j <= n; ++j) {
			if (s[i][j] == '1') {
				++cnt;
				inc(i + j, 0);
				inc(i - j + n, 1);
			}
		}
	}

	cout << cnt << endl;
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