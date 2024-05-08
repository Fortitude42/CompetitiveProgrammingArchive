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

int t, n, cnt[5], cnt1[5][5];
int a[N][5];
 
main () {
	scanf("%d", &t);
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		memset(cnt1, 0, sizeof(cnt1));

		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
		    vi ones;

			for (int j = 0; j < 5; ++j) {
				int x;
				scanf("%d", &x);          
				cnt[j] += x;
				if (x)
					ones.pb(j);
			}

			for (int x = 0; x < sz(ones); ++x)
				for (int y = x + 1; y < sz(ones); ++y)
					++cnt1[ones[x]][ones[y]];
		}

		bool ok = 0;

		for (int x = 0; x < 5; ++x)
			for (int y = x + 1; y < 5; ++y) {
				int c1 = cnt[x], c2 = cnt[y], c3 = cnt1[x][y];
				if (c1 + c2 - c3 == n && c1 - c3 <= n / 2 && c2 - c3 <= n / 2) 
					ok = 1;
			}

		puts(ok ? "YES" : "NO");				
	}
}