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

ll s[M*3], t[M*3], a[M*3], pref[M*3], suff[M*3], T[(M*3) << 2][2];
int n, m, x[M], p[M];
vi vals;

void inc(int p, int x, int l, int r, int lvl) {
	if (l > r)
		return;

	if (lvl == 1) {                                                   
		s[l] += (p + x);
		s[r + 1] -= (p + x);
		t[l]--;
		t[r + 1]++;
		return;
	}

	s[l] += (p - x);
	s[r + 1] -= (p - x);
	t[l]++;
	t[r + 1]--;
}

void build(int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (tl == tr) {
		T[v][0] = a[tl] - vals[tl];
		T[v][1] = a[tl] + vals[tl];
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	T[v][0] = max(T[v << 1][0], T[v << 1 | 1][0]);
	T[v][1] = max(T[v << 1][1], T[v << 1 | 1][1]);
}

ll get(int l, int r, int lvl, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (l > r || tl > r || l > tr)
		return -INF;

	if (l <= tl && tr <= r) 
		return T[v][lvl];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> p[i];       

		int l = x[i] - p[i];
		int r = x[i] + p[i];

		vals.pb(l);
		vals.pb(r);
		vals.pb(x[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) {
		int l = lower_bound(all(vals), x[i] - p[i]) - vals.begin();
		int r = lower_bound(all(vals), x[i] + p[i]) - vals.begin();
		int j = lower_bound(all(vals), x[i]) - vals.begin();

		inc(p[i], x[i], l, j, 0);
		inc(p[i], x[i], j + 1, r, 1);
	}

	for (int i = 0; i < sz(vals); ++i) {
		if (i > 0) {
			s[i] += s[i - 1];
			t[i] += t[i - 1];
		}
		a[i] = s[i] + t[i] * vals[i];
		pref[i] = a[i];
		if (i > 0)
			pref[i] = max(pref[i], pref[i - 1]);
	}

	suff[sz(vals)] = -INF;
	for (int i = sz(vals) - 1; i >= 0; --i)
		suff[i] = max(suff[i + 1], a[i]);
	build();

	

	for (int i = 1; i <= n; ++i) {
		int l = lower_bound(all(vals), x[i] - p[i]) - vals.begin();
		int r = lower_bound(all(vals), x[i] + p[i]) - vals.begin();
		int j = lower_bound(all(vals), x[i]) - vals.begin();
		
		if ((l > 0 && pref[l - 1] > m) || suff[r + 1] > m) {
			cout << "0";
			continue;
		}
		
		if (get(l, j, 0) - (p[i] - x[i]) > m || get(j + 1, r, 1) - (p[i] + x[i]) > m) {
			cout << "0";
			continue;
		}
		cout << "1";
	}
	cout << endl;

	for (int i = 0; i <= sz(vals); ++i)
		s[i] = t[i] = 0;
	vals.clear();
}

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}