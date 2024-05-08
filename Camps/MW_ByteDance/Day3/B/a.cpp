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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e4 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int T, t, L, a[N], l[20], r[20]; 
vi lvl[20];


void rec (int lf, int rg, int j) {
	if (!j) {
		for (int i = lf; i <= rg; ++i)
			lvl[j].pb(a[i]);
		lvl[j].pb(-1);
		return;
	}

	int n = rg - lf + 1;

	int T1 = -1;
	for (int TT = T - 1; TT <= 2*T - 1; ++TT) {
		if (l[j - 1] * (TT + 1) <= n - TT && n - TT <= r[j - 1] * (TT + 1)) {
			T1 = TT + 1;
			break;
		}
	}

	assert(T1 != -1);	
	int m = n - T1 + 1;
	while (T1) {
		int x = min(r[j - 1], m - (T1 - 1) * l[j - 1]);
		rec(lf, lf + x - 1, j - 1);
		if (T1 > 1)
			lvl[j].pb(a[lf + x]);
		lf += x + 1;
		T1--;
		m -= x;
	}

	lvl[j].pb(-1);
}

main () {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		for (int j = 0; j < 20; ++j)
			lvl[j].clear();

		printf("Case %d:\n", tt);

		scanf("%d%d", &T, &L);
		for (int i = 1; i <= L; ++i)
			scanf("%d", &a[i]);

		sort(a + 1, a + 1 + L);
		l[0] = T - 1, r[0] = 2*T - 1;

		int jj = -1;
		for (int j = 1; ; ++j) {
			l[j] = l[j - 1] * T + T - 1;
			r[j] = min(L, r[j - 1] * 2*T + 2*T - 1);
			if (l[j] > L) {
			    jj = j;
				break;     
			}
		}
		
		int J = -1;
		for (int j = 0; j < jj; ++j) 
			if (l[j] <= L && L <= r[j]) {
				J = j;
				break;
			}


		cerr << L << ' ' << J << endl;		
		if (J == -1) {
			printf("INVALID\n");
			continue;
		}


		rec(1, L, J);
		for (int j = J; j >= 0; --j, printf("\n"))
			for (auto x : lvl[j])
				if (x == -1)
					printf(";");
				else {
					if (x != lvl[j][0])
						printf(" ");
					printf("%d", x);
				}
	}
}