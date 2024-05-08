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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



int n, m, cnt1, cnt2;

char c[M][M];

bool check(char s){
	return (s == '/' || s == '\\');
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) 
			cin >> c[i][j]; 

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(check(c[i][j])){
				cnt1++;
				continue;
			}

			bool ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;

			for(int j1 = j; j1 <= m; j1++){
				if(check(c[i][j1]))
					ok1 = 1;
			}                                 

			for(int j1 = j; j1 >= 1; j1--){
				if(check(c[i][j1]))
					ok2 = 1;
			}
			
			for(int i1 = i; i1 <= n; i1++){
				if(check(c[i1][j]))
					ok3 = 1;
			}         
			
			for(int i1 = i; i1 >= 1; i1--){
				if(check(c[i1][j]))
					ok4 = 1;
			}

			if(ok1 && ok2 && ok3 && ok4)
				cnt2++;

		}
	}

	assert(cnt1 % 2 == 0);
	cout << cnt1 / 2 + cnt2;

}

main () {
	//file("ascii");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                                      