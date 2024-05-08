#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
//#define int long long 
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 3e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, a[N], res[N], mx[2];
pii b[N];

void f (int i, int j) {
	if (i > j)
		swap(i, j);
			int left = 0, right = 0, mid = 0;

			for (int ii = i - 1; ii > 0; --ii) {
				if ((left & 1) && a[ii] <= a[i])
					++left;
				else if (!(left & 1) && a[ii] <= a[j])
					++left;
			}

			for (int jj = j + 1; jj <= n; ++jj) {
				if ((right  & 1) && a[jj] <= a[j])
					++right;
				else if (!(right & 1) && a[jj] <= a[i])
					++right;
			}

			for (int ii = i + 1; ii < j; ++ii) {
				if ((mid & 1) && a[ii] <= a[i])
					++mid;
				else if (!(mid & 1) && a[ii] <= a[j])
					++mid;
			}
	


			mid = mid / 2;
			
			if (left + right == 0) {
				for (int jj = 0; jj <= mid; ++jj)
					res[jj*2 + 2] = min(res[jj*2 + 2], abs(a[i] - a[j]));
			} else {
				for (int jj = 0; jj <= left + right + mid*2; ++jj)
					res[jj + 2] = min(res[jj + 2], abs(a[i] - a[j]));
			}
}
main () {
	fastio
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		res[i] = inf;
		b[i] = mp(a[i], i);
		mx[i & 1] = max(mx[i & 1], a[i]);
	}

	res[n] = abs(mx[0] - mx[1]);

	sort(b + 1, b + 1 + n);

	for (int i = 2; i <= n; ++i) 
		for (int j = 1; j <= min(i - 1, 3); ++j)
			f(b[i].s, b[i - j].s);
	
	for (int i = 2; i <= n; ++i)
		cout << res[i] << ' '; 
}

