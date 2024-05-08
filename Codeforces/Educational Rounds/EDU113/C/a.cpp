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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int t, n, rf[N], f[N]; 

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % mod;
		n >>= 1;
		a = a * 1ll * a % mod;
	}

	return res;
}

void precalc() {
	f[0] = 1;
	for (int i = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % mod;

	rf[N - 1] = binpow(f[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % mod;
}

int cnk(int n, int k) {
	return f[n] * 1ll * rf[n - k] % mod * rf[k] % mod;
}

main () {
	precalc();
	cin >> t;
	while (t--) {
		cin >> n;
		int mx1 = -1, mx2 = -1, cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if (x > mx1) {
				mx2 = mx1;
				cnt2 = cnt1;
				mx1 = x;
				cnt1 = 1;
			} else if (x == mx1) {
				++cnt1;
			} else if (x > mx2) {
				mx2 = x;
				cnt2 = 1;
			} else if (x == mx2) {
				mx2 = x;
				++cnt2;
			}
		}

		if (cnt1 > 1) {
			cout << f[n] << endl;
			continue;
		}

		if (mx1 - mx2 > 1) {
			cout << 0 << endl;
			continue;
		}

		cout << cnk(n, cnt2 + 1) * 1ll * f[n - cnt2 - 1] % mod * f[cnt2] % mod * cnt2 % mod << endl;
	}
}