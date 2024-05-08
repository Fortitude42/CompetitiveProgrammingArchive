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


vi valx, valy;
vector < pii > g[M << 1];
int t[M << 3], lz[M << 3];
int n, x[M], y[M], lx[M], rx[M], ly[M], ry[M];

void build(int v = 1, int tl = 0, int tr = sz(valy) - 1) {
	t[v] = lz[v] = 0;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void push(int v) {
	if (lz[v]) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];

		t[v << 1] += lz[v];
		t[v << 1 | 1] += lz[v];

		lz[v] = 0;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 0, int tr = sz(valy) - 1) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		lz[v] += x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

bool check(int k) {
	valx = valy = {-k, k, k + 1};
	valx = {-k, k + 1};
	valy = {-k, k};
	for (int i = 1; i <= n; ++i) {
		lx[i] = max(-k, x[i] - k);
		rx[i] = min(k + 1, x[i] + k + 1);

		ly[i] = max(-k, y[i] - k);
		ry[i] = min(k, y[i] + k);
		if (lx[i] > rx[i] || ly[i] > ry[i])
			continue;


		valx.pb(lx[i]);
		valx.pb(rx[i]);

		valy.pb(ly[i]);
		if (ly[i] - 1 >= -k)
			valy.pb(ly[i] - 1);
		valy.pb(ry[i]);
		if (ry[i] + 1 <= k)
			valy.pb(ry[i] + 1);
	}

	sort(all(valx));
	valx.resize(unique(all(valx)) - valx.begin());

	sort(all(valy));
	valy.resize(unique(all(valy)) - valy.begin());

	build();
	for (int i = 0; i <= sz(valx); ++i) 
		g[i].clear();	


	for (int i = 1; i <= n; ++i) {
		if (lx[i] > rx[i] || ly[i] > ry[i])
			continue;

		lx[i] = lower_bound(all(valx), lx[i]) - valx.begin();
		rx[i] = lower_bound(all(valx), rx[i]) - valx.begin();		

		ly[i] = lower_bound(all(valy), ly[i]) - valy.begin();
		ry[i] = lower_bound(all(valy), ry[i]) - valy.begin();

		g[lx[i]].pb(mp(i, 1));
		g[rx[i]].pb(mp(i, -1));
	}	

	for (int j = 0; j + 1 < sz(valx); ++j) {                                  
		for (auto i : g[j])
			update(ly[i.f], ry[i.f], i.s);
		
		if (!t[1]) 
			return 1;					
	}

	return 0;	
}
 
void solve(int tt) {
	cin >> n;
	if (n == -1)
		exit(0);

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	int l = 0, r = inf, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (!check(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}


	cout << "Case " << tt << ": ";
	if (res == -1) {
		cout << "never\n";
		return;
	}

	cout << res << "\n";
}

main () {
	fastio
  for (int tt = 1; ; ++tt) {
    solve(tt);
  }
}