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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 2e4 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int n, q, a[N][12], b[N][12], tp[N], xa[N], xb[N], ya[N], yb[N];
vi vals;

struct Matrix {
	int m[12][12];
	Matrix () {
		memset(m, 0, sizeof(m));
	}
} t[N << 3];

Matrix merge (const Matrix &A, const Matrix &B, const int &tm) {
	Matrix res;
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			res.m[x][y] = inf;

	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			for (int z = 1; z <= n; ++z)
				res.m[x][y] = min(res.m[x][y], A.m[x][z] + b[tm][z] + B.m[z][y]);

	return res;
}

void build (int v = 1, int tl = 0, int tr = q + q) {
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			if (x != y)
				t[v].m[x][y] = inf;
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void update (int i, int v = 1, int tl = 0, int tr = q + q) {
	if (tl == tr) {
		if (tp[i] == 1) {
			for (int x = 1; x <= n; ++x)
				for (int y = 1; y <= n; ++y)
					t[v].m[x][y] = abs(a[i][x] - a[i][y]);
/*			for (int i = 1; i <= n; ++i, cerr << endl)
				for (int j = 1; j <= n; ++j)
					cerr << t[v].m[i][j] << ' ';

			cerr << "***********************************" << endl;*/
		}
		return;
	}

	int tm = (tl + tr) >> 1;
	if (xa[i] <= tm)
		update(i, v << 1, tl, tm);
	else
		update(i, v << 1 | 1, tm + 1, tr);	
	
	t[v] = merge(t[v << 1], t[v << 1 | 1], tm); 
	
	if (v == 2) {                                  
//		for (int x = 1; x <= n; ++x, cerr << endl)
//			for (int y = 1; y <= n; ++y)
//				cerr << t[v].m[x][y] << ' ';
	}
}

Matrix get (int l, int r, int v = 1, int tl = 0, int tr = q + q) {
	if (l > r || tl > r || l > tr)
		return Matrix();
	
	if (l <= tl && tr <= r) 
		return t[v];

	int tm = (tl + tr) >> 1;
/*	Matrix a = get(l, r, v << 1, tl, tm);
	Matrix b = get(l, r, v << 1 | 1, tm + 1, tr);
	int tt = (r > tm ? tm : N - 1);
	Matrix c = merge(a, b, tt);

	cerr << "*****************************" << v << ' '<< tl << ' ' << tr << ' ' << tm << endl;
	for (int x = 1; x <= n; ++x, cerr << endl)
		for (int y = 1; y <= n; ++y)
			cerr << a.m[x][y] << ' ';

	cerr << endl;				
	for (int x = 1; x <= n; ++x, cerr << endl)
		for (int y = 1; y <= n; ++y)
			cerr << b.m[x][y] << ' ';
	cerr << endl;

	for (int x = 1; x <= n; ++x, cerr << endl)
		for (int y = 1; y <= n; ++y)
			cerr << c.m[x][y] << ' ';

	cerr << tt << endl;*/

	if (l > tm)
		return get(l, r, v << 1 | 1, tm + 1, tr);

	if (r <= tm)
		return get(l, r, v << 1, tl, tm);

	return merge(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr), tm);
}


main () {
//	for (int i = 0; i < N; ++i)
//		for (int j = 0; j < 12; ++j)
//			b[i][j] = inf;

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d", &tp[i]);
		if (tp[i] == 1) {
			scanf("%d", &xa[i]);
			vals.pb(xa[i]);
			for (int j = 2; j <= n; ++j) {
				scanf("%d", &a[i][j]);
				a[i][j] += a[i][j - 1];
			}
		}

		if (tp[i] == 2) {
			scanf("%d", &xa[i]);
			vals.pb(xa[i]);
			for (int j = 1; j <= n; ++j)
				scanf("%d", &a[i][j]);
		}

		if (tp[i] == 3) {
			scanf("%d%d%d%d", &xa[i], &ya[i], &xb[i], &yb[i]);
			vals.pb(xa[i]);
			vals.pb(xb[i]);
		}
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());


	build();
	for (int i = 1; i <= q; ++i) {
		xa[i] = lower_bound(all(vals), xa[i]) - vals.begin();
		if (tp[i] == 1) 
			update(i);
		
		if (tp[i] == 2) {
			for (int j = 1; j <= n; ++j)
				b[xa[i]][j] = a[i][j];
			update(i);
		} 
		
		if (tp[i] == 3) {
			xb[i] = lower_bound(all(vals), xb[i]) - vals.begin();
			int res = get(xa[i], xb[i]).m[ya[i]][yb[i]];
//			Matrix M = get(xa[i], xb[i]);

			if (res == inf || xa[i] > xb[i])
				res = -1;
			printf("%d\n", res);
		}
	}

}