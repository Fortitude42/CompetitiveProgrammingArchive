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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, x[M], ans[M], d[M];
vi g[M], roots;
bool zero[M];

void dfs(int v) {
	for (auto to : g[v]) {
		zero[to] = zero[v];
		if (zero[v])
			ans[to] = ans[v];
		else
			ans[to] = -ans[v];
		dfs(to);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];

	for (int i = 1; i <= m; ++i)
		cin >> d[i];


	int add = 0;
	bool neg = 0;
	int l = 1, r = N;

	for (int i = 1; i <= m; ++i) {
		if (l > r)
			break;

		if (!neg) 
			add -= d[i];
		else
			add += d[i]	;

		int dd = -add;
		if (dd > r) {
		    neg = 1;
			continue;
		}
		if (dd < l) {
			neg = 0;
			continue;
		}

		assert(dd >= 1 && dd <= N);
			
		ans[dd] = i;
		zero[dd] = 1;
		roots.pb(dd);

		int cnt1 = dd - l;
		int cnt2 = (r - l + 1) - cnt1 - 1;
		if (cnt1 > cnt2) {
			neg = 1;
			for (int x = dd + 1; x <= r; ++x) {
				int y = -x - add*2;
				assert(y >= l && y < dd);
				g[y].pb(x);
			}
			r = dd - 1;					
		} else {
			neg = 0;
			for (int x = l; x < dd; ++x) {
				int y = -x - add*2;
				assert(y > dd && y <= r);
				g[y].pb(x);
			}
			l = dd + 1;
		}
	}

	for (int i = l; i <= r; ++i) {
		ans[i] = i + add; 
		roots.pb(i);
	}

	for (auto r : roots)
		dfs(r);

	for (int i = 1; i <= n; ++i) {
		cout << (zero[x[i]] ? "Yes" : "No") << ' ';
		cout << ans[x[i]] << endl;
	}
}

main () {
	int TT = 1;
	fastio
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}