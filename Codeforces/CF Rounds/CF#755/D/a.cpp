//by parasat
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
const int N = (1 << 10), inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

pii p[60][M];
string s[12];
vi pos[12][60];
int n, d[60][M];
bool valid[60][M], was[60][M];
vector < pii > order, g[60][M];

int get(char c) {
	if ('a' <= c && c <= 'z')
		return c - 'a';

	return 26 + c - 'A';
}

char get(int c) {
	if (c < 26)
		return c + 'a';

	return c - 26 + 'A';
}         

void dfs(int c, int mask) {
	was[c][mask] = 1;
	d[c][mask] = 0;


	for (int cc = 0; cc < 52; ++cc) {
		int mask1 = 0;
		for (int i = 0; i < n; ++i) {
			int bit = (mask >> i) & 1;
			int Pos = pos[i][c][bit];
			if (!sz(pos[i][cc]) || pos[i][cc].back() <= Pos) {
				mask1 = -1;
				break;
			}

			if (pos[i][cc][0] <= Pos)
				mask1 |= (1 << i);
		}

		if (mask1 > -1) {
			g[c][mask].pb({cc, mask1});
			if (!was[cc][mask1]) 
				dfs(cc, mask1);			
		}
	}

	order.pb({c, mask});
}

void solve() {
	order.clear();
	memset(d, -1, sizeof(d));
	memset(valid, 0, sizeof(valid));
	memset(was, 0, sizeof(was));
	for (int c = 0; c < 60; ++c)
		for (int mask = 0; mask < M; ++mask)
			g[c][mask].clear();

	for (int i = 0; i < 12; ++i)
		for (int j = 0; j < 60; ++j)
			pos[i][j].clear();

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];             
		for (int j = 0; j < sz(s[i]); ++j) {
			s[i][j] = get(s[i][j]);
			pos[i][s[i][j]].pb(j);
		}
	}
	
	for (int c = 0; c < 52; ++c)
		for (int mask = 0; mask < (1 << n); ++mask) {
			valid[c][mask] = 1;
			for (int i = 0; i < n; ++i) 
				if (sz(pos[i][c]) <= ((mask >> i) & 1))
					valid[c][mask] = 0;			
		}

	for (int c = 0; c < 52; ++c)
		for (int mask = 0; mask < (1 << n); ++mask)
			if (valid[c][mask] && !was[c][mask]) 
				dfs(c, mask);

	reverse(all(order));
	for (auto x : order) {
		int c = x.f, mask = x.s;
		for (auto y : g[c][mask]) {
			int cc = y.f, mask1 = y.s;
			if (d[cc][mask1] < d[c][mask] + 1) {
				d[cc][mask1] = d[c][mask] + 1;
				p[cc][mask1] = {c, mask};
			}
		}
	}
	
	int c = 0, mask = 0;
	for (int cc = 0; cc < 52; ++cc)
		for (int mask1 = 0; mask1 < (1 << n); ++mask1)
			if (d[c][mask] < d[cc][mask1]) {
				c = cc;
				mask = mask1;
			}

	string ans = "";
	cerr << c << ' ' << mask << ' ' << d[c][mask] << endl;
	while (d[c][mask] > -1) {
		ans += get(c);
		if (!d[c][mask])
			break;
		int cc = p[c][mask].f, mask1 = p[c][mask].s;
		c = cc, mask = mask1;
	}

	reverse(all(ans));
	cout << sz(ans) << endl;
	cout << ans << endl;
}

main () {
	memset(p, -1, sizeof(p));

  	int TT;
  	TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}