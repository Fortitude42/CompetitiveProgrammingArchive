#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "paint.h"
#include <vector> 

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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 


int t[N << 2], dp[N];
bool good[N];
vi G[N];
int n;

void update (int pos, int x, int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get (int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > r || tl > r || l > tr)
		return inf;
	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1,  tr));
}

int cnt[N], cnt1[N];
bool ok;

void add (int x, int y) {
	--cnt1[cnt[x]];
	cnt[x] += y;
	++cnt1[cnt[x]];
}


int minimumInstructions(int _n, int m, int k, vi C, vi A, vector < vi > B) {
	n = _n;
	
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < A[i]; ++j) 
			G[B[i][j]].pb(i);
		
	for (int i = 0; i < m; ++i)
		for (auto j : G[C[i]])
			++cnt[((i - j) % m + m) % m];

	for (int i = 0; i < m; ++i)
		++cnt1[cnt[i]];

	for (int y = 0; y + m - 1 < n; ++y) {
		if (cnt1[m])
			good[y] = 1;

		for (auto j : G[C[y]])
			add(((y - j) % m + m) % m, -1);

		if (y + m < n)
			for (auto j : G[C[y + m]])
				add(((y - j) % m + m) % m, 1);
	}


	for (int i = 0; i < n; ++i) {
		dp[i] = get(max(0, i - m + 1), i - 1);
		if (good[i]) {
			int x = (!i ? 0 : dp[i - 1]) + 1;
			dp[i] = min(dp[i], x);
			update(i, x);			
		} else
			update(i, inf);
	}


	if (dp[n - 1] == inf)
		dp[n - 1] = -1;
	return dp[n - 1];
}
