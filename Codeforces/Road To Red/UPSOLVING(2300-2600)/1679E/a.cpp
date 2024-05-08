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
const int N = (1 << 17), inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, q, s[M][20], res[M];
string t;

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		n >>= 1;
		a = a * 1ll * a % MOD;
	}

	return res;
}
 
inline void add(int &x, int &y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void solve() {
	cin >> n >> t;

	int Cnt = 0;
	for (auto c : t)
		if (c == '?')
			++Cnt;

	for (int l = 0; l < n; ++l)
		for (int r = l; r < n; ++r) {
			int cnt = 0, mask = 0;
			for (int x = l, y = r; x < y; ++x, --y) {
				if (t[x] != '?' && t[y] != '?') {
					if (t[x] == t[y])
						continue;
					cnt = -1;
					break;
				}
				++cnt;
				if (t[x] != t[y])
					mask |= (1 << ((t[x] == '?' ? t[y] : t[x]) - 'a'));
			}

			if (cnt == -1)
				continue;

			for (int k = 1; k < 20; ++k) {
			    int x = binpow(k, Cnt - cnt);
				add(s[mask][k], x); 
			}
		}

	memset(res, -1, sizeof(res));

	cin >> q;
	while (q--) {
		cin >> t;
		int mask = 0, len = sz(t);
		for (auto c : t)
			mask |= (1 << (c - 'a'));
		if (res[mask] == -1) {
			res[mask] = s[0][len];
			for (int mask1 = mask; mask1 > 0; mask1 = mask & (mask1 - 1)) 
				add(res[mask], s[mask1][len]); 
		}
		cout << res[mask] << endl;
	}
}

main () {
	fastio
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}