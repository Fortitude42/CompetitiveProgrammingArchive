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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
double a[M], pref[M][2], suff[M][2];
 
double f(int k, double t) {
	t = 1 - t;
	double mn = min(pref[k - 1][0], suff[k][0] * t);
	double mx = max(pref[k - 1][1], suff[k][1] * t);
	return fabs(mx - mn);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[i] = x;
	}

	pref[0][0] = inf;
	pref[0][1] = 0;
	
	for (int i = 1; i <= n; ++i) {
		pref[i][0] = min(a[i], pref[i - 1][0]);
		pref[i][1] = max(a[i], pref[i - 1][1]);
	}

	suff[n + 1][0] = inf;
	suff[n + 1][1] = 0;
	for (int i = n; i > 0; --i) {
		suff[i][0] = min(a[i], suff[i + 1][0]);
		suff[i][1] = max(a[i], suff[i + 1][1]);
	}
	

	for (int k = 1; k <= n; ++k) {
		double l = 0, r = 1, K = 100;
		while (K--) {
			double m1 = l + (r - l) / 3;
			double m2 = r - (r - l) / 3;
			if (f(k, m1) < f(k, m2))
				r = m2;
			else
				l = m1;
		}
		
		printf("%.11f ", r);
	}
}


main () {
	fastio
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}