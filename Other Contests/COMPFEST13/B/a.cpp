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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, x[N], y[N];

pair < db, db > F(db a, db b, db c) {
	if (a == 0) 
		return mp(-b / c, -b / c);
	
	db d = (b*b - 4*a*c);
	if (d < 0)
		return mp(-inf, inf);

	d = sqrt(d);
	return mp((-d - b) / (2*a), (d - b) / (2*a));
} 

pair < pair < db, db >, pair < db, db > > f(db a, db b, db c, db r) {
	if (b == 0) {
		db x = -c / a;
		db y = sqrt(r*r - x*x);
		if (fabs(x) > r)
			return mp(mp(inf, inf), mp(inf, inf));
		return mp(mp(x, y), mp(x, -y));
	}

	db k = (-a*x) / b;
	db l = -c / b;
	pair < db, db > cur = F(1 + k*k, -2*k*l, l*l - r*r);
	return mp(mp(cur.f, k*cur.f + l), mp(cur.s, k*cur.s + l));
}

const db pi = acos(-1);

db angle(db x, db y) {
	if (x == 0)
		return (y > 0 ? pi / 2 : pi * 1.5);
	db z = atan(y / x);
	while (z < 0)
		z += pi;
	return z;
}



bool check(db r) {
	int cnt = 0, mx = 0, bal = 0;
	vector < pair < db, int > > v;

	for (int i = 1; i <= n; ++i) {
		if (!x[i] && !y[i])
			++cnt;
		else {
			pair < pair < db, db >, pair < db, db > > cur = f(2*x[i], 2*y[i], -(x[i]*x[i] + y[i]*y[i]));
			if (cur.f.f == inf)
				continue;
			db l = angle(cur.f.f, cur.f.s);
			db r = angle(cur.s.f, cur.s.s);
			if (r < l)
				swap(l, r);
			if (r - l >= pi)
				swap(l, r);

			if (r < l)	
				++bal;
			v.pb({l, 1});
			v.pb( );
		}
	}
}

main () {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	db l = 0, r = 2*N, k = 0;
	while (k++ < 40) {
		db mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;	
	}

	cout << setprecision(6) << fixed << r << endl;
}