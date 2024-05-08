#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
double dist() const { return sqrt((double)dist2()); }
// angle to x=axis in interva l [=pi , pi ]
double angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes d is t ()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated ’a ’ radians ccw around the origin
P rotate(double a) const {
return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
friend ostream& operator<<(ostream& os, P p) {
return os << "(" << p.x << "," << p.y << ")"; }
int half () const { return int(y < 0 || (y == 0 && x < 0)); }
};

Point < ll > a[10];

bool is_rhombus() {
	ll d0 = (a[0] - a[1]).dist2();
	for (int i = 1; i < 4; ++i)
		if ((a[i] - a[(i + 1) % 4]).dist2() != d0)
			return 0;

	return 1;
}

bool is_rec() {
	for (int i = 0; i < 4; ++i) {
		ll A = (a[(i + 3) % 4] - a[i]).dist2();
		ll B = (a[(i + 1) % 4] - a[i]).dist2();
		ll C = (a[(i + 3) % 4] - a[(i + 1) % 4]).dist2();

		if (A + B != C)
			return 0;
	}

	return 1;
}

bool is_parallel(Point<ll> s1, Point<ll> e1, Point<ll> s2, Point<ll> e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	return d == 0;
}

bool is_square() {
    return is_rhombus() && is_rec();
}

bool is_parallelogram() {
	return is_parallel(a[0], a[1], a[2], a[3]) && is_parallel(a[1], a[2], a[3], a[0]);
}

bool is_trapezium() {
	return is_parallel(a[0], a[1], a[2], a[3]) || is_parallel(a[1], a[2], a[3], a[0]);
}

bool is_kite() {
	for (int i = 0; i < 4; ++i) {
		ll d0 = (a[(i + 1) % 4] - a[i]).dist2();

		ll d1 = (a[(i + 3) % 4] - a[i]).dist2();

		ll d2 = (a[(i + 1) % 4] - a[(i + 2) % 4]).dist2();

		ll d3 = (a[(i + 3) % 4] - a[(i + 2) % 4]).dist2();
		if (d0 == d1 && d2 == d3)
			return 1;
	}

	return 0;
}



void solve() {
	for (int i = 0; i < 4; ++i)
		cin >> a[i].x >> a[i].y;


	if (is_square()) {
		cout << "square";
		return;
	}

	if (is_rec()) {
		cout << "rectangle";
		return;
	}

	if (is_rhombus()) {
		cout << "rhombus";
		return;
	}

	if (is_parallelogram()) {
		cout << "parallelogram";
		return;
	}

	if (is_trapezium()) {
		cout << "trapezium";
		return;
	}

	if (is_kite()) {
		cout << "kite";
		return;
	}

	cout << "none";
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}