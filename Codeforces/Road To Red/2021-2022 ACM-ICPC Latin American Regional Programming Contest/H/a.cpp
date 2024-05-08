#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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
const int N = 500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, l[M][M], r[M][M];
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> l[i][j];
	for (int i = 1; i <= n; i += 2)
		for (int j = 1; j <= n; j += 2) {
			int ii = (i + 1) / 2;
			int jj = (j + 1) / 2;
			int cur = 0;
			if (j > 1)
				cur += l[j - 1][i];
			if (j < n)
				cur += l[i][j + 1];
			r[ii][jj] = cur;
		}
	n = (n + 1) / 2;

	vector<ll> u (n+1), v (n+1), p (n+1), way (n+1);

	for (int i=1; i<=n; ++i) {
		p[0] = i;
		ll j0 = 0;
		vector<ll> minv (n+1, INF);
		vector<char> used (n+1, false);

		do {
			used[j0] = true;
			ll i0 = p[j0],  delta = INF,  j1;
			for (int j=1; j<=n; ++j)
				if (!used[j]) {
					ll cur = r[i0][j]-u[i0]-v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j],  j1 = j;
				}
			for (int j=0; j<=n; ++j)
				if (used[j])
					u[p[j]] += delta,  v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		} while (p[j0] != 0);
		do {
			ll j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += r[p[i]][i]; 
	}

	cout << ans << endl;
}

main () {
	fastio
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}