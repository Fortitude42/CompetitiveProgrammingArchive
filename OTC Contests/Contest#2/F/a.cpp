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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int q, tp, x, k, v, s;
vi g[N], mn[N];
vpii t[N];

void add (int x, int i) {
	int v = 0;
	mn[i][0] = min(mn[i][0], x);

	for (int j = 19; j >= 0; --j) {
		int bit = (x >> j) & 1;
//		cerr << i << ' ' << bit << endl;
		if (!bit) {
			if (!t[i][v].f) {
				t[i][v].f = sz(t[i]);
				t[i].pb({0, 0});
				mn[i].pb(inf);
			}
			v = t[i][v].f;
		} else {
			if (!t[i][v].s) {
				t[i][v].s = sz(t[i]);
				t[i].pb({0, 0});
				mn[i].pb(inf);
			}
			v = t[i][v].s;
		}

		mn[i][v] = min(mn[i][v], x);
	}
}

int get (int i, int x, int s) {
	if (x + mn[i][0] > s)
		return -1;

	int u = 0, res = 0;
	for (int j = 19; j >= 0; --j) {
		if (!t[i][u].f) {
			u = t[i][u].s;
			res |= (1 << j);
			continue;
		}

		if (!t[i][u].s) {
			u = t[i][u].f;
			continue;
		}

		int bit = (x >> j) & 1;
		if ((!bit && mn[i][t[i][u].s] + x <= s) || (bit && mn[i][t[i][u].f] + x > s)) {
			res |= (1 << j);
			u = t[i][u].s;
		} else
			u = t[i][u].f;	
	}

	return res;
}
 

main () {
	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i)
			g[j].pb(i);

		t[i].pb({0, 0});
		mn[i].pb(inf);
	}

	cin >> q;
	while (q--) {
		cin >> tp;
		if (tp == 1) {
			cin >> x;
			for (auto y : g[x])
				add(x, y);
		} else {
			cin >> x >> k >> s;
			if (x % k != 0) {
				cout << -1 << endl;
				continue;
			}
			cout << get(k, x, s) << endl;
		}
//		cerr << "hello\n";
	}
}