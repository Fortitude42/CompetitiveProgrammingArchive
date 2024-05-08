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
 
const int inf = 1e9, maxn = 5e6 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n;
pii a[N], b[N], f[maxn];
 
main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].f);     
		a[i].s = i;
	}	

	sort(a + 1, a + 1 + n);
	pii x = {-1, -1};
	pii y = {-1, -1};
	for (int i = 1; i < n; ++i) {
		if (a[i].f == a[i + 1].f) {
			if (x.f == -1) 
				x = {a[i].s, a[i + 1].s};
			else
				y = {a[i].s, a[i + 1].s};
			++i;	
		}
	}

	if (y.f != -1) {
		cout << "YES\n";
		cout << x.f << ' ' << y.f << ' ' << x.s << ' ' << y.s << endl;
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				if (!f[a[i].f + a[j].f].f) 
					f[a[i].f + a[j].f] = {a[i].s, a[j].s};
				else {
					pii cur = f[a[i].f + a[j].f];
					if (cur.f != a[i].s && cur.f != a[j].s && cur.s != a[i].s && cur.s != a[j].s) {
						cout << "YES\n";
						cout << cur.f << ' ' << cur.s << ' ' << a[i].s << ' ' << a[j].s << endl;
						return 0;
					}
				}
			}

	cout << "NO";
}