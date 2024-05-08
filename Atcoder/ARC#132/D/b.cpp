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


int n, m;
string s, t;
vi a, b;
 
vector < pair < int, pii > > f(vector < pair < int, pii > > X) {
	vector < pair < int, pii > > Y;
	sort(all(X));
	for (int i = 0; i < sz(X); ) {
		int j = i;
		int l = inf, r = -inf;

		while (j < sz(X) && X[j].f == X[i].f) {
			l = min(l, X[j].s.f);
			r = max(r, X[j].s.s);
			++j;
		}

		Y.pb({X[i].f, {l, r}});
		i = j;
	}

	return Y;
}

void solve() {
	fastio
	cin >> n >> m >> s >> t;
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == '1')
			a.pb(i + 1);                  
		
		if (t[i] == '1')
			b.pb(i + 1);
	}

	for (int i = 0; i < m; ++i) {
		if (a[i] > b[i])
			swap(a[i], b[i]);	  
	}
	
	vector < pair < int, pii > > cur;

	if (a[0] == 1)
		cur.pb({0, {1, 1}});

	if (b[0] > 1)
		cur.pb({1, {max(2, a[0]), b[0]}});

	for (int i = 2; i <= m; ++i) {
		vector < pair < int, pii > > curr;

		for (auto x : cur) {
			int l = max(x.s.f + 1, a[i - 1]), r = min(x.s.s + 1, b[i - 1]);
			if (l <= r)
				curr.pb({x.f, {l, r}});
		}
		
		int L = max(a[i - 1], cur.back().s.s + 2), R = b[i - 1];

		if (L <= R)
			curr.pb({cur[0].f + 2, {L, R}});
		cur = f(curr);
	}


	int ans = inf;
	for (auto x : cur)
		ans = min(ans, x.f + (x.s.s < (n + m)));

	cout << n + m - 1 - ans << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}