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
const int N = 5e5 + 11, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int m, c[M], f[M];
map < int, int > s[2];

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;

	if (x < 0)
		x += MOD;
}

void precalc(){
	f[0] = 1;
	for (int i = 1; i <= N; ++i)
		f[i] = f[i - 1] * 1ll * i % MOD;
}

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		n >>= 1;
		a = a * 1ll * a % MOD;
	}

	return res;
}

int get(int r) {
	return (r * 1ll * (r + 1) / 2) % MOD;
}

int get(int l, int r) {
	add(l, -1);

	int ans = get(r);
	add(ans, -get(l));
	return ans;
}


void solve() {
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &c[i]);        

		s[(c[i] - 1) & 1][c[i]]--;
		s[(c[i] - 1) & 1][1 - c[i]]++;
	}

	int ans = 1, res = 0, tot = 0;


	for (int x = -N; x <= N; ++x) {
		for (int j = 0; j < 2; ++j)
			s[j][x] += s[j][x - 1];

		int cur = s[abs(x) & 1][x];
		ans = ans * 1ll * f[cur] % MOD;
		add(res, x * 1ll * get(tot, tot + cur - 1) % MOD);
		add(tot, cur);
	}

	printf("%d %d\n", res, ans);
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

