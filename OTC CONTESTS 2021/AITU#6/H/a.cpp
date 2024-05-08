//template by paradox & gege & parasat
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

int n, m, c[M];
double p[M][M], s[M][M];
 
void solve() {
	fastio

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		cin >> c[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			p[i][j] = (c[i] > c[j]);


	for (int j = 1; j <= m; ++j) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);

		for (int i = 1; i <= n; ++i) {
			if (i == a || i == b)
				continue;
			if (i < a)//i < a < b
				s[i][a] = s[i][b] = (p[i][a] + p[i][b]) / 2;
			else if (i < b)  {//a < i < b
				s[a][i] = (p[a][i] + 1 - p[i][b]) / 2;
				s[i][b] = (1 - p[a][i] + p[i][b]) / 2;
			} else //a < b < i
				s[a][i] = s[b][i] = (p[a][i] + p[b][i]) / 2;				
		}                                          

		p[a][b] = 0.5;
		for (int i = 1; i <= n; ++i) {
			if (i == a || i == b)
				continue;

			p[i][a] = s[i][a];
			p[i][b] = s[i][b];

			p[a][i] = s[a][i];
			p[b][i] = s[b][i];
		}			
	}

	double ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) { 
			ans += p[i][j];            
		}


	cout << fixed << setprecision(10);
	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}