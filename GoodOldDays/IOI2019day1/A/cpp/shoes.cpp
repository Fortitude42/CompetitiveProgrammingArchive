#include "shoes.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 4e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t[N], n, pos[N];
bool was[N];
vi g[N];



void inc (int pos, int x) {
	while (pos < n) {
		t[pos] += x;
		pos |= pos + 1;		
	}
}

int get (int r) {
	int res = 0;
	while (r >= 0) {
		res += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

ll count_swaps(vi s) {
	n = sz(s);
	for (int i = 0; i < n; ++i)  {
		g[s[i] + n].pb(i);
		inc(i, 1);
	}

	for (int i = 0; i <= n + n; ++i)
		reverse(all(g[i]));
	
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		
		int l, r;
		if (s[i] < 0) {
			l = i;      
			r = g[-s[i] + n].back();
		} else {
			l = g[-s[i] + n].back();
			r = i;	
		}

		was[l] = was[r] = 1;
		g[s[l] + n].ppb();
		g[s[r] + n].ppb();
		
		int cur = get(max(l, r)) - get(min(l, r) - 1);
		if (l > r)
			res += cur - 1;
		else
			res += cur - 2;

		inc(l, -1);
		inc(r, -1);
	}

	return res;
}
