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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, m, lx[N], ly[N], rx[N], ry[N], t[N], timer;
vector < ll > s[4][N];
ll res[N];
vi a[N];

bool in (int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

bool in (int x, int l, int r) {
	return l <= x && x <= r;
}

ll get (int i, int xa, int ya, int xb, int yb) {
	if (xa > xb || ya > yb)
		return 0;
	--xa, --ya;
	return s[i][xb][yb] - s[i][xb][ya] - s[i][xa][yb] + s[i][xa][ya];
}

ll get1 (int xa, int ya, int xb, int yb) {//inter(bx, by) = empty
	ll res = 0;
	res += get(3, 1, 1, n, ya - 1);
	res += get(3, 1, 1, xa - 1, m);
	res += get(0, xb + 1, 1, n, m);
	res += get(0, 1, yb + 1, n, m);



	res -= get(3, 1, 1, xa - 1, ya - 1);
	res -= get(1, xb + 1, 1, n, ya - 1);
	res -= get(2, 1, yb + 1, xa - 1, m);
	res -= get(0, xb + 1, yb + 1, n, m);

	return res;
}

ll get2 (int xa, int ya, int xb, int yb, int Z) {//by is inside of bx
	ll res = get(0, xa, ya, xb, yb) - Z;
	++timer;

	for (int y = ya; y <= yb + 1; ++y) {
		if (!in(xb + 1, y))
			continue;

		int z = a[xb + 1][y];
		if (t[z] != timer && in(lx[z], xa, xb) && in(ly[z], ya, yb)) {
			t[z] = timer;
			res -= z;
		}   	
	}

	for (int x = xa; x <= xb; ++x) {
		if (!in(x, yb + 1))
			continue;

		int z = a[x][yb + 1];
		if (t[z] != timer && in(lx[z], xa, xb) && in(ly[z], ya, yb)) {
			t[z] = timer;
			res -= z;
		}			
	}

	return res;
}

ll get3 (int xa, int ya, int xb, int yb, int z) {//bx is inside of by
	ll res = 0;
	res += get(0, 1, 1, xa, ya) - z;
	res += get(1, 1, yb, xa, m) - z;
	res += get(2, xb, 1, n, ya) - z;
	res += get(3, xb, yb, n, m) - z;


	res -= get(1, 1, 1,x  xa, ya) - z;
	cerr << get(1, 1, 1, xa, ya) - z << endl;
	res -= get(3, xb, 1, n, ya) - z;

	res -= get(2, 1, 1, xa, ya) - z;
	res -= get(3, 1, yb, xa, m) - z;

	res -= get(0, xb, 1, n, ya) - z;
	res -= get(1, xb, yb, n, m) - z;

	res -= get(0, 1, yb, xa, m) - z;	
	res -= get(2, xb, yb, n, m) - z;

	res += get(3, 1, 1, xa, ya) - z;
	res += get(2, 1, yb, xa, m) - z;
	res += get(1, xb, 1, n, ya) - z;
	res += get(0, xb, yb, n, m) - z;

	cerr << res << endl;
	return res / 4;
}

main () {
	while (scanf("%d%d", &n, &m) == 2) {

		for (int i = 0; i <= n; ++i) {
			a[i].resize(m + 1, 0);
			for (int j = 0; j < 4; ++j)
				s[j][i].resize(m + 1, 0);
		}

		for (int i = 1; i <= n*m; ++i) {
			lx[i] = ly[i] = inf;        
			rx[i] = ry[i] = -1;
		}

		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);    
				lx[a[i][j]] = min(lx[a[i][j]], i);
				ly[a[i][j]] = min(ly[a[i][j]], j);
				rx[a[i][j]] = max(lx[a[i][j]], i);
				ry[a[i][j]] = max(ry[a[i][j]], j);
			}
		
		
		for (int i = 1; i <= n*m; ++i) {
			if (lx[i] == inf)
				continue;

			s[0][lx[i]][ly[i]] += i;
			s[1][lx[i]][ry[i]] += i;
			s[2][rx[i]][ly[i]] += i;
			s[3][rx[i]][ry[i]] += i;

			res[i] = n * 1ll * (n + 1) / 2;
			res[i] -= i;
		}

		for (int x = 0; x < 4; ++x)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					s[x][i][j] += s[x][i - 1][j] + s[x][i][j - 1] - s[x][i - 1][j - 1];

		ll ans = 0;
		for (int i = 8; i <= n*m; ++i) {
			if (lx[i] == inf)
				continue;

/*			res[i] -= get1(lx[i], ly[i], rx[i], ry[i]);
			res[i] -= get2(lx[i], ly[i], rx[i], ry[i], i);
			res[i] -= get3(lx[i], ly[i], rx[i], ry[i]);*/
			cerr << get3(lx[i], ly[i], rx[i], ry[i], i) << endl;
			return 0;
			ans += (res[i] ^ i);
		}

		cout << ans << endl;
	}
}