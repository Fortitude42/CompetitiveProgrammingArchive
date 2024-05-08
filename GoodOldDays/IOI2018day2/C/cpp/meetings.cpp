#include "meetings.h"
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
 
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vpii v;
vi h, l, r;
int n, q, mx[N][17], d[N];
ll s1[5010][5010], s2[5010][5010];


int get (int l, int r) {
	if (l > r)
		return 0;

	int D = d[r - l + 1];
	return max(mx[l][D], mx[r - (1 << D) + 1][D]);	
}


vector < ll > solve1 () {
	for (int i = 0; i < n; ++i) {
		if (h[i] != 1)
			continue;

		int j = i;
		while (j + 1 < n && h[j + 1] == 1)
			++j;

		v.pb(mp(i, j));
		i = j;
	}

	for (int i = 0; i < sz(v); ++i) 
		mx[i][0] = v[i].s - v[i].f + 1;		

	for (int i = 2; i < N; ++i)
		d[i] = d[i >> 1] + 1;

	for (int j = 1; j < 17; ++j)
		for (int i = 0; i + (1 << j) - 1 < sz(v); ++i)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);


	vector < ll > ans;

	for (int j = 0; j < q; ++j) {
		int lf = upper_bound(all(v), mp(l[j], inf)) - v.begin();
 		int rg = upper_bound(all(v), mp(r[j], inf)) - v.begin() - 1;
		
		int res = get(lf, rg - 1);
		assert(res <= (r[j] - l[j] + 1));
		if (lf)
			res = max(res, min(r[j], v[lf - 1].s) - max(l[j], v[lf - 1].f) + 1);

		if (rg >= 0)
			res = max(res, min(v[rg].s, r[j]) - max(l[j], v[rg].f) + 1);				 				

//		cerr << res << endl;
		ans.pb(2*(r[j] - l[j] + 1) - res);
	}

	return ans;
}



void build () {
	for (int i = 2; i < N; ++i)
		d[i] = d[i >> 1] + 1;

	for (int i = 0; i < n; ++i)
		mx[i][0] = h[i];

	for (int j = 1; j < 14; ++j)
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);				
}


ll get1 (int l, int r, int i) {
	if (l > r)
		return 0;
	if (r == n - 1)
		return s1[i][l];							

	return s1[i][l] - s1[i][r + 1];


}

ll get2 (int l, int r, int i) {
	if (l > r)
		return 0;

	if (!l)	
		return s2[i][r];

	return s2[i][r] - s2[i][l - 1];
}

vector < ll > minimum_costs(vi H, vi L, vi R) {
	n = sz(H);
	q = sz(L);
	h = H;
	l = L;
	r = R;
	if (*max_element(all(H)) <= 2) 
		return solve1();	
	
	
	build();

	for (int i = 0; i < n; ++i) {
		s1[i][i] = s2[i][i] = h[i];
		
		for (int j = i - 1; j >= 0; --j)
			s1[i][j] = s1[i][j + 1] + get(j, i);
		
		for (int j = i + 1; j < n; ++j)
			s2[i][j] = s2[i][j - 1] + get(i, j);
	}		


	vector < ll > V;
	for (int i = 0; i < q; ++i) {
		ll ans = INF;
		for (int j = l[i]; j <= r[i]; ++j) 
			ans = min(ans, get1(l[i], j, j - 1) + get2(j, r[i], j));
		
		V.pb(ans);					
	}	

	return V;
}
