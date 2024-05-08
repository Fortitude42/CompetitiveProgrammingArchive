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
const int N = 2e3 + 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int d, n, a[M], mt[M]; 
vi ans, g[M];
bool was[M];

bool cmp(int x, int y) {
	return __builtin_popcount(x) < __builtin_popcount(y);
}

void f(int x, int y) {
	for (int i = 0; i < d; ++i)
		if (!(x & (1 << i)) && (y & (1 << i)))
			ans.pb(i);
}

bool dfs(int v){
	if (was[v])
		return 0;

	was[v] = 1;
	for (auto to : g[v])
		if (mt[to] == -1) {
			mt[to] = v;
			mt[v] = to;
			return 1;
		}

	for (auto to : g[v])
		if (dfs(mt[to])) {
			mt[to] = v;
			mt[v] = to;
			return 1;
		}

	return 0;			
} 

void solve() {
	cin >> d >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < d; ++j) {
			char c;
			cin >> c;
			if (c == '1')
				a[i] |= (1 << j);
		}
	}

	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if ((a[i] & a[j]) == a[i]) 
				g[i].pb(j + n); 
			

	
	memset(mt, -1, sizeof(mt));
	for (int i = n; i > 0; --i) {
		memset(was, 0, sizeof(was));
		dfs(i);
	}

	memset(was, 0, sizeof(was));
	for (int i = 1; i <= n; ++i)
		if (!was[i]) {
			int j = i;

			f(0, a[j]);
			while (mt[j] != -1) {
				f(a[j], a[mt[j] - n]);
				j = mt[j] - n;
				was[j] = 1;
			}
			ans.pb(-1);
		}

	ans.ppb();

	cout << sz(ans) << endl;
	for (auto x : ans)
		if (x == -1)
			cout << "R ";
		else
			cout << x << ' ';
}

main () {
	fastio
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}