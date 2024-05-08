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
const long double eps = 1e-9, inf = 1e9;


// Basic point/vector struct.
struct Point { 

    long double x, y;
    explicit Point(long double x = 0, long double y = 0) : x(x), y(y) {}

    // Addition, substraction, multiply by constant, cross product.

    friend Point operator + (const Point& p, const Point& q) {
        return Point(p.x + q.x, p.y + q.y); 
    }

    friend Point operator - (const Point& p, const Point& q) { 
        return Point(p.x - q.x, p.y - q.y); 
    }

    friend Point operator * (const Point& p, const long double& k) { 
        return Point(p.x * k, p.y * k); 
    } 

    friend long double cross(const Point& p, const Point& q) { 
//    	if (p.x >= inf && q.y >= inf)
//    		cerr << p.x << ' ' << q.y << ' ' << p.y << ' ' << q.x << endl;
        return p.x * q.y - p.y * q.x; 
    }
};

// Basic half-plane struct.
struct Halfplane { 

    // 'p' is a passing point of the line and 'pq' is the direction vector of the line.
    Point p, pq; 
    long double angle;

    Halfplane() {}
    Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);
    }

    // Check if point 'r' is outside this half-plane. 
    // Every half-plane allows the region to the LEFT of its line.
    bool out(const Point& r) { 
        return cross(pq, r - p) < -eps; 
    }

    // Comparator for sorting. 
    // If the angle of both half-planes is equal, the leftmost one should go first.
    bool operator < (const Halfplane& e) const { 
        if (fabsl(angle - e.angle) < eps) return cross(pq, e.p - p) < eps;
        return angle < e.angle;
    } 

    // We use equal comparator for std::unique to easily remove parallel half-planes.
    bool operator == (const Halfplane& e) const { 
        return fabsl(angle - e.angle) < eps; 
    }

    // Intersection point of the lines of two half-planes. It is assumed they're never parallel.
    friend Point inter(const Halfplane& s, const Halfplane& t) {
    	if (fabs(cross(s.pq, t.pq)) < eps)
    		cerr << s.angle << ' ' << t.angle << endl;

        long double alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
        return s.p + (s.pq * alpha);
    }
};


// Actual algorithm
vector<Point> hp_intersect(vector<Halfplane>& H) { 

    Point box[4] = {  // Bounding box in CCW order
        Point(inf, inf), 
        Point(-inf, inf), 
        Point(-inf, -inf), 
        Point(inf, -inf) 
    };

    for(int i = 0; i<4; i++) { // Add bounding box half-planes.
        Halfplane aux(box[i], box[(i+1) % 4]);
        H.push_back(aux);
    }

    // Sort and remove duplicates
    sort(H.begin(), H.end());
    H.erase(unique(H.begin(), H.end()), H.end());

    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < int(H.size()); i++) {

        // Remove from the back of the deque while last half-plane is redundant
        while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }

        // Remove from the front of the deque while first half-plane is redundant
        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }

        // Add new half-plane
        dq.push_back(H[i]);
        ++len;
    }

    // Final cleanup: Check half-planes at the front against the back and vice-versa
    while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    // Report empty intersection if necessary
    if (len < 3) return vector<Point>();
    cerr << len << endl;
    for (int i = 0; i < len; ++i)
    	cerr << dq[i].p.x << ' ' << dq[i].p.y << ' ' << (dq[i].pq.y / dq[i].pq.x) << endl;


    // Reconstruct the convex polygon from the remaining half-planes.
    vector<Point> ret(len);
    for(int i = 0; i+1 < len; i++) {
        ret[i] = inter(dq[i], dq[i+1]);
    }

//    cout << fixed << setprecision(4) << endl;

    ret.back() = inter(dq[len-1], dq[0]);
//    for (int i = 0; i < len; ++i)
//		cout << ret[i].x / (10000000) << ' ' << ret[i].y / 10000000 << endl;

    for (int i = 1; i < sz(ret); ++i)
    	if (fabsl(ret[i].x - ret[i - 1].x) < eps && fabsl(ret[i].y - ret[i - 1].y) < eps)
    		return vector<Point>();
    
    return ret;
}

int n;
Point a[M];

bool check(int x) {
	vector < Halfplane > hps;
	for (int i = 0; i < n; ++i)
		hps.pb(Halfplane(a[(i + x + 1) % n], a[i])); 
	

	return sz(hp_intersect(hps)) > 0;
}

 
void solve() {
    cerr << fixed << setprecision(7);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;

	int l = 1, r = n - 1, res = n;
	check(25000);
	return;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (!check(mid)) {
			cerr << mid << endl;
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}

	cout << res << endl;
}                                                                                       

main () {
	int TT;
	TT = 1;
//	file("jungle")
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

