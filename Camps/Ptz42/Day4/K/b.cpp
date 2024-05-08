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
typedef double db;
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const db eps = 1e-4;

double n, m, l, L;
bool rev; 

db dist(db xa, db ya, db xb, db yb) {
	return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}


void solve() {
	n = m = 100;
	db addx = 0;
	bool skip = 0, rev = 0;
	vector < pair < db, db > > ans;
	ans.pb({0, 0});
	L = l;


	while (l > n + m) {
		if (!rev) {
			ans.pb({addx, m});
			ans.pb({addx + 1, m});
			l -= (m + 1);
		} else {
			if (l <= m + sqrt(n*n + m*m))
				break;
			
			ans.pb({addx, 0});
			l -= m;
			if (l <= 1 + sqrt((n - 1)*(n - 1) + m*m)) {
				db lf = 0, rg = 1, timer = 100;
				while (timer--) {
					db mid = (lf + rg) / 2;
					if (mid + sqrt((n - mid)*(n - mid) + m*m) <= l)
						lf = mid;
					else
						rg = mid;
				}

				ans.pb({addx + lf, 0});
				ans.pb({addx + n, m});
				skip = 1;
				break;
			}
			l--;
			ans.pb({addx + 1, 0});
		}

		rev ^= 1;
		n--;
		++addx;
	}

	db lf = 0, rg = m, timer = 100;
	while (timer--) {
		db mid = (lf + rg) / 2;
		if (!rev) {
			if (mid + dist(0, mid, n, m) <= l)
				lf = mid;
			else
				rg = mid;
		} else {
			if ((m - mid) + dist(0, mid, n, m) <= l)
				rg = mid;
			else
				lf = mid;
		}
	}
	
	if (!skip) {
		if (!rev) {
			if (lf > eps)
				ans.pb({addx, lf});
		} else {
			if (fabs(rg - m) > eps)
				ans.pb({addx, rg});
		}
	}

	if (!skip)
		ans.pb({n + addx, m});

	cout << sz(ans) << endl;
	cout << setprecision(6) << fixed;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;

	db res = 0;
	for (int i = 1; i < sz(ans); ++i)
		res += dist(ans[i].f, ans[i].s, ans[i - 1].f, ans[i - 1].s);


	if (!(fabs(res - L) < eps)) {
		cerr << fixed << setprecision(12);
		cerr << res << ' ' << L << endl;
		exit(0);
	}
	
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (double t = 1; t <= 100*100; ++t) {
		if (t < sqrt(100*100*2))
			continue;
		l = t;
		solve();
	}
}

