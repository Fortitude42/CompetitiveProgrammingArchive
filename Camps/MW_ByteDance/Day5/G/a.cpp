#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = (1 << 16) + 3;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, dp[N], p[N];
string s[20];
 
int rec (int mask) {
	if (!mask)
		return 0;

	if (__builtin_popcount(mask) == 1)
		return 1;

	int &res = dp[mask];

	if (res != -1)
		return res;

	res = inf;
	for (int j = 0; j < m; ++j) {
		int mask1 = 0, mask2 = 0;
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i)) {
				if (s[i][j] == '0')
					mask1 |= (1 << i);
				else
					mask2 |= (1 << i);
			}
			

		if (!mask1 || !mask2)
			continue;
//		cerr << mask << ' ' << mask1 << ' ' << mask2 << endl;

		int cur = max(rec(mask1), rec(mask2)) + 1;
		if (res > cur) {
			res = cur;
			p[mask] = j;
		}				
	}

	return res;
}

void write (int mask) {
	if (__builtin_popcount(mask) == 1) {
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				cout << "= " << i << endl;
		return;	
	}

	cout << "> " << p[mask] << endl;
	int mask1 = 0, mask2 = 0;
	for (int i = 0; i < n; ++i)
		if (mask & (1 << i)) {
			if (s[i][p[mask]] == '0')
				mask1 |= (1 << i);
			else
				mask2 |= (1 << i);
		}

	write(mask1);
	write(mask2);
}

main () {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	m = sz(s[0]);

	rec((1 << n) - 1);
	write((1 << n) - 1);

}