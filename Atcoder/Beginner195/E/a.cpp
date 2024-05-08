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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, pw[N], dp[N][7];
string s, t;

int rec (int i, int j) {
	int &res = dp[i][j];
	if (res != -1)
		return res;

	if (i == n) {
		if (!j)
			return res = 1;
		return res = 0;
	}

	int g1 = rec(i + 1, (j + pw[n - 1 - i] * (s[i] - '0')) % 7);
	int g2 = rec(i + 1, j);
//	cerr << i << ' ' << j << ' ' << pw[n -  1 - i] << ' ' << (s[i] - '0') << ' ' << g1 << ' ' << g2 << endl;

	if ((t[i] == 'T' && (g1 || g2)) || (t[i] == 'A' && g1 && g2))
		return res = 1;
	return res = 0;
} 

main () {
	pw[0] = 1;
	for (int i = 1; i < N; ++i)
		pw[i] = pw[i - 1] * 10 % 7;

	memset(dp, -1, sizeof(dp));

	fastio
	cin >> n >> s >> t;
	puts(rec(0, 0) ? "Takahashi" : "Aoki");
}