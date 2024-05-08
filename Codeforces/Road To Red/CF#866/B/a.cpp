#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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

int n;
pii a[M];
set < pii > ans;

void check(int h, int w) {
	map < int, set < int > > qh, qw;
	for (int i = 1; i <= n; ++i) {
		qh[a[i].f].insert(i);
		qw[a[i].s].insert(i);
	}

	int hh = h, ww = w;
	while (1) {
		while (sz(qh[h])) {
			int i = *qh[h].begin();
			qh[a[i].f].erase(i);
			qw[a[i].s].erase(i);

			w -= a[i].s;
		}
		while (sz(qw[w])) {
			int i = *qw[w].begin();
			qh[a[i].f].erase(i);
			qw[a[i].s].erase(i);

			h -= a[i].f;
		}

		if (!sz(qh[h]) && !sz(qw[w]))
			break;
	}
//	cerr << h << ' ' << w << endl;
//	cerr << hh << ' ' << ww << endl << endl;

	if (!h || !w)
		ans.insert(mp(hh, ww));
}

void solve() {
	cin >> n;
	int s = 0, h = 0, w = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].f >> a[i].s;
		s += a[i].f * a[i].s;
		h = max(h, a[i].f);
		w = max(w, a[i].s);
	}

	ans.clear();
	if (s % h == 0)
		check(h, s / h);
	if (s % w == 0)
		check(s / w, w);

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
}

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}