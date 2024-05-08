#include "rect.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2512;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, xl, xr, yl, yr, cnt, mx[N][14], d[N];
vector < vi > a;
bool bad[N];

bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;                     	
}

int get (int l, int r) {
	int D = d[r - l + 1];
	return max(mx[l][D], mx[r - (1 << D) + 1][D]);
}

ll count_rectangles(vector < vi > _a) {
	a = _a;
	n = sz(a), m = sz(a[0]);
	for (int i = 0; i < m; ++i)
		mx[i][0] = a[1][i];

	for (int i = 2; i < N; ++i)
		d[i] = d[i >> 1] + 1;
	for (int j = 1; j < 14; ++j)
		for (int i = 0; i + (1 << j) - 1 < m; ++i)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);

	for (int i = 0; i < m; ++i)
		if (a[1][i] >= a[0][i] || a[1][i] >= a[2][i])
			bad[i] = 1;

	ll ans = 0;
	for (int l = 1; l < m - 1; ++l)
		for (int r = l; r < m - 1; ++r) {
			if (bad[r])
				break;                  
			if (get(l, r) < a[1][l - 1] && get(l, r) < a[1][r + 1])
				++ans;
		}

	return ans;		
}   
