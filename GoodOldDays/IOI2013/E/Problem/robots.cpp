#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "robots.h" 

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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e6 + 12;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int x[N], y[N], w[N], s[N], n, a, b, cnt[N], was[N], timer;
set < pii > q;
vpii v;

bool check (int d) {
	memset(cnt, 0, sizeof(cnt));
	q.clear();

	for (int i = 0; i < b; ++i)
		q.insert({y[i], i});
	
	++timer;

	for (int i = sz(v) - 1; i >= 0; --i) {
		auto it = q.lower_bound(mp(v[i].s, inf));
		if (it == q.end())
			continue;

		was[i] = timer;
		int j = it->s;
//		cerr << j << ' ' << y[j] << ' ' << i << ' ' << v[i].f << ' ' << v[i].s << endl;

		++cnt[j];
		if (cnt[j] == d)
			q.erase(it);
	}

	int j = a - 1, c = 0;
	for (int i = sz(v) - 1; i >= 0; --i) {
		if (was[i] == timer)
			continue;

		if (j < 0)
			return 0;
		
		if (v[i].f >= x[j]) 
			return 0; 
			
		++c;
		if (c == d) {
			c = 0;
			--j;
		}
	}
	
	return 1;
}

int putaway(int _a, int _b, int _n, int X[], int Y[], int W[], int S[]) {
	n = _n;
	a = _a;
	b = _b;

	for (int i = 0; i < a; ++i)
		x[i] = X[i];
	for (int i = 0; i < b; ++i)
		y[i] = Y[i];
	for (int i = 0; i < n; ++i) {
		w[i] = W[i];
		s[i] = S[i];
		v.pb({w[i], s[i]});
	}


	sort(all(v));
	sort(x, x + a);
	
	int l = 1, r = n, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}

	return res;
}
