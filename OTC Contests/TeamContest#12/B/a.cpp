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

int n, a[N], b[N], d[N], mn[N][20], mx[N][20];

void build () {
	for (int i = 1; i <= n; ++i) {
		if (i > 1)
			d[i] = d[i >> 1] + 1;	

		mx[i][0] = a[i];
		mn[i][0] = b[i];
	}

	for (int j = 1; j < 20; ++j)                    
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);				
		}	
} 

int getMn (int l, int r) {
	int D = d[r - l + 1];
	return min(mn[l][D], mn[r - (1 << D) + 1][D]);
}

int getMx (int l, int r) {
	int D = d[r - l + 1];
	return max(mx[l][D], mx[r - (1 << D) + 1][D]);
}

bool check (int x) {
	for (int i = 1; i + x - 1 <= n; ++i) {
		int l = getMx(i, i + x - 1), r = getMn(i, i + x - 1);		
		if (r - l + 1 >= x)
			return 1;
	}

	return 0;
}


main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	build();

	int l = 1, r = n, res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

	cout << res << endl;
}