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

int n, t[M], a[M], d[M], e[M], b[M], tt[M], timer, ans;
vector < pii > vals;

inline void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

void inc(int pos, int x) {
	while (pos < n) {
		if (tt[pos] != timer) {
			tt[pos] = timer;
			t[pos] = 0;
		}

		add(t[pos], x);
		pos |= pos + 1;
	}
}

int get(int r) {
	int res = 0;
	while (r >= 0) {
		if (tt[r] == timer)
			add(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}

 
void solve() {
	vals.clear();
	ans = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		vals.pb({a[i], -i});
	}

	sort(all(vals));
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(all(vals), mp(a[i], -i)) - vals.begin(); 
		b[a[i]] = i;
	}
/*
	for (int i = 1; i <= n; ++i)
		cerr << a[i] << ' ';
	cerr << endl << endl;
*/

	++timer;
	for (int i = 1; i <= n; ++i) {
		d[i] = get(a[i]) + 1;

		if (d[i] == MOD)
			d[i] = 0;

		inc(a[i], d[i]);
	}



	++timer;
	for (int i = n; i > 0; --i) {
		e[i] = get(n - 1 - a[i]) + 1;

		if (e[i] == MOD)
			e[i] = 0;

		inc(n - 1 - a[i], e[i]);
	}

	int mx = -1;
	for (int i = n; i >= 1; --i) 
		if (a[i] > mx) {
			vi pos;
			for (int j = mx + 1; j <= a[i] - 1; ++j)
				if (b[j] < i)
					pos.pb(b[j]);

			sort(all(pos));
			reverse(all(pos));

			++timer;
			inc(n - 1 - a[i], 1);
			for (auto j : pos) {
				int cur = get(n - 1 - a[j]);
				add(ans, d[j] * 1ll * (e[j] - cur) % MOD);
				inc(n - 1 - a[j], cur);
			}			

			mx = a[i];
		}

	printf("%d\n", ans);
}

main () {
	int TT;
	TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}