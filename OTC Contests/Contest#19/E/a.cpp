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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

struct Matrix {
	int a[2][2];
	Matrix () {	
		memset(a, 0, sizeof(a));
	}

	Matrix (int i, int j, int x, int y) {
		a[0][0] = i;
		a[0][1] = j;
		a[1][0] = x;
		a[1][1] = y;
	}

	Matrix operator * (const Matrix &m) {
		Matrix res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k) 
					res.a[i][j] = (res.a[i][j] + a[i][k] * 1ll * m.a[k][j]) % mod;

		return res;
	}
};

void write (Matrix M) {
		for (int i = 0; i < 2; ++i, printf("\n"))
			for (int j = 0; j < 2; ++j)
				printf("%d ", M.a[i][j]);
	printf("\n");
}

const Matrix ZERO = Matrix(1, 0, 0, 1);
Matrix t[N << 2][2];
int a[N][4], n, q;

void build (int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v][0] = Matrix(a[tl][0], a[tl][2], a[tl][1], a[tl][3]);
		t[v][1] = Matrix(a[tl][0], a[tl][2], a[tl][1], a[tl][3]);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v][0] = t[v << 1][0] * t[v << 1 | 1][0];
	t[v][1] = t[v << 1 | 1][1] * t[v << 1][1];
}

Matrix get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return ZERO;

	if (l <= tl && tr <= r)
		return t[v][0];

	int tm = (tl + tr) >> 1;
//	Matrix a = get(l, r, v << 1, tl, tm);
//	Matrix b = (get(l, r, v << 1 | 1, tm + 1, tr));
//	write(get(l, r, v << 1, tl, tm));
//	write(get(l, r, v << 1 | 1, tm + 1, tr));
//	write(get(l, r, v << 1, tl, tm) * get(l, r, v << 1 | 1, tm + 1, tr));
//	printf("\n\n\n\n");
//	write(a);
//	write(b);
//	write(a*b);
//	printf("\n");
//	return a*b;

	return get(l, r, v << 1, tl, tm) * get(l, r, v << 1 | 1, tm + 1, tr);
}

Matrix get1 (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return ZERO;

	if (l <= tl && tr <= r)
		return t[v][1];

	int tm = (tl + tr) >> 1;
//	Matrix a = get(l, r, v << 1, tl, tm);
//	Matrix b = (get(l, r, v << 1 | 1, tm + 1, tr));
//	write(get(l, r, v << 1, tl, tm));
//	write(get(l, r, v << 1 | 1, tm + 1, tr));
//	write(get(l, r, v << 1, tl, tm) * get(l, r, v << 1 | 1, tm + 1, tr));
//	printf("\n\n\n\n");
//	write(a);
//	write(b);
//	write(a*b);
//	printf("\n");
//	return a*b;

	return get1(l, r, v << 1 | 1, tm + 1, tr) * get1(l, r, v << 1, tl, tm);

}



 
main () {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 4; ++j)
			scanf("%d", &a[i][j]);

	build();
	while (q--) {
		int l, r, key, value;
		scanf("%d%d%d%d", &key, &value, &l, &r);
		Matrix res = Matrix(key, value, 0, 0);

		if (l > r) {
			swap(l, r); 
			res = res * get1(l, r);
		} else
			res = res * get(l, r);


//		write(res);
		printf("%d %d\n", res.a[0][0], res.a[0][1]);
	}
}