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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


char s[N];
int n, x[N], y[N];
map < pii, int > cnt, cnt1[4];
ll ans, pref[N], suff[N][4], res[N][4];

inline int get (int x, int y) {
	return ((abs(x) + 1) ^ (abs(y) + 1)) + 1;
} 


void add (ll &res, int x, int y, int j) {
	++cnt1[j][mp(x, y)];
	res += cnt1[j][mp(x, y)] * 1ll * get(x, y);
}

void del (ll &res, int x, int y, int j) {
	res -= cnt1[j][mp(x, y)] * 1ll * get(x, y);
	--cnt1[j][mp(x, y)];
}

main () {
	scanf("%d\n%s", &n, s);
	for (int i = 0; i < n; ++i) {
		x[i + 1] = x[i];
		y[i + 1] = y[i];
		if (s[i] == 'L')
			--x[i + 1];
		if (s[i] == 'R')
			++x[i + 1];
		if (s[i] == 'U')
			++y[i + 1];
		if (s[i] == 'D')
			--y[i + 1];
	}

	
	for (int i = 0; i <= n; ++i) {
		++cnt[mp(x[i], y[i])];
		pref[i] = (!i ? 0 : pref[i - 1] ) + cnt[mp(x[i], y[i])] * 1ll * get(x[i], y[i]);
	}

	
	for (int j = 0; j < 4; ++j) {
		cnt1[j] = cnt;
		suff[n + 1][j] = pref[n];
		for (int i = n + 1; i >= 0; --i) {
			if (i <= n) {
				int curx = x[i] + dx[j], cury = y[i] + dy[j];
				suff[i][j] = suff[i + 1][j];
				del(suff[i][j], x[i], y[i], j);
				add(suff[i][j], curx, cury, j);
			}

			if (i) 
				res[i][j] = suff[i][j] - cnt1[j][mp(x[i - 1], y[i - 1])] * 1ll * get(x[i - 1], y[i - 1]);
		}
	}




	for (int i = 0; i < n; ++i) {
		int j;
		if (s[i] == 'L')
			j = 0;
		if (s[i] == 'R')	
			j = 1;
		if (s[i] == 'D')	
			j = 2;
		if (s[i] == 'U')
			j = 3;
		
		cout << res[i + 2][j] << endl;
	}


	
}