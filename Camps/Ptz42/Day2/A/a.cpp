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
const int N = 2e5 + 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int q, tp[M], s[M], x[M], y[M];
map < pii, int > cnt[2];
vector < pair < pii, int > > vals;

struct node {
	int res, xa, ya, xb, yb;
} t[M << 2], cur;

void upd(int v) { 
	t[v].xa = min(t[v << 1].xa, t[v << 1 | 1].xa);
	t[v].ya = min(t[v << 1].ya, t[v << 1 | 1].ya);
	t[v].xb = min(t[v << 1].xb, t[v << 1 | 1].xb);
	t[v].yb = min(t[v << 1].yb, t[v << 1 | 1].yb);
	t[v].res = min(t[v << 1].res, t[v << 1 | 1].res);
	
	if (t[v << 1].xb != -inf && t[v << 1 | 1].xa != -inf)
		t[v].res = min(t[v].res, t[v << 1].xb + t[v << 1 | 1].xa);

	if (t[v << 1].ya != -inf && t[v << 1 | 1].yb != -inf)
		t[v].res = min(t[v].res, t[v << 1].ya + t[v << 1 | 1].yb);
}

void build(int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (tl == tr) {
		t[v].res = t[v].xa = t[v].ya = t[v].xb = t[v].yb = inf;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	upd(v);
}

void update(int pos, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (tl == tr) {
		t[v] = cur;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, v << 1, tl, tm);
	else
		update(pos, v << 1 | 1, tm + 1, tr);
	upd(v);
}

void f(int i, bool add) {
	int xy = x[i] - y[i];
	if (s[i] == 1)
		xy = -xy;

	int pos = lower_bound(all(vals), mp(mp(xy, x[i]), s[i])) - vals.begin();
	cur.res = inf;
//	cerr << pos << endl;
	if (s[i] == 0) {
		cur.xa = add ? x[i] : inf;
		cur.ya = add ? y[i] : inf;
		cur.xb = inf;
		cur.yb = inf;
	} else {
		cur.xb = add ? x[i] : inf;
		cur.yb = add ? y[i] : inf;
		cur.xa = inf;
		cur.ya = inf;
	}
	update(pos);
}

void solve() {
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> tp[i] >> s[i] >> x[i] >> y[i];
		--s[i];
		if (s[i] == 0)
			vals.pb({{x[i] - y[i], x[i]}, s[i]});
		else
			vals.pb({{y[i] - x[i], x[i]}, s[i]});			
	}	

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	build();
	for (int i = 1; i <= q; ++i) {
		if (tp[i] == 1) {
			++cnt[s[i]][mp(x[i], y[i])];
			if (cnt[s[i]][mp(x[i], y[i])] == 1)
				f(i, 1);
		} else {
			--cnt[s[i]][mp(x[i], y[i])];
			if (cnt[s[i]][mp(x[i], y[i])] == 0)
				f(i, 0);
		}

		cout <<  (t[1].res == inf ? -1 : t[1].res) << endl;
	}

}

main () {
	fastio
	int TT = 1;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                                      