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

int t, n;
string s;
set < int > pos;

 
int Nxt (int v) {
	if (*pos.rbegin() == v)
		return -1;

	return *pos.upper_bound(v);
}

int Cur (int v) {
	if (*pos.rbegin() <= v)
		return *pos.rbegin();

	return *pos.lower_bound(v);			
}

main () {
	cin >> t;
	while (t--) {
		pos.clear();

		cin >> n >> s;
		for (int i = 0; i < n; ++i)
			pos.insert(i);

		int x = 0, ans = 0;
		while (sz(pos)) {
			++ans;
			x = Cur(x);

			while (1) {
				int y = Nxt(x);
				if (y == -1) {
					pos.erase(pos.begin());
					break;
				}

				if (s[x] != s[y]) 
					x = y;
				else {
					pos.erase(x);
					break;
				}
			}

			if (!sz(pos))
				break;

			char c = s[*pos.begin()];
			while (sz(pos)) {
				if (s[*pos.begin()] != c)
					break;

				pos.erase(pos.begin());
			}
		}

		cout << ans << endl;
	}
}