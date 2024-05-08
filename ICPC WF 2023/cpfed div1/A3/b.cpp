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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, k, v, x;
int a[M][M]; 
bool used[M];

int get() {
	memset(used, 0, sizeof used);
	int ans = 0, i = 1;
	while (1) {
		assert(i <= n);
		++ans;

		int j = 1;
		while (j <= k && used[a[i][j]])
			++j;

		assert(j <= k);	

		used[a[i][j]] = 1;

		if (a[i][j] == x)
			break;

		++i;
		if (i == n + 1)
			i = 1;
	}
	assert(ans <= k);

	return ans;
}

void solve(int tt) {
	scanf("%d%d", &n, &k);
	if (n == 0)  {
	    assert(k == 0);
		exit(0);
	}
			
	if (tt > 1)
		printf("\n");


	scanf("%d%d", &v, &x);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j) {
			scanf("%d", &a[i][j]);
			assert((i != v) ^ (a[i][j] == 0));
		}

	for (int i = 1; i <= k; ++i) {
		assert(!a[v][i]);
		a[v][i] = i;              
	}

	int ans = 0;
	do {
		ans = max(ans, get());
//		for (int i = 1; i <= k; ++i)
//			cerr << a[v][i] << ' ';
//		cerr << endl;
	} while (next_permutation(a[v] + 1, a[v] + k + 1));
	printf("Case #%d: Katya's place can be %d.", tt, k + 1 - ans);
}

main () {
  int TT;
  TT = inf;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve(tt);
  }
}