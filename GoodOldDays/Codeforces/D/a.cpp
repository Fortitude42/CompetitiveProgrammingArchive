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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, q, t[N << 2], add[N << 2], xa, ya, xb, yb, a, b;
map < int, int > was[N];
vpii addx[N], addy[N];
ll ans;

void push (int v, int tl, int tr, int tm) {
	if (add[v]) {
		add[v << 1] ^= 1;
		add[v << 1 | 1] ^= 1;
		t[v << 1] = (tm - tl + 1) - t[v << 1];
		t[v << 1 | 1] = (tr - tm) - t[v << 1 | 1];
		add[v] = 0;
	}
}

void update (int l, int r, int v = 1, int tl = 1, int tr = N - 1) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v] = (tr - tl + 1) - t[v];
		add[v] ^= 1;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	update(l, r, v << 1, tl, tm);
	update(l, r, v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
}

void rec (int a, int b) {
	if (was[a].count(b)) {
		cout << -1;
		exit(0);
	}

	was[a][b] = 1;
	ll c = a*1ll*(m - b) + b*1ll*(n - a); 

	if (!c)
		return;

	ans += c;
	int aa = 0, bb = 0;
	if (b & 1)
		aa += n - a;
	if ((m - b) & 1)
		aa += a;

	if (a & 1)
		bb += n - b;
	if ((n - a) & 1)
		bb += b;

	rec(aa, bb);
}

main () {
	fastio
	cin >> n >> m >> q;
	while (q--) {
		cin >> xa >> ya >> xb >> yb;
		addx[xa].pb({ya, yb});	
		addx[xb + 1].pb({ya, yb});
		addy[ya].pb({xa, xb});
		addy[yb + 1].pb({xa, xb});
	}

	for (int i = 1; i <= n; ++i) {
		for (auto x : addx[i])
			update(x.f, x.s);

		ans += t[1];
		if (t[1] & 1)
			++a;
	}

	memset(t, 0, sizeof(t));
	memset(add, 0, sizeof(add));
	for (int i = 1; i <= m; ++i) {
		for (auto x : addy[i])
			update(x.f, x.s);
		if (t[1] & 1)
			++b;
	}
//	cerr << a << ' ' << b << endl;

	rec(a, b);
	cout << ans << endl;
}