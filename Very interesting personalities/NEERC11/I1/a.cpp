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


int n, p[M], q[M], pp[M], dp[M][M];
bool was[M];


int calc() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (p[i] == pp[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	

	return dp[n][n];
}

int ask(){
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	cout << endl;
//	cout << calc() << endl;
	int x;
	cin >> x;
	if(x == n) exit(0);
	return x;
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		p[i] = i;

	while (1) {
		int j = -1;
		for (int i = 1; i <= n; ++i)
			if (!was[p[i]]) {
				j = i;
				break;
			}

		if (j == -1)
			break;
		
		vi v;
		for (int i = 1; i <= n; ++i)
			if (i != j)
				v.pb(p[i]);		
		
		int mx = -1, cur = p[j];
		for (int x = -1; x < sz(v); ++x) {
			int i = 1;
			for (int y = 0; y <= x; ++y)
				p[i++] = v[y];

			p[i++] = cur;
			for (int y = x + 1; y < sz(v); ++y)
				p[i++] = v[y];

			int r = ask();
			if (r > mx) {
				mx = r;
				for (int i = 1; i <= n; ++i)
					q[i] = p[i];
			}
		}

		for (int i = 1; i <= n; ++i)
			p[i] = q[i];
		was[cur] = 1;
	}
}

main () {
//9 5 3 8 7 1 6 4 2

	pp[1] = 9;
	pp[2] = 5;
	pp[3] = 3;
	pp[4] = 8;
	pp[5] = 7;
	pp[6] = 1;
	pp[7] = 6;
	pp[8] = 4;
	pp[9] = 2;
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

