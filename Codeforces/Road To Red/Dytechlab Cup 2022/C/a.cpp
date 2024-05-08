//template by paradox & gege & parasat
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


int n, x[3], y[3], cntx[M], cnty[M], xs, ys, d1[M], d2[M];

 
void solve() {
	cin >> n;
	for (int i = 0; i < 3; ++i) {
		cin >> x[i] >> y[i]; 
		cntx[x[i]] = 0;
		cnty[y[i]] = 0;
	}
	cin >> xs >> ys;

	for (int i = 0; i < 3; ++i) {
		++cntx[x[i]];
		++cnty[y[i]];
	}

	int xx = -1, yy = -1;
	for (int i = 0; i < 3; ++i) {
		if (cntx[x[i]] == 2) {
			assert(xx == -1 || xx == x[i]);
			xx = x[i];
		}

		if (cnty[y[i]] == 2) {
			assert(yy == -1 || yy == y[i]);
			yy = y[i];
		}
	}


	assert(xx != -1 && yy != -1);
	if (xs == xx || ys == yy) {
		puts("YES");
		return;
	}

	vector < pii > coords;
	coords.pb({xx, yy});
	for (int i = 0; i < 4; ++i) {
		int tox = xx + dx[i], toy = yy + dy[i];
		if (tox > 0 && toy > 0 && tox <= n && toy <= n) 
			coords.pb({tox, toy});
		
	}

	for (auto c : coords) {		
		if (sz(coords) > 3 && (c.f % 2) == (xs % 2) && (c.s % 2) == (ys % 2)) {
			puts("YES");
			return;
		}
	}

	puts("NO");
}   	


main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}