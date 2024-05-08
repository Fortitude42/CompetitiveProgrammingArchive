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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int T, n, t[N], s[N];
ll mx[N], a1, a2;
 
main () {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> t[i];              
			mx[i] = 0;
		}


		for (int i = 1; i <= n; ++i)
			cin >> s[i];

		for (int j = 1; j <= n; ++j)
			for (int i = j - 1; i > 0; --i) {
				if (t[i] == t[j]) 
					continue;
				a1 = mx[i] + abs(s[i] - s[j]);
				a2 = mx[j] + abs(s[i] - s[j]);
				mx[i] = max(mx[i], a2);
				mx[j] = max(mx[j], a1);
			}

		cout << *max_element(mx + 1, mx + 1 + n) << endl;
	}
}