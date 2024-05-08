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

int q, v, u; 

main () {
	cin >> q;
	while (q--) {
		cin >> u >> v;
		bool ok = 1;
		if (u > v)
			ok = 0;

		int b1 = __builtin_popcount(u);
		int b2 = __builtin_popcount(v);
		if (b1 < b2)
			ok = 0;
		else {
			vi v1;
			vi v2;
			for (int i = 30; i >= 0; --i) {
				if (v & (1 << i))          
					v1.pb(i);
				if (u & (1 << i))
					v2.pb(i);
			}
			for (auto x : v1)
				cerr << x << ' ';
			cerr << endl;
			for (auto x : v2)
				cerr << x << ' ';
			cerr << endl;	

			bool found = 1;
			do {
				found = 0;
			for (int i = 0; i < sz(v1); ++i)
				for (int j = 0; j < sz(v2); ++j)
					if (v1[i] == v2[j]) {
						swap(v1.back(), v1[i]);
						swap(v2.back(), v2[j]);
						v1.ppb();
						v2.ppb();
						found = 1;
					}			
			} while (found);

			sort(all(v1));
			int cnt = 0;

			for (auto x : v1)
				cerr << x << ' ';
			cerr << endl;
			for (auto x : v2)
				cerr << x << ' ';
			for (auto x : v1) {
				++cnt;

			    int cnt1 = 0;
				for (auto y : v2) 
					if (y <= x) {
						++cnt1;
					}

				if (cnt1 < cnt)
					ok = 0;
			}

		}
		puts(ok ? "Yes" : "No");
	}
}