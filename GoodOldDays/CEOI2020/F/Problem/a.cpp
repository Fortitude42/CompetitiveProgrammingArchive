#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 212;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int r, c, q, f[N], rf[N], dp[N][N][N];

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2 == 1)
			res = res * 1ll * a % mod;
		n /= 2;
		a = a * 1ll * a % mod;
	}

	return res;
}


void precalc () {
	f[0] = 1;
	for (int i = 1; i < N; ++i) 
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}

int cnk (int n, int k) {
	if (n < k)
		return 0;
	int ans = rf[k];
	for (int i = n - k + 1; i <= n; ++i)			
		ans = ans * 1ll * i % mod;

	return ans;	
}

char t;
int c1, cr;

bool in (int x, int y) {
	return x > 0 && y > 0 && x <= r && y <= c;
}

bool check (int xa, int ya, int x, int y) {
	if (x == xa || y == ya || (x + y) == (xa + ya) || (xa - ya) == (x - y))
		return 1;		 	
	return 0;
}

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}


main () {
	precalc();
	cin >> r >> c >> q;
	while (q--) {
		cin >> t >> c1 >> cr;
		if (t == 'P') {
			if (c1 != cr) 
				cout << 0 << ' ' << 0 << endl;
			else 
				cout << r - 1 << ' ' << 1 << endl;
			continue;
		}

		if (t == 'R') {
			if (c1 == cr) 
				cout << 1 << ' ' << 1 << endl;
			else
				cout << 2 << ' ' << 2 << endl;
			continue;
		} 

		if (t == 'Q') {
/*			if (c1 == 1) {
			cerr << c1 + 1 << ' ' << cr + r << endl;
			cerr << c1 - 1 << ' ' << cr - r << endl;}*/
			if (c1 == cr || (c1 + 1) == (cr + r) || (c1 - 1) == (cr - r))
				cout << 1 << ' ' << 1 << endl;
			else {
				if (r <= 10) {	
					int ans = 0;
					for (int i = 1; i <= r; ++i)
						for (int j = 1; j <= c; ++j)
							if (check(i, j, 1, c1) && check(i, j, r, cr)) {
								++ans;                                      

							}
					cout << 2 << ' ' << ans << endl;
					continue;
				}

				int ans = 2;
				int x = 1, y = c1;
				while (in(x, y)) {
					if (check(x, y, r, cr)) 
						++ans;              
					
					++x;
					--y;
				}             

				for (int i = 1; i <= c; ++i)
					if (check(1, i, r, cr)) 
						++ans;                
					


				x = 1, y = c1;
				while (in(x, y)) {
					if (check(x, y, r, cr)) 
						++ans;                
					
					++x;
					++y;
				}

				
				cout << 2 << ' ' << ans << endl;
			}
			continue;
		}

		if (t == 'K' && r < N && q <= 50) {	
			for (int i = 1; i <= r; ++i)
				for (int j = 1; j <= c; ++j)
					for (int x = 0; x < r; ++x) 
						dp[i][j][x] = 0;
				
			dp[1][c1][0] = 1;

			for (int x = 1; x < r; ++x) 
			for (int i = 1; i <= r; ++i)
				for (int j = 1; j <= c; ++j)
						for (int y = -1; y <= 1; ++y)  
							if (in(i - 1, j + y))
								add(dp[i][j][x], dp[i - 1][j + y][x - 1]);						 
						
					


			cout << r - 1 << ' ' << dp[r][cr][r - 1] << endl;
			continue;
		}

		return 0;
	}       
}