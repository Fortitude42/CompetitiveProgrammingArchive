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

vi vals, pos[M], g[M];
int n, m, a[M], mx[M], s[M], pref[M], suff[M];

 
void solve() {
	for (int i = 0; i < sz(vals); ++i)
		pos[i].clear();
	vals.clear();
	int ans = inf;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) { 
		cin >> a[i]; 
		g[i].clear();
		mx[i] = i;
		vals.pb(a[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(all(vals), a[i]) - vals.begin();
		pos[a[i]].pb(i);
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		mx[l] = max(mx[l], r);
	}

	for (int i = 1; i <= n; ++i)
		mx[i] = max(mx[i], mx[i - 1]);

	int L = n, R = 0;
	for (int x = 0; x < sz(vals); ++x) {
		for (int i = 0; i < sz(pos[x]); ++i)
			s[i] = 0;

		for (int i = 0, j = 0; i < sz(pos[x]); ++i) {
			while (j < sz(pos[x]) && pos[x][j] <= mx[pos[x][i]])
				++j;

			if (j == i + 1)
				continue;

			assert(j > i + 1);
			if (i + 1 <= j - 2) {
				++s[i + 1];
				--s[j - 1];
			}
			g[pos[x][i]].pb(pos[x][j - 1]);
			g[pos[x][j - 1]].pb(pos[x][i]);
		}

		for (int i = 0; i < sz(pos[x]); ++i) {
			if (i)
				s[i] += s[i - 1];

			if (s[i] > 0) {
				L = min(L, pos[x][i]);
				R = max(R, pos[x][i]);
			}
		}
	}

	for (int l = 1; l <= n; ++l) {
		pref[l] = pref[l - 1];
		for (int j : g[l])
			pref[l] = max(pref[l], j);
	}

	suff[n + 1] = 0;
	for (int r = n; r > 0; --r) {
		suff[r] = suff[r + 1];
		for (auto j : g[r])
			if (j < r)
				suff[r] = max(suff[r], j);
	}

	for (int l = 0; l < L; ++l) {
		bool stop = 0;

		for (auto j : g[l]) 
			if (j < l) {
				stop = 1;
				break;
			}

		if (stop)	
			break;
		int r = max({pref[l], suff[l + 1], R});

		
		if (r < l)
			ans = 0;
		else
			ans = min(ans, r - l);
	}

	cout << ans << endl;

}   	

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}