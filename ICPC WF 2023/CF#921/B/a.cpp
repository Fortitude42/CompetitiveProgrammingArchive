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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, m, Q, lz[M << 2], L[M << 2], R[M << 2];
pii a[M];
ll t[M << 2];

inline ll get(int x) {
	return x*1ll*(x + 1) / 2;
}

void build(int v = 1, int tl = 1, int tr = n) {
	t[v] = 0;
	lz[v] = 0;
	L[v] = R[v] = 0;
	if (tl == tr) 
		return;	

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void push(int v, int tl, int tr, int tm) {
	if (!lz[v])
		return;

	lz[v << 1] = lz[v];
	lz[v << 1 | 1] = lz[v];


	L[v << 1 | 1] = L[v];
	R[v << 1 | 1] = L[v << 1 | 1] + (tr - tm - 1);
	L[v << 1] = R[v << 1 | 1] + 1;
	R[v << 1] = R[v];


	t[v << 1] = (get(R[v << 1]) - get(L[v << 1] - 1))*lz[v << 1];
	t[v << 1 | 1] = (get(R[v << 1 | 1]) - get(L[v << 1 | 1] - 1))*lz[v << 1 | 1];


//	cerr << L[v << 1] << ' ' << R[v << 1] << ' ' << lz[v << 1] << ' ' << t[v << 1] << endl;
//	cerr << L[v << 1 | 1] << ' ' << R[v << 1 | 1] << ' ' << lz[v << 1 | 1] << ' ' << t[v << 1 | 1] << endl << endl;


	lz[v] = 0;
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		L[v] = r - tr;
		R[v] = L[v] + tr - tl;
		lz[v] = x;
		t[v] = (get(R[v]) - get(L[v] - 1))*lz[v];
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
}


ll get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r) 
		return t[v];
	

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}
 
void solve() {
	cin >> n >> m >> Q;

	set < pii > qq;
	for (int i = 1; i <= m; ++i)
		cin >> a[i].f;

	for (int i = 1; i <= m; ++i) {
		cin >> a[i].s;
		qq.insert(a[i]);
	}


	sort(a + 1, a + 1 + m);
	build();
	for (int i = 2; i <= m; ++i) {
		update(a[i - 1].f + 1, a[i].f, a[i - 1].s);
	}
	

	while (Q--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int x, v;
			cin >> x >> v;

			auto it = qq.lower_bound(mp(x, 0));
			pii nxt = *it;

			it--;
			pii prv = *it;

			update(prv.f + 1, x, prv.s);
			update(x + 1, nxt.f, v);

			qq.insert(mp(x, v));
		} else {
			int l, r;
			cin >> l >> r;
			cout << get(l, r) << "\n";
		}
	}
	
}

main () {
  int TT;
  TT = 1;
  fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}