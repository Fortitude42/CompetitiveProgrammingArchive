#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < pii, null_type, less < pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

template <class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F& x, const F& y) : x(x), y(y) {}

  void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
  template <class F1> explicit operator Point<F1> () const {
    return Point<F1>(static_cast<F1>(x), static_cast<F1>(y)); }
  template <class F1> Point& operator = (const Point<F1>& other) {
    x = other.x; y = other.y; return *this; }
  template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }
  template <class F1> Point& operator -= (const Point<F1>& other) {
    x -= other.x; y -= other.y; return *this; }
  template <class F1> Point& operator *= (const F1& factor) {
    x *= factor; y *= factor; return *this; }
  template <class F1> Point& operator /= (const F1& factor) {
    x /= factor; y /= factor; return *this; }
};

template <class F> int read(Point<F>& point) { return read(point.x, point.y) / 2; }
template <class F> int write(const Point<F>& point) { return write(point.x, point.y); }

template <class F> istream& operator >> (istream& is, Point<F>& point) {
  return is >> point.x >> point.y; }
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
  return os << point.x << ' ' << point.y; }

template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }

#define FUNC1(name, arg, expr) \
template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }
#define FUNC3(name, arg1, arg2, arg3, expr) \
template <class F1, class F2, class F3> \
inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }

FUNC1(operator -, Point<F>& point, makePoint(-point.x, -point.y))
FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator -, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator *, F1& factor, Point<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y))
FUNC2(operator *, Point<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor))
FUNC2(operator /, Point<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor))

FUNC2(operator *, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator ^, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.y - lhs.y * rhs.x)

// < 0 if rhs <- lhs counter-clockwise, 0 if collinear, > 0 if clockwise.
FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))

FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))

FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,
    lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x))
FUNC2(operator >, Point<F1>& lhs, Point<F2>& rhs, rhs < lhs)
FUNC2(operator <=, Point<F1>& lhs, Point<F2>& rhs, !(lhs > rhs))
FUNC2(operator >=, Point<F1>& lhs, Point<F2>& rhs, !(lhs < rhs))

// Angles and rotations (counter-clockwise).
FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,
      angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,
      makePoint(angleCos * point.x - angleSin * point.y,
                angleSin * point.x + angleCos * point.y))
FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,
      origin + rotate(point - origin, angle))
FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))

// Distances.
FUNC1(abs, Point<F>& point, point * point)
FUNC1(norm, Point<F>& point, sqrt(abs(point)))
FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))

#undef FUNC1
#undef FUNC2
#undef FUNC3


template <class F>
struct Line {
  Point<F> a, ab;
  Line() : a(), ab() {}
  Line(const Point<F>& a, const Point<F>& b, bool twoPoints = true)
    : a(a), ab(twoPoints ? b - a : b) {}
  Line(const F& xa, const F& ya, const F& xb, const F& yb)
    : a(xa, ya), ab(xb - xa, yb - ya) {}

  void swap(Line& other) { using std::swap; swap(a, other.a); swap(ab, other.ab); }
  template <class F1> explicit operator Line<F1> () const {
    return Line<F1>(Point<F1>(a), Point<F1>(ab), false); }
  template <class F1> Line& operator = (const Line<F1>& other) {
    a = other.a; ab = other.ab; return *this; }

  Point<F> b() const { return a + ab; }
  operator bool () const { return ab != Point<F>(); }
};

template <class F> int read(Line<F>& line) {
  int res = read(line.a, line.ab) / 2;
  return line.ab -= line.a, res;
}

template <class F>
inline Line<F> makeLine(const Point<F>& a, const Point<F>& b, bool twoPoints = true) {
  return Line<F>(a, b, twoPoints);
}

template <class F> void swap(Line<F>& lhs, Line<F>& rhs) { lhs.swap(rhs); }


template <class F1, class F2>
bool onLine(const Point<F1>& point, const Line<F2>& line) {
  if (!line) return point == line.a;
  return ((point - line.a) ^ line.ab) == 0;
}

template <class F1, class F2>
bool onSegment(const Point<F1>& point, const Line<F2>& seg) {
  if (!seg) return point == seg.a;
  auto vecta = seg.a - point, vectb = seg.b() - point;
  return (vecta ^ vectb) == 0 && (vecta * vectb) <= 0;
}

template <class F1, class F2> using distF = decltype(sqrt(F1() + F2()));

template <class F1, class F2>
distF<F1, F2> distLine(const Point<F1>& point, const Line<F2>& line) {
  if (!line) return dist(point, line.a);
  return abs((point - line.a) ^ line.ab) / norm(line.ab);
}

template <class F1, class F2>
distF<F1, F2> distSegment(const Point<F1>& point, const Line<F2>& seg) {
  if (((point - seg.a) * seg.ab) <= 0) return dist(point, seg.a);
  if (((point - seg.b()) * seg.ab) >= 0) return dist(point, seg.b());
  return distLine(point, seg);
}

template <class F1, class F2, class F3>
void projection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  res = line.a;
  if (line) res += line.ab * static_cast<F3>((point - line.a) * line.ab) / abs(line.ab);
}

template <class F1, class F2, class F3>
void reflection(const Point<F1>& point, const Line<F2>& line, Point<F3>& res) {
  projection(point, line, res);
  res = 2 * res - point;
}

template <class F1, class F2, class F3>
void closest(const Point<F1>& point, const Line<F2>& seg, Point<F3>& res) {
  if (((point - seg.a) * seg.ab) <= 0) res = seg.a;
  else if (((point - seg.b()) * seg.ab) >= 0) res = seg.b();
  else projection(point, seg, res);
}

template <int TYPE> struct EndpointChecker {};
template <> struct EndpointChecker<0> {  // no endpoint (ray)
  template <class F> bool operator ()(const F& a, const F& b) const { return true; }};
template <> struct EndpointChecker<1> {  // closed endpoint
template <class F> bool operator ()(const F& a, const F& b) const { return a <= b; }};
template <> struct EndpointChecker<2> {  // open endpoint
template <class F> bool operator ()(const F& a, const F& b) const { return a < b; }};

template <int LA, int LB, int RA, int RB, class F1, class F2, class F3>
bool intersectLines(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
  assert(lhs && rhs);
  auto s = lhs.ab ^ rhs.ab;
  if (s == 0) return false;
  auto ls = (rhs.a - lhs.a) ^ rhs.ab;
  auto rs = (rhs.a - lhs.a) ^ lhs.ab;
  if (s < 0) s = -s, ls = -ls, rs = -rs;
  bool intersect =
    EndpointChecker<LA>()(decltype(ls)(0), ls) && EndpointChecker<LB>()(ls, s) &&
    EndpointChecker<RA>()(decltype(rs)(0), rs) && EndpointChecker<RB>()(rs, s);
  if (intersect) res = lhs.a + lhs.ab * static_cast<F3>(ls) / s;
  return intersect;
}

template <class F1, class F2, class F3>
bool intersectClosedSegments(const Line<F1>& lhs, const Line<F2>& rhs, Point<F3>& res) {
  return intersectLines<1, 1, 1, 1>(lhs, rhs, res);
}

template <class F1, class F2, class F3>
bool intersectSegments(const Line<F1>& lhs, const Line<F2>& rhs, Line<F3>& res) {
  auto s = lhs.ab ^ rhs.ab;
  auto ls = (rhs.a - lhs.a) ^ rhs.ab;
  if (s == 0) {
    if (ls != 0) return false;
    auto lhsa = lhs.a, lhsb = lhs.b();
    auto rhsa = rhs.a, rhsb = rhs.b();
    if (lhsa > lhsb) swap(lhsa, lhsb);
    if (rhsa > rhsb) swap(rhsa, rhsb);
    res = Line<F3>(max(lhsa, rhsa), min(lhsb, rhsb));
    return res.ab >= Point<F3>();
  }
  auto rs = (rhs.a - lhs.a) ^ lhs.ab;
  if (s < 0) s = -s, ls = -ls, rs = -rs;
  bool intersect = 0 <= ls && ls <= s && 0 <= rs && rs <= s;
  if (intersect)
    res = Line<F3>(lhs.a + lhs.ab * static_cast<F3>(ls) / s, Point<F3>());
  return intersect;
}


struct node {
	int val, prior, cnt;
	node *l, *r;
	node () {}
	node (int v, int p) {
		val = v;
		prior = p;
		cnt = 1;
		l = r = NULL;	
	}	
};

typedef node * pnode;

int cnt (pnode t) {
	return ((!t) ? 0: t->cnt);
}


void upd (pnode &t) {
	if (!t)
		return;
	t->cnt = 1 + cnt(t->r) + cnt(t->l); 
}


int get(pnode t, int key) {
	int cur_key = cnt(t->l);
	if (cur_key >= key)
		return get(t->l, key);

	if (key == cur_key + 1)
		return t->val;

	return get(t->r, key - cur_key - 1);
}

void split (pnode t, int key, pnode &l, pnode &r, int add = 0) {
	if (!t) {
		l = r = NULL;
		return;
	}

	int cur_key = cnt(t->l) + add;	
	if (key <= cur_key) {
		split(t->l, key, l, t->l, add);
		r = t;
	} else {
		split(t->r, key, t->r, r, cur_key + 1);
		l = t;
	}
	upd(t);
}


void merge (pnode &t, pnode l, pnode r) {
	if (!l)
		t = r;
	else if (!r)
		t = l;
	else if (l->prior > r->prior) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	upd(t);
}

pnode root, A, B, C;

void out (pnode t) {
	if (!t)
		return;
	out(t->l);
	cout << t->val << ' ';
	out(t->r);
}



const int maxn = 1e4;

int n, m;
Point<int> pl[M], pr[M];
Line<int> l[M];
vi g[maxn + maxn + 11];
Line<int> tmp;


void check(int i, int j) {
	assert(i == -1 || i != j);
	if (i != -1 && j != -1 && intersectSegments(l[i], l[j], tmp)) {
		cout << "YES\n";
		cout << i << ' ' << j << endl;
		exit(0);
	}
}

bool is_higher(int i, int x, int y) {//pl[i].x != pr[i].x
	return pl[i].y * 1ll * (pr[i].x - pl[i].x) + (pr[i].y - pl[i].y) * 1ll * (x - pl[i].x) >= y * 1ll * (pr[i].x - pl[i].x);
}

int get_lower_count(int x, int y) {
	int l = 1, r = cnt(root), res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int i = get(root, mid);

		if (!is_higher(i, x, y)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

	return res;
}



int getRand() {
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)
			res |= (1 << i);

	return res;
}

 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> pl[i] >> pr[i];
		pl[i].x += maxn;
		pr[i].x += maxn;

		if (pl[i].x > pr[i].x)
			swap(pl[i], pr[i]);

		l[i] = Line<int>(pl[i], pr[i]);

		g[pl[i].x].pb(i);
		if (pr[i].x != pl[i].x)
			g[pr[i].x].pb(i);
	}
	
	for (int x = 0; x < maxn + maxn + 11; ++x) {
		vector < pair < pii, int > > v;
		for (auto i : g[x]) {
			if (pr[i].x != x && pl[i].x == x) {//add new line
				int c = get_lower_count(x, pl[i].y);
				int lw = c > 0 ? get(root, c) : -1;				
				int hi = c < cnt(root) ? get(root, c + 1) : -1;
				check(i, hi);
				check(i, lw);

				if (hi != -1 && lw != -1)
					check(hi, lw);

				pnode cur = new node(i, getRand());
				split(root, c, A, B);
				merge(A, A, cur);
				merge(root, A, B);
				m++;
				assert(cnt(root) == m);
			} 
		}

		for (auto i : g[x]) {
			if (pl[i].x == pr[i].x) {//vertical line
				if (pl[i].y > pr[i].y)
					swap(pl[i], pr[i]);

				v.pb(mp(mp(pl[i].y, pr[i].y), i));

				int c = get_lower_count(x, pl[i].y);
				int lw = c > 0 ? get(root, c) : -1;			
				int hi = c < cnt(root) ? get(root, c + 1) : -1;
				check(i, hi);
				check(i, lw);
				if (hi != -1 && lw != -1)
					check(lw, hi);
			} 		
		}

		for (auto i : g[x]) {
			if (pl[i].x != x && pr[i].x == x) {
				int c = get_lower_count(x, pr[i].y);
				int lw = c > 0 ? get(root, c) : -1;
				int my = c < cnt(root) ? get(root, c + 1) : -1;
				int hi = c + 1 < cnt(root) ? get(root, c + 2) : -1;

				check(lw, my);
				check(lw, hi);
				check(my, hi);

				assert(my == i);
				split(root, c, root, A);
				assert(A);
				split(A, 1, A, B);
				assert(A->val == i);
				merge(root, root, B);
				m--;
				assert(cnt(root) == m);
/*				int c = get_lower_count(x, pr[i].y);
				int lw = c > 0 ? get(root, c) : -1;			

				split(root, c, root, A);
				if (A) {
					split(A, 1, A, B);
					assert(A->val == i);
					if (A->val != i) {
						check(A->val, i); 
						check(A->val, lw);
					}
				} else {
					B = NULL;
				}
//				cerr << A->val << ' ' << i << endl;
				merge(root, root, B);

				int hi = c < cnt(root) ? get(root, c + 1) : -1;
				if (hi != -1 && lw != -1)
					check(hi, lw);

				if (hi != -1) {
					check(i, hi); 
					if (A && A->val != i)
						check(A->val, hi);
				}
				

				if (lw != -1)
					check(i, lw);

				if (!A)
					assert(0);
				if (A && A->val != i)
					assert(0);*/
			}
		}


		sort(all(v));
		pii mx = {-1, -1};
		for (int i = 0; i < sz(v); ++i) {
			check(v[i].s, mx.s);
			mx = max(mx, mp(v[i].f.s, v[i].s));
		}

	}

	cout << "NO\n";
}

main () {
	srand(time(0));
  	int TT;
  	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}