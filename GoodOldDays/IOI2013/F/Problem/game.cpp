#include "game.h"
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
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef vector < pii > vpii;
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 4e5 + 11, mod = 998244353, N = 5e6 + 11;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int Sz, n, m;
int l, r, x, y;
ll z;
               	
ll gcd (ll x, ll y) {
	while (1) {
		if (x > y)
			swap(x, y);
		if (!x)				
			return y;		
//		cerr << x << ' ' << y << endl;
		y %= x;
	}
}
 
struct ST {
	int l, r, pos;
	ll g;
};
 
ST T[N];
 
void upd1 (int pos, ll x, int v, int tl = 0, int tr = m - 1) {
//	cerr << v << ' ' << tl << ' ' << tr << ' ' << pos << ' ' << x << endl;
	if (tl == tr) {
		T[v].g = x;
		return;
	}

	if (!T[v].l && !T[v].r && T[v].pos == -1) {
		T[v].pos = pos;
		T[v].g = x;
		return;
	}

	if (T[v].pos != -1) {
		if (T[v].pos == pos) {
			T[v].g = x;
			return;
		}
   		
		int u = T[v].pos;
		T[v].pos = -1;

		T[v].l = ++Sz;
		
		T[v].r = ++Sz;

		upd1(u, T[v].g, v, tl, tr);
	}
 
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		if (!T[v].l) 
			T[v].l = ++Sz;
		upd1(pos, x, T[v].l, tl, tm);
	} else {
		if (!T[v].r)
			T[v].r = ++Sz;
		upd1(pos, x, T[v].r, tm + 1, tr);
	}
 
	T[v].g = gcd(T[T[v].l].g, T[T[v].r].g);
}
 
ll get1 (int l, int r, int v, int tl = 0, int tr = m - 1) {
	if (l > r || tl > r || l > tr)
		return 0;
 
    if (T[v].pos != -1) {
    	if (l <= T[v].pos && T[v].pos <= r)
    		return T[v].g;
		return 0;
    }

	if (l <= tl && tr <= r)
		return T[v].g;
 
	int tm = (tl + tr) >> 1;
	
	ll res = 0;
	
	if (T[v].l)
		res = get1(l, r, T[v].l, tl, tm);
 
	if (T[v].r)
		res = gcd(res, get1(l, r, T[v].r, tm + 1, tr));
 
 	return res;
}

struct STT {
	int l, r, v;
};
 
STT TT[maxn];
 
int Sz1;
 
 
 
void upd (int v = 1, int tl = 0, int tr = n - 1) {
//	cerr << tl << ' ' << tr << endl;
	if (tl == tr) {
		upd1(y, z, TT[v].v);
		return;
	}

	int tm = (tl + tr) >> 1;
 
	if (x <= tm) {
		if (!TT[v].l) {
//			assert(Sz + 1 < N);
//			assert(Sz1 + 1 < maxn);
//			if (Sz + 1 == N || Sz1 + 1 == maxn) 
//				exit(0);
			TT[v].l = ++Sz1;
			TT[Sz1].v = ++Sz;
		}
		upd(TT[v].l, tl, tm);
	} else {
		if (!TT[v].r) {
//			assert(Sz + 1 < N);
//			assert(Sz1 + 1 < maxn);
//			if (Sz + 1 == N || Sz1 + 1 == maxn) 
//				exit(0);			
			TT[v].r = ++Sz1;
			TT[Sz1].v = ++Sz;
		}
		upd(TT[v].r, tm + 1, tr);
	}
 
	ll cur = 0;
	if (TT[v].l) 
		cur = get1(y, y, TT[TT[v].l].v); 
	
	if (TT[v].r)
		cur = gcd(cur, get1(y, y, TT[TT[v].r].v));
 
	upd1(y, cur, TT[v].v);
//	cerr << tl << ' ' << tr << ' ' << cur << endl;
}
 
ll get (int v, int tl = 0, int tr = n - 1) {
	if (l > r || tl > r || l > tr)
		return 0;
 
	if (l <= tl && tr <= r) {
		return get1(x, y, TT[v].v); 
	}
 
	int tm = (tl + tr) >> 1;	
	
	ll res = 0;
	
	if (TT[v].l)
		res = get(TT[v].l, tl, tm);
 
	if (TT[v].r)
		res = gcd(res, get(TT[v].r, tm + 1, tr));
 
	return res;
}
 
 
void init(int r, int c) {
	for (int i = 0; i < N; ++i) {
		T[i].pos = -1; 
		T[i].g = 0;
	}

//	assert(0);
	n = r, m = c;
	n = inf, m = inf;
	TT[++Sz1].v = ++Sz;
}
 
void update(int X, int Y, ll Z) {
//	cerr << x << ' ' << y << ' ' << z << endl;
	x = X, y = Y, z = Z;
	upd(1);
//	cerr << Sz << ' ' << Sz1 << endl;
}
 
long long calculate(int L, int X, int R, int Y) {		
//	cerr << x << ' ' << y << ' ' << lf << ' ' << rg << endl;
	l = L, r = R, x = X, y = Y;
    return get(1);
}