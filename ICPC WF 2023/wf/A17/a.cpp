#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define sz(x) (int)x.size()
#define mp make_pair
#define all(x) x.begin(), x.end()

const long double eps = 1e-10;
const long double epsl = 1e-8;

int cmp(long double a, long double b){
	if(fabsl(a - b) < eps) return 0;
	if(a - b < eps) return -1;
	return 1;
}

using namespace std;
using ll = long long;
using pii = pair <int, int>;

template <class T> int sgn(T x) { return (x > eps) - (x < -eps); }
template <class T>
struct Point{
	typedef Point P;
	T x, y;
	explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
	bool operator< (P p) const { return tie(x, y) < tie(p.x, p.y); }
	bool operator== (P p) const {return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
	P operator+ (P p) const { return P(x + p.x, y + p.y); }
	P operator- (P p) const { return P(x - p.x, y - p.y); }
	P operator* (T d) const { return P(x * d, y * d); }
	P operator/ (T d) const { return P(x / d, y / d); }
	T dot(P p) const { return x * p.x + y * p.y; }
	T cross(P p) const { return x * p.y - y * p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x * x + y * y;}
	long double dist() const { return sqrt((long double)dist2()); }
	long double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); }
	P perp() const { return P(-y, x); }
	P normal() const { return perp().unit(); }
	friend ostream& operator << (ostream& os, P p){ return os << '(' << p.x << ',' << p.y << ')'; }
};

template <class P> long double segDist(P s, P e, P p) {
	if (s == e)
		return (p - s).dist();
	auto d = (e - s).dist2(), t = min(d, max((long double).0, (p - s).dot(e - s)));
	return ((p - s) * d - (e - s) * t).dist() / d;
}

template <class P> bool onSegment(P s, P e, P p) {
	return segDist(s, e, p) <= eps;
}

template<class P> vector <P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	oc = a.cross(b, c), od = a.cross(b, d);
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set <P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

template <class P> pair <int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d= (e1 - s1).cross(e2 - s2);
	if (fabsl(d) < eps)
		return {-(fabsl(s1.cross(e1, s2)) < eps), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

template <class P> int sideOf(P s, P e, P p) {
	auto a = (e - s).cross(p - s);
	long double l = (e - s).dist() * eps;
	return (a > l) - (a < -l);
}

int n;
vector<Point<long double>> a;
long double ans;

Point<long double> get(Point<long double> s, Point<long double> e){
	vector<Point<long double>> vec;
	for(int i = 0; i < n; i++){
		pair<int, Point<long double>> temp = lineInter(s, e, a[i], a[(i + 1) % n]);
		if(temp.first != 1) continue;
		Point<long double> inter = temp.second;
		if(!onSegment(a[i], a[(i + 1) % n], inter)) continue;
		if(sideOf(s, s + (e - s).perp(), inter) == 1) continue;
		if(inter == a[i]){
			if(sideOf(a[i], a[(i + 1) % n], inter + (e - s).unit() * epsl) == -1) vec.pb(inter);
		} else if (inter == a[(i + 1) % n]) {
		    int j = (i + 0) % n;
			if(sideOf(a[(j + 0) % n], a[(j + 1) % n], inter + (e - s).unit() * epsl) == -1) vec.pb(inter);		
		}
		else vec.pb(inter);
	}
	assert(!vec.empty());
	long double d = 1e9;
	for(Point<long double> p: vec) d = min(d, (p - s).dist());
	return s + (e - s).unit() * d;
}

main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
//			if(i != 2 || j != 4) continue;
//			cout << "i = " << i << " j = " << j << '\n';
			Point<long double> s = a[i], e = a[j];
			/*
			long double d = (e - s).dist();
			for(int k = 0; k < n; k++){
				pair<int, Point<long double>> temp = lineInter(s, e, a[k], a[(k + 1) % n]);
				if(temp.first != 1) continue;
				if(sideOf(s, s + (e - s).perp(), temp.second) == -1) d = min(d, (temp.second - s).dist());
			}
			Point<long double> temp = s + (e - s).unit() * d / 2;
			if(!inPolygon(a, temp)) continue;
			swap(s, e);
			for(int k = 0; k < n; k++){
				pair<int, Point<long double>> temp = lineInter(s, e, a[k], a[(k + 1) % n]);
				if(temp.first != 1) continue;
				if(sideOf(s, s + (e - s).perp(), temp.second) == -1) d = min(d, (temp.second - s).dist());
			}
			temp = s + (e - s).unit() * d / 2;
			if(!inPolygon(a, temp)) continue;
			*/
			Point<long double> e1 = get(s, e), s1 = get(e, s);
			if(cmp((e1 - s).dist(), (e - s).dist()) < 0) continue;
			if(cmp((s1 - e).dist(), (e - s).dist()) < 0) continue;
			ans = max(ans, (e1 - s1).dist());
//			cout << "ans = " << ans << '\n';
		}
	}
	cout << fixed << setprecision(9) << ans;
}
