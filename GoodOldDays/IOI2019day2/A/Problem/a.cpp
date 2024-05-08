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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, x[N], y[N];
set < pii > qx, qy;
 
main () {
	file("10");
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i) {
		qx.insert(mp(x[i], i));
		qy.insert(mp(y[i], i));
	}

	pair < pii, int > cur = mp(mp(0, 0), 0);
	
	vpii res;

	while (sz(qx)) {
		if (!cur.s) {
			if (qx.rbegin()->f < cur.f.f) {
				++cur.s;
				continue;			                        	
			}
			            
			int i = qx.lower_bound(mp(cur.f.f, 0))->s;
			qx.erase(mp(x[i], i));
			qy.erase(mp(y[i], i));
			                      
			res.pb(mp(x[i], cur.f.s));
			res.pb(mp(x[i], y[i]));
			if (cur.f.s < y[i]) 
				cur.s = 1;
			else
				cur.s = 3;
			cur.f = mp(x[i], y[i]);	
			continue;
		} 
		
		if (cur.s == 1) {
			if (qy.rbegin()->f < cur.f.s) {
				++cur.s;
				continue;
			}

			int i = qy.lower_bound(mp(cur.f.s, 0))->s;
			qx.erase(mp(x[i], i));
			qy.erase(mp(y[i], i));

			res.pb(mp(cur.f.f, y[i]));
			res.pb(mp(x[i], y[i]));
			if (cur.f.f < x[i]) 
				cur.s = 0;
			else
				cur.s = 2;	
			cur.f = mp(x[i], y[i]);
			continue;
		} 

		if (cur.s == 2) {
			if (qx.begin()->f > cur.f.f) {
				++cur.s;
				continue;
			}

			auto it = qx.lower_bound(mp(cur.f.f, 0));
			--it;
			int i = it->s;

			qx.erase(mp(x[i], i));
			qy.erase(mp(y[i], i));

			res.pb(mp(x[i], cur.f.s));
			res.pb(mp(x[i], y[i]));

			if (cur.f.s < y[i])
				cur.s = 1;
			else
				cur.s = 3;
			cur.f = mp(x[i], y[i]);
			continue;		
		}

		if (cur.s == 3) {
			if (qy.begin()->f > cur.f.s) {
				cur.s = 0;
				continue;
			}

			auto it = qy.lower_bound(mp(cur.f.s, 0));
			it--;
			int i = it->s;

			qx.erase(mp(x[i], i));
			qy.erase(mp(y[i], i));

			res.pb(mp(cur.f.f, y[i]));
			res.pb(mp(x[i], y[i]));

			if (cur.f.f < x[i])
				cur.s = 0;
			else
				cur.s = 2;
			cur.f = mp(x[i], y[i]);
			continue;
		}
	}		


	vpii res1;
	res1.pb(mp(0, 0));
	res1.pb(res[0]);
	for (int i = 1; i < sz(res); ++i) {
		pii x = res1[sz(res1) - 1];
		pii y = res1[sz(res1) - 2];
		if (x.f == y.f && y.f == res[i].f) {
			if (min(y.s, res[i].s) <= x.s && x.s <= max(y.s, res[i].s)) 
				res1.ppb();			
		} else if (x.s == y.s && y.s == res[i].s) {
			if (min(y.f, res[i].f) <= x.f && x.f <= max(y.f, res[i].f))
				res1.ppb();
		}

		res1.pb(res[i]);
	}

/*	for (auto x : res)
		cerr << x.f << ' ' << x.s << endl;*/
	cerr << sz(res1) << endl;
	cout << sz(res1) << endl;
	for (auto x : res1)
		cout << x.f << ' ' << x.s << endl;
}
