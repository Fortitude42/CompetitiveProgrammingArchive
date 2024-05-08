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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e3 + 12;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

bool rev, tp[N], was[N][N][4], ok[N][N], ok1[N][N];
int n, t, xa[N], ya[N], xb[N], yb[N], P;
vi X, Y;

bool in (int l, int r, int x) {
	return l <= x && x <= r;
}

pii inter (int i, int j) {
	if (tp[i] == tp[j])
		return {-1, -1};

	if (tp[i])
		swap(i, j);

	if (!in(xa[i], xb[i], xa[j]) || !in(ya[j], yb[j], ya[i]))
		return {-1, -1};

	return {xa[j], ya[i]};
}


void dfs (int x, int y, int d) {
	if (ok[x][y])
		d = (d + 2) % 4;

	if (ok1[x][y])
		d = (d + 1) % 4;

	if (was[x][y][d])
		return;

	was[x][y][d] = 1;

//	assert(in(0, sz(X) - 1, x + dx[d]));
//	assert(in(0, sz(Y) - 1, y + dy[d]));
	
	int dist = abs(X[x + dx[d]] - X[x]) + abs(Y[y + dy[d]] - Y[y]);

	if (dist >= t) {
		cout << X[x] + dx[d] * t << ' ' << Y[y] + dy[d] * t << endl;
		exit(0);
	}
	
	t -= dist;
	P += dist;

	dfs(x + dx[d], y + dy[d], d);
}

main () {
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
		tp[i] = (xa[i] == xb[i]);
	}

	if (xa[1] > xb[1] || ya[1] > yb[1]) 
		rev = 1;
	
	for (int i = 1; i <= n; ++i) {
		if (xa[i] > xb[i] || ya[i] > yb[i]) {
			swap(xa[i], xb[i]);
			swap(ya[i], yb[i]);
		}

		X.pb(xa[i]);
		X.pb(xb[i]);
		Y.pb(ya[i]);
		Y.pb(yb[i]);
	}

	sort(all(X));
	X.resize(unique(all(X)) - X.begin());

	sort(all(Y));
	Y.resize(unique(all(Y)) - Y.begin());

	for (int i = 1; i <= n; ++i) {
		xa[i] = lower_bound(all(X), xa[i]) - X.begin();
		xb[i] = lower_bound(all(X), xb[i]) - X.begin();

		ya[i] = lower_bound(all(Y), ya[i]) - Y.begin();
		yb[i] = lower_bound(all(Y), yb[i]) - Y.begin();		

		ok[xa[i]][ya[i]] = 1;
		ok[xb[i]][yb[i]] = 1;
	}

	for (int i = 1; i <= n; ++i)	
		for (int j = i + 1; j <= n; ++j) {
			pii cur = inter(i, j);
			
			if (cur.f == -1)
				continue;

			ok1[cur.f][cur.s] = 1;
		}

	int X = xa[1], Y = ya[1], d = 0;

	if (tp[1])
		d = 1;

	if (rev) {
		d = (d + 2) % 4;
		X = xb[1], Y = yb[1];
	}

	dfs(X, Y, (d + 2) % 4);
	t %= P;
	
	memset(was, 0, sizeof(was));

	dfs(X, Y, (d + 2) % 4);
}