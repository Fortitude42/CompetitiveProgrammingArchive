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
const int N = (1 << 8), inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int a, b, c, d, m, v[10];
queue < vi > q;
map < vi, int > dist[M];
 

void precalc() {
	for (int gmask = 0; gmask < (1 << 8); ++gmask) {
		vi cur;
		for (int mask = 0; mask < 8; ++mask) {
			if (!(gmask & (1 << mask)))
				continue;
			cur.pb(mask);
		}

		dist[gmask][cur] = 0;
		q.push(cur);

		while (sz(q)) {
			cur = q.front();
			int curval = dist[gmask][cur];
			q.pop();

			vi to[4];
			for (int i = 0; i < sz(cur); ++i) {
				int bitx = cur[i] & 1;
				int bity = (cur[i] >> 1) & 1;
				int bitm = (cur[i] >> 2) & 1;
				to[0].pb((bitx & bity) + (bity)*2 + bitm*4);
				to[1].pb((bitx | bity) + (bity)*2 + bitm*4);
				to[2].pb(bitx + (bity^bitx)*2 + bitm*4);
				to[3].pb(bitx + (bity^bitm)*2 + bitm*4);
			}

			for (int i = 0; i < 4; ++i)
				if (!dist[gmask].count(to[i])) {
					dist[gmask][to[i]] = curval + 1;
					q.push(to[i]);
				}
		}
	}
}

void solve() {
	cin >> a >> b >> c >> d >> m;
	int gmask = 0;
	memset(v, -1, sizeof v);
	for (int bit = 0; bit < 30; ++bit) {
		int bita = (a >> bit) & 1;
		int bitb = (b >> bit) & 1;		
		int bitm = (m >> bit) & 1;

		int bitc = (c >> bit) & 1;
		int bitd = (d >> bit) & 1;

		int mask1 = bita + bitb*2 + bitm*4;
		int mask2 = bitc + bitd*2 + bitm*4;

		if (v[mask1] != -1 && v[mask1] != mask2) {
			cout << "-1\n";
			return;
		}
		v[mask1] = mask2;
		gmask |= (1 << mask1);
	}

	vi cur;
	for (int mask = 0; mask < 8; ++mask) {
		if (v[mask] == -1)
			continue;

		cur.pb(v[mask]);
	}

	if (!dist[gmask].count(cur)) 
		cout << -1 << "\n";
	else
		cout << dist[gmask][cur] << "\n";
}

main () {
	precalc();
  int TT;
  TT = 1;
  	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}                              