#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

vector < int > vals;
int n, x[N], y[N];
set < int > q;
vpii g[N*N];
char d[N];

 
main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> d[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (d[j] < d[i]) {
				swap(d[i], d[j]);
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}

	vector < pair < int, pii > > e;

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			if (d[i] == d[j])
				continue;  
			if (d[i] == 'e' && d[j] == 'n') {
				 int tx = x[j] - x[i], ty = y[i] - y[j];
				 if (tx != ty || tx <= 0)
				 	continue;
				e.pb(mp(tx*2, mp(i, j)));
			}

			if (d[i] == 'e' && d[j] == 's') {
				int tx = x[j] - x[i], ty = y[j] - y[i];
				if (tx != ty || tx <= 0)
					continue;
				e.pb(mp(tx*2, mp(i, j)));
			}

			if (d[i] == 'e' && d[j] == 'w') {
				int tx = x[j] - x[i];
				if (tx <= 0 || y[i] != y[j])
					continue;
				e.pb(mp(tx, mp(i, j)));
			}

			if (d[i] == 'n' && d[j] == 's') {
				int ty = y[j] - y[i];
				if (ty <= 0 || x[i] != x[j])
					continue;
				e.pb(mp(ty, mp(i, j)));
			}

			if (d[i] == 'n' && d[j] == 'w') {
				int tx = x[j] - x[i], ty = y[j] - y[i];
				if (tx != ty || tx <= 0)
					continue;
				 e.pb(mp(tx*2, mp(i, j)));
			}

			if (d[i] == 's' && d[j] == 'w') {
				int tx = x[j] - x[i], ty = y[i] - y[j];
				if (tx != ty || tx <= 0)
					continue;
				e.pb(mp(tx * 2, mp(i, j)));	
			}
		}

	for (int i = 0; i < sz(e); ++i) 
		vals.pb(e[i].f);

	sort(all(vals));	
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 0; i < sz(e); ++i) {
//		cerr << e[i].f << endl;
		e[i].f = lower_bound(all(vals), e[i].f) - vals.begin();
		g[e[i].f].pb(e[i].s);
	}
	
	for (int i = 1; i <= n; ++i)
		q.insert(i);

	for (int i = 0; i < N*N; ++i) {
		vpii del;
		for (auto j : g[i])
			if (q.count(j.f) && q.count(j.s)) 
				del.pb(j);
		
		for (auto x : del) {
			q.erase(x.f);
			q.erase(x.s);
		}			
	}

	cout << sz(q) << endl;	
}