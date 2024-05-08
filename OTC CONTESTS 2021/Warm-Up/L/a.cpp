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


int n, tp[N], t[N << 3], lz[N << 3];
ll l[N], r[N];
vector < ll > vals;

inline void upd(int v, int tp, int tl, int tr) {
	if (tp <= 2) {
		lz[v] = tp;
		t[v] = tp == 1 ? tr - tl + 1 : 0;
	} else {
		if (lz[v] == -1)
			lz[v] = 3;
		else if (lz[v] == 3)	
			lz[v] = -1;
		else
			lz[v] = 3 - lz[v];	

		t[v] = tr - tl + 1 - t[v];
	}
   
}

inline void push(int v, int tl, int tr, int tm) {
	if (lz[v] != -1) {
		upd(v << 1, lz[v], tl, tm);
		upd(v << 1 | 1, lz[v], tm + 1, tr);
		lz[v] = -1;
	}
}

void update(int l, int r, int tp, int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		upd(v, tp, tl, tr);
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	update(l, r, tp, v << 1, tl, tm);
	update(l, r, tp, v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
}

int get(int v = 1, int tl = 0, int tr = sz(vals) - 1) {
	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	if (t[v << 1] == tm - tl + 1)
		return get(v << 1 | 1, tm + 1, tr);
	return get(v << 1, tl, tm);
}

main () {
	memset(lz, -1, sizeof(lz));

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%lld%lld", &tp[i], &l[i], &r[i]);
		r[i]++;
		vals.pb(l[i]);
		vals.pb(r[i]);
	}
	vals.pb(1);

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i) {
		l[i] = lower_bound(all(vals), l[i]) - vals.begin();
		r[i] = lower_bound(all(vals), r[i]) - vals.begin() - 1;

		update(l[i], r[i], tp[i]);

		printf("%lld\n", vals[get()]);
	}


}                               