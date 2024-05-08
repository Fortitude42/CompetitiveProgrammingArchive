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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi g[30], order, gr[30], gg[30];
int n, col[30], k, ind[30];
char c[100][100][100];
bool was[30];


void dfs(int v) {
	was[v] = 1;
	for (auto to : g[v])
		if (!was[to])
			dfs(to);

	order.pb(v);
}

void dfs1(int v) {
	col[v] = k;
	for (auto to : gr[v])
		if (!col[to])
			dfs1(to);
}

void dfs2(int v) {
	was[v] = 1;
	for (auto to : gg[v])
		if (!was[to])
			dfs2(to);

	order.pb(v);
}

void makePath(int i, int j) {
	int z = 2*i - 1;
	for (int y = 4*i - 3; y <= 4*j - 3; ++y)
		if (!isdigit(c[4*i - 3][y][z]))
			c[4*i - 3][y][z] = '.'; 
		

	for (int x = 4*i - 3; x <= 4*j - 3; ++x)
		if (!isdigit(c[x][4*i - 3][z]))
			c[x][4*j - 3][z] = '.';
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int d;
			cin >> d;
			if (d) {
				g[i].pb(j); 
				gr[j].pb(i);
			}
		}

	for (int i = 1; i <= n; ++i)
		if (!was[i])
			dfs(i);
		
	reverse(all(order));
	for (auto x : order)
		if (!col[x]){
		    ++k;
			dfs1(x); 
		}

	for (int i = 1; i <= n; ++i)
		for (auto j : g[i])
			if (col[i] != col[j])
				gg[col[i]].pb(col[j]);

	for (int i = 1; i <= k; ++i) {
		sort(all(gg[i]));
		gg[i].resize(unique(all(gg[i])) - gg[i].begin());
	}

	order.clear();
	memset(was, 0, sizeof(was));

	for (int i = 1; i <= k; ++i)
		if (!was[i])
			dfs2(i);

	reverse(all(order));
	for (int i = 0; i < k; ++i)
		ind[order[i]] = i + 1;

	int X = 4*k - 1, Y = 4*k - 1, Z = 2*k - 1;
	for (int z = 1; z <= Z; ++z)
		for (int x = 1; x <= X; ++x)
			for (int y = 1; y <= Y; ++y)
				c[x][y][z] = '#';

	for (int i = 1; i <= k; ++i) {
		int l = 4*i - 3, r = 4*i - 1;

		vi cur;
		for (int j = 1; j <= n; ++j)
			if (col[j] == order[i - 1])
				cur.pb(j);

		for (int z = 1; z <= 2*i - 1; ++z)
			for (int x = l; x <= r; ++x)
				for (int y = l; y <= r; ++y) {
					if (z == 2*i - 1 && sz(cur)) {
						c[x][y][z] = char(cur.back() + '0');
						cur.ppb();
					}
					else
						c[x][y][z] = '.'; 
				}
	}

	for (int i = 1; i <= k; ++i)
		for (auto j : gg[i])
			makePath(ind[i], ind[j]);
	
	cout << X << ' ' << Y << ' ' << Z << endl;
	for (int z = 1; z <= Z; ++z) {
		for (int x = 1; x <= X; x++, cout << endl)
			for (int y = 1; y <= Y; ++y)
				cout << c[x][y][z];
								
		cout << endl << endl;
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

