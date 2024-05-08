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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int t, n, m;
vi a[N], p[N][4];

 
main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			a[i].resize(m + 1);
			for (int j = 0; j < 4; ++j)
				p[i][j].resize(m + 1);

			for (int j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);     
				p[i][0][j] = min(j == 1 ? inf : p[i][0][j - 1], a[i][j]);
				p[i][1][j] = max(p[i][1][j - 1], a[i][j]);
			}

			for (int j = m; j > 0; --j) {
				p[i][2][j] = min(j == m ? inf : p[i][2][j + 1], a[i][j]);
				p[i][3][j] = max(j == m ? -inf : p[i][3][j + 1], a[i][j]);
			}
		}


		int kk = -1;
		string ans;

		for (int k = 1; k < m; ++k) {
			vector < pair < pair < pii, pii >, int > > v;
			for (int i = 1; i <= n; ++i) 
				v.pb({{{p[i][0][k], p[i][1][k]}, {p[i][2][k + 1], p[i][3][k + 1]}}, i});

			sort(all(v));

			for (int i = 1; i < sz(v); ++i) {
				v[i].f.f.s = max(v[i - 1].f.f.s, v[i].f.f.s);
				v[i].f.s.f = min(v[i - 1].f.s.f, v[i].f.s.f);
			}

			for (int i = sz(v) - 2; i >= 0; --i) {
				v[i].f.f.f = min(v[i + 1].f.f.f, v[i].f.f.f);
				v[i].f.s.s = max(v[i + 1].f.s.s, v[i].f.s.s);
			}

			for (int i = 0; i < sz(v) - 1; i++) {
				if (v[i + 1].f.f.f > v[i].f.f.s && v[i].f.s.f > v[i + 1].f.s.s) {
					kk = k;
					ans.resize(n, 'R');
					for (int j = 0; j <= i; ++j)
						ans[v[j].s - 1] = 'B';
					break;
				}
			}

			if (kk != -1)
				break;
		}

		if (kk == -1) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (auto c : ans)
			printf("%c", c);
		printf(" %d\n", kk);
	}
}