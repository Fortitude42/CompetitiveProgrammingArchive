#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
//#define int long long 
#pragma GCC optimize("Ofast")

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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e4 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;



int dp[N][2][2], n, q, a[N], was[N][2][2], timer, X, nn;
char s[N];


void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}


int calc (int i = 0, int lst = 0, int j = 0) {
	if (i == nn) 
		return 1;

	int &res = dp[i][lst][j];
	if (was[i][lst][j] == timer)
		return res;

	was[i][lst][j] = timer;
		
	int c = 9;
	if (!j)
		c = s[i + X] - '0';

	res = 0;
	if (j) {		
		res = calc(i + 1, 1, 1);
		if (lst)
			add(res, calc(i + 1, 0, 1)*8ll%mod);
		else
			add(res, calc(i + 1, 0, 1)*9ll%mod);			
		return res;
	}

	for (int cc = 0; cc <= c; ++cc) {
		if (lst && cc == 3)
			continue;
		add(res, calc(i + 1, (cc == 1), (cc < (s[i + X] - '0'))));
	}

	return res;
}

int type, l, r;


main () {
	fastio

	scanf("%d%d", &n, &q);
	scanf("\n%s", s);
	for (int i = 1; i <= n; ++i)
		a[i] = s[i - 1] - '0';

	memset(dp, -1, sizeof(dp));
	++timer;
	nn = n, X = 0;
	printf("%d\n", calc());

	while (q--) {
		scanf("%d%d%d", &type, &l, &r);
		--l;
		++timer;

		if (type == 1) {
			--r;
			nn = r - l + 1;
			X = l;
			printf("%d\n", calc());
		} else 
			s[l] = '0' + r;		

	}
}
