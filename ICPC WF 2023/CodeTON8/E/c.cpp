#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 500, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int s[2], f[M], rf[M];

int binpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		a = a * 1ll * a % MOD;
		n >>= 1;
	}

	return res;
}


void precalc() {
	f[0] = 1;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] * 1ll * i % MOD;

	rf[M - 1] = binpow(f[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % MOD;
}

int cnk(int n, int k) {
	assert(n >= 0 && k >= 0 && k <= n);
	return f[n] * 1ll * rf[k] % MOD * rf[n - k] % MOD;
}


void rec(int sum, int n, int mx) {
	if (n == 1) {
		s[max(sum, mx) & 1]++;
		return;
	}

	for (int x = 0; x <= sum; ++x)
		rec(sum - x, n - 1, max(mx, x));	
}

main () {
  int TT;
  TT = 1;
  precalc();


  for (int n = 4; n <= 4; ++n)
  	for (int sum = 1; sum <= 10; ++sum){
  		s[0] = s[1] = 0;

	  rec(sum, n, 0);
	  cout << sum << ' ' << n << " -----> " << s[0] << ' ' << s[1] << " " << cnk(n + sum - 1, n - 1) << endl;
	}
	
/*
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
*/
}