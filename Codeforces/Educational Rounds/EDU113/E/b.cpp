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

 
int k = 5, s[10];
int n;

void rec(int i = 0, int mask = (1 << n) - 1) {
	if (i == k) {
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
				s[k] = i + 1;


		for (int i = 0; i <= k; ++i)
			cout << s[i] << ' ';
		cout << endl;
		return;
	}

	vi v;
	for (int i = 0; i < n; ++i)
		if (mask & (1 << i))
			v.pb(i);

	for (int mask1 = 0; mask1 < (1 << (sz(v)/ 2)); ++mask1) {
		int curMask = 0;
		for (int j = 0; j < sz(v) / 2; ++j) 
			if (mask1 & (1 << j)) {
				curMask |= (1 << v[j*2]);
				s[i] += v[j*2 + 1] + 1;
			} else {
				curMask |= (1 << v[j*2 + 1]);
				s[i] += v[j*2] + 1;				
			}

		rec(i + 1, curMask);
		for (int j = 0; j < sz(v) / 2; ++j) 
			if (mask1 & (1 << j))
				s[i] -= v[j*2 + 1] + 1;
			else 
				s[i] -= v[j*2] + 1;
	}

}

main () {
	n = (1 << k);
	rec();
}