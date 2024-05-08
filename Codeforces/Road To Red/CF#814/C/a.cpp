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

vector < vector < ll > > s;
multiset < ll > Q[162];
int n, q, a[M]; 
bool u[M];

void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	vi d;
	for (int i = 2; i <= n; ++i)
		if (!u[i] && !(n % i)) 
			d.pb(n / i);

	s.clear();
	s.resize(sz(d));

	for (int i = 0; i < sz(d); ++i) {
		s[i].resize(d[i], 0);

		for (int j = 0; j < n; ++j)
			s[i][j % d[i]] += a[j];

		Q[i].clear();
		for (int j = 0; j < d[i]; ++j)
			Q[i].insert(s[i][j]);
	}

	for (int qq = 1; qq <= q + 1; ++qq) {	
		ll res = 0;
		for (int i = 0; i < sz(d); ++i) {
			res = max(res, *Q[i].rbegin() * d[i]); 
		}
		printf("%lld\n", res);

		if (qq <= q) {
			int p, x;
			scanf("%d%d", &p, &x);
			p--;
			for (int i = 0; i < sz(d); ++i) {
				Q[i].erase(Q[i].find(s[i][p % d[i]]));
				s[i][p % d[i]] -= a[p];
				s[i][p % d[i]] += x;
				Q[i].insert(s[i][p % d[i]]);
			}

			a[p] = x;
		}
	}
}

main () {
	for (int i = 2; i < M; ++i)
		for (int j = i + i; j < M; j += i)
			u[j] = 1;

	int TT = 1;
	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}