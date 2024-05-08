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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 312;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, p[N][N], pos[N];
vpii vals[N];

main () {
	cin >> n;
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> p[i][j];

	for (int i = 1; i <= n; ++i)
		pos[p[n + 1][i]] = i;

	set < pii > q;
	for (int i = 1; i <= n; ++i) {
		q.insert(mp(pos[i], i));

		auto it = q.begin();
		
		int j = it->s, k = -1;
		++it;
		if (it != q.end())
			k = it->s;

		for (int x = 1; x <= n; ++x) {
			if (x == j) {
				if (k != -1)
					vals[x].pb({k, i});
			} else 
				vals[x].pb({j, i});
		}
	}		

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			pos[p[i][j]] = j;

		set < pii > q;
		for (auto j : vals[i])
			q.insert(mp(pos[j.f], j.s));
		cout << q.begin()->s << ' ';
	}
		

	
}