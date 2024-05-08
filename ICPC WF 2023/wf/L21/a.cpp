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
 

//const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int dx, dy, k;


int dist(int xa, int ya, int xb, int yb) {
	int x = xb - xa;
	int y = yb - ya;

	int ly = max(abs(x), abs(y));
	int a = 2*ly - 1;
	if (y == ly) {
		if (x == -ly)
			return (a+2)*(a+2);
		return a*a + (ly + x);
	}

	if (x == ly)
		return a*a + 2*ly + (ly - y);
	
	if (y == -ly)
		return a*a + 4*ly + (ly - x);

	assert(x == -ly);
	return a*a + 6*ly + y + ly;
}


map < int, int > nxt[M*M*M];
int sz;
vi g[M][M], gg[M*M*M];

void add(const vi &s) {
	int v = 0;
	for (int i = 0; i < sz(s); ++i) {
		gg[v].pb(s[i]);
		int x = s[i];
		if (!nxt[v].count(x))
			nxt[v][x] = ++sz;
		v = nxt[v][x];			
	}
}


int get(const vi &s) {
	int v = 0;
	int res = 0;
	for (int i = 0; i < sz(s); ++i) {
		if (sz(gg[v]) > 1) {
			if (gg[v].back() == s[i])
				res = max(res, gg[v][sz(gg[v]) - 2]);
			else
				res = max(res, s[i]);
		}

		v = nxt[v][s[i]];
	}

	return res;
}

bool comp(pii a, pii b) {
	if (a.s == b.s)
		return a.f < b.f;
	return a.s < b.s;
}
 
void solve() {
	cin >> dx >> dy;
	vector < pii > vc;
	for (int y = dy; y > 0; --y)
		for (int x = 1; x <= dx; ++x) {
			char c;
			cin >> c;
			if (c == 'X')
				vc.pb({x, y});
		}

	k = sz(vc);

	for (int x = 1; x <= dx; ++x)
		for (int y = 1; y <= dy; ++y) {
			for (auto c : vc) 
				g[x][y].pb(dist(x, y, c.f, c.s) - 1);
			sort(all(g[x][y]));
			add(g[x][y]);
		}
	for (int i = 0; i <= sz; ++i)
		sort(all(gg[i]));

	ll sum = 0;
	int mx = -1;
	vector < pii > mxv;

	for (int x = 1; x <= dx; ++x)
		for (int y = 1; y <= dy; ++y) {
			int cur = get(g[x][y]);
			if (cur > mx) {
				mxv = {mp(x, y)};
				mx = cur;
			} else if (cur == mx)
				mxv.pb(mp(x, y));
			sum += cur;
		}


	cout << setprecision(6) << fixed;
	cout << (sum + 0.0) / (dx*dy) << "\n";
	cout << mx << "\n";
	sort(all(mxv), comp);
	for (auto x : mxv)
		cout << "(" << x.f << "," << x.s << ") ";
			
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}