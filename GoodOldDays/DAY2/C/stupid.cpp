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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, l[N], r[N], pos[N];

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> l[i] >> r[i];
	vi v;
	
	for (int i = 1; i <= n; ++i) 
		v.pb(i);

	do {
		for (int i = 0; i < n; ++i)
			pos[v[i]] = i + 1;

		bool ok = 1;
		for (int i = 1; i <= n; ++i)
			if (!(l[i] <= pos[i] && pos[i] <= r[i])) {
				ok = 0; 
				break;
			}

		if (ok) {
			for (auto x : v)
				cout << x << ' ';
			for (auto x : v)
				cerr << x << ' ';
			return 0;
		}
			
	} while (next_permutation(all(v)));

	cout << -1 << endl;	
	cerr << -1 << endl;	
}