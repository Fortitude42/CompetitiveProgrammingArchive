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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, x[N], y[N];
vector < pair < db, int > > lf, rg;

struct line {
	db k, b;
	int id;
	line () {
		k = b = 0;
		id = 0;
	}

	line (db k1, db b1, int id1) {
		k = k1;
		b = b1;
		id = id1;
	}
	

	bool operator < (const line &X) const {
		if (X.k != k)
			return k < X.k;

		return b < X.b;
	}
};

db inter (line A, line B) {
	return (A.b - B.b) / (B.k - A.k);
}

vector < line > up, dw;
 
main () {
	cin >> t;
	while (t--) {
		up.clear();
		dw.clear();
		lf.clear();
		rg.clear();

		cin >> n;
		for (int i = 0; i < n; ++i) 
			cin >> x[i] >> y[i];      

		for (int i = n - 1; i >= 0; --i) 
			x[i] -= x[0], y[i] -= y[0];

		for (int i = 1; i < n; ++i) {
			db xx = (x[i] + 0.0) / 2, yy = (y[i] + 0.0) / 2;
			if (!y[i]) {
				if (x[i] > 0)	
					rg.pb(mp(xx, i));
				else
					lf.pb(mp(xx, i));
			} else {
				db k = -(x[i] + 0.0) / y[i];
				db b = yy - k*xx;
				if (y[i] > 0)
					up.pb(line(k, b, i));
				else
					dw.pb(line(k, b, i));
			}
		}

		sort(all(rg));
		sort(all(lf));
		reverse(all(lf));

		while (sz(rg) > 1)	
			rg.ppb();
		
		while (sz(lf) > 1)
			lf.ppb();

		sort(all(up));
		reverse(all(up));

		deque < line > u, d;

		for (int i = 0; i < sz(up); ++i) {
			while (sz(u) > 1 && inter(u.back(), u[sz(u) - 2]) >= inter(u.back(), up[i]))
				u.ppb();

			u.pb(up[i]);
		}

		for (int i = 0; i < sz(dw); ++i) {
			while (sz(d) > 1 && inter(d.back(), d[sz(d) - 2]) >= inter(d.back(), dw[i]))
				d.ppb();
			d.pb(dw[i]);
		}


		while (sz(d) > 1 && sz(u) > 1) {
			
		}

	}
}