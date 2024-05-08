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

int t;
pii a[10];
 
inline ll getX (int x, int d) {
	vi V = {x, x, x + d, x + d};
	ll res = 0;
	for (int i = 0; i < 4; ++i)
		res += abs(V[i] - a[i].f);
	return res;
}


inline ll getY (int y, int d) {
	vi V = {y, y + d, y, y + d};
	ll res = 0;
	for (int i = 0; i < 4; ++i)
		res += abs(V[i] - a[i].s);
	return res;
}


inline ll solve1 (int d) {
	ll resX = INF, resY = INF;

	int l = -inf, r = inf;
	while (r - l > 3) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;

		ll val1 = getX(m1, d);
		ll val2 = getX(m2, d);

		resX = min({resX, val1, val2});

		if (val1 < val2) 
			r = m2;
		else
			l = m1;			
	}

	for (int i = l; i <= r; ++i)
		resX = min(resX, getX(i, d));

	l = -inf, r = inf;
	while (r - l > 3) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;

		ll val1 = getY(m1, d);
		ll val2 = getY(m2, d);

		resY = min({resY, val1, val2});
		if (val1 < val2)
			r = m2;
		else
			l = m1;	
	}

	for (int i = l; i <= r; ++i)
		resY = min(resY, getY(i, d));

	return resX + resY;
}

inline ll solve () {
	int l = 0, r = inf;
	ll res = INF;

	while (r - l > 3) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		
		ll val1 = solve1(m1);
		ll val2 = solve1(m2);


		res = min({res, val1, val2});
		if (val1 < val2)
			r = m2;
		else
			l = m1;	
	}

	for (int i = l; i <= r; ++i)
		res = min(res, solve1(i));

	return res;
}

main () {
//	cin >> t;
	t = 10000;
	while (t--) {                         
		for (int i = 0; i < 4; ++i) {
		//	scanf("%d%d", &a[i].f, &a[i].s);
		  	a[i] = mp(i, i);
		}

		sort(a, a + 4);
		ll res = INF;
		do {
			res = min(res, solve());
		} while (next_permutation(a, a + 4));

		printf("%lld\n", res);
	}
}
