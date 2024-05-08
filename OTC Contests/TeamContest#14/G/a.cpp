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
 
const int inf = 1e9, maxn = 1e3 + 48, mod = 1e9 + 7, N = 1e4 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, a[N], b[N], c[N], t[N], x[N], timer, sum, res[N], id[N][maxn];
vi g[N], gg[N];
set < int > q;


main () {
//	file("generators");
	fastio
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> a[i] >> b[i] >> c[i];

	for (int i = 1; i <= n; ++i) {
		++timer;
		int cnt = 0;
		while (t[x[i]] != timer) {
			t[x[i]] = timer;
			id[i][x[i]] = cnt++;
			g[i].pb(x[i]);
			x[i] = (a[i]*x[i] + b[i]) % c[i];
		}

		q.clear();
		sort(all(g[i]));
		reverse(all(g[i]));

		for (auto x : g[i])
			if (!q.count(x % k)) {
				q.insert(x % k);
				gg[i].pb(x);
			}

		sum += gg[i][0];
		res[i] = gg[i][0];
	}

	if (sum % k) {
		cout << sum << endl;
		for (int i = 1; i <= n; ++i)
			cout << id[i][res[i]] << ' ';
		return 0;
	}

	pii Mn = {inf, inf};

	for (int i = 1; i <= n; ++i)
		if (sz(gg[i]) > 1)
			Mn = min(Mn, mp(gg[i][0] - gg[i][1], i));

	if (Mn.f == inf)
		cout << -1 << endl;
	else {
		cout << sum - Mn.f << endl;	
		res[Mn.s] = gg[Mn.s][1];
		for (int i = 1; i <= n; ++i)
			cout << id[i][res[i]] << ' ';
	}
}