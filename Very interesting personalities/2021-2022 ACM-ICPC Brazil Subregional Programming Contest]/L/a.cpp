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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


char s[M];
int n, m, p[M+M][20], ans = 1, v[M+M];

int get(int v, int lvl) {
	return v == p[v][lvl] ? v : p[v][lvl] = get(p[v][lvl], lvl);
}

void merge(int v, int u, int lvl) {
	v = get(v, lvl);
	u = get(u, lvl);
	
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u][lvl] = v;
}


 
void solve() {
	scanf("%d%d", &n, &m);
	scanf("\n%s", (s + 1));

	for (int i = 1; i <= n+n; ++i)
		for (int j = 0; j < 20; ++j)
			p[i][j] = i;

	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		int l1 = n + (n - r + 1);

		for (int j = 19; j >= 0; --j)
			if ((r - l + 1) >= (1 << j)) {
				merge(l, l1, j);
				l += (1 << j);
				l1 += (1 << j);
			}
	}

	for (int j = 19; j > 0; --j) 
		for (int i = 1; i + (1 << (j - 1)) - 1 <= n + n; ++i) {
			merge(i, get(i, j), j - 1);
			merge(i + (1 << (j - 1)), get(i, j) + (1 << (j - 1)), j - 1); 
		}

	for (int i = 1; i <= n; ++i)
		merge(i, n + (n - i + 1), 0);
	
	for (int i = 1; i <= n; ++i) {
		if (s[i] != '?')
			v[get(i, 0)] |= (1 << (s[i] - '0'));
	}

	for (int i = 1; i <= n; ++i) {
		int j = get(i, 0);
		if (s[i] == '?' && !v[j]) {
			v[j] = 1;
			ans *= 2;
			if (ans >= MOD)
				ans -= MOD;
		}

		if (v[j] == 3)
			ans = 0;
	}

	printf("%d\n", ans);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

