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

int m, n, k = 1, q, x[M], y[M], z[M], sz[M];
int ind[M*10];
char s[M];


int get(int v, int k) {
//	cerr << v << ' ' << k << endl;
	if (k > sz[v])
		return -1;

	if (v == 1)
		return k;

	int i = ind[v];
	assert(i > 0);

	if (s[i] == 'S') {
		if (y[i] == v)
			return get(x[i], 2*k - 1);
		assert(z[i] == v);
		return get(x[i], 2*k);
	}

	assert(s[i] == 'M');
	if (k <= min(sz[x[i]], sz[y[i]])*2) {
		if (k & 1)
			return get(x[i], (k + 1) / 2);
		return get(y[i], k / 2);
	}

	if (sz[x[i]] > sz[y[i]])
		return get(x[i], k - sz[y[i]]);
	return get(y[i], k - sz[x[i]]);
}

bool used[M];

void dfs(int v) {	
	used[v] = 1;
	int i = ind[v];
	assert(i > 0);

	if (s[i] == 'M') {
		if (!used[x[i]])
			dfs(x[i]);
		if (!used[y[i]])
			dfs(y[i]);
		sz[z[i]] = sz[x[i]] + sz[y[i]];
	} else {
		if (!used[x[i]])
			dfs(x[i]);
		sz[y[i]] = (sz[x[i]] + 1) / 2;
		sz[z[i]]= sz[x[i]] / 2;			
	}
}
 
void solve() {
	cin >> m >> n >> q;
	sz[1] = m;

	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> x[i] >> y[i] >> z[i];

		if (s[i] == 'M') {
			ind[z[i]] = i;
		} else {
			ind[y[i]] = i;
			ind[z[i]] = i;
		}		
	}

	used[1] = 1;
	for (int i = 0; i < M; ++i) 
		if (ind[i] > 0 && !used[i])
			dfs(i);

	while (q--) {
		int v, k;
		cin >> v >> k;
		int u = get(v, k);
		if (u == -1) 
			cout << "none\n";
		else
			cout << u << "\n";
	}

}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}