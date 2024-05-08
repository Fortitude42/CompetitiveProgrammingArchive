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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, q, t[N << 2]; 

void update (int pos, int x, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = x;
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);	

	t[v] = __gcd(t[v << 1], t[v << 1 | 1]);
}

int get1 (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return __gcd(get1(l, r, v << 1, tl, tm), get1(l, r, v << 1 | 1, tm + 1, tr));
}

int res, g;

void get (int l, int x, int v = 1, int tl = 1, int tr = n) {
	if (res || tr < l)
		return;


	int tm = (tl + tr) >> 1;
	if (tl >= l) {
		int gg = __gcd(t[v], g);
		if (gg % x == 0) {
			g = gg;
			return;
		}

		if (tl == tr) {
		    res = tl;
			return;    
		}
	}

	get(l, x, v << 1, tl, tm);
	get(l, x, v << 1 | 1, tm + 1, tr);
}



main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	    int x;
		scanf("%d", &x);
		update(i, x);
	}

	scanf("%d", &q);
	while (q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			
			res = 0, g = 0;
			get(l, x);
			if (!res) {
				puts("YES");
				continue;
			}

			g = get1(l, res - 1);
			l = res + 1;
			res = 0;
			get(l, x);
			puts((!res || res > r) ? "YES" : "NO");								
		} else {
			int pos, x;
			scanf("%d%d", &pos, &x);
			update(pos, x);
		}
	}

	
}