#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
//#define int long long 
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int t, x, y, p[N];
bool stop;
bitset < N > dp;
int c[] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000,20000}, cc[15], res[15];

void rec (int i = 0, int sum = 0) {
	if (stop)
		return;	

	if (i == 14) {
		if (x != sum)
			return;

		for (int j = 0; j <= y; ++j)
			dp[j] = 0;

		dp[0] = 1;

		for (int j = 0; j < 14; ++j)
			for (int x = 0; x < cc[j]; ++x) 
				dp |= (dp << c[j]);
			
		

/*		if (y == 10 && cc[1] == 3 && cc[2] == 1) {
			for (int i = 0; i <= y; ++i)
				cerr << dp[i] << ' ';
			cerr << endl;
		}*/
		if (!dp[y]) {
			stop = 1;
			for (int j = 0; j < 14; ++j)
				res[j] = cc[j];			
		}
		return;
	}

	if ((x < sum && x + c[i] > sum))
		return;

	int z = 2;
	if (i % 3 == 1)
		z = 5;

	for (int j = 0; j < z; ++j) {
		if (sum + j*c[i] > x)
			break;

		cc[i] = j;
		rec(i + 1, sum + j*c[i]);

		if (stop)
			return;
	}
}

main () {
	cin >> t;
	while (t--) {
		cin >> x >> y;
		stop = 0;
		rec();
		if (!stop) {
			printf("YES\n");
			continue;
		} 

		printf("NO\n");
		for (int i = 0; i < 14; ++i)
			printf("%d ", res[i]);
		printf("\n");
	}
}