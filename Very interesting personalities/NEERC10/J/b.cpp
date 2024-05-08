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
const int N = 5e4, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

//#define double long double
const double eps = 1e-12;
const double PI = acos((double)-1.0);
int sign(const double &x) { return (x > eps) - (x < -eps); }
struct PT {
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const double a) const { return PT(x * a, y * a); }
    friend PT operator * (const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const double a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};              
inline double dot(const PT &a, const PT &b) { return a.x * b.x + a.y * b.y; }
inline double dist2(const PT &a, const PT &b) { return dot(a - b, a - b); }
inline double dist(const PT &a, const PT &b) { return sqrt(dot(a - b, a - b)); }
inline double cross(const PT &a, const PT &b) { return a.x * b.y - a.y * b.x; }
inline int orientation(const PT &a, const PT &b, const PT &c) { return sign(cross(b - a, c - a)); }
PT perp(const PT &a) { return PT(-a.y, a.x); }
PT rotateccw90(const PT &a) { return PT(-a.y, a.x); }
PT rotatecw90(const PT &a) { return PT(a.y, -a.x); }
PT rotateccw(const PT &a, const double &t) { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }
PT rotatecw(const PT &a, const double &t) { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t)); }
double SQ(const double &x) { return x * x; }
double rad_to_deg(const double &r) { return (r * 180.0 / PI); }
double deg_to_rad(const double &d) { return (d * PI / 180.0); }
double get_angle(PT &a, PT &b) {
    double costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((double)-1.0, min((double)1.0, costheta)));
}
double area(const vector<PT> &p) {
    double ans = 0; int n = p.size();
    for (int i = 0; i < n; i++) ans += cross(p[i], p[(i + 1) % n]);
    return fabs(ans);
}
// contains all points p such that: cross(b - a, p - a) >= 0
struct HP {
    PT a, b;
    HP() {}
    HP(PT a, PT b) : a(a), b(b) {}
    HP(const HP& rhs) : a(rhs.a), b(rhs.b) {}
    int operator < (const HP& rhs) const {
        PT p = b - a;
        PT q = rhs.b - rhs.a;
        int fp = (p.y < 0 || (p.y == 0 && p.x < 0));
        int fq = (q.y < 0 || (q.y == 0 && q.x < 0));
        if (fp != fq) return fp == 0;
        if (cross(p, q)) return cross(p, q) > 0;
        return cross(p, rhs.b - a) < 0;
    }
    PT line_line_intersection(PT a, PT b, PT c, PT d) {
        b = b - a; d = c - d; c = c - a;
        return a + b * cross(c, d) / cross(b, d);
    }
    PT intersection(const HP &v) {
        return line_line_intersection(a, b, v.a, v.b);
    }
};

inline int check(HP &a, HP &b, HP &c) {
    return cross(a.b - a.a, b.intersection(c) - a.a) > -eps; //-eps to include polygons of zero area (straight lines, points)
}

vector<PT> half_plane_intersection(vector<HP> &h) {
    sort(h.begin(), h.end());
    vector<HP> tmp;
    for (int i = 0; i < h.size(); i++) {
        if (!i || cross(h[i].b - h[i].a, h[i - 1].b - h[i - 1].a)) {
            tmp.push_back(h[i]);
        }
    }
    h = tmp;
    vector<HP> q(h.size() + 10);
    int qh = 0, qe = 0;
    for (int i = 0; i < h.size(); i++) {
        while (qe - qh > 1 && !check(h[i], q[qe - 2], q[qe - 1])) qe--;
        while (qe - qh > 1 && !check(h[i], q[qh], q[qh + 1])) qh++;
        q[qe++] = h[i];
    }
    while (qe - qh > 2 && !check(q[qh], q[qe - 2], q[qe - 1])) qe--;
    while (qe - qh > 2 && !check(q[qe - 1], q[qh], q[qh + 1])) qh++;
    vector<HP> res; 
    for (int i = qh; i < qe; i++) res.push_back(q[i]);
    vector<PT> hull;

    if (res.size() > 2) {
        for (int i = 0; i < res.size(); i++) {
             hull.push_back(res[i].intersection(res[(i + 1) % ((int)res.size())]));
        }
    }

    if (sz(hull) && fabs(hull[0].x - hull.back().x) < eps && fabs(hull[0].y - hull.back().y) < eps)
    	hull.clear();

    return hull;
}

int n;
PT a[M];

bool check(int x) {
	vector < HP > hps;
	for (int i = 0; i < n; ++i)
		hps.pb(HP(a[(i + x + 1) % n], a[i])); 
	

	return sz(half_plane_intersection(hps)) > 0;
}

main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;
	

	int l = 1, r = n - 1, res = n;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (!check(mid)) {
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}

	cout << res << endl;

}
