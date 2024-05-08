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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int q, tp[M], a[M], b[M], t[M << 2][2];
map < pii, int > cnt;
vector < pii > vals;

void update(int pos, int lvl, int x, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (tl == tr) {
		t[v][lvl] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, lvl, x, v << 1, tl, tm);
	else
		update(pos, lvl, x, v << 1 | 1, tm + 1, tr);

	t[v][lvl] = max(t[v << 1][lvl], t[v << 1 | 1][lvl]);
}

int get(int l, int r, int lvl, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (l > r || tl > r || l > tr)
		return -inf;

	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

int getPos(int i) {
	return lower_bound(all(vals), mp(a[i] - b[i], a[i])) - vals.begin();
}
 
void solve() {
	for (int lvl = 0; lvl < 2; ++lvl)
		for (int i = 0; i < (M << 2); ++i)
			t[i][lvl] = -inf;

	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &tp[i], &a[i]);
		if (tp[i] <= 2) {
			scanf("%d", &b[i]); 
			vals.pb({a[i] - b[i], a[i]});
		}		
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= q; ++i) {
		if (tp[i] == 1) {
			++cnt[mp(a[i], b[i])];
			if (cnt[mp(a[i], b[i])] == 1) {
				int j = getPos(i);
				update(j, 0, a[i]);
				update(j, 1, b[i]);
			}
		} 
		
		if (tp[i] == 2) {
			--cnt[mp(a[i], b[i])];
			if (cnt[mp(a[i], b[i])] == 0) {
				int j = getPos(i);
				update(j, 0, -inf);
				update(j, 1, -inf);
			}
		}

		if (tp[i] == 3) {
			int j = lower_bound(all(vals), mp(a[i], -inf)) - vals.begin();
			printf("%d\n", max(get(j, sz(vals) - 1, 1) + a[i], get(0, j - 1, 0)));
		}
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

