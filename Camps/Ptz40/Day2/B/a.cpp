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
typedef long double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 4e3 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-9, pi = acos(-1);
const ll INF = 1e18;

 
int z, n, k;
db a[N], b[N], c[N];
pair < db, db > A;
db m;

db triangle_area_2 (db x1, db y1, db x2, db y2, db x3, db y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int comp (db a, db b) {
	if (fabs(a - b) < eps)
		return 0;

	if (a - b < eps)
		return -1;

	return 1;
}


bool clockwise (pair < db, db > a, pair < db, db > b, pair < db, db > c) {
	return comp(triangle_area_2 (a.f, a.s, b.f, b.s, c.f, c.s), 0) < 0;
}

bool cmp (pair < db, db > B, pair < db, db > C) {
	if (!comp(A.f, B.f) && !comp(A.s, B.s))
		return 1;

	if (!comp(A.f, C.f) && !comp(A.s, C.s))
		return 0;
	return clockwise(A, B, C);
}

db area (vector < pair < db, db > > v) {
//	if (!sz(v))
//		return 0;
	assert(sz(v) != 2);
	if (sz(v) <= 2)
		return 0;
	A = v[0];
	sort(all(v), cmp);
	
//	for (auto x : v)
//		cerr << x.f << ' ' << x.s << endl;
	
	db res = 0;
	for (int i = 0; i < sz(v); ++i) {
		res += v[i].f * v[(i + 1) % sz(v)].s;
		res -= v[i].s * v[(i + 1) % sz(v)].f;
	}

//	cerr << fabs(res) / 2 << endl << endl;
	return fabs(res) / 2;	
}

pair < db, db > inter () {
	if (!b[1] && !b[2])
		return mp(inf, inf);

	for (int i = 1; i <= 2; ++i) {
		if (!b[i]) {
			db x = (-c[i] + 0.0) / a[i];
			db y = (-c[3 - i] - a[3 - i] * x + 0.0) / b[3 - i];
			return mp(x, y);
		}
	}

	db k1 = (-a[1] + 0.0) / b[1], b1 = (-c[1] + 0.0) / b[1];
	db k2 = (-a[2] + 0.0) / b[2], b2 = (-c[2] + 0.0) / b[2];

	if (!comp(k1, k2))
		return mp(inf, inf);


	db x = (b2 - b1) / (k1 - k2);
	db y = k1*x + b1;
	return mp(x, y);
}


main () {
	cout << fixed << setprecision(9);
	cin >> z;
	while (z--) {
		cin >> n >> m;
		k = 0;

		for (int i = 1; i <= n; ++i) 
			cin >> a[i] >> b[i] >> c[i];
		
		
		if (n > 2) {
			cout << 100 << ".00000000%\n";
			continue;
		}

		vector < pair < db, db > > q;
		if (n == 2) {
			pair < db, db > cur = inter();
			db F1 = a[1] * cur.f + b[1] * cur.s + c[1];
			db F2 = a[2] * cur.f + b[2] * cur.s + c[2];
//			cerr << cur.f << ' ' << cur.s << endl;
//			cerr << F1 << ' ' << F2 << endl;

			if (comp(cur.f, 0) < 0 || comp(cur.f, m) > 0 || comp(cur.s, 0) < 0 || comp(cur.s, m) > 0) {
				cout << 100 << ".000000000%\n";
				continue;			
			}
			q.pb(cur);
		}

		for (db x = 0; x <= m; x += m)
			for (db y = 0; y <= m; y += m) {
				q.pb(mp(x, y));
				for (int i = 1; i <= n; ++i) {
					if (comp(a[i], 0)) 
						q.pb(mp((-c[i] - b[i] * y + 0.0) / a[i], y));
					if (comp(b[i], 0))
						q.pb(mp(x, (-c[i] - a[i] * x + 0.0) / b[i]));
				}
			}

		for (int i = 0; i < sz(q); ++i) {
			pair < db, db > cur = q[i];
			bool ok = 1;
			if (comp(cur.f, 0) < 0 || comp(cur.f, m) > 0 || comp(cur.s, 0) < 0 || comp(cur.s, m) > 0) 
			    ok = 0;

			for (int j = 0; j < i; ++j)
				if (fabs(q[i].f - q[j].f) < eps && fabs(q[i].s - q[j].s) < eps)
					ok = 0;

			if (!ok) {
				swap(q[i], q.back());
				q.ppb();
				--i;
			}
		}

		db S = inf;
		if (n == 1) {
			vector < pair < db, db > > v1, v2;
			for (auto p : q) {
				db cur = a[1] * p.f + b[1] * p.s + c[1];
				if (comp(cur, 0) <= 0)
					v1.pb(p);
				if (comp(cur, 0) >= 0)	
					v2.pb(p);
			}
			db a1 = area(v1);
			db a2 = area(v2);
			S = a1;
			if (comp(S, a2) > 0)
				S = a2;				
			assert(!comp(a1 + a2, m*m));
		} else {
			vector < pair < db, db > > v1, v2, v3, v4;
			for (auto p : q) {
				db cur1 = a[1] * p.f + b[1] * p.s + c[1];
				db cur2 = a[2] * p.f + b[2] * p.s + c[2];
//				cerr << p.f << ' ' << p.s << endl;
				if (comp(cur1, 0) >= 0 && comp(cur2, 0) >= 0)
					v1.pb(p);
				if (comp(cur1, 0) >= 0 && comp(cur2, 0) <= 0)
					v2.pb(p);
				if (comp(cur1, 0) <= 0 && comp(cur2, 0) >= 0)
					v3.pb(p);
				if (comp(cur1, 0) <= 0 && comp(cur2, 0) <= 0)
					v4.pb(p);
			}
			db a1 = area(v1);
			db a2 = area(v2);
			db a3 = area(v3);
			db a4 = area(v4);
			assert(!comp(a1 + a2 + a3 + a4, m*m));
			S = a1;
			if (comp(S, a2) > 0)
				S = a2;

			if (comp(S, a3) > 0)
				S = a3;

			if (comp(S, a4) > 0)
				S = a4;
		}
		db ans = (S + 0.0) / (m*m);
		ans *= 100;
		ans = 100 - ans;
//		assert(comp(ans, 0) >= 0);
		cout << ans  << "%" << endl;
	}
}