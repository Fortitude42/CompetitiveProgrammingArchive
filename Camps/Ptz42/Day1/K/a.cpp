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
const int N = 22, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, n1, n2;
vector < pii > g[M][3], gg[M][3];
 
int get(char c) {
	if (c == 'R')
		return 0;
	if (c == 'G')
		return 1;
	return 2;
}

ll ans;
int u[M][3], z[M][3];
const int maxn = (1 << 24) + 11;

int dp[maxn];

void rec1(int i = 0, int mask = 0) {
	if (i == n2) {		
		++dp[mask];
		return;
	}

	for (int c = 0; c < 3; ++c)
		if (!u[i + n1][c]) {
			for (auto x : g[i + n1][c]) 
				u[x.f][x.s]++;

			rec1(i + 1, mask | (1 << (3*i + c)));
			for (auto x : g[i + n1][c]) 
				u[x.f][x.s]--;
		}
}

void rec(int i = 0, int mask = 0) {
	if (i == n1) {		
		mask ^= ((1 << (3*n2)) - 1);
		if (!n2)
			++ans;
		else
			ans += dp[mask];
		return;
	}

	for (int c = 0; c < 3; ++c)
		if (!u[i][c]) {
			for (auto x : g[i][c]) 
				u[x.f][x.s]++;

			rec(i + 1, mask | z[i][c]);
			for (auto x : g[i][c]) 
				u[x.f][x.s]--;
		}
}

void solve() {
	cin >> n >> m;
	n1 = min(n, 14);
	n2 = n - n1;

	while (m--) {
		int x, y;
		char a, b;
		cin >> x >> a >> y >> b;
		--x, --y;
		if (y < n1 || x >= n1) 
			g[x][get(a)].pb(mp(y, get(b)));
		else
			z[x][get(a)] |= (1 << ((3 * (y - n1) + get(b))));
	}

	rec1();

	for (int i = 0; i < 3*n2; ++i)
		for (int mask = 0; mask < (1 << (n2*3)); ++mask)
			if (mask & (1 << i))
				dp[mask] += dp[mask ^ (1 << i)];
		
	rec();
	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

