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
 
const int inf = 1e9, maxn = 1e4, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, a[N], b[N];
 
main () {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		int l = 1;
		if (n & 1) {
			l = 4;
			if (abs(a[2]) == abs(a[3])) {
				b[1] = a[2];
				for (int x = -50; x <= 50; ++x) {
					b[2] = -x;
					b[3] = x - a[1];
					if (a[2] != a[3])
						b[3] = -b[3];

					if (b[2] && b[3] && (abs(b[2]) <= maxn && abs(b[3]) <= maxn))
						break;
				}

			} else if (abs(a[2] - a[3]) <= maxn) {
				b[1] = a[2] - a[3];
				b[2] = -a[1];
				b[3] = a[1];
			} else {
				b[1] = a[2] + a[3];
				b[2] = -a[1];
				b[3] = -a[1];
			}
//			cerr << b[1] << ' ' << b[2] << ' ' << b[3] << endl;
			assert(b[1] * a[1] + b[2] * a[2] + b[3]*a[3] == 0);
		}

		int r = n;
		while (l < r) {
			b[l] = a[r];
			b[r] = -a[l];
			assert(b[l] * a[l] + a[r] * b[r] == 0);
			l++;
			r--;
		}

		for (int i = 1; i <= n; ++i)
			cout << b[i] << ' ';
		cout << endl;
	}
}