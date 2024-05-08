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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17, maxn = 5e4 + 11;
const ll INF = 1e18;

int n, c[M], g[M][3], sz = 1, cc[maxn], gg[maxn][3];
string alpha = "RPS";
int lst[M];

int get(char c) {
	for (int i = 0; i < sz(alpha); ++i)	
		if (c == alpha[i])
			return i;
//	assert(0);
	return -1;				
}
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		char cc;
		cin >> cc;
		c[i] = get(cc);
		for (int j = 0; j < 3; ++j)
			cin >> g[i][j];
	}

	memset(cc, -1, sizeof(cc));
	memset(gg, -1, sizeof(gg));

	for (int i = 1; i <= n; ++i) {
		int v = 1, u = i, timer = 200;
		bool found = 0;
		while (timer--) {
			if (cc[v] == -1) 
				cc[v] = (c[u] + 1) % 3;	

			int nv, nu;
			if (gg[v][c[u]] == -1) {
				gg[v][c[u]] = ++sz; 
				found = 1;
				u = g[u][cc[v]];
				v = sz;
				break;
			}                             

			nv = gg[v][c[u]];
			nu = g[u][cc[v]];
			v = nv, u = nu;			
		}
//		cerr << v << ' ' << u << endl;

		if (found) {
			memset(lst, 0, sizeof(lst));
			while (1) {
				lst[u] = v;
				assert(cc[v] == -1);
				assert(gg[v][c[u]] == -1);
				cc[v] = (c[u] + 1) % 3;
				
				int nu = g[u][cc[v]];
				if (lst[nu]) {
					gg[v][c[u]] = lst[nu];
					break;
				} 

				v = gg[v][c[u]] = ++sz;
				u = nu;				
			}
		}
	}

	cout << sz << endl;
	for (int i = 1; i <= sz; ++i) {
		assert(cc[i] != -1);
		cout << alpha[cc[i]] << ' ';
		for (int j = 0; j < 3; ++j) {
			if (gg[i][j] == -1)
				gg[i][j] = i;
			cout << gg[i][j] << ' ';
		}
		cout << endl;
	}
}

main () {
//	file("epic");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

