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
const int N = 10, inf = 1e9, MOD = 1e9 + 7;
const int M = 12;
const ll INF = 1e18;
const double pi = acos(-1);

int n, m, k;
int a[M][M], pos[M], c[M], p[M];
map < vi, int > dp[M], dp1[M];
vi g[M], col;

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}

vi get(const vi &col, int i, int mask) {
	for (int j = 0; j < m; ++j)
		p[j] = j;
	memset(pos, -1, sizeof pos);
	for (int j = 0; j < m; ++j)
		if (col[j]) {
			if (pos[col[j]] == -1) {
				pos[col[j]] = j;
				continue;
			}
			merge(j, pos[col[j]]);
		}

	for (int j = 0; j + 1 < m; ++j)
		if (mask & (1 << j)) {
			if (!a[i][j] || !a[i][j + 1] || get(j) == get(j + 1))
				return {};
			merge(j, j + 1);
		}

	memset(c, 0, sizeof c);
	k = 0;
	vi ans;

	for (int j = 0; j < m; ++j) {
		int j1 = get(j);
		if (a[i][j] && !c[j1])
			c[j1] = ++k;

		ans.pb(c[j1]);
	}
	
	return ans;
}


vi get1(const vi &col, int i, int mask) {
	memset(pos, -1, sizeof pos);
	vi ans(m);
	for (int j = 0; j < m; ++j)
		if (mask & (1 << j)) {
			if (!col[j] || !a[i + 1][j])
				return {};
			ans[j] = col[j];
			pos[col[j]] = j;
		}

	for (int j = 0; j < m; ++j)
		if (col[j] > 0 && pos[col[j]] == -1)
			return {};

	return ans;
		
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = (c == '.');
		}
	}

	col.resize(m, 0);

	dp[0][col] = 1;
	for (int i = 0; i < n; ++i) {		
		for (auto x : dp[i]) {
//			cout << i << ' ' << x.s << endl;
//			for (auto j : x.f)
//				cout << j << ' ';
//			cout << endl << endl << endl;

			for (int mask = 0; mask < (1 << (m - 1)); ++mask) {
				vi y = get(x.f, i, mask);
				if (!sz(y))
					continue;				
				add(dp1[i][y], x.s);
			}				
		}

		if (i + 1 < n) {
			for (auto x : dp1[i]) {
//				cout << i << ' ' << x.s << endl;
//				for (auto j : x.f)
//					cout << j << ' ';
//				cout << endl << endl;

				for (int mask = 0; mask < (1 << m); ++mask) {
					vi y = get1(x.f, i, mask);
					if (!sz(y))
						continue;
//					cout << "--->" << mask << endl;
//					for (auto j : y)
//						cout << j << ' ';					
//					cout << endl;
					add(dp[i + 1][y], x.s);
				}
//				cout << endl << endl << endl;
			}
		}
	}

	for (int j = 0; j < m; ++j)
		col[j] = a[n - 1][j];
	cout << dp1[n - 1][col] << endl;
}   

main () {
	fastio
  	int TT;
  	TT = 1;
//	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}                           