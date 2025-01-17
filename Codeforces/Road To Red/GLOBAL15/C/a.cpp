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
const int N = 200, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, k; 
bool was[M];


bool inter(int l, int r, int a, int b) {
	if (l > r)
		swap(l, r);
	if (a > b)
		swap(a, b);
	bool ina = (l <= a && a <= r);
	bool inb = (l <= b && b <= r);
	return (ina != inb);
}

void solve() {
	memset(was, 0, sizeof(was));
	vector < pii > v;

	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int x, y;
		cin >> x >> y;
		v.pb({x, y});
		was[x] = was[y] = 1;
	}

	vi vv;
	for (int i = 1; i <= 2*n; ++i)
		if (!was[i])
			vv.pb(i);

	for (int i = 0; i < sz(vv) / 2; ++i)
		v.pb({vv[i], vv[i + sz(vv) / 2]});

	int ans = 0;
	for (int i = 0; i < sz(v); ++i)
		for (int j = i + 1; j < sz(v); ++j)
			if (inter(v[i].f, v[i].s, v[j].f, v[j].s))
				++ans;

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