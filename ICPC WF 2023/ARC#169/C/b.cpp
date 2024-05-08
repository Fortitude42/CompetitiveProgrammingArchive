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
const int N = 5000, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;


int n, tot, s[M];
int a[M], dp[M][M];


void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		 x += MOD;
}

 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];


	if (a[1] == -1) {
		for (int j = 1; j <= n; ++j) {
			dp[j][1] = 1;
			s[j] = 1;
			tot++;
		}

	} else {
		dp[a[1]][1] = 1;
		s[a[1]] = 1;
		tot = 1;
	}


	for (int i = 2; i <= n; ++i) {
		vi vals;
		if (a[i] != -1)
			vals.pb(a[i]);
		else {
			for (int j = 1; j <= n; ++j)
				vals.pb(j);
		}


		int toadd = 0;
		for (auto j : vals) {
			add(dp[j][i], tot - s[j]);			
			add(toadd, tot - s[j]);
			add(s[j], tot - s[j]);
		}

		add(tot, toadd);


		if (a[i] != -1) {
			for (int lst = 1; lst <= n; ++lst) {
				if (lst == a[i])
					continue;

				for (int st = 1; st <= n; ++st) {
					add(tot, -dp[lst][st]);
					add(s[lst], -dp[lst][st]);
					cerr << "-----> " << -dp[lst][st] << endl;
					dp[lst][st] = 0;
				}
			}
		}


		for (int lst = 1; lst <= n; ++lst) {
			int st = i - lst;
			if (st < 0)
				continue;
			cerr << "--> " << lst << ' ' << st << ' ' << -dp[lst][st] << endl;
			add(tot, -dp[lst][st]);
			add(s[lst], -dp[lst][st]);
			dp[lst][st] = 0;
		}

		cerr << tot << endl;
	}

	cout << tot << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}