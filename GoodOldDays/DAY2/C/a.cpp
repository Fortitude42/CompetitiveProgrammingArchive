#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
//#define int long long 
#pragma GCC optimize("Ofast")

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
 
typedef tree < pii, null_type, less < pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, l[N], r[N], res[N], s[N], bal, t[N << 2], lz[N << 2], tt[N << 2], t1[N << 2];
set < int > Q[N];
vi add[N];

inline void push (int v) {
	if (lz[v]) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
		t[v << 1] += lz[v];
		t[v << 1 | 1] += lz[v];
		lz[v] = 0;
	}
}


void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return;
	if (l <= tl && tr <= r) {
		t[v] += x;
		lz[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void update1 (int pos, int x, int v = 1, int tl = 1, int tr = n) {
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

int get1 (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return inf;

	if (l <= tl && tr <= r)
		return tt[v];

	int tm = (tl + tr) >> 1;

	return min(get1(l, r, v << 1, tl, tm), get1(l, r, v << 1 | 1, tm + 1, tr));
}

void inc (int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t1[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		inc(pos, x, v << 1, tl, tm);
	else
		inc(pos, x, v << 1 | 1, tm + 1, tr);
	t1[v] = t1[v << 1] + t1[v << 1 | 1];
}

int get (int k, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;
	
	if (t1[v << 1] >= k)
		return get(k, v << 1, tl, tm);
	
	return get(k - t1[v << 1], v << 1 | 1, tm + 1, tr);
}



void upd (int x, int y) {
	s[x] += y;
	update(x, n, -y);
}


bool check (int x, int j) {		
	upd(x, -1);
	int y = t[1];
	upd(x, 1);
	return y - j >= 0;
}


main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		++s[r[i]];
		add[l[i]].pb(i);
	}

	for (int i = 1; i <= n; ++i) {
		update(i, i, i); 
		update(i, n, -s[i]);
		update1(i, inf);
	}

	
	for (int i = 1; i <= n; ++i) {
		if (s[i] > 1) {
			cout << -1;
			return 0;
		}
		
		for (auto j : add[i]) {
			if (!sz(Q[r[j]])) {
				inc(r[j], 1);
				update1(r[j], j);
			} else {
				int x = *Q[r[j]].begin();
				if (x > j)
					update1(r[j], j);				
			}

			Q[r[j]].insert(j);
		}


		pii X = {inf, inf};
		int lf = 1, rg = t1[1];
		while (lf <= rg) {
			int mid = (lf + rg) >> 1;
			int cur = get(mid);
			if (check(cur, i)) {
				X.s = cur; 
				lf = mid + 1;
			} else
				rg = mid - 1; 				
		}
		 
		


		if (X.s == inf) {
			cout << -1;
			return 0;
		}

		X.f = get1(1, X.s);
		X.s = r[X.f];

		Q[X.s].erase(Q[X.s].begin());
		if (!sz(Q[X.s])) {
			inc(X.s, -1);
			update1(X.s, inf);
		} else 
			update1(X.s, *Q[X.s].begin());		


		upd(X.s, -1);
		res[i] = X.f;
		update(i, i, inf);
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
}