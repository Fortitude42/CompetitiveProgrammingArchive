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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


string a, b, c;
bool dp[N][2];
pair < pii, pii > p[N][2];
int t, n;
char s;


 
main () {
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		a = b = c = "";

		scanf("%d", &n);
		scanf("\n");
		for (int i = 0; i < n; ++i) {
			scanf("%c", &s);
			a += s;
		}

		scanf("\n");
		for (int i = 0; i < n; ++i) {
			scanf("%c", &s);
			b += s;
		}

		scanf("\n");
		for (int i = 0; i < n; ++i) {
			scanf("%c", &s);
			c += s;
		}
		            
		dp[n][0] = 1;

		for (int i = n - 1; i >= 0; --i) {
			int x = (isdigit(a[i]) ? a[i] - '0' : -1);
			int y = (isdigit(b[i]) ? b[i] - '0' : -1);
			int z = (isdigit(c[i]) ? c[i] - '0' : -1);

			for (int j = 0; j < 2; ++j)	{
			    if (!dp[i + 1][j])
			    	continue;

				for (int xx = 0; xx < 10; ++xx)
					for (int yy = 0; yy < 10; ++yy) {
						int X = (x == -1 ? xx : x);
						int Y = (y == -1 ? yy : y);
						int s = (X + Y + j);
						if (s % 10 == z || z == -1) {
							dp[i][s / 10] = 1;
							p[i][s / 10] = mp(mp(X, Y), mp(s % 10, j));
						}

							
					}
			}
		}

		if (!dp[0][0]) {
			printf("NO\n");
			continue;
		}           

		vector < pair < pii, int > > ans;
		int i = 0, j = 0;

		while (i < n) {
			pair < pii, pii > cur = p[i][j];
			ans.pb(mp(mp(cur.f.f, cur.f.s), cur.s.f));
			i++;
			j = cur.s.s;
		}

		printf("YES\n");
		for (auto x : ans)
			printf("%d", x.f.f);
		printf("\n");
		for (auto x : ans)
			printf("%d", x.f.s);
		printf("\n");
		for (auto x : ans)
			printf("%d", x.s);
		printf("\n");   
	}
}