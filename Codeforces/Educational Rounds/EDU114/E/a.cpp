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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353 , N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, k, cnt[2][2], p[N], cntx[N][2][2], cnty[N][2][2];
set < int > badx, bady, X, Y;
map < int, int > g[N];

bool checkx(int x) {

	if (cntx[x][0][1] && cntx[x][0][0])
		return 0;

	if (cntx[x][1][0] && cntx[x][1][1])
		return 0;

	if (cntx[x][0][0] && cntx[x][1][0])
		return 0;

	if (cntx[x][0][1] && cntx[x][1][1])
		return 0;

	return 1;
}

bool checky(int y) {
	if (cnty[y][0][1] && cnty[y][0][0])
		return 0;

	if (cnty[y][1][0] && cnty[y][1][1])
		return 0;

	if (cnty[y][0][0] && cnty[y][1][0])
		return 0;

	if (cnty[y][0][1] && cnty[y][1][1])
		return 0;

	return 1;
}

void del(int x, int y) {
	if (!g[x].count(y) || g[x][y] == -1)
		return;

	int z = g[x][y];
	--cnt[(x + y) & 1][z];

	//bad --> good
	--cntx[x][y & 1][z];
	if (badx.count(x) && checkx(x))
		badx.erase(x);

	--cnty[y][x & 1][z];
	if (bady.count(y) && checky(y))
		bady.erase(y);

	
	//exists?
	if (!cnty[y][0][0] && !cnty[y][0][1] && !cnty[y][1][0] && !cnty[y][1][1])
		Y.erase(y);

	if (!cntx[x][0][0] && !cntx[x][0][1] && !cntx[x][1][0] && !cntx[x][1][1])
		X.erase(x);

	g[x][y] = -1;
}

void add(int x, int y, int z) {
	if (z == -1)
		return;

	g[x][y] = z;
	++cnt[(x + y) & 1][z];
	++cntx[x][y & 1][z];
	++cnty[y][x & 1][z];
	
	//exists?
	Y.insert(y);
	X.insert(x);

	//good --> bad
	if (!checkx(x))
		badx.insert(x);
	if (!checky(y))
		bady.insert(y);
}

void precalc() {
	p[0] = 1;
	for (int i = 1; i < N; ++i)
		p[i] = p[i - 1] * 2 % mod;
}

void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;


}

main () {
    precalc();
	
	scanf("%d%d%d", &n, &m, &k);
	while (k--) {
		int tp, x, y;
		scanf("%d%d%d", &x, &y, &tp);

		del(x, y);
		add(x, y, tp);
	
		
		int ans = 0, d = 0;

		if (!cnt[0][0] && !cnt[1][1])
			ans++, d++;
		
		if (!cnt[0][1] && !cnt[1][0])
			ans++, d++;
		if (!sz(badx)) 
			add(ans, p[n - sz(X)] - d);
		
		if (!sz(bady))
			add(ans, p[m - sz(Y)] - d);

		printf("%d\n", ans);
	}

}
