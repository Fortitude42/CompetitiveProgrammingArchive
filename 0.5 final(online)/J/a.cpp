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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 52;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n;
set < pair < db, pii > > q;
db dp[N][N*N], d[N], h[N], L;
vector < pair < db, db > > p, g[N]; 

db dist (db xa, db ya, db xb, db yb) {
	return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

bool check (db xa, db ya, db xb, db yb, int i) {
	db A = yb - ya;
	db B = xa - xb;
	db C = ya * xb - xa * yb;
	db K = -(A / B);
	db L = -(C / B);
	if (K*d[i - 1] + L <= h[i] || K*d[i] + L <= h[i])
		return 0;
	return 1;
}

bool check (db xa, db ya, db xb, db yb, int i, int j) {
	for (int x = i; x <= j; ++x)    
		if (!check(xa, ya, xb, yb, x))
			return 0;
	return 1;
}


main () {
	cin >> n >> L;
	for (int i = 1; i <= n; ++i)
		cin >> d[i];

	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	
	for (int i = 1; i <= n; ++i) {
		p.pb(mp(d[i - 1], h[i]));
		p.pb(mp(d[i], h[i]));
	}

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			if (h[j] >= h[i] || h[i] - h[j] > L)
				continue;

			db x = sqrt(L*L - (h[i] - h[j]) * (h[i] - h[j]));
			if (!(d[i] + x > d[j - 1] && d[i] + x < d[j]))
				continue;
			
			p.pb(mp(d[i] + x, h[j]));
		}

	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j)
			for (int x = i + 1; x < j; ++x) {
				if (h[x] >= h[i] || h[x] >= h[j])
					continue;

				db l = d[x - 1], r = d[x], k = 0;
				while (k++ < 80) {
					db m1 = l + (r - l) / 3;
					db m2 = r - (r - l) / 3;
					db d1 = dist(d[i], h[i], m1, h[x]) + dist(m1, h[x], d[j - 1], h[j]);
					db d2 = dist(d[i], h[i], m2, h[x]) + dist(m2, h[x], d[j - 1], h[j]);
					if (d1 > d2)
						l = m1;
					else
						r = m2;	
				}

				if (fabs(l - d[x]) < eps || fabs(l - d[x - 1]) < eps)
					continue;
				p.pb(mp(l, h[x]));
			}

	sort(all(p));
	vector < pair < db, db > > pp;
	for (auto j : p)
		if (!sz(pp) || fabs(pp.back().f - j.f) >= eps || fabs(pp.back().s - j.s) >= eps)
			pp.pb(j);

	swap(p, pp);



	int j = 0;
	for (int i = 1; i <= n; ++i) {
		while (j < sz(p) && p[j].f <= d[i]) {
			if (p[j].s == h[i])
				g[i].pb(p[j]);
			else
				g[i + 1].pb(p[j]);
			++j;
		}
	}
				
	
	
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < sz(g[i]); ++j)
			dp[i][j] = inf;

/*	for (int i = 1; i <= n; ++i) {
		for (auto j : g[i])
			cerr << j.f << ' ' << j.s << endl;
		cerr << "-----> " << endl;				
	}*/

//	cerr << dp[n][sz(g[n]) - 1] << endl;

	dp[1][0] = 0;
	q.insert(mp(0, mp(1, 0)));

	while (sz(q)) {
		int i = (q.begin()->s).f, a = (q.begin()->s).s;
//		cerr << i << ' ' << a << ' ' << dp[i][a] << endl;
		q.erase(q.begin());
		db x = g[i][a].f, y = g[i][a].s;

		for (int j = i + 1; j <= n; ++j) {
		    db D = dist(x, y, d[j - 1], h[j]);
			if (h[j] > h[i] && D <= L && check(x, y, d[j - 1], h[j], i + 1, j - 1) && dp[j][0] > dp[i][a] + D) {
				q.erase(mp(dp[j][0], mp(j, 0)));
				dp[j][0] = dp[i][a] + D;
				q.insert(mp(dp[j][0], mp(j, 0)));
			}
		}
		
		if (a < sz(g[i]) - 1) {
			db D = dist(x, y, g[i][a + 1].f, g[i][a + 1].s);
			if (dp[i][a + 1] > dp[i][a] + D) {
				q.erase(mp(dp[i][a + 1], mp(i, a + 1)));
				dp[i][a + 1] = dp[i][a] + D;
				q.insert(mp(dp[i][a + 1], mp(i, a + 1)));
			}
		} else {
			for (int j = i + 1; j <= n; ++j)
				if (h[j] < h[i])
				for (int b = 0; b < sz(g[j]); ++b) {
					db X = g[j][b].f, Y = g[j][b].s;
					db D = dist(X, Y, x, y);
					if (D <= L && dp[i][a] + D < dp[j][b] && check(x, y, X, Y, i + 1, j - 1)) {
						q.erase(mp(dp[j][b], mp(j, b)));
						dp[j][b] = dp[i][a] + D;
						q.insert(mp(dp[j][b], mp(j, b)));
					}
				}
		}		
	}
	
	cout << setprecision(10) << fixed;

	if (dp[n][sz(g[n]) - 1] == inf)
		cout << "-1" << endl;
	else 
		cout << dp[n][sz(g[n]) - 1] << endl;	
		
}