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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


ll pw[30];
int n, m = -1;
vpii cars;
queue < ll > q;
bool u1[N], u2[N]; 
map < ll, int > d;
int c[10][10];




ll get (vpii v) {
	ll res = 0;
	for (int i = 0; i < sz(v); ++i) {
		res += v[i].f * pw[i*2];
		res += v[i].s * pw[i*2 + 1];
	}

	return res;
}

vpii getVector (ll f) {
	vpii v;
	for (int i = 0; i < n; ++i) {
		int x = f % 6;
		f /= 6;
		int y = f % 6;
		f /= 6;
		v.pb({x, y});
	}

	return v;
}

bool inter (int i, int x, int y) {
	if (cars[i].f == x && cars[i].s == y)
		return 1;

	if (u1[i]) {
		if (cars[i].f + 1 == x && cars[i].s == y)
			return 1;
		if (u2[i] && cars[i].f + 2 == x && cars[i].s == y)
			return 1;
		return 0;
	}

	if (cars[i].f == x && cars[i].s + 1 == y)
		return 1;
	if (u2[i] && cars[i].f == x && cars[i].s + 2 == y)
		return 1;

	return 0;
}

bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < 6 && y < 6;
}

main () {
	pw[0] = 1;
	for (int i = 1; i < 24; ++i)
		pw[i] = pw[i - 1] * 6;

	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			cin >> c[i][j];

	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			if (c[i][j] != 0 && (!i || c[i - 1][j] != c[i][j]) && (!j || c[i][j - 1] != c[i][j])) {
//				cout << c[i][j] << endl;
				cars.pb({i, j});
				if (c[i][j] == 1)
					m = sz(cars) - 1;

				if (c[i + 1][j] == c[i][j]) {
					u1[sz(cars) - 1] = 1;
					if (c[i + 2][j] == c[i][j])
						u2[sz(cars) - 1] = 1;
				} else {
					if (c[i][j + 2] == c[i][j])
						u2[sz(cars) - 1] = 1;
				}
			}

	if (u1[m]) {
		cout << -1 << endl;
		return 0;
	}


	n = sz(cars);

	
	q.push(get(cars));
	d[get(cars)] = 0;


	int timer = 0;  	
	while (sz(q)) {
		ll v = q.front();
		q.pop();
		if (d[v] > 8) {
			cout << -1;
			return 0;
		}

		cars = getVector(v);

		if (inter(m, 2, 5)) {
			cout << d[v] + 2 << endl;			
			return 0;
		}

		for (int i = 0; i < sz(cars); ++i) {
			for (int x = 0; x < 4; ++x) {
				int tox = cars[i].f + dx[x], toy = cars[i].s + dy[x];
				if (u1[i]) {
					if (x == 0) {
						tox++;
						if (u2[i])
							tox++;
					}
				} else {
					if (x == 2) {
						toy++;
						if (u2[i])
							toy++;
					}
				}
				

				if (!in(tox, toy) || (u1[i] && x > 1) || (!u1[i] && x < 2))
					continue;

				bool ok = 1;
				for (int j = 0; j < sz(cars); ++j)
					if (i != j && inter(j, tox, toy)) {
						ok = 0;
						break;
					}

				if (!ok)
					continue;
				
				ll vv = v;
				if (!x)
					vv += pw[i*2];
				if (x == 1)
					vv -= pw[i*2];
				if (x == 2)	
					vv += pw[i*2 + 1];
				if (x == 3)
					vv -= pw[i*2 + 1];
				
				if (!d.count(vv)) {
					d[vv] = d[v] + 1;
					q.push(vv);
				}
			}
		}
	}

	cout << -1 << endl;
}