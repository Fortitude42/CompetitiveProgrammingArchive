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


char ask (int xa, int ya, int xb, int yb) {
	cout << "Q " << xa << ' ' << ya << ' ' << xb << ' ' << yb << endl;

	char c;
	cin >> c;
	return c;
}

 
int l, r, u, d;
vector < pair < pii, int > > v;

int LF () {
	int l = -N, r = N, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ask(mid, 0, mid, 1) == '+')
			l = mid + 1;
		else {
			res = mid;
			r = mid - 1;
		}
	}

	return res;
}

int RG () {
	int l = -N, r = N, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ask(mid, 0, mid, 1) == '-')
			r = mid - 1;
		else {
			l = mid + 1;			
			res = mid;
		}
	}
	return res;
}

int UP () {
	int l = -N, r = N, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ask(0, mid, 1, mid) == '+') 
			r = mid - 1;
		else {
			l = mid + 1;
			res = mid;
		}
	}

	return res;
}

int DW () {
	int l = -N, r = N, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ask(0, mid, 1, mid) == '-') 
			l = mid + 1;
		else {
			res = mid;
			r = mid - 1;
		}
	}

	return res;
}


main () {
	l = LF();
	r = RG();
	u = UP();
	d = DW();

//	l = 1, r = 11;
//	u = 10, d = 3;

//	cerr << l << ' ' << r << ' ' << u << ' ' << d << endl;
	
	
	if (ask(l, d, l - 1, d + 1) == 'X') 
		v.pb({{l, d}, 0});

	if (ask(l, u, l - 1, u - 1) == 'X')
		v.pb({{l, u}, 1});

	if (ask(r, u, r - 1, u + 1) == 'X')
		v.pb({{r, u}, 2});

	if (ask(r, d, r - 1, d - 1) == 'X')
		v.pb({{r, d}, 3});

	if (sz(v) == 3) {
		cout << "A ";
		for (auto x : v)
			cout << x.f.f << ' ' << x.f.s << ' ';
		return 0;
	}

	if (sz(v) == 2) {
		assert(0);
		return 0;
	}





	int lf = l, rg = r, x = -1, y = -1;
	if (v[0].s == 0) {
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			if (ask(l - 1, d, mid, u) == 'X') {
				x = mid;
				rg = mid - 1;
			} else
				lf = mid + 1;
		}   	

		lf = d, rg = u;
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			if (ask(l, d - 1, r, mid) == 'X') {
				y = mid;
				rg = mid - 1;
			} else
				lf = mid + 1;
		}

		cout << "A " << v[0].f.f << ' ' << v[0].f.s << ' ';
		cout << x << ' ' << u << ' ' << r << ' ' << y << endl;
	 	return 0;
	}

	if (v[0].s == 1) {
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			if (ask(l - 1, u, mid, d) == 'X') {
				x = mid;
				rg = mid - 1;
			} else
				lf = mid + 1;
		}

		lf = d, rg = u;
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			if (ask(l, u + 1, r, mid) == 'X') {
				y = mid;
				lf = mid + 1;
			} else
				rg = mid - 1;
		}

		cout << "A " << v[0].f.f << ' ' << v[0].f.s << ' ';
		cout << x << ' ' << d << ' ' << r << ' ' << y << endl;
		return 0;
	}

	if (v[0].s == 2) {
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			if (ask(r + 1, u, mid, d) == 'X') {
				x = mid;
				lf = mid + 1;
			} else
				rg = mid - 1;
		}

		lf = d, rg = u;
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			if (ask(r, u + 1, l, mid) == 'X') {
				y = mid;
				lf = mid + 1;
			} else
				rg = mid - 1;
		}

		cout << "A " << v[0].f.f << ' ' << v[0].f.s << ' ';
		cout << x << ' ' << d << ' ' << l << ' ' << y << endl;
		return 0;
	}

	while (lf <= rg) {
		int mid = (lf + rg) >> 1;
		if (ask(r + 1, d, mid, u) == 'X') {
			x = mid;
			lf = mid + 1;
		} else 
			rg = mid - 1;
	}

	lf = d, rg = u;
	while (lf <= rg) {
		int mid = (lf + rg) >> 1;
		if (ask(r, d - 1, l, mid) == 'X') {
			rg = mid - 1;
			y = mid;
		} else
			lf = mid + 1;
	}

	cout << "A " << v[0].f.f << ' ' << v[0].f.s << ' ';
	cout << x << ' ' << u << ' ' << l << ' ' << y << endl;
	return 0;
}	