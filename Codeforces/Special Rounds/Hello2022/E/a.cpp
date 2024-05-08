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

int n, m, a[M], pref[M][3];
string ans[M];

struct group {
	int k, id;
	ll s;
	vi vals;


	bool operator < (const group &x) const {
		return 1ll * s * x.k < 1ll * x.s * k;
	}
} g[M];

bool ok(const group &x, const int &y) {
	return x.s <= y * 1ll * x.k;
}

int get(int l, int r, int i) {
	return pref[r][i] - pref[l - 1][i];
}

bool check(int l, int r, int i) {
	return get(l, r, i) == r - l + 1;
}

 
void solve() {

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);

	reverse(a + 1, a + 1 + m);

	for (int i = 1; i <= m; ++i) {
		ans[i] = "";
		g[i].id = i;
		cin >> g[i].k;
		g[i].s = 0;


		g[i].vals.resize(g[i].k);
		for (int j = 0; j < g[i].k; ++j) {
			cin >> g[i].vals[j];
			g[i].s += g[i].vals[j];
		}
	}

	sort(g + 1, g + 1 + m);

	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < 3; ++j)
			pref[i][j] = pref[i - 1][j];

		pref[i][0] += ok(g[i], a[i]);
		if (i > 1)
			pref[i][1] += ok(g[i], a[i - 1]);
		if (i < n)
			pref[i][2] += ok(g[i], a[i + 1]);
	}

	for (int i = 1; i <= m; ++i) {
		for (auto x : g[i].vals) {

			group tmp;
			tmp.s = g[i].s - x;
			tmp.k = g[i].k - 1;

			int l = 1, r = m, j = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (tmp < g[mid])
					r = mid - 1;
				else {
					l = mid + 1;
					j = mid;
				}
			}

			if (j == i)
				--j;

			if (j < i) {
				if (!ok(tmp, a[j + 1])
				    || (j && !check(1, j, 0))
					|| (i < m && !check(i + 1, m, 0))
					|| (j + 1 <= i - 1 && !check(j + 1, i - 1, 2))) {
					ans[g[i].id] += '0';
					continue;
				}

				ans[g[i].id] += '1';
				continue;
			}

			if (!ok(tmp, a[j]) 
				|| (i > 1 && !check(1, i - 1, 0)) 
				|| (j < m && !check(j + 1, m, 0))
				|| (i + 1 <= j && !check(i + 1, j, 1))) {
				ans[g[i].id] += '0';
				continue;
			}

			ans[g[i].id] += '1';
		}
	}

	for (int i = 1; i <= m; ++i)
		cout << ans[i];
	cout << endl;
}

main () {
	int TT;
	TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}