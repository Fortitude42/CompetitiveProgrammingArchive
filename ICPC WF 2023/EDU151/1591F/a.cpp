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
const int N = 2e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, L[M*30], R[M*30], t[M*30], lzm[M*30], lza[M*30], Sz;
int a[M];

void nw(int v) {
	if (!L[v]) {
		L[v] = ++Sz;
		lzm[Sz] = 1;
	}

	if (!R[v]) {
		R[v] = ++Sz;
		lzm[Sz] = 1;
	}
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void push(int v, int tl, int tr, int tm) {
	nw(v);
	if (lzm[v] != 1) {

		lzm[L[v]] = lzm[L[v]] * 1ll * lzm[v] % MOD;
		lza[L[v]] = lza[L[v]] * 1ll * lzm[v] % MOD;
		t[L[v]] = t[L[v]] * 1ll * lzm[v] % MOD;
		
		lzm[R[v]] = lzm[R[v]] * 1ll * lzm[v] % MOD;
		lza[R[v]] = lza[R[v]] * 1ll * lzm[v] % MOD;
		t[R[v]] = t[R[v]] * 1ll * lzm[v] % MOD;

		lzm[v] = 1;
	}

	if (lza[v] > 0) {
		add(lza[L[v]], lza[v]);
		add(t[L[v]], lza[v]*1ll*(tm - tl + 1) % MOD);

		add(lza[R[v]], lza[v]);
		add(t[R[v]], lza[v]*1ll*(tr - tm) % MOD);

		lza[v] = 0;
	}
}

void mult(int l, int r, int x, int v = 1, int tl = 1, int tr = inf) {
	if (l > r || tl > r || l > tr)
		return;


	if (l <= tl && tr <= r) {
		t[v] = t[v] * 1ll * x % MOD;
		lzm[v] = lzm[v] * 1ll * x % MOD;
		lza[v] = lza[v] * 1ll * x % MOD;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	mult(l, r, x, L[v], tl, tm);
	mult(l, r, x, R[v], tm + 1, tr);
	t[v] = t[L[v]] + t[R[v]];
	if (t[v] >= MOD)
		t[v] -= MOD;
}

void add(int l, int r, int x, int v = 1, int tl = 1, int tr = inf) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] = (t[v] + x*1ll*(tr - tl + 1)) % MOD;
		add(lza[v], x);
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	add(l, r, x, L[v], tl, tm);
	add(l, r, x, R[v], tm + 1, tr);
	t[v] = t[L[v]] + t[R[v]];
	if (t[v] >= MOD)
		t[v] -= MOD;
}

 
void solve() {
	//m[v] = 1
	//add[v] = 0
	//s[v] = 0
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	Sz = 1;
	lzm[1] = 1;
	nw(1);

	add(1, a[1], 1);
	for (int i = 2; i <= n; ++i) {
		int s = t[1];
		mult(1, a[i], MOD - 1);
		mult(a[i] + 1, inf, 0);
		add(1, a[i], s);
	}

	cout << t[1] << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}