#include "cave.h"

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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 5012;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

bool was[N];

void exploreCave(int n) {
	int s[n], d[n];
	

	for (int i = 0; i < n; ++i) {
		int good = 0, bad = 1;

		vi pos;
		for (int j = 0; j < n; ++j)
			if (!was[j]) {
				s[j] = 0; 
				pos.pb(j);
			}

		if (tryCombination(s) == i) {
			good = 1;
			bad = 0;
		}
		
		int l = 0, r = sz(pos) - 1, x = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;

			for (int j = 0; j <= mid; ++j) 
				s[pos[j]] = good; 

			for (int j = mid + 1; j < sz(pos); ++j)
				s[pos[j]] = bad;

			if (tryCombination(s) == i) 
				l = mid + 1;
			else {
				r = mid - 1;
				x = pos[mid];
			}
		}

		assert(x != -1);
		was[x] = 1;
		d[x] = i;
		s[x] = good;
	}
	

	answer(s, d);
}
