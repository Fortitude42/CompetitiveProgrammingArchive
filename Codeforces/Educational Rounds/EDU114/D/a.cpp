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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, c[N], a[14][N], m, sumMx;
set < vi > Q;
vi V, ans;
bool ok;
 
void rec(int i, int sum, int sumMx) {
	if (ok)
		return;

	if (i == n + 1) {
		if (!Q.count(V)) {
			ok = 1;       
			ans = V;
		}
		return;
	}

	for (int j = c[i]; j > 0 && sumMx - a[i][c[i]] + a[i][j] >= sum && !ok; --j) {
		V.pb(j);
		rec(i + 1, sum - a[i][j], sumMx - a[i][c[i]]);
		V.ppb();
	}
}

bool check(int x) {
	V.clear();
	ok = 0;
	rec(1, x, sumMx);
	return ok;
}

main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= c[i]; ++j) 
			scanf("%d", &a[i][j]);       
		sumMx += a[i][c[i]];
	}
	scanf("%d", &m);

	for (int i = 1; i <= m; ++i) {
		vi x;
		for (int j = 1; j <= n; ++j) {
			int y;
			scanf("%d", &y);
			x.pb(y);
		}
		Q.insert(x);
	}


	int l = 0, r = sumMx;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	for (auto x : ans)
		printf("%d ", x);
		
}