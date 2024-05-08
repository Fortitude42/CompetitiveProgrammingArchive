#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], b[N], dp[N], p[N];
vpii g[N];
pii t[N];
vi c, d;

void inc (int pos, pii x) {
	while (pos < N) {
		t[pos] = max(t[pos], x);
		pos |= pos + 1;
	}
}

pii get (int r) {
	pii res = {0, 0};
	while (r >= 0) {
		res = max(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}
 
main () {
	file("people");
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		b[i] = inf + 1 - b[i];
		c.pb(a[i]);
		d.pb(b[i]);
	}

	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(all(c), a[i]) - c.begin();
		b[i] = lower_bound(all(d), b[i]) - d.begin();
//		cerr << a[i] << ' ' << b[i] << endl;
		g[a[i]].pb({b[i], i});
	}

	for (int i = n - 1; i >= 0; --i) {
		for (auto j : g[i]) {
			pii cur = get(j.f - 1);
			dp[j.s] = cur.f + 1;
			p[j.s] = cur.s;
//			cerr << j.f << ' ' << cur.f << ' ' << cur.s << endl;
		}

		for (auto j : g[i]) {
			inc(j.f, mp(dp[j.s], j.s)); 
//			cerr << "+ " << j.f << ' ' << dp[j.s] << endl;
		}
	}
	
	int j = 0;
	for (int i = 1; i <= n; ++i)
		if (dp[i] > dp[j])
			j = i;

//	cerr << dp[j] << ' ' << p[j] << endl;				


	vi ans;
	while (j > 0) {
		ans.pb(j);
		j = p[j];
	}

	sort(all(ans));

	assert(sz(ans) == *max_element(dp + 1, dp + n + 1));
	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ';
			
}