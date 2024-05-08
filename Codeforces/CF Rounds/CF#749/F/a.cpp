#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, res[N][N], ans;
 

void solve(vi v, int k, int c) {
	int n = sz(v);
	if (n < k) {
		for (int i = 0; i < sz(v); ++i)
			for (int j = i + 1; j < sz(v); ++j) {
				res[v[i]][v[j]] = c;              
				ans = max(ans, c);
			}
		return;
	}

	int m1 = n % k;
	int m2 = k - m1;
	int n1 = (n + k - 1) / k;
	int n2 = n / k;

	int j = 0;
	while (m1--) {	
		vi cur;
		for (int i = 0; i < n1; ++i)
			cur.pb(v[j++]);		
		
		for (int i = j; i < sz(v); ++i) 
			for (auto x : cur) {
				res[x][v[i]] = c;		 
				ans = max(ans, c);
			}

		solve(cur, k, c + 1);			
	}

	while (m2--) {	
		vi cur;
		for (int i = 0; i < n2; ++i)
			cur.pb(v[j++]);		
		
		for (int i = j; i < sz(v); ++i) 
			for (auto x : cur) {
				res[x][v[i]] = c;
				ans = max(ans, c);
			}

		solve(cur, k, c + 1);			
	}
}

main () {
	cin >> n >> k;
	vi v;
	for (int i = 1; i <= n; ++i)
		v.pb(i);

	solve(v, k, 1);

	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			printf("%d ", res[i][j]);
}