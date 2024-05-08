//by paradox & gege & parasat
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
const int N = 1e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

const double EPS = 1e-15;

struct Point {
	double x, y;
	Point() : x(0.0), y(0.0) {}
	Point(double x, double y) : x(x), y(y) {}
};

Point p[M];
double ansh;

Point getLine(const Point &a, const Point &b) {
	double k = (b.y - a.y) / (b.x - a.x);
	double bb = a.y - k * a.x;
	return Point(k, bb);
}

double get(double r, int n) {
	Point cur(r, 0);
	double res = -1.0;

	for (int i = 1; i <= n; i++) {
		Point line = getLine(p[i], cur);
		double ch = line.y;
		double cr = -ch / line.x;
		double vol = cr * cr * ch;                                                              
		if (vol - res > EPS) {
			res = vol;
			ansh = ch;
		}
	}                                                        
	return res;
}

void solve() {
	int n;
	scanf("%d", &n);

	double mx = -1.0;
	for (int i = 1; i <= n; i++) {
		double x, y, z;
		scanf("%lf %lf %lf", &x, &y, &z);
		p[i].x = sqrt(x * x + y * y);
		p[i].y = z;
		if (p[i].x - mx > EPS)
			mx = p[i].x;
	}

	double l = mx + 1e-3, r = 1e15;
	for (int it = 0; it < 200; it++) {
		double m1 = l + (r - l) / 3.0;
		double m2 = r - (r - l) / 3.0;
		double resl = get(m1, n);
		double resr = get(m2, n);
		if (resl - resr > EPS)
			l = m1;
		else 
			r = m2;
	}
	
	double ansr = l;
	get(ansr, n);
	printf("%.5lf %.5lf\n", ansh, ansr);
}

main () {
//	file("dome");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

