//by paradox & gege & parasat
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
const pii base = mp(1e6 + 3, 1e6 + 33), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 4000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, b[M], ans[M];
map < int, int > g;
vi a = {24048, 23754, 14544, 30066, 32285, 22101, 11574, 10088, 9217, 30110, 20415, 9439, 18852, 17113, 25823, 18764, 8762 };

int f(int mask, int n) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i))
			res = (res + a[i]) % MOD;
		else
			res = res * 1ll * a[i] % MOD; 
	}

	return res;
}

void precalc() {
	for (int mask = 0; mask < (1 << sz(a)); ++mask)
		g[f(mask, sz(a))] = mask; 
	
	
}

int ask() {
	cout << "? ";
	for (int i = 0; i <= n; ++i)
		cout << b[i] << ' ';
	cout << endl;
	int x;
	cin >> x;
	return x;
}


void solve() {
	cin >> n;
	int r = n, suff = 0;
	while (r > 0) {
		int len = min(sz(a), r);
		for (int i = 0; i <= r - len; ++i)
			b[i] = 0;

		for (int x = 0; x < len; ++x)
			b[r - x] = a[sz(a) - 1 - x];

		for (int i = r + 1; i <= n; ++i)	
			b[i] = 1;

		int x = (ask() - suff + MOD) % MOD;
		int mask = g[x];
		

		for (int x = 0; x < sz(a); ++x)
			if (mask & (1 << x)) {
				ans[r - sz(a) + 1 + x] = 1;
				++suff;
			}

		r -= len;
	}

	cout << "! ";
	for (int i = 1; i <= n; ++i)
		cout << (ans[i] ? '+' : 'x');
}

main () {
	fastio
	precalc();
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

