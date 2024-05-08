#include "party.h"

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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 

vi g[20];
int rev, _n, _m, mask[N], lst[N];

int get1 (int i) {
	if (!rev)
		return i;
	if (i >= _m)
		return i - _m;
	return i + _n;
}

int get (int i) {
	if (!rev)
		return i;
	if (i >= _n)	
		return i - _n;
	return i + _m;
}

vi Ask (vi v) {
	sort(all(v));
	return ask(v);
}

int findUnusualGuest(int n, int m, int q) {
	if (n < m) {
		rev = 1;
		swap(n, m);
	}
    _n = n, _m = m;

    for (int x = 0; x < 6; ++x) {
        vi cur;

    	for (int i = 1; i <= m; ++i)
    		if (i & (1 << x)) 
    			cur.pb(get(i - 1 + n));
		    		
		if (!sz(cur))
			continue;

		g[x] = Ask(cur);


		for (auto y : g[x]) 
			mask[get1(y)] += (1 << x);  
		
    }

    memset(lst, -1, sizeof(lst));
    for (int i = 0; i < n; ++i) {
    	if (!mask[i] || mask[i] > m)
    		return get(i);

    	if (lst[mask[i]] == -1) {
			lst[mask[i]] = i; 
			continue;
		}

		int j = lst[mask[i]];
		int x = mask[i] - 1 + n;
		
		vi cur;
		cur.pb(get(x));
		
		cur = Ask(cur);

		if (sz(cur) > 1 || !sz(cur))
			return get(x);

		if (cur[0] != get(i))
			return get(i);

		return get(j);
    }
	return 0;
}
