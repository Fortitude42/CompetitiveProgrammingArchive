#include "sorting.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vector < pii > ans;
int a[N], b[N], c[N], d[N], e[N], n, s[N], t[N], pos[N], pos1[N];

void Swap (int i, int j) { 
	swap(t[i], t[j]);
	swap(pos[t[i]], pos[t[j]]);
}

void Swap1 (int i, int j) { 
	swap(s[i], s[j]);
	swap(pos1[s[i]], pos1[s[j]]);
}


bool check (int T) {
	ans.clear();
	for (int i = 0; i < n; ++i)	{
		s[i] = a[i];             
		t[i] = a[i];
		pos[t[i]] = pos1[s[i]] = i;
	}

	for (int i = 0; i < T; ++i) 
		Swap1(c[i], b[i]);
	int j = 0;

	for (int i = 0; i < T; ++i) {
		Swap(c[i], b[i]);
		while (j < n && s[j] == j)
			++j;

		if (j < n) {
			ans.pb(mp(pos[j], pos[s[j]]));
			Swap(pos[j], pos[s[j]]);
			Swap1(j, pos1[j]); 
		} else
			ans.pb(mp(0, 0));
	}

	while (j < n && s[j] == j)
		++j;

	return (j == n);			
}

int findSwapPairs(int _n, int s[], int m, int x[], int y[], int p[], int q[]) {
	n = _n;
	for (int i = 0; i < n; ++i) {
		a[i] = s[i];	          
		b[i] = x[i];
		c[i] = y[i];
	}

	int l = 0, r = n - 1, res = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}


	check(res);
	for (int i = 0; i < sz(ans); ++i) {
		p[i] = ans[i].f;                
		q[i] = ans[i].s;
	}

	for (int i = sz(ans); i < res; ++i)
		p[i] = q[i] = 0;

	

	return res;
}


