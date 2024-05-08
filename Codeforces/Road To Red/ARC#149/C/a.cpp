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
const int N = 2e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17, maxn = 1012;
const ll INF = 1e18;

bool u[M], used[M];
int n, c[maxn][maxn];

void precalc() {
	for (int i = 2; i < M; ++i)
		if (!u[i])
			for (int j = i + i; j < M; j += i)
				u[j] = 1;
}

void add(int x, int y, int z) {
	used[z] = 1;
	c[x][y] = z;
}
 
void solve() {
	cin >> n;
	if (n % 2 == 0) {
		int r1 = n / 2, r2 = n / 2 + 1;
		add(r1, 1, 1);
		add(r2, 1, 8);
		for (int i = 2; i <= n; ++i) {
			add(r1, i, (i - 1)*2 + 1); 
			add(r2, i, 2*((i - 1)*2 + 1));
		}

		int odd = 1, even = 2;
		for (int i = 1; i <= n; ++i) {
			if (i == r1 || i == r2)
				continue;
			for (int j = 1; j <= n; ++j) {
				if (i < r1) {
					while (used[odd])
						odd += 2;
					add(i, j, odd);
				} else {
					while (used[even])
						even += 2;
					add(i, j, even);	
				}
			}
		}
	} else {
		int m = (n + 1) / 2;
		add(m, m, 7);
		add(m, m + 1, 8);
		add(m - 1, m + 1, 1);
		add(m + 1, m, 2);

		int odd = 3, even = 2;
		for (int i = 1; i <= n; ++i) {
			while (used[odd])
				odd += 2;

			if (i < m) {
				add(m, i, odd);
				add(m + 1, i, odd*2);
			} else if (i > m + 1) {
				add(m - 1, i, odd);
				add(m, i, odd*2);
			}
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (c[i][j])
					continue;
				if (i < m || (i == m && j <= m)) {
					while (used[odd])
						odd += 2;
					add(i, j, odd);
				} else {
					while (used[even])
						even += 2;
					add(i, j, even);	
				}
			}
	}

	for (int i = 1; i <= n; ++i, cout << endl)
		for (int j = 1; j <= n; ++j)
			cout << c[i][j] << ' ';
}

main () {
	fastio
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}