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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], b[M], a1[M], c[M], ans[M];
int u[512], mx;
vi g[M];


void dfs(int v, int p = 0) {
	vi prv;	
	if (!c[v]) {
		prv.resize(mx);
		for (int j = 0; j < mx; ++j)
			prv[j] = u[j];


		for (int j = 0; j < mx; ++j)
			u[(j + a[v]) % mx] = min(u[(j + a[v]) % mx], prv[j] + a[v]);
	} else
		a1[v] = c[v];

	for (auto to : g[v])
		if (to != p)  {
			if (c[v] > 0 && c[to] == 0)
				mx = c[v];

			dfs(to, v);			
		}

	if (c[v] > 0) {
		ans[v] = (b[v] % c[v]) == 0;
	} else {
		ans[v] = u[b[v] % mx] <= b[v];
		for (int j = 0; j < sz(prv); ++j)
			u[j] = prv[j];
	}
}

 
void solve() {
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		g[u].pb(v);
		g[v].pb(u);
	}

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a1[i] = a[i];
	}

	for (int i = 1; i <= n; ++i)
		cin >> b[i];

	c[1] = (1 << 20);
	queue < int > q;
	q.push(1);
	int cnt = 5000 - 1;
	while (sz(q)) {
		int v = q.front();
		q.pop();

		if (c[v] == 1)
			break;


		for (auto to : g[v]) {
			if (cnt > 0 && !c[to]) {
				cnt--;
				c[to] = c[v] >> 1;
				q.push(to);
			}
		}
	}

	for (int j = 0; j < 512; ++j)
		u[j] = inf;

	u[0] = 0;

	dfs(1);

	for (int i = 1; i <= n; ++i)
		cout << a1[i] << ' ';
	cout << "\n";
	for (int i = 1; i <= n; ++i)
		cout << ans[i];
	cout << "\n";
}

main () {
  int TT;
  TT = 1;
  	fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}