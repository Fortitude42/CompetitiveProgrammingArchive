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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, k, a[N], cnt[18][N], mn, sum, p[N], b[N], tmp[N];

void add (int &x, int y) {
	x += y;

	if (x >= mod)
		x -= mod;

	if (x < 0)
		x += mod;
}

int get (int n) {
	for (int k = 0; ; ++k)
		if ((1 << k) > n)
			return k;
}

void rec (int i = 1, int lst = 0, int rest = n, int cur = 0) {
	if (rest == 1) {
//		cerr << "--> " << lst << endl;
		mn = min(mn, cur + (a[lst] < i));
		return;
	}


	rec(i + 1, lst + (1 << (i - 1)), rest / 2, cur + (rest + 1) / 2 - cnt[i][lst]);//even

	rec(i + 1, lst, (rest + 1) / 2, cur + rest / 2 - cnt[i][lst + (1 << (i - 1))]);//odd
}

void build () {
	int j = 1;
	for (int i = 0; i < n; ++i) {
		if (!b[i]) 
			b[i] = j++;

		if (i + (1 << b[i]) < n)
			b[i + (1 << b[i])] = b[i];
	}
}


main () {
	p[0] = 1;
	for (int i = 1; i < N; ++i)
		p[i] = p[i - 1]*2 % mod;

	while (scanf("%d%d", &n, &m) == 2) {
		k = get(n);

		for (int i = 0; i <= k; ++i)
			for (int j = 0; j < (1 << i); ++j)
				cnt[i][j] = 0;

		for (int i = 0; i < n; ++i)
			b[i] = 0;
		mn = inf, sum = 0;


		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);      
			if (a[i] <= k) 
				++cnt[a[i]][i % (1 << a[i])];						
		}

		rec();
		
		for (int i = 0; i < n; ++i) {
			add(sum, p[m] - 1 - (n - 1));
			add(sum, -p[m - a[i]]);
		}

		build();

		for (int i = 0; i < n; ++i)
			tmp[a[i]] = 0;
			
		for (int i = 0; i < n; ++i)  {
			add(sum, tmp[a[i]]);      
			tmp[b[i]]++;
		}

		reverse(b, b + n);
		
		for (int i = 0; i < n; ++i)
			tmp[a[i]] = 0;

		for (int i = n - 1; i >= 0; --i) {
			add(sum, tmp[a[i]]);
			tmp[b[i]]++;
		}

		printf("%d %d\n", mn, sum);
//		cerr << mn << ' ' << sum << endl;
	}
}