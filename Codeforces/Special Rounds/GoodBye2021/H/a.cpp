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
const int N = 1e5 + 5e4, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, x, p[M];
 
void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

int rec1(const vi &a, const vi &b, int j, bool write) {
	if (!sz(a) || !sz(b))	
		return 0;

	vi a0, a1, b0, b1;

	for (int x : a)
		if (x & (1 << j))
			a1.pb(x);
		else
			a0.pb(x);

	for (auto x : b)
		if (x & (1 << j))
			b1.pb(x);
		else
			b0.pb(x);

	if (write){
	for (auto x : a0)
		cerr << x << ' ';
	cerr << endl;
	for (auto x : a1)
		cerr << x << ' ';
	cerr << endl;
	for (auto x : b0)
		cerr << x << ' ';
	cerr << endl;
	for (auto x : b1)
		cerr << x << ' ';
	cerr << endl << "---------------------" << endl;
	}
	                     

	
	if (x & (1 << j)) {
		if (!j)
			return (p[sz(a)] - 1) * 1ll * (p[sz(b)] - 1) % MOD;		

		int ans = 0;
		add(ans, (p[sz(a1)] - 1) * 1ll * (p[sz(b1)] - 1) % MOD);
		add(ans, (p[sz(a0)] - 1) * 1ll * (p[sz(b0)] - 1) % MOD);
		if (write)
		cerr << "---> " << (p[sz(a1)] - 1) * 1ll * (p[sz(b1)] - 1) << ' ' << (p[sz(a0)] - 1) * 1ll * (p[sz(b0)] - 1) << endl;
		
		int x = rec1(a1, b0, j - 1, 0);
		int y = rec1(a0, b1, j - 1, 0);

		add(ans, x * 1ll * y % MOD);

		if (write) {
		cerr << "--> " << x * 1ll * y << endl;
		cerr << "--> " << x * 1ll * (p[sz(a0)] + p[sz(b1)] - 1) << endl;
		cerr << "--> " << y * 1ll * (p[sz(a1)] + p[sz(b0)]) << endl; 
		}
		add(ans, x * 1ll * (p[sz(a0)] + p[sz(b1)] - 1) % MOD);
		add(ans, y * 1ll * (p[sz(a1)] + p[sz(b0)] - 1) % MOD);
		return ans;
	}

	if (!j) {
		int ans = 0;
		add(ans, (p[sz(a1)] - 1) * 1ll * (p[sz(b1)] - 1) % MOD);
		add(ans, (p[sz(a0)] - 1) * 1ll * (p[sz(b0)] - 1) % MOD);		
		return ans;
	}


	return (rec1(a0, b0, j - 1, 0) + rec1(a1, b1, j - 1, 0)) % MOD;
}

int rec(const vi &v, int j) {
	if (!sz(v))
		return 0;

	vi a, b;
	for (auto x : v)
		if (x & (1 << j))
			a.pb(x);
		else
			b.pb(x);

	if (!(x & (1 << j))) {
		if (!j) {
			assert(0);
		}

		return (rec(a, j - 1) + rec(b, j - 1)) % MOD;
	}

	if (!j) 
		return p[sz(a) + sz(b)] - 1;

	int res = p[sz(a)] - 1;
	add(res, p[sz(b)] - 1);
	add(res, rec1(a, b, j - 1, 0));
	return res;
}

void solve() {
	cin >> n >> x;
	if (!x) {
		map < int, int > cnt;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			++cnt[x];
		}
		int ans = 0;

		for (auto x : cnt)
			add(ans, p[x.s] - 1);
		cout << ans << endl;
		return;
	}

	vi all;
	for (int i = 1; i <= n; ++i) {
	    int x;
	    cin >> x;
		all.pb(x);                  
	}


	cout << rec(all, 30) << endl;
}

void precalc() {
	p[0] = 1;
	for (int i = 1; i < M; ++i)
		p[i] = p[i - 1] * 2 % MOD;
}

main () {
	precalc();
	fastio
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}