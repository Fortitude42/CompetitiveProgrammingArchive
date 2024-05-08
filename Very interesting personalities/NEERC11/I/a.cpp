//by paradox & gege & parasat
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
const int N = 40, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, p[M], q[M], dp[M][M];

int calc() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (p[i] == q[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	

	return dp[n][n];
}


int ask(){
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
	cout << calc();
	int x;
	cin >> x;
	if(x == n) exit(0);
	return x;
} 

void solve() {
	cin >> n;
	
	q[1] = 9;
	q[2] = 5;
	q[3] = 3;
	q[4] = 8;
	q[5] = 7;
	q[6] = 1;
	q[7] = 4;
	q[8] = 2;

	int l = 1, r = n;
	set < int > vals;
	for (int i = 1; i <= n; ++i)
		vals.insert(i);

	while (l < r) {
		bool found = 0;
		for (auto i : vals)
			for (auto j : vals) {
				if (i >= j || found)
					continue;

				p[l] = i;
				p[r] = j;

				int x = 1;
				for (auto y : vals)
					if (y != i && y != j) {
						p[l + x] = y; 
						x++;
					}

				int r1 = ask();

				swap(p[l], p[r]);
				int r2 = ask();

				if (abs(r1 - r2) == 2) {
					if (r1 > r2) {
						p[l] = i;
						p[r] = j;
					} else {
						p[l] = j;
						p[r] = i;
					}

					found = 1;
				}
			}

		assert(found);

		vals.erase(p[l]);
		vals.erase(p[r]);
		l++, r--;
	}

	p[l] = *vals.begin(); 
	ask();

}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

