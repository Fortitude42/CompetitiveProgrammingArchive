#include "doll.h"
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

int n, m, s, k, X[N], Y[N];
vi c, x, y, g[N];
bool ok[N << 2];

void build (int p, int v, int u, int tl, int tr) {
	if (tl == tr - 1) {
		if (u >= tl)
			X[v] = p; 
		return;        
	}
	int tm = (tl + tr) >> 1;
	if (u < tm) 
		X[v] = ++s;
	else
		X[v] = p;
	Y[v] = ++s;
	if (X[v] != p)
		build(p, X[v], u, tl, tm);
	build(p, Y[v], u, tm + 1, tr);			
}

void upd (int p, int v, int u, int tl, int tr) {	
//    cerr << v << endl;
    ok[v] ^= 1;
	if (tl == tr - 1) {
//		cerr << "--> " << tl << ' ' << tr << ' ' << v << ' ' << u << endl;
		if (ok[v]) {
			if (X[v] == p) {
				upd(p, p, u, 0, (1 << k) - 1);      
				return;
			}
			X[v] = -u;
		} else
			Y[v] = -u;
		return;
	}


	int tm = (tl + tr) >> 1;
	if (ok[v]) {
		if (X[v] == p)
			upd(p, X[v], u, 0, (1 << k) - 1);
		else
			upd(p, X[v], u, tl, tm);
	} else 
		upd(p, Y[v], u, tm + 1, tr);
}


void create_circuit(int _m, vi a) {
	m = _m;
	n = sz(a);
	c.resize(m + 1);	
	
	a.pb(0);


	c[0] = a[0];

	k = 0;
	while ((1 << k) < sz(a))
		++k;
	
	c[0] = -(++s);
	build(s, s, (1 << k) - sz(a) - 1, 0, (1 << k) - 1);
	for (auto x : a)
		upd(1, 1, x, 0, (1 << k) - 1);
	
	for (int i = 1; i <= s; ++i) {
		x.pb(-X[i]);	          
		y.pb(-Y[i]);
	} 

	for (int i = 1; i <= m; ++i)
		c[i] = -1;

	for (int i = 0; i <= m; ++i)
		cerr << c[i] << ' ';
	cerr << endl;
	cerr << sz(x) << ' ' << sz(y) << endl;
	for (int i = 0; i < sz(x); ++i)
		cerr << x[i] << ' ' << y[i] << endl;

	answer(c, x, y);
}
