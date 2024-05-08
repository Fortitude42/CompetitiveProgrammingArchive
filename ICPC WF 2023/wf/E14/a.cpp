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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

bool b[M][M][M];
int n, deg[M], cnt[M][M], id[M][M];
vi g[M], gg[M];
bool used[M];


 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> deg[i];
		for (int j = 0; j < deg[i]; ++j) {
			int v;
			cin >> v;
			id[i][v] = j;
			g[i].pb(v);
		}
	}

	for (int i = 1; i <= n; ++i)
		for (auto j : g[i])
			gg[i].pb(deg[j]);


	queue < pair < pii, int > > q;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) {
			if (deg[i] != deg[j]) {
				for (int sh = 0; sh < deg[j]; ++sh) {
					b[i][j][sh] = 1;
					q.push(mp(mp(i, j), sh));
				}

				cnt[i][j] = 0;
				continue;
			}
			
			for (int sh = 0; sh < deg[i]; ++sh) {
				for (int x = 0; x < deg[i]; ++x)
					if (gg[i][x] != gg[j][(x + sh) % deg[i]]) {
						b[i][j][sh] = 1;
						q.push({mp(i, j), sh});
						break;
					}

				if (!b[i][j][sh])
					++cnt[i][j];
			}
		}

	while (sz(q)) {
		int v = q.front().f.f, u = q.front().f.s;
		int sh = q.front().s;
		q.pop();

		for (int iv = 0; iv < sz(g[v]); ++iv) {
			int iu = (iv + sh) % deg[u];

			int v1 = g[v][iv];
			int u1 = g[u][iu];

			int idv = id[v1][v], idu = id[u1][u];

			if (v1 > u1) {
				swap(v1, u1);
				swap(idv, idu);
			}

			int sh1 = ((idu - idv) % deg[u1] +deg[u1]) % deg[u1];

			if (!b[v1][u1][sh1]) {
				b[v1][u1][sh1] = 1;
				--cnt[v1][u1];
				q.push(mp(mp(v1, u1), sh1));
			}

		}
	}


	vector < vi > ans;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			if (!deg[i]) {
				vi cur = {i};
				for (int j = i + 1; j <= n; ++j)
					if (!deg[j]){
						used[j] = 1;
						cur.pb(j);
					}
				if (sz(cur) > 1)
					ans.pb(cur);
				continue;
			}

			vi cur = {i};
			for (int j = i + 1; j <= n; ++j)
				if (cnt[i][j] > 0) {
					used[j] = 1;
					cur.pb(j);
				}

//			cerr << i << ' ' << sz(cur) << endl;
			if (sz(cur) > 1)	
				ans.pb(cur);
		}
	}

	if (!sz(ans))
		cout << "none";
	else {
		for (auto v : ans) {
		    for (auto x : v)
				cout << x << ' '; 
			cout << "\n";
		}
	}
	
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}