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


typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
if (sz(pts) <= 2) return pts;
sort(all(pts));
vector<P> h(sz(pts)*2);
int s = 0, t = 0;
for (int it = 2; it--; s = --t, reverse(all(pts)))
for (P p : pts) {
while (t >= s + 2 && h[t-2].cross(h[t-1], p) < 0) {t--; }
h[t++] = p;
}
return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int n;
map < pair < ll, ll >, int > id;
vector < Point < ll > > p;
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		p.pb(Point<ll>(x, y));
		id[mp(x, y)] = i;
	}

	p = convexHull(p);
	vi ans;
	for (auto pt : p) {
		assert(id.count(mp(pt.x, pt.y)));
		ans.pb(id[mp(pt.x, pt.y)]);
	}

	sort(all(ans));
	for (int i = 0; i < sz(ans); ++i) {
		if (i > 0 && ans[i] == ans[i - 1])
			continue;
		printf("%d ", ans[i]);
//		assert(!i || ans[i] != ans[i - 1]);
	}

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}