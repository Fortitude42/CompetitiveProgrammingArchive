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

int n, m;
ll mx[M << 2], sum[M << 2];


void update(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		sum[v] = mx[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
	sum[v] = sum[v << 1] + sum[v << 1 | 1];
	mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}

pair < ll, ll > get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return mp(0, 0);

	if (l <= tl && tr <= r) 
		return mp(sum[v], mx[v]);

	int tm = (tl + tr) >> 1;
	pair < ll, ll > a = get(l, r, v << 1, tl, tm);
	pair < ll, ll > b = get(l, r, v << 1 | 1, tm + 1, tr);

	return mp(a.f + b.f, max(a.s, b.s));

}
 
void solve() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		update(i, x);
	}
		
	while (m--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int pos, v;
			scanf("%d%d", &pos, &v);
			update(pos, v);
		} else {
			int l, r, x, y;
			scanf("%d%d%d%d", &l, &r, &x, &y);
			pair < ll, ll > tmp = get(l, r);
			ll sum = tmp.f, mx = tmp.s;
			if (x < y)
				swap(x, y);

			double ans = 0;
			if ((mx * y + x - 1) / x > (sum - mx))
				ans = (mx + 0.0) / x;
			else	
				ans = (sum + 0.0) / (x + y);

			printf("%.12lf\n", ans);
		}
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