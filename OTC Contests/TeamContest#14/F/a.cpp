#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e3 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, w, x[N], y[N], X, Y;
queue < pii > q;
pii p[N][2];


ldb dist (int i, int j) {
	return sqrt((x[i] - x[j]) * 1ll * (x[i] - x[j]) + (y[i] - y[j]) * 1ll * (y[i] - y[j]));
}

bool check (ldb d) {
	if (d*2 >= (ldb)w) {
		X = w;
		Y = 0;
		return 1;
	}


	for (int i = 1; i <= n; ++i)
		for (int j = 0; j 	< 2; ++j)
			p[i][j] = mp(-1, -1);

	for (int i = 1; i <= n; ++i) {
		if ((ldb)x[i] <= d) {
			p[i][0] = mp(-2, -2);
			q.push({i, 0});
		}

		if ((ldb)x[i] <= 2*d) {
			p[i][1] = mp(-2, -2);
			q.push({i, 1});
		}
	}

	while (sz(q)) {
		int v = q.front().f, i = q.front().s;
		q.pop();

		for (int u = 1; u <= n; ++u) {
			if (p[u][i].f == -1 && dist(u, v) <= d) {
				p[u][i] = mp(v, i);
				q.push(mp(u, i));
			}

			if (!i && p[u][1].f == -1 && dist(u, v) <= d*2) {
				p[u][1] = mp(v, i);
				q.push(mp(u, 1));
			}
		}
	}

	pii ans = {-1, -1};
	for (int i = 1; i <= n; ++i) {
		if (p[i][0].f != -1 && (ldb)(x[i] + 2*d) >= (ldb)w) {
			X = w + x[i];
			Y = y[i]*2;
			return 1;
		}

		if (p[i][1].f != -1 && (ldb)(x[i] + d) >= (ldb)w) {
			ans = mp(i, 1);
			break;
		}
	}


	if (ans.f == -1)
		return 0;

	while (1) {
		pii cur = p[ans.f][ans.s];
		if (cur.f == -2)
			break;

		if (cur.s != ans.s) {
			X = x[cur.f] + x[ans.f];
			Y = y[cur.f] + y[ans.f];
		}

		ans = cur;
	}

	if (ans.s == 1) {
		X = x[ans.f];
		Y = y[ans.f]*2;
	}

	return 1;
	
}

 
main () {
	fastio
//	file("froggy");
	cin >> w >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	

	ldb l = 0, r = inf, k = 50;
	while (k--) {
		ldb mid = (l + r) / 2;
//		cerr << mid << endl;
		if (check(mid)) 
			r = mid;
		else
			l = mid;
	}


	check(r);
	if (!X || X == w*2)
		X = 1;
	cout << fixed << setprecision(6);
	cout << (X + 0.0) / 2 << ' ' << (Y + 0.0) / 2 << endl;
}