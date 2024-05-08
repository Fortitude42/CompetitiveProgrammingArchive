#include "vision.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 212;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int h, w, k, l[N << 1], r[N << 1], L, R;
vi gl[N << 1] , gr[N << 1], tmp;


bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}

int f (int k) {
    vi vl, vr;
    vl.pb(L);
    vr.pb(R);

	for (int i = 0; i + k <= h + w - 2; ++i) {
		tmp.clear();
		for (int j = i; j <= i + k; ++j)
			tmp.pb(l[j]);
		int X = add_xor(tmp), O = add_or(tmp);
		vl.pb(add_xor({X, O}));

		tmp.clear();
		for (int j = i; j <= i + k; ++j)
			tmp.pb(r[j]);
		X = add_xor(tmp), O = add_or(tmp);
		vr.pb(add_xor({X, O}));
	}	

	return add_and({add_or(vl), add_or(vr)});
}

void construct_network(int H, int W, int K) {
	h = H, w = W, k = K;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			gl[i + j].pb(i*w + j);   
			gr[i - j + w - 1].pb(i*w + j);
		}
 	
	vi vl, vr;
	for (int i = 0; i <= h + w - 2; ++i) {
		l[i] = add_or(gl[i]);
		r[i] = add_or(gr[i]);
		vl.pb(l[i]);
		vr.pb(r[i]);
	} 	    	

	L = add_xor(vl);
	R = add_xor(vr);
	
	vi V;
	V.pb(f(k));
	if (k > 1)
		V.pb(f(k - 1));
	add_xor(V);	
}
                    	