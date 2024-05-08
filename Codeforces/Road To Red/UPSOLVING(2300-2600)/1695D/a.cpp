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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, ans, cnt[M], cnt1[M];
bool was[M];
vi g[M];

 
void solve() {
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		was[i] = 0;
		cnt[i] = 0;
		cnt1[i] = 0;
	}

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
		++cnt[x], ++cnt[y];
	}

	if (n == 1) {
		cout << 0 << endl;
		return;
	}

	queue < int > q;
	for (int i = 1; i <= n; ++i)
		if (cnt[i] == 1) {
			q.push(i); 
			was[i] = 1;
		}


	while (sz(q)) {
		int v = q.front();
		q.pop();
		int par = -1;
		for (auto to : g[v])
			if (!was[to])
				par = to;

		if (par == -1)
			continue;
		++cnt1[par];


		if (cnt[par] == 2) {
			--cnt[par];
			was[par] = 1;
			q.push(par);
		}
	}

	ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += max(0, cnt1[i] - 1);

	cout << max(ans, 1) << endl;
}

main () {
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}