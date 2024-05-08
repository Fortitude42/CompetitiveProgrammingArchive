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
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int xmax, ymax;
bool sw, neg;
int l[M], r[M];
string s;


struct Rec{
	int xa, ya;
	int xb, yb;

	Rec(int xa=0,int ya=0, int xb=0, int yb=0): xa(xa), ya(ya), xb(xb), yb(yb) {}

	bool inter(const Rec &r) const {
		int xl = max(xa, r.xa);
		int xr = min(xb, r.xb);

		int yl = max(ya, r.ya);
		int yr = min(yb, r.yb);

		return xl < xr && yl < yr;
	};
};

vector < Rec > vr;


void solve(int tt) {
	int x, y;
	cin >> x >> y;

	int i = -1;
	for (int j = 0; j < sz(vr); ++j) 
		if (vr[j].xa <= x && x < vr[j].xb && vr[j].ya <= y && y < vr[j].yb) {
			i = j;
			break;
		}

	if (s != "OPEN" && i == -1) {
		if (s == "MOVE" || s == "RESIZE") {
			int tmp;
			cin >> tmp >> tmp;
		}
		cout << "Command " << tt << ": " << s << " -  no window at given position\n";
		return;
	}


	if (s == "MOVE") {
		int dx, dy;
		cin >> dx >> dy;
		if (!dx && !dy)
			return;
		sw = neg = 0;
		if (!dy) {
			sw = 1;
			swap(xmax, ymax);
			swap(dx, dy);
			for (int j = 0; j < sz(vr); ++j) {
				swap(vr[j].xa, vr[j].ya);
				swap(vr[j].xb, vr[j].yb);
			}
		}

		if (dy < 0) {
			neg = 1;
			dy = -dy;
			for (int j = 0; j < sz(vr); ++j) {
				vr[j].ya = ymax - vr[j].ya;
				vr[j].yb = ymax - vr[j].yb;
				swap(vr[j].ya, vr[j].yb);
			}
		}

		vi inds, valx ={vr[i].xa, vr[i].xb - 1}, used_inds;

		for (int j = 0; j < sz(vr); ++j) {
			if (vr[j].ya < vr[i].yb)
				continue;
			inds.pb(j);
			valx.pb(vr[j].xa);
			valx.pb(vr[j].xb - 1);
		}

		inds.pb(i);

		sort(all(valx));
		valx.resize(unique(all(valx)) - valx.begin());
			
		for (auto j : inds) {
			l[j] = lower_bound(all(valx), vr[j].xa) - valx.begin();
			r[j] = lower_bound(all(valx), vr[j].xb - 1) - valx.begin();
		}

		inds.ppb();
		used_inds.pb(i);

		int cursh = 0;
		while (1) {
			int maxsh = dy - cursh;
			for (auto j1 : used_inds)
				maxsh = min(maxsh, ymax - vr[j1].yb);

			assert(maxsh>=0);
			if (!maxsh)
				break;
			for (int jj = 0; jj < sz(inds); ++jj) {
				int j = inds[jj];
				int sh = inf;
				bool was = 0;

				for (auto j1 : used_inds) {
					if (vr[j1].yb > vr[j].ya || max(l[j1], l[j]) > min(r[j1], r[j]))						
						continue;
					was = 1;
					sh = min(sh, vr[j].ya - vr[j1].yb);
				}
				if (sh < 0 || !was)
					continue;
				assert(sh >= 0);
				if (!sh) {
					maxsh = 0;
					swap(inds[jj], inds.back());
					inds.ppb();
					jj--;
					used_inds.pb(j);
					continue;
				}

				maxsh = min(maxsh, sh);
			}
//			cerr << maxsh << endl;

			if (!maxsh)
				continue;
				
			cursh += maxsh;
			for(auto j : used_inds){
				vr[j].ya += maxsh;
				vr[j].yb += maxsh;
			}
		}
		
	

		if (cursh != dy) 
			cout << "Command " << tt << ": MOVE - moved " << cursh << " instead of " << dy << "\n";		

		if (neg) {
			dy = -dy;
			cursh = -cursh;
			for (int j = 0; j < sz(vr); ++j) {
				vr[j].ya = ymax - vr[j].ya;
				vr[j].yb = ymax - vr[j].yb;
				swap(vr[j].ya, vr[j].yb);
			}
		}                              

		if (sw) {
		    swap(xmax, ymax);
			swap(dx, dy);
			for (int j = 0; j < sz(vr); ++j) {
				swap(vr[j].xa, vr[j].ya);
				swap(vr[j].xb, vr[j].yb);          
			}
		}

		return;
	}                                                        

	if (s == "CLOSE") {
		vector < Rec > nvr;		
		for (int j = 0; j < sz(vr); ++j)
			if (j != i)
				nvr.pb(vr[j]);
		vr = nvr;
		return;		
	}

	assert(s == "OPEN" || s == "RESIZE");
	if (s == "RESIZE") {
		assert(i != -1);
		x = vr[i].xa;
		y = vr[i].ya;
	}

	int w, h;
	cin >> w >> h;
	Rec nw = Rec(x, y, x + w, y + h);

	bool bad = 0;
	if (x + w > xmax || y + h > ymax) {
		bad = 1;
	}

	if (s == "OPEN")
		i = -1;
	for (int j = 0; j < sz(vr); ++j)
		if (j != i && vr[j].inter(nw)) {
			bad = 1;
			break;
		}

	if (bad) 
		cout << "Command " << tt << ": " << s << " - window does not fit \n";						
	else {
		if (s == "OPEN"){
			vr.pb(nw);	
			assert(s == "OPEN");
		}
		else {
			assert(i != -1);
			vr[i] = nw;
		}
	}
}

main () {
	cin >> xmax >> ymax;
	int tt = 0;
	while (cin >> s) {
		solve(++tt);
	}

	cout << sz(vr) << " window(s):\n";
	for (auto r : vr)
		cout << r.xa << ' ' << r.ya << ' ' << r.xb - r.xa << ' ' << r.yb - r.ya << "\n";

//	for (auto r : vr)
//		cerr << r.xa << ' ' << r.ya << ' ' << r.xb << ' ' << r.yb << "\n";
}