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

int n, p[N], pos[N], cnt;
bool was[N];
vi ans;
 
void Swap (int i, int j) {
	swap(p[i], p[j]);
	swap(pos[p[i]], pos[p[j]]);
}

main () {
	fastio
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];              
		pos[p[i]] = i;
	}
	
	for (int i = 1; i <= n; ++i) {
		while (pos[i] > i) {
			if (was[pos[i]]) {
				cout << -1;
				return 0;
			}
			was[pos[i]] = 1;
			Swap(pos[i], pos[i] - 1);
			ans.pb(pos[i]);
		}
	}

	if (sz(ans) != n - 1) {
		cout << -1 << endl;
		return 0;
	}

	for (auto x : ans)
		cout << x << endl;




}