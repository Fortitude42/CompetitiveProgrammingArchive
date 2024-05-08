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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


vi v, vv;
int cnt[30][30], n, Cnt;

void rec (int i = 0) {
	if (i == sz(v)) {
		memset(cnt, 0, sizeof(cnt));

		bool ok = 1;
		for (auto mask : vv) {
			if (!ok)
				break;

			for (int i = 0; i < n && ok; ++i)
				for (int j = i + 1; j < n && ok; ++j)
					if (((mask & (1 << j)) && (mask & (1 << i))) || (!(mask & (1 << j)) && !(mask & (1 << i)))) {
						++cnt[i][j];      
						if (cnt[i][j] == 4)
								ok = 0;
					}
		}

		
		
		if (ok) {
			for (auto mask : vv) {
				for (int i = 0; i < n; ++i)
					if (mask & (1 << i))
						cout << i << ' ';
				cout << endl;
			}
			exit(0);
		}

		return;
	}

	if (sz(vv) < 7) {
		vv.pb(v[i]);
		rec(i + 1);
		vv.ppb();
	}

	if (7 - sz(vv) <= sz(v) - i - 1)
		rec(i + 1);
}

main () {
	n = 8;
	for (int mask = 0; mask < (1 << n); ++mask) 
		if (__builtin_popcount(mask) == 4 && (mask & 1)) 
			v.pb(mask);

	rec();
}