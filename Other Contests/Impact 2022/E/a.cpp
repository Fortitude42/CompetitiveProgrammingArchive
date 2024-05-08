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
const int N = 1500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 7;
const ll INF = 1e18;


int tt[M], timer;
vector < pair < short, short > > g[M*M];
int n, c[M][M], t[M], a[M][M], cnt[2*M];

inline int R () {
	char c;
	bool started = 0;
	int ans = 0;
	while (1) {
		c = getchar();
		if ((c > '9' || c < '0') && !started)
			continue;
		if ((c > '9' || c < '0') && started)
			break;

		started = 1;
		ans = ans * 10 + c - '0';
	}
 
	return ans;
}

void inc(short pos, int &x) {
	while (pos <= n) {
		if (tt[pos] != timer) {
			t[pos] = x;
			tt[pos] = timer;
		} else
			t[pos] = max(t[pos], x);
		pos |= (pos + 1);
	}
}

int get(short r) {
	int res = 0;
	while (r > 0) {
		if (tt[r] == timer)
			res = max(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}
 
void solve() {
	n = R();
	for (short i = 1; i <= n; ++i)
		for (short j = 1; j <= n; ++j) {
			c[i][j] = R();
			g[c[i][j]].pb({i, j});
		}

	for (int i = 1; i <= n*n; ++i) {
		if (!sz(g[i]))
			continue;

		++timer;
		for (auto j : g[i]) {
			int x = get(j.s) + 1;
			a[j.f][j.s] = x;
			inc(j.s, x);
		}

		++timer;

		for (int j = sz(g[i]) - 1; j >= 0; --j) {
			int x = get(n - g[i][j].s + 1) + 1;
			++cnt[a[g[i][j].f][g[i][j].s] + x - 1];
			inc(n - g[i][j].s + 1, x);
		}
	}

	for (int i = 1; i <= 2*n - 1; ++i)
		printf("%d ", cnt[i]);


}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}