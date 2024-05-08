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

int n, m, t[M<<3][2];
int a[M], b[M], cur[M], prv[M];
vi vals;

void build(int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	t[v][0] = t[v][1] = 0;
	if (tl == tr)
		return;
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

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
		return 0;

	if (l <= tl && tr <= r)			
		return t[v][lvl];

	int tm = (tl + tr) >> 1;
	return max(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}
 
void solve() {
	vals.clear();


	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		vals.pb(a[i]);
	}

	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		vals.pb(b[i]);
	}


	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) 
		a[i] = lower_bound(all(vals), a[i]) - vals.begin();
	

	for (int i = 1; i <= m; ++i)
		b[i] = lower_bound(all(vals), b[i]) - vals.begin();

	sort(b + 1, b + 1 + m);
	reverse(b + 1, b + 1 + m);


	build();
	int mx = 0;
	for (int i = n; i > 0; --i) {
		prv[i] = get(a[i], a[i], 0);
		cur[i] = get(a[i] + 1, sz(vals) - 1, 0) + 1;
		update(a[i], 0, cur[i]);
		mx = max(mx, cur[i]);
	}

	vi ans;
	int i = 1;
	for (int j = 1; j <= m; ++j) {
		while (i <= n + 1) {
			int pref = get(0, b[j] - 1, 1);
			int suff = get(b[j] + 1, sz(vals) - 1, 0);
			if (pref + suff + 1 > mx) {
				if (i == n + 1) {
					i++;
					break;
				}

				update(a[i], 0, prv[i]);
				cur[i] = get(0, a[i] - 1, 1) + 1;
				update(a[i], 1, cur[i]);
				ans.pb(a[i]);
				++i;
			} else
				break;
		}
		ans.pb(b[j]);
	}

	while (i <= n)
		ans.pb(a[i++]);

	for (auto x : ans)
		cout << vals[x] << ' ';
	cout << "\n";
}

main () {
  int TT;
  TT = 1;
  fastio
  cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}