//template by paradox & gege & parasat
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 9;
const int M = N + 17;
const ll INF = 1e18;

 
ll k;
vi primes;
map < int, int > mn, mx;
int d, m, f[100], rf[100], dp[100];

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

int binpow(int a, ll n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		n >>= 1;
		a = a * 1ll * a % MOD;
	}

	return res;
}

int calc(int len) {
	if (len <= 0)
		return 0;

	int &res = dp[len];
	if (res != -1)
		return res;

	if (len == 1)
		return res = 1;
	
	res = binpow(len, k);
	add(res, -binpow(len - 1, k)*2 % MOD);
	add(res, binpow(len - 2, k));
	return res;
}

void solve() {
	cin >> k >> d >> m;
	for (int i = 2; i*i <= d; ++i) {
		if (d % i)
			continue;
		primes.pb(i);
		int cnt = 0;
		while (!(d % i)) {
			cnt++;
			d /= i;
		}

		mn[i] = cnt;
	}

	if (d > 1) {
		primes.pb(d);
		mn[d] = 1;
	}

	for (int i = 2; i*i <= m; ++i) {
		if (m % i)
			continue;
		primes.pb(i);				
		int cnt = 0;
		while (!(m % i)){ 
			++cnt;
			m /= i;
		}

		mx[i] = cnt;
	}


	if (m > 1) {
		primes.pb(m);
		mx[m] = 1;
	}

	sort(all(primes));
	primes.resize(unique(all(primes)) - primes.begin());
	int ans = 1;

	for (auto p : primes) {
		int Mn = mn[p];
		int Mx = mx[p];
		ans = ans * 1ll * calc(Mx - Mn + 1) % MOD;
	}

	cout << ans << endl;
}


main () {
	memset(dp, -1, sizeof(dp));	
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}