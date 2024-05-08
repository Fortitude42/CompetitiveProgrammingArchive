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
 
const int inf = 1e9, maxn = 1e6 + 11, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int k, n, p[N], x[N], g[N][18], d[N];
int pos[maxn], bad[maxn], was[maxn]; 

void build () {
	for (int i = 1; i < n; ++i) {
		g[i][0] = x[i + 1] - x[i];
		if (i > 1)
			d[i] = d[i >> 1] + 1;
	}

	for (int j = 1; j < 18; ++j)
		for (int i = 1; i + (1 << j) - 1 < n; ++i)
			g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
}

int get (int l, int r) {
	if (l > r)
		return 0;

	int D = d[r - l + 1];
	return __gcd(g[l][D], g[r - (1 << D) + 1][D]);
}


 
main () {
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &p[i]);       
		for (int j = p[i]; j < maxn; j += p[i])
			was[j] = p[i];
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);       
		pos[x[i]] = i;
	}
	
	build();


	for (int i = 1; i <= k; ++i) {
		vi Pos;
		for (int j = x[1]; j < maxn; j += p[i])
			if (pos[j]) {
				Pos.pb(pos[j]);
				bad[pos[j]] = i;
			}


		int ans = get(Pos.back() + 1, n - 1);
		for (int i = 0; i < sz(Pos) - 1; ++i) 
			ans = __gcd(ans, get(Pos[i] + 1, Pos[i + 1] - 2));

		int prv = -1;
		
		for (int j = 0; j < sz(Pos); ++j) {
			if (j && bad[Pos[j] - 1] != i)
				prv = Pos[j] - 1;

			if (Pos[j] < n && bad[Pos[j] + 1] != i && prv != -1)
				ans = __gcd(ans, x[Pos[j] + 1] - x[prv]);
		} 

			
		if (!ans) {
			cout << "YES\n";
			cout << x[1] << ' ' << p[i] << endl;
			int ss = 1;
			while (bad[ss] == i)
				++ss;

			if (ss == n + 1)
				ss = 1;

			cout << x[ss] << ' ' << p[i] << endl;
			return 0;
		}

		if (was[ans]) {
			int pp = was[ans];
			int ss = 1; 	
			while (bad[ss] == i)
				++ss;

			cout << "YES\n";
			cout << x[1] << ' ' << p[i] << endl;
			cout << x[ss] << ' ' << pp << endl;
			return 0;
		}
	}

	cout << "NO";
	return 0;
}