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

ll s[M], ans = INF;
int n, k;
vector < int > g[M], gg[M];


void rec(int l = 1, int r = n, int x = 0) {

	if (l > r) {
		ll mn = INF, mx = -INF;
		for (int j = 1; j <= k; ++j) {
			mn = min(mn, s[j]);
			mx = max(mx, s[j]);
		}

		if (mx == mn + 1) {
			ans = mx - mn;
			for (int j = 1; j <= k; ++j)
				gg[j] = g[j];

			cout << ans << endl;
			for (int i = 1; i <= k; ++i) {
				for (auto j : gg[i]) {
					cout << j << ' ';
//					s[i] += j;
				}

				cout << "---> " << s[i];
				cout << endl;
			}

			cout << endl << endl;

	
		}

		return;
	}


	for (int j = 1; j <= k; ++j) {
		if (sz(g[j]) == n/k)
			continue;

		if (!x) {
			s[j] += l;
			g[j].pb(l);
			rec(l + 1, r, x);
			s[j] -= l;
			g[j].ppb();
		} else {
			s[j] += r;
			g[j].pb(r);
			rec(l, r - 1, x);
			s[j] -= r;
			g[j].ppb();		
		}
	}

}


 
void solve(int nn, int kk) {
	memset(s, 0, sizeof s);
	n = nn, k = kk;
	ans = INF;
	rec();
	cout << ans << endl;
	for (int i = 1; i <= k; ++i) {
		for (auto j : gg[i]) {
			cout << j << ' ';
			s[i] += j;
		}

		cout << "---> " << s[i];
		cout << endl;
	}

}

void solve() {
	int nn, kk;
	cin >> nn >> kk;
	solve(nn, kk);
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}