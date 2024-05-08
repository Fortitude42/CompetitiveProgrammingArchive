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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const double EPS = 1e-15;

double ans[M];
int a[M], b[M], g[M];
 
void solve() {
	int n, A, B;
	scanf("%d %d %d", &n, &A, &B);

	double ansA = 0.0;
	double ansB = 0.0;
	vi ord;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &g[i], &a[i], &b[i]);
		if (!b[i]) {
			ansA += g[i] * a[i];
			ans[i] = g[i];
		} else
			ord.pb(i);
	}

	sort(all(ord), [&](const int i, const int j) {
		if (a[i] * b[j] != a[j] * b[i])
			return a[i] * b[j] > a[j] * b[i];
		return g[i] > g[j];
	});

	for (int i : ord) {
		double left = B - ansB;
		double canTake = (-EPS <= g[i] * b[i] - left ? left / b[i] : g[i]);
		ans[i] = canTake;
		ansA += canTake * a[i];
		ansB += canTake * b[i];
	}

	if (EPS < A - ansA) {
		printf("-1 -1\n");
		return;
	}
	printf("%.10lf %.10lf\n", ansA, ansB);
	for (int i = 1; i <= n; i++)
		printf("%.10lf ", ans[i]);
	printf("\n");
}

main () {
//	file("burrito");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}