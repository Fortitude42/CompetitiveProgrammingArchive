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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


vi dig;
int n, ind[20];
ll x, p[20], s;
vector < pair < ll, int > > g[20];

void solve() {
	cin >> x >> n;
	for (int i = 1; i <= n; ++i) {
	    int k;
	    ll q;
		cin >> k >> q;
		g[k].pb({p[k]*q, i});
	}

	for (int i = 0; i < 20; ++i) {
		sort(all(g[i]));
		reverse(all(g[i]));
	}

	vi ans;
	while (x > 0) {
		dig.pb(x % 10);
		x /= 10;
	}
	

	for (int i = 0; i < sz(dig); ++i) {
		for (int j = 0; j <= i; ++j) {
			while (dig[i] > 0 && s >= p[i]) {
				dig[i]--;
				s -= p[i];
			}
		}

		while (dig[i] > 0) {
			int jj = -1;
			ll mx = -1;

			for (int j = 0; j <= i; ++j) {
				if (ind[j] == sz(g[j]))
					continue;
				if (g[j][ind[j]].f > mx) {
					mx=  g[j][ind[j]].f;
					jj = j;
				}
			}

			if (jj == -1) {
				cout << -1 << endl;
				return;
			}

			ans.pb(g[jj][ind[jj]].s);
			s += g[jj][ind[jj]].f;
			ind[jj]++;

			while (dig[i] > 0 && s >= p[i]) {
				dig[i]--;
				s -= p[i];
			}
		}
	}

	cout << sz(ans) << endl;
	sort(all(ans));
	for (auto x : ans)
		cout << x << ' ';
}

main () {
	p[0] = 1;
	for (int i = 1; i < 19; ++i)
		p[i] = p[i - 1] * 10;

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

