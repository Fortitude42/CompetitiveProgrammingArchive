#include "horses.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e5 + 11;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t[N << 2], tt[N << 2], n, x[N], y[N];
set < int > q;

void build (int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		t[v] = y[tl];
		tt[v] = x[tl];
		return;
	}

	int tm = (tl + tr) >> 1;
	
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);
	tt[v] = tt[v << 1] * 1ll * tt[v << 1 | 1] % mod;
}

void updX (int pos, int x, int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		tt[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		updX(pos, x, v << 1, tl, tm);
	else
		updX(pos, x, v << 1 | 1, tm + 1, tr);

	tt[v] = tt[v << 1] * 1ll * tt[v << 1 | 1] % mod;				
}


void updY (int pos, int x, int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		updY(pos, x, v << 1, tl, tm);
	else
		updY(pos, x, v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);	
}


int getX (int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > r || tl > r || l > tr)
		return 1;

	if (l <= tl && tr <= r)
		return tt[v];

	int tm = (tl + tr) >> 1;
	return getX(l, r, v << 1, tl, tm) * 1ll * getX(l, r, v << 1 | 1, tm + 1, tr) % mod;
}



int getY (int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return max(getY(l, r, v << 1, tl, tm), getY(l, r, v << 1 | 1, tm + 1, tr));
}
 
vector < pii > V;

bool cmp (int i, int j) {
	bool rev = 0;
	if (j > i) {
		swap(i, j);
		rev = 1;
	}

	int cur = V[i].s;
	for (int k = j + 1; k <= i; ++k) {
		if (cur > (2*inf) / x[V[k].f])
			return rev^1;

		cur *= x[V[k].f];
	}

	bool ok = 0;
	if (cur > V[j].s)
		ok = 1;

	return ok ^ rev;
}

int solve () {
	q.insert(0);
	auto it = q.begin();
	V.clear();

	while (1) {
	    int cur = - *it;
	    V.pb(mp(cur, getY(cur, n - 1)));
	    ++it;

	    if (it == q.end() || sz(V) == 31)
	    	break;
	}

	reverse(all(V));

	int j = 0;
	for (int i = 1; i < sz(V); ++i)
		if (cmp(i, j))
			j = i;

//	cerr << j << endl;
	return getX(0, V[j].f) * 1ll * V[j].s % mod;
}

int init(int _n, int X[], int Y[]) {
	n = _n;
	for (int i = 0; i < n; ++i) {
		x[i] = X[i];
		y[i] = Y[i];
	}
	

	build();
	for (int i = 0; i < n; ++i)	
		 if (x[i] > 1)
		 	q.insert(-i);
	 

	return solve();
}

int updateX(int pos, int val) {	
	updX(pos, val);
	x[pos] = val;

	if (val > 1)
		q.insert(-pos);
	else
		q.erase(-pos);

	return solve();
}

int updateY(int pos, int val) {
	updY(pos, val);
	y[pos] = val;
	return solve();
}
