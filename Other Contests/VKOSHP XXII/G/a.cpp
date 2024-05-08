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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const double eps = 1e-9;

pii f[4]; 
int p[4];
double q[4];

void solve() {
	for (int i = 0; i < 4; ++i) {
		cin >> f[i].f;            
		f[i].s = i;
	}

	sort(f, f + 4);
	double ans = 0;

	do {
		double a = f[0].f, b = f[1].f, x = f[2].f;
		double y;

		if (x == 1)
			y = f[3].f;
		else
			y = (a*b + x - a - b) / (x - 1);

		if (fabs(a*b - a - b - x*y + x + y) >= eps || y > f[3].f)
			continue;

		double cur = a*b + x + y;
		if (cur > ans) {
			ans = cur;
			p[0] = f[0].s;
			p[3] = f[1].s;
			p[1] = f[2].s;
			p[2] = f[3].s;
		
			q[0] = a;
			q[3] = b;
			q[1] = x;
			q[2] = y;
		}		
	} while (next_permutation(f, f + 4));

	for (int i = 0; i < 4; ++i)
		cout << p[i] + 1 << ' ';
	cout << endl;
	cout << fixed << setprecision(10);
	for (int i = 0; i < 4; ++i)
		cout << q[i] << ' ';
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}