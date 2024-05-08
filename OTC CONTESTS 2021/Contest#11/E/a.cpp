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
const int N = 3000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, k, d[M][M], par[M][M]; 
set < pii > st[M];
queue < pii > q;
vi g[M];


void solve() {
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}

	while (k--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		st[b].insert({a, c});
	}

	memset(d, -1, sizeof(d));
	d[1][0] = 0;
	q.push({1, 0});

	int Lst = -1;
	while (sz(q)) {
		int v = q.front().f, lst = q.front().s;
		q.pop();

		if (v == n) {
			Lst = lst;
			break;
		}


		for (auto to : g[v]) {
			if (d[to][v] > -1 || st[v].count(mp(lst, to)))
				continue;

			
			d[to][v] = d[v][lst] + 1;
			par[to][v] = lst;
			q.push({to, v});
		}
	}

	if (Lst == -1)  {
		printf("-1\n");
		return;
	}

	vi ans;
	int v = n;
	while (v) {
		ans.pb(v);
		int nLst = par[v][Lst];
		v = Lst;
		Lst = nLst;
	}

	reverse(all(ans));
	printf("%d\n", sz(ans) - 1);
	for (auto x : ans)
		printf("%d ", x);
}   



main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}             