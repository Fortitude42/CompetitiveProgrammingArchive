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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n; 
vi a;
set < int > q;

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		a = a * 1ll * a % MOD;
		n >>= 1;
	}

	return res;
}

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



void solve() {
	srand(time(0));

	n = 17;
	while (1) {
		a.clear();
		q.clear();
		for (int i = 0; i < n; ++i)
			a.pb(rand());

		bool ok = 1;
		for (int mask = 0; mask < (1 << n); ++mask) {
			int fm = f(mask, n);
			if (q.count(fm)) {
				ok = 0;
				break;
			}
			q.insert(fm);
		}

		if (ok)
			break;
	}


	cout << "! ";
	for (int i : a)
		cout << i << ' ';
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

