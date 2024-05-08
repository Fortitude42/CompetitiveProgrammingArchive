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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, k, d[N], t[N << 2][2], add[N << 2][2], tt[N << 2], fst[N << 2];
pii a[N];

void update1(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		tt[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update1(pos, x, v << 1, tl, tm);
	else
		update1(pos, x, v << 1 | 1, tm + 1, tr);	

	tt[v] = min(tt[v << 1], tt[v << 1 | 1]);
}

int get1(int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return tl;
	
	int tm = (tl + tr) >> 1;

	if (tt[v << 1] <= x)
		return get1(x, v << 1, tl, tm);

	return get1(x, v << 1 | 1, tm + 1, tr);
}


inline void push(int v, int lvl) {
	if (add[v][lvl]) {
		t[v << 1][lvl] += add[v][lvl];
		t[v << 1 | 1][lvl] += add[v][lvl];
		add[v << 1][lvl] += add[v][lvl];
		add[v << 1 | 1][lvl] += add[v][lvl];
		add[v][lvl] = 0;
	}
}

void update(int l, int r, int lvl, int x, int v = 1, int tl = 1, int tr = m) {
	if (l > r || tl > r || l > tr || !l || r > m)
		return;

	if (l <= tl && tr <= r) {
		t[v][lvl] += x;
		add[v][lvl] += x;
		return;
	}

	push(v, lvl);
	int tm = (tl + tr) >> 1;
	update(l, r, lvl, x, v << 1, tl, tm);
	update(l, r, lvl, x, v << 1 | 1, tm + 1, tr);
	t[v][lvl] = min(t[v << 1][lvl], t[v << 1 | 1][lvl]);
}

int get(int l, int r, int lvl, int v = 1, int tl = 1, int tr = m) {
	if (l > r || tl > r || l > tr || !l || r > m)
		return inf;

	if (l <= tl && tr <= r) {
		return t[v][lvl];    
	}

	push(v, lvl);
	int tm = (tl + tr) >> 1;
	return min(get(l, r, lvl, v << 1, tl, tm), get(l, r, lvl, v << 1 | 1, tm + 1, tr));
}

int get2(int l, int r, int lvl, int v = 1, int tl = 1, int tr = m) {
	if (l > r || tl > r || l > tr || t[v][lvl] >= 0)
		return -1;

	if (tl == tr)
		return tl;
	push(v, lvl);

	int tm = (tl + tr) >> 1;

	if (l <= tl && tr <= r) {
		if (t[v << 1][lvl] < 0)
			return get2(l, r, lvl, v << 1, tl, tm);
		return get2(l, r, lvl, v << 1 | 1, tm + 1, tr);
	}

	int x = get2(l, r, lvl, v << 1, tl, tm);
	return x == -1 ? get2(l, r, lvl, v << 1 | 1, tm + 1, tr) : x;
}



main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].s);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].f);

	for (int i = 1; i <= m; ++i)
		scanf("%d", &d[i]);

	sort(d + 1, d + 1 + m);
	for (int i = 1; i <= n; ++i) {
		a[i].f = upper_bound(d + 1, d + 1 + m, a[i].f) - d - 1;
		a[i].s = lower_bound(d + 1, d + 1 + m, a[i].s) - d;
	}

	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= m; ++i) 
		update(1, i, 1, -1);

	for (int i = 1; i <= n; ++i) {
		update1(i, a[i].s);
		update(1, a[i].f, 1, 1);
	}

	

	int pref = 0;

	while (pref < m && get(1, pref + 1, 1) + (m - pref - 1) >= 0) 
		++pref;                                                    	

	int ans = pref;
	for (int i = m; i > 0; --i) {
		update(i, m, 0, -1);
		int pos = get2(i, m, 0);

		if (tt[1] > pos)
			break;


		int x = get1(pos);
		
		update(a[x].s, m, 0, 1);
		update1(x, inf);
		update(1, a[x].f, 1, -1);

		while (pref && get(1, pref, 1) + (m - pref) < 0)
			--pref;	
		ans = max(ans, pref + (m - i + 1));
		if (ans >= m)
			break;
	}

	cout << min(ans, m) << endl;
}