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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, q; 
unordered_set < int > was[M];
unordered_map < int, int > mx[M], d[M];

void solve() {
	scanf("%d%d%d", &n, &m, &q);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (n > m)
			swap(a, b);
		was[a].insert(b);
	}

	if (n > m)
		swap(n, m);

	queue < pii > Q;
	Q.push({1, 1});
	d[1][1] = 0;
	mx[0][1] = 1;

	while (sz(Q)) {
		int x = Q.front().f, y = Q.front().s;
		int z = d[x][y];
		Q.pop();
		if (mx[z][x] != y)
			continue;
		
		if (x == n && y == m) {
			printf("%d\n", z);
			return;
		}

		int to = x + y;
		if (was[x].count(y))
			to++;

		int toy = min(to, m);
		int tox = min(to, n);
		if (!d[x].count(toy) && (!mx[z + 1].count(x) || mx[z + 1][x] < toy)) {
			mx[z + 1][x] = toy;
			d[x][toy] = z + 1;
			Q.push({x, toy});
		}
		
		if (!d[tox].count(y) && (!mx[z + 1].count(tox) || mx[z + 1][tox] < y)) {
			mx[z + 1][tox] = y;
			d[tox][y] = z + 1;
			Q.push({tox, y});
		}
    }

}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                                      