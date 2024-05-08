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
const int N = 300, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 27;
const ll INF = 1e18;

int w, h;
int a[M][M], b[M][M], tmp[M][M];


int findi() {
	for (int i = 1; i <= h + 10; ++i)
		for (int j = 1; j <= w + 10; ++j) {
			tmp[i][j] = a[i][j];
			b[i][j] = 0;
		}

	for (int i = 1; i <= h + 10; ++i)
		for (int j = 1; j <= w + 10; ++j)
			if (tmp[i][j]) {
				if (j >= w || i >= h)
					return i;

				b[i + 1][j + 1] = 1;
				for (int x = i; x <= i + 2; ++x)
					for (int y = j; y <= j + 2; ++y)
						tmp[x][y] ^= 1;
			}

	return -1;
}


int findj() {
	for (int i = 1; i <= h + 10; ++i)
		for (int j = 1; j <= w + 10; ++j) {
			tmp[i][j] = a[i][j];
			b[i][j] = 0;
		}

	for (int j = 1; j <= w + 10; ++j)
		for (int i = 1; i <= h + 10; ++i)
			if (tmp[i][j]) {
				if (i >= h || j >= w)
					return j;

				b[i + 1][j + 1] = 1;
				for (int x = i; x <= i + 2; ++x)
					for (int y = j; y <= j + 2; ++y)
						tmp[x][y] ^= 1;
			}

	return -1;
}
 
void solve() {
	cin >> w >> h;
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j) {
		    char c;
		    cin >> c;
			a[i][j] = c == '#';
		}


	while (1) {
		int sum = 0;
		for (int x = 1; x <= h; ++x)
			for (int y = 1; y <= w; ++y) {
				sum += a[x][y];
			}

		if (sum == 1)
			break;


		int i = findi();
		if (i == -1) {			
			for (int i = 1; i <= h + 10; ++i)
				for (int j = 1; j <= w + 10; ++j)
					a[i][j] = b[i][j];
			continue;
		}
		int j = findj();
		assert(j != -1);
		a[i][j] ^= 1;

		int i1 = findi();
		if (i1 != -1) {
			a[i][j] ^= 1;
			break;
		}

		for (int i = 1; i <= h + 10; ++i)
			for (int j = 1; j <= w + 10; ++j) {
				a[i][j] = b[i][j];		
			}
	}

//	for (int i = 1; i <= h; ++i, cout << endl)
//		for (int j = 1; j <= w; ++j)
//			cout << a[i][j];



	int lx = h + 1, rx = -1;
	int ly = w + 1, ry = -1;
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j)
			if (a[i][j]) {
				lx = min(lx, i);
				rx = max(rx, i);
				ly = min(ly, j);
				ry = max(ry, j);
			}

	assert(lx <= rx);
	assert(ly <= ry);
	for (int i = lx; i <= rx; ++i, cout << endl)
		for (int j = ly; j <= ry; ++j)
			cout << (a[i][j] == 1 ? '#' : '.');
				

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}