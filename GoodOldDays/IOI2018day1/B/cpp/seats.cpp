#include "seats.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, t[N << 2], tt[N << 2], lz[N << 2], a[N], tmp[4], k;
vi r, c, q;

void build (int v = 1, int tl = 0, int tr = n*m - 1) {
    tt[v] = tr - tl + 1;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}


void update (int l, int r, int x, int v = 1, int tl = 0, int tr = n*m - 1) {
	if (l > r || tl > r || l > tr)
		return;
	if (l <= tl && tr <= r) {
		t[v] += x;
		lz[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	if (t[v << 1] < t[v << 1 | 1]) {
		t[v] = t[v << 1];
		tt[v] = tt[v << 1];
	} else if (t[v << 1] > t[v << 1 | 1]) {
		t[v] = t[v << 1 | 1];
		tt[v] = tt[v << 1 | 1];	
	} else {
		t[v] = t[v << 1];
		tt[v] = tt[v << 1] + tt[v << 1 | 1];
	}			

	t[v] += lz[v];
}

                                                   
bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void upd (int x, int y, int z) {
	k = 0;	
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			int tox = x + i, toy = y + j;
			tmp[k++] = in(tox, toy) ? a[tox*m + toy] : n*m;
		}

	sort(tmp, tmp + 4);
	update(tmp[0], tmp[1] - 1, z);
	update(tmp[2], tmp[3] - 1, z);
}

void give_initial_chart (int _n, int _m, vi _r, vi _c) {
	n = _n;
	m = _m;
	r = _r;
	c = _c;
	
	for (int i = 0; i < n*m; ++i)
		a[r[i]*m + c[i]] = i;

		
	build();
	for (int i = -1; i < n; ++i)
		for (int j = -1; j < m; ++j) 
			upd(i, j, 1);
}       	


int swap_seats(int i, int j) {
	for (int x = -1; x < 1; ++x)
		for (int y = -1; y < 1; ++y) {
			upd(r[i] + x, c[i] + y, -1);
			upd(r[j] + x, c[j] + y, -1);             
		}
	
	swap(r[i], r[j]);
	swap(c[i], c[j]);
	swap(a[r[i]*m + c[i]], a[r[j]*m + c[j]]);	

	for (int x = -1; x < 1; ++x)
		for (int y = -1; y < 1; ++y) {
			upd(r[i] + x, c[i] + y, 1);
			upd(r[j] + x, c[j] + y, 1);             
		}
	return tt[1];
}