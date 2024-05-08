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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int x, y, par[M][M];
bool was[M][M];
queue < pii > q;


void add(int i, int j) {
	if (!was[i][j]) {
		was[i][j] = 1;
		q.push({i, j});
	}
}

 
void solve() {
	cin >> x >> y;
	memset(par, -1, sizeof(par));

	add(0, 0);
	while (sz(q)) {
		int i = q.front().f, j = q.front().s;
		cerr << i << ' ' << j << endl;
		q.pop();

		if (i + j > 0) {
			for (int k = 2; ; ++k) {
				if (i*k > N || j*k > N)
					break;

				add(i*k, j*k);
			}
		}
			
		int g = __gcd(i, j);
		add(i/g, j/g);

		for (int c = 1; ; ++c) {
			int ii = i + c*(c - 1) / 2;
			int jj = j + 2*c - 1;
			if (ii > N || jj > N)
				break;
			add(ii, jj);
		}
	}

	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			if (!was[i][j])
				cerr << i << ' ' << j << endl;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}