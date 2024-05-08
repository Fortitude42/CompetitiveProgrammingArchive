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
const int N = 4e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, tmp[M], timer;
int c[M];
vi a[M], pos[M];
vector < ll > d[M];
set < pair < ll, int > > q1[M], q2[M];
set < pair < ll, pair < pii, int > > > q;
 
void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);

	for (int j = 1; j <= m; ++j) {
		q1[j].clear();
		q2[j].clear();	
	}

	for (int i = 1; i <= n; ++i) {
		a[i].resize(m + 1);
		d[i].resize(m + 1);
		pos[i].clear();
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			pos[i].pb(j);
			pos[i].pb(j);
			q1[j].insert(mp(a[i][j], i));
			q2[j].insert(mp(a[i][j], i));
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			d[i][j] = INF;

	d[1][0] = 0;
	q.insert(mp(0ll, mp(mp(1, 0), 0)));
	while (sz(q)) {
		pair < ll, pair < pii, int > > x = *q.begin();
		q.erase(q.begin());
		ll val = x.f;
		int i = x.s.f.f;
		int j = x.s.f.s;
		int tp = x.s.s;

		if (!tp) {
			++timer;
			for (int jj = 0; jj < sz(pos[i]); ++jj) {

				if (pos[i][jj] == j || tmp[pos[i][jj]] == timer)
					continue;

				int j1 = pos[i][jj];
				while (sz(q1[j1])) {
					pair < ll, int > cur = *q1[j1].rbegin();
					if (cur.f < a[i][j1])
						break;

					q1[j1].erase(cur);
					int i1 = cur.s;
					//val + c[i1]
					if (d[i1][0] > val + c[i1]){
						q.erase(mp(d[i1][0], mp(mp(i1, 0), 0)));
						d[i1][0] = val + c[i1];
						q.insert(mp(d[i1][0], mp(mp(i1, 0), 0)));
					}
				}

				q.insert(mp(val + a[i][j1], mp(mp(i, j1), 1)));

				swap(pos[i][jj], pos[i].back());
				pos[i].ppb();
				tmp[pos[i][jj]]
				--jj;
			}
		} else {
			int j1 = j;
			while (sz(q2[j1])) {
				pair < ll, int > cur = *q2[j1].begin();
				if (cur.f > a[i][j1])
					break;

				q2[j1].erase(cur);
				int i1 = cur.s;
				if (d[i1][j1] > val + c[i1] - a[i1][j1]) {
					q.erase(mp(d[i1][j1], mp(mp(i1, j1), 0)));
					d[i1][j1] = val + c[i1] - a[i1][j1];
					q.insert(mp(d[i1][j1], mp(mp(i1, j1), 0)));
				}
			}
		}
	}
	

	ll ans = d[n][0];
	for (int j = 1; j <= m; ++j)
		ans = min(ans, d[n][j]);
	printf("%lld\n", ans);
}

main () {
  int TT;
  TT = 1;
  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}