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

int n, m, a[M], l[M], r[M], ans[M], t[M][2];
ll s[M][2], b[M];
vi g[M];
map < ll, int > lst[2];

void inc(int pos, int lvl, int x) {
	while (pos <= n) {
		t[pos][lvl] += x;
		pos |= (pos + 1);
	}
}

int get(int r, int lvl) {
	int res = 0;
	while (r >= 0) {
		res += t[r][lvl];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

int get(int l, int r, int lvl) {
	return get(r, lvl) - get(l - 1, lvl);
}

 
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		s[i][0] = s[i - 1][0];
		s[i][1] = s[i - 1][1];
		s[i][i & 1] += a[i];
	}

	for (int i = 1; i <= n; ++i)
		b[i] = s[i][1] - s[i][0];
	
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]); 
		l[i]--;
		g[r[i]].pb(i);
	}

	for (int rg = 0; rg <= n; ++rg) {
		if (lst[rg & 1].count(b[rg]))
			inc(lst[rg & 1][b[rg]], rg & 1, -1);
		
		lst[rg & 1][b[rg]] = rg;
		inc(rg, rg & 1, 1);

		for (auto i : g[rg])
			ans[i] = get(l[i], r[i], 0) + get(l[i], r[i], 1);
	}

	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}