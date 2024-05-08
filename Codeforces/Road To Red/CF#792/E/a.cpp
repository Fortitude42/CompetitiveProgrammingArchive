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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi v;
vector < pii > vv;
map < int, int > cnt, pos;
int n, k, a[M], t[M << 2][2];
 
void build(int v = 1, int tl = 0, int tr = sz(vv) - 1) {
	t[v][0] = t[v][1] = 0;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}


void update(int pos, int lvl, int x, int v = 1, int tl = 0, int tr = sz(vv) - 1) {
	if (tl == tr) {
		t[v][lvl] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	
	if (pos <= tm)
		update(pos, lvl, x, v << 1, tl, tm);
	else
		update(pos, lvl, x, v << 1 | 1, tm + 1, tr);

	t[v][lvl] = t[v << 1][lvl] + t[v << 1 | 1][lvl];
}


int get(int k, int v = 1, int tl = 0, int tr = sz(vv) - 1) {
	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;

	if (t[v << 1][0] > k)
		return get(k, v << 1, tl, tm);

	return get(k - t[v << 1][0], v << 1 | 1, tm + 1, tr);
}

int get1(int l, int r, int lvl, int v = 1, int tl = 0, int tr = sz(vv) - 1) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	return get1(l, r, lvl, v << 1, tl, tm) + get1(l, r, lvl, v << 1 | 1, tm + 1, tr);
}

void solve() {
	pos.clear();
	cnt.clear();
	v.clear();
	vv.clear();

	int diff = 0;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!cnt.count(a[i]))
			++diff;
		++cnt[a[i]];
	}

	for (int i = 1; i <= n; ++i)
		v.pb(a[i]);
	

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (auto x : v)
		vv.pb({cnt[x], x});

	sort(all(vv));

	build();

	for (int i = 0; i < sz(vv); ++i) {
		pos[vv[i].s] = i; 
		update(i, 0, vv[i].f);
		update(i, 1, 1);
	}
	

	int ans = diff;
	int need = 0;
	for (int x = 0; x <= n; ++x) {
		if (need > k)
			break;

		int cur_diff = diff + need;
		if (t[1][0] <= k)
			cur_diff -= t[1][1];
		else {
			int j = get(k);
			cur_diff -= get1(0, j - 1, 1);
		}

		if (x > 0)
			ans = min(ans, cur_diff - x);

		if (!cnt.count(x))
			++need;
		else {
			update(pos[x], 0, -cnt[x]);
			update(pos[x], 1, -1);
		}	
	}
	
	cout << ans << endl;
}

main () {
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}