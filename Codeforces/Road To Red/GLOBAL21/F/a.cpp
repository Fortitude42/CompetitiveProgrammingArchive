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
const int N = 1e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, p[M], cnt[M], d[M][M]; 
string s[110][110];
vi comp[M], g[M];
queue < int > q;

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])
		swap(v, u);

	p[u] = v;
	cnt[v] += cnt[u];
}

int get(int a, int b) {
	if (a > b)
		swap(a, b);
	return a*n + b;
}

void merge(int a, int b, int x, int y) {
	merge(get(x, y), get(a, b));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n*n; ++i) {
		p[i] = i; 
		cnt[i] = 1;
		comp[i].clear();
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 1; j <= n - i - 1; ++j) {
			cin >> s[i][j];
			for (int k = 0; k < n; ++k)
				if (s[i][j][k] == '1')
					merge(i, k, i + j, k); 				
		}
	}

	for (int i = 0; i < n - 1; ++i)
		for (int j = 1; j <= n - i - 1; ++j)
			for (int k = 0; k < n; ++k)
				if (s[i][j][k] == '0' && get(get(i, k)) == get(get(i + j, k))) {
					cout << "No\n";
					return;
				}



	for (int i = 0; i < n*n; ++i)
		comp[get(i)].pb(i);



	for (int a = 0; a < n; ++a)
		for (int b = a + 1; b < n; ++b) {
			int x = a*n + b;
			if (p[x] == x && cnt[x] == n - 1) {//consider a tree
				for (int i = 0; i < n; ++i)
					g[i].clear();					

				for (auto e : comp[x]) {
					int a = e / n, b = e % n;
					g[a].pb(b);
					g[b].pb(a);
				}

				bool isTree = 1;

				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j)
						d[i][j] = -1;

					q.push(i);
					d[i][i] = 0;

					while (sz(q)) {
						int v = q.front();
						q.pop();

						for (auto j : g[v])
							if (d[i][j] == -1) {
								d[i][j] = d[i][v] + 1;
								q.push(j);
							}
					}

					if (!i) { //check once if given graph is a tree
						for (int j = 0; j < n; ++j)
							if (d[i][j] == -1) {
								isTree = 0;
								break;
							}
						if (!isTree)
							break;
					}
				}

				if (!isTree)
					continue;
				
				bool good = 1;
				for (int i = 0; i < n - 1 && good; ++i)
					for (int j = 1; j <= n - i - 1 && good; ++j)
						for (int k = 0; k < n && good; ++k)
							if ((s[i][j][k] == '0' && d[i][k] == d[i + j][k]) || (s[i][j][k] == '1' && d[i][k] != d[i + j][k]))  
								good = 0;
							

				if (good) {
					cout << "YES\n";
					for (auto e : comp[x]) {
						int a = e / n, b = e % n;
						cout << a + 1 << ' ' << b + 1 << endl;
					}

					return;
				}
			}				
		}

	cout << "NO\n";			
}

main () {                             
	fastio
	int TT;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}