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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int l[M], r[M];
int q, n[3], a[3][3][M];
ll t[M << 2], add[M << 2];
vector < pair < pii, int > > gg[M];

void push(int v, int tl, int tr, int tm) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		t[v << 1] += add[v] * (tm - tl + 1);
		t[v << 1 | 1] += add[v] * (tr - tm);

		add[v] = 0;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n[2]) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += (tr - tl + 1) * 1ll * x;
		add[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);

	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = t[v << 1] + t[v << 1 | 1];
}

ll get(int l, int r, int v = 1, int tl = 1, int tr = n[2]) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)	
		return t[v];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}
 
void solve() {
	for (int i = 0; i < 3; ++i)
		scanf("%d", &n[i]);

	scanf("%d", &q);
	while (q--) {
		int x, y, k, m;
		scanf("%d%d%d%d", &x, &k, &y, &m);
		--x, --y;

		a[x][y][k] = max(a[x][y][k], m - 1);
	}

	for (int x = 0; x < 3; ++x)
		for (int y = 0; y < 3; ++y)
			if (x != y)
				for (int i = 1; i <= n[x]; ++i)
					a[x][y][i] = max(a[x][y][i], a[x][y][i - 1]);

	int pref = n[2];
	for (int i = n[1]; i > 0; --i) {
		while (pref > 0 && a[2][1][pref] == i)
			--pref;

		//a[1][2][i] + 1, a[1][2][i] + 2, ..., pref
		l[i] = a[1][2][i] + 1;
		r[i] = pref;
	}


	ll ans = 0;
	pref = n[1];
	int pref1 = n[2];

	for (int i = n[0]; i > 0; --i) {
		while (pref > 0 && a[1][0][pref] == i)
			--pref;

		while (pref1 > 0 && a[2][0][pref1] == i)
			--pref1;
		
		if (a[0][1][i] + 1 <= pref) {
			gg[a[0][1][i]].pb({{a[0][2][i] + 1, pref1}, 0});
			gg[pref].pb({{a[0][2][i] + 1, pref1}, 1});
		}
	}

	for (int i = 1; i <= n[1]; ++i) {
		update(l[i], r[i], 1);
		for (auto x : gg[i]) {
			ll cur = get(x.f.f, x.f.s);
			ans += !x.s ? -cur : cur;
		}				
	}

	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}             