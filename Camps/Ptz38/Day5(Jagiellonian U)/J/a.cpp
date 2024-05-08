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
 
const int inf = 1e9, maxn = 1e6 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, x[N], y[N], z[N], c[N], k, q, xa, ya, za, xb, yb, zb;
set < int > qxy[maxn], qxz[maxn], qyx[maxn], qyz[maxn], qzx[maxn], qzy[maxn];
map < pair < int, pii >, int > id; 

void add (int i) {
	if (x[i] == -1) {
		qxy[y[i]].insert(z[i]);
		qxz[z[i]].insert(y[i]);
	}

	if (y[i] == -1) {
		qyx[x[i]].insert(z[i]);
		qyz[z[i]].insert(x[i]);
	}

	if (z[i] == -1) {
		qzx[x[i]].insert(y[i]);
		qzy[y[i]].insert(x[i]);
	}
}

void del (int i) {
	if (x[i] == -1) {
		qxy[y[i]].erase(z[i]);
		qxz[z[i]].erase(y[i]);
	}

	if (y[i] == -1) {
		qyx[x[i]].erase(z[i]);
		qyz[z[i]].erase(x[i]);
	}

	if (z[i] == -1) {
		qzx[x[i]].erase(y[i]);
		qzy[y[i]].erase(x[i]);
	}
}


void dfs (int i) {
	assert(i > 0);
	c[i] = k;
	del(i);

	for (int xx = -1; xx <= 1; ++xx)
		for (int yy = -1; yy <= 1; ++yy)
			for (int zz = -1; zz <= 1; ++zz) {
				if (abs(xx) + abs(yy) + abs(zz) > 1)
					continue;

				if (x[i] == -1 && abs(xx) == 1)
					continue;
				if (y[i] == -1 && abs(yy) == 1)
					continue;
				if (z[i] == -1 && abs(zz) == 1)
					continue;
					
				int xi = x[i] + xx, yi = y[i] + yy, zi = z[i] + zz;

				if (id.count(mp(xi, mp(yi, zi))) && !c[id[mp(xi, mp(yi, zi))]]) 
					dfs(id[mp(xi, mp(yi, zi))]);

				if (xi == -1) {
					while (sz(qyz[zi])) {
						int X = *qyz[zi].begin();
						dfs(id[mp(X, mp(-1, zi))]);
					}
   	
					while (sz(qzy[yi])) {
						int X = *qzy[yi].begin();
						dfs(id[mp(X, mp(yi, -1))]);
					}
				}
	
				if (yi == -1) {
					while (sz(qxz[zi])) {
						int Y = *qxz[zi].begin();
						dfs(id[mp(-1, mp(Y, zi))]);
					}

					while (sz(qzx[xi])) {
						int Y = *qzx[xi].begin();
						dfs(id[mp(xi, mp(Y, -1))]);
					}
				}

		
				if (zi == -1) {
					while (sz(qyx[xi])) {
						int Z = *qyx[xi].begin();
						dfs(id[mp(xi, mp(-1, Z))]);
					}
		
					while (sz(qxy[yi])) {
						int Z = *qxy[yi].begin();
						dfs(id[mp(-1, mp(yi, Z))]);
					}
				}
			}
}


main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		k = 0;
		id.clear();
		
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			id[mp(x[i], mp(y[i], z[i]))] = i;
			add(i);
			c[i] = 0;
		}


		for (int i = 1; i <= n; ++i)
			if (!c[i]) {
				++k;
				dfs(i);
			}

		scanf("%d", &q);
		while (q--) {
			scanf("%d%d%d%d%d%d", &xa, &ya, &za, &xb, &yb, &zb);
			vi A, B;
			if (id.count(mp(-1, mp(ya, za))))
				A.pb(id[mp(-1, mp(ya, za))]);

 	 		if (id.count(mp(xa, mp(-1, za))))
 	 			A.pb(id[mp(xa, mp(-1, za))]);

			if (id.count(mp(xa, mp(ya, -1)))) 
				A.pb(id[mp(xa, mp(ya, -1))]);
                               

			if (id.count(mp(-1, mp(yb, zb))))
				B.pb(id[mp(-1, mp(yb, zb))]);

 	 		if (id.count(mp(xb, mp(-1, zb))))
 	 			B.pb(id[mp(xb, mp(-1, zb))]);

			if (id.count(mp(xb, mp(yb, -1)))) 
				B.pb(id[mp(xb, mp(yb, -1))]);

			bool ok = 0;
			for (auto x : A)
				for (auto y : B)
					if (c[x] == c[y])
						ok = 1;

			puts(ok ? "YES" : "NO");
		}
		
	}
}           x