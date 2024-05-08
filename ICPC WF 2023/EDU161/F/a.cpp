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

int n, x;
int d[M][M][M], cnt[M][M];
bool was[M][M][M];
int a[M], nxt[M][M], prv[M][M];
 
void solve() {
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= x; ++i) {
		prv[0][i] = 0;
		nxt[n + 1][i] = n + 1;
	}


	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= x; ++j) {
			prv[i][j] = prv[i - 1][j];
			if (a[i] == j)
				prv[i][j] = i;
		}
	
	for (int i = n; i > 0; --i) {
		for (int j = x; j > 0; --j) {
			nxt[i][j] = nxt[i + 1][j];
			if (j == a[i])
				nxt[i][j] = i;
		}
	}

	for (int l = 1; l <= n; ++l)
		for (int r = l; r <= n; ++r)
			for (int i = 1; i <= x; ++i) {
				d[l][r][i] = -1;
				cnt[l][r] = 0;
				was[l][r][i] = 0;
			}

	deque < pair < pii, int > > q;
	for (int i = 1; i <= n; ++i) {
		d[i][i][a[i]] = 0;
		q.push_back(mp(mp(i, i), a[i]));
	}


	while (sz(q)) {
		int l = q.front().f.f, r = q.front().f.s, v = q.front().s;
		q.pop_front();
		if (was[l][r][v])
			continue;

		was[l][r][v] = 1;
		if (l + 1 <= r && (d[l + 1][r][v] == -1 || d[l + 1][r][v] > d[l][r][v])) {
			d[l + 1][r][v] = d[l][r][v];
			q.push_front(mp(mp(l + 1, r), v));
		}

		if (r - 1 >= l && (d[l][r - 1][v] == -1 || d[l][r - 1][v] > d[l][r][v])) {
			d[l][r - 1][v] = d[l][r][v];
			q.push_front(mp(mp(l, r - 1), v));
		}
				
		if (l > 1 && a[l - 1] == v && (d[l - 1][r][v] == -1 || d[l - 1][r][v] > d[l][r][v])) {
			d[l - 1][r][v] = d[l][r][v];
			q.push_front(mp(mp(l - 1, r), v));
		}


		if (r < n && a[r + 1] == v && (d[l][r + 1][v] == -1 || d[l][r + 1][v] > d[l][r][v])) {
			d[l][r + 1][v] = d[l][r][v];
			q.push_front(mp(mp(l, r + 1), v));
		}


		
		if (l == 1 && r == n) {
			cout << d[l][r][v] << "\n";

			while (sz(q))
				q.pop_back();
			return;
		}


		++cnt[l][r];
//		if (cnt[l][r] <= 5) {
			for (int v1 = 1; v1 <= x; ++v1)
				if (v != v1) {
					int L = prv[l - 1][v1] + 1;
					int R = nxt[r + 1][v1] - 1;
					if (d[L][R][v1] == -1) {
						d[L][R][v1] = d[l][r][v] + 1;
						q.pb(mp(mp(L, R), v1));
					}
				}
//		}
	}
}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}