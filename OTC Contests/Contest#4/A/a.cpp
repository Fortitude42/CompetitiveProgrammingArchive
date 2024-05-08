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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, d[500];
 
main () {
	cin >> t;
	while (t--) {
		cin >> n;
		vi primes;
		for (int i = 1; i <= n; ++i)
			cin >> d[i];

		sort(d + 1, d + 1 + n);
		ll X;
		if (n % 2 == 1)	
			X = d[(n + 1) / 2] * 1ll * d[(n + 1) / 2];
		else
			X = d[1]*1ll*d[n];

		vector < ll > D;
		for (int i = 2; i*1ll*i <= X; ++i) {
			if (X % i)
				continue;
			D.pb(i);
			if (i*1ll*i != X)
				D.pb(X / i);
		}
		sort(all(D));

		bool bad = 0;
		if (sz(D) != n)
			bad = 1;
		else {
			for (int i = 0; i < n; ++i)
				if (D[i] != d[i + 1]) {
					bad = 1;
					break;
				}
		}
		
		if (bad)
			cout << -1 << endl;
		else
			cout << X << endl;
	}
}