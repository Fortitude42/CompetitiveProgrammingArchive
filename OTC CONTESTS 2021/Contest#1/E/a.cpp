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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

ll mx[4][N << 2], add[5][N << 2];
int n, q, x[N], t[N];
string s[N];
vi vals;

inline void push(int v, int lvl) {
	if (add[lvl][v]) {
		add[lvl][v << 1] += add[lvl][v];
		add[lvl][v << 1 | 1] += add[lvl][v];
		
		mx[lvl][v << 1] += add[lvl][v];
		mx[lvl][v << 1 | 1] += add[lvl][v];

		add[lvl][v] = 0;
	}
}

void update(int l, int r, int lvl, int x, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		mx[lvl][v] += x;		
		add[lvl][v] += x;
		return; 
	}

	push(v, lvl);
	int tm = (tl + tr) >> 1;
	update(l, r, lvl, x, v << 1, tl, tm);
	update(l, r, lvl, x, v << 1 | 1, tm + 1, tr);
	mx[lvl][v] = max(mx[lvl][v << 1], mx[lvl][v << 1 | 1]);		
} 
 
main () {
	fastio
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> s[i] >> x[i] >> t[i];
		vals.pb(t[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	n = sz(vals);

	for (int i = 1; i <= q; ++i) {
		t[i] = lower_bound(all(vals), t[i]) - vals.begin(); 

		int tp = 4;
		if (s[i] == "Calliope")
			tp = 0;
		else if (s[i] == "Gura")	
			tp = 1;
		else if (s[i] == "Ina")	
			tp = 2;
		else if (s[i] == "Kiara")	
			tp = 3;

		if (tp == 4) {
			for (int tt = 0; tt < 4; ++tt)
				update(t[i], n - 1, tt, -x[i]);
		} else {
			update(t[i], n - 1, tp, x[i]);
		}

		ll ans = 0;
		for (int tt = 0; tt < 4; ++tt)
			ans = max(ans, mx[tt][1]);
		cout << ans << endl;
	}
	
}