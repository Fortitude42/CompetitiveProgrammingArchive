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
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;	
}

struct matrix {
	int a[3][3];
	matrix() {
		memset(a, 0, sizeof(a));
	}

	matrix operator * (const matrix &X) {
		matrix res;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) 
				for (int x = 0; x < 3; ++x)
					add(res.a[i][j], a[i][x] * 1ll * X.a[x][j] % MOD);

		return res;
	}
} zero;

matrix binpow(matrix X, ll n) {
	matrix res = zero;
	while (n) {
		if (n & 1)
			res = res * X;
		X = X * X;
		n >>= 1;
	}

	return res;
}
 
ll n, m;
int s, t, u;

void precalc() {
	for (int i = 0; i < 3; ++i)
		zero.a[i][i] = 1;
}

void solve() {
	cin >> n >> m >> s >> t >> u;
	matrix res;
	res.a[1][2] = MOD - 1;
	res.a[2][1] = 1;

	matrix mm;
	mm.a[0][1] = 1;
	mm.a[1][2] = 1;
	mm.a[2][0] = u;
	mm.a[2][1] = MOD - t;
	mm.a[2][2] = s;


	matrix mn ;
	mn.a[1][0] = 1;
	mn.a[2][1] = 1;
	mn.a[0][2] = u;
	mn.a[1][2] = MOD - t;
	mn.a[2][2] = s;

	res = binpow(mm, m) * res;
	res = res * binpow(mn, n);
	for (int i = 0; i < 3; ++i, cerr << endl)
		for (int j = 0; j < 3; ++j)
			cerr << res.a[i][j] << ' ';

	cout << res.a[0][0] << endl;
}

main () {
	precalc();

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

