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

 
int t, n, m, pos[N*N];
pii a[N*N];
bool was[N][N];

int geti(int pos) {
	return (pos + m - 1) / m;
}

int getj(int pos) {
	int s = pos % m;
	return !s ? m : s;
}

main () {
	fastio
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n*m; ++i) {
			cin >> a[i].f;
			a[i].s = i;
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				was[i][j] = 0;

		sort(a + 1, a + 1 + n*m);

		int ans = 0;
		for (int i = 1; i <= n*m; ) {
			int j = i;
			while (j <= n*m && a[i].f == a[j].f)
				++j;

			//i..j-1
			vector < pair < pii, int > > v;
			for (int x = i; x < j; ++x)
				v.pb({{geti(x), -getj(x)}, x});

			sort(all(v));
			reverse(all(v));

			for (int x = i; x < j; ++x) {
				pos[a[x].s] = v.back().s;
				v.ppb();
			}
				
			i = j;
		}

		for (int i = 1; i <= n*m; ++i) {
			int x = geti(pos[i]), y = getj(pos[i]);
			for (int yy = 1; yy < y; ++yy) 
				ans += was[x][yy];
			was[x][y] = 1;
		}

		cout << ans << endl;

	}
}