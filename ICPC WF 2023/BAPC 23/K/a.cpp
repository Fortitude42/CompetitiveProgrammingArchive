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

int n, timer, lft;
map < int, int > was[M];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int ask(int x, int y) {
	if (was[x].count(y))
		return was[x][y];

	assert(--lft >= 0);

	cout << "? " << x << ' ' << y << endl;
	int res;
	cin >> res;
	return was[x][y] = res;
}


bool in(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void solve(int lx, int rx, int ly, int ry) {
	int mx = uniform_int_distribution<int>(lx, rx)(rng);
	int my = uniform_int_distribution<int>(ly, ry)(rng);

	pair < int, pii > c = mp(-1, mp(-1, -1));

	for (int x = lx; x <= rx; ++x) {
	    pair < int, pii > cur = mp(ask(x, my), mp(x, my));
		c = max(c, cur);
	}

	for (int y = ly; y <= ry; ++y) {
	    pair < int, pii > cur = mp(ask(mx, y), mp(mx, y));
		c = max(c, cur);
	}
	
	int X = c.s.f, Y = c.s.s;
	
	if (Y == my) {
		int l = (Y - 1 >= ly) ? ask(X, Y - 1) : -inf;
		int r = (Y + 1 <= ry) ? ask(X, Y + 1) : -inf;

		if (c.f > l && c.f > r) {
			
			cout << "! " << c.f << endl;
			exit(0);
		}

		assert(X != mx);

		int nw_ly, nw_ry, nw_lx, nw_rx;
		if (X < mx) {
			nw_lx = lx;
			nw_rx = mx - 1;
		} else {
			nw_lx = mx + 1;
			nw_rx = rx;
		}

		if (l > c.f) {
			nw_ly = ly;
			nw_ry = my - 1;
		} else {
			assert(r > c.f);
			nw_ly = my + 1;
			nw_ry = ry;
		}	         		

		solve(nw_lx, nw_rx, nw_ly, nw_ry);
		return;
	}

	assert(X == mx);
	int l = (X - 1 >= lx) ? ask(X - 1, Y) : -inf;
	int r = (X + 1 <= rx) ? ask(X + 1, Y) : -inf;

	if (c.f > l && c.f > r) {
		cout << "! " << c.f << endl;
		exit(0);
	}

	int nw_ly, nw_ry, nw_lx, nw_rx;
	if (Y < my) {
		nw_ly = ly;
		nw_ry = my - 1;
	} else {
		nw_ly = my + 1;
		nw_ry = ry;
	}			

	if (l > c.f) {
		nw_lx = lx;
		nw_rx = mx - 1;
	} else {
		assert(r > c.f);
		nw_lx = mx + 1;
		nw_rx = rx;
	}

	solve(nw_lx, nw_rx, nw_ly, nw_ry);
}
 
void solve() {
	cin >> n;
	lft = 10*n + 100;
	solve(1, n, 1, n);
}	

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}
