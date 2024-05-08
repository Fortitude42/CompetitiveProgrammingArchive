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
const int N = 2e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

pii b[M*M];
int xa, ya, xb, yb;
pair < int, pii > vals[M*M];
pair < pii, pii > t[M*M << 2];
int col[M][M], l[M*M], r[M*M]; 
int n, m, q, k, sz, a[M][M], pos[M][M];

 
bool in(int x, int y) {
	return x >= xa && y >= ya && x <= xb && y <= yb;
}

void update(int pos, pii x, int v = 1, int tl = 1, int tr = n*m) {
	if (tl == tr) {
		t[v] = {x, x};
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, x, v << 1, tl, tm);
	else
		update(pos, x, v << 1 | 1, tm + 1, tr);

	t[v].f.f = min(t[v << 1].f.f, t[v << 1 | 1].f.f);
	t[v].f.s = min(t[v << 1].f.s, t[v << 1 | 1].f.s);
	t[v].s.f = max(t[v << 1].s.f, t[v << 1 | 1].s.f);
	t[v].s.s = max(t[v << 1].s.s, t[v << 1 | 1].s.s);
}

bool check(int v) {
	return in(t[v].f.f, t[v].f.s) && in(t[v].s.f, t[v].s.s);
}

int getPrefix(int l, int r, int v = 1, int tl = 1, int tr = n*m) {
	if (l > r || tl > r || l > tr || check(v))
		return n + 1;

	if (tl == tr)
		return tl;

	int tm = (tl + tr) >> 1;
	if (l <= tl && tr <= r) {
		if (check(v << 1))
			return getPrefix(l, r, v << 1 | 1, tm + 1, tr);
		return getPrefix(l, r, v << 1, tl, tm);
	}
	int a = getPrefix(l, r, v << 1, tl, tm);
	return a == (n + 1) ? getPrefix(l, r, v << 1 | 1, tm + 1, tr) : a;
}

int getSuffix(int l, int r, int v = 1, int tl = 1, int tr = n*m) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (check(v))
		return tl;

	if (tl == tr)
		return -1;
		
	int tm = (tl + tr) >> 1;
	if (l <= tl && tr <= r) {
		if (check(v << 1 | 1))
			return getSuffix(l, r, v << 1, tl, tm);
		return getSuffix(l, r, v << 1 | 1, tm + 1, tr);
	}

	int a = getSuffix(l, r, v << 1 | 1, tm + 1, tr);
	return !a ? getSuffix(l, r, v << 1, tl, tm) : a;
}


void solve() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]); 
			vals[(i - 1)*m + j - 1] = {a[i][j], {i, j}};
		}

	sort(vals, vals + n*m - 1);

	xa = 1, ya = 1, xb = n, yb = m;
	for (int i = 0; i < n*m; ++i) {
	    int x = vals[i].s.f, y = vals[i].s.s;
		if (col[x][y])
			continue;

		col[x][y] = ++k;
	    pos[x][y] = ++sz;
	    update(sz, {x, y});
//		cout << x << ' ' << y << endl;
		l[k] = sz;		

	    while (1) {	    	
			int xx = -1, yy = -1;
			for (int i = 0; i < 4; ++i) {
				int tox = x + dx[i], toy = y + dy[i];
				if (in(tox, toy) && a[tox][toy] == a[x][y] + 1) {
					xx = tox;
					yy = toy;
					break;
				}
			}

			if (xx == -1)
				break;

			x = xx, y = yy;
			col[x][y] = k;
			pos[x][y] = ++sz;
			update(sz, {x, y});
//			cout << x << ' ' << y << endl;
	    }
	    r[k] = sz;
	}	

	while (q--) {
		scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
		int k = col[xa][ya];
		cerr << getSuffix(1, r[k]) << endl;
/*		int lf = max(l[k], getSuffix(1, r[k]) + 1);
		int rg = min(r[k], getPrefix(l[k], n) - 1);
		
		puts((rg - lf + 1) == (xb - xa + 1) * (yb - ya + 1) ? "YES" : "NO");*/
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

