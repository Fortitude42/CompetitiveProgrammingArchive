//template by paradox & gege & parasat
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

int n, a[M], q, pref[M], add[M << 2];
pii t[M << 2];
string s;

void build(int v = 1, int tl = 1, int tr = n) {
	add[v] = 0;
	if (tl == tr) {
	    t[v] = mp(a[tl], tl);
		return; 
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void push(int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		t[v << 1].f += add[v];
		t[v << 1 | 1].f += add[v];

		add[v] = 0;
	}
}

void del(int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = mp(-inf, -1);
		add[v] = 0;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		del(pos, v << 1, tl, tm);
	else
		del(pos, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v].f += x;
		add[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v);

	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

pii get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return mp(-1, -1);

	if (l <= tl && tr <= r)
		return t[v];

	push(v);
	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i]; 
		pref[i] = pref[i - 1] + (a[i] <= q);
	}
	
	pii ans = mp(pref[n], n + 1);

	int cnt = 0;
	build();
	for (int i = n; i > 0; --i) {
		while (1) {
			pii x = get(i, n);
			if (x.f <= q)
				break;

			del(x.s);
			update(x.s + 1, n, 1);
			cnt++;
		}

		if (q < cnt)
			break;

		ans = max(ans, mp(pref[i - 1] + (n - i + 1), i));
	}

	for (int i = 1; i < ans.s; ++i)
		cout << (a[i] <= q);

	for (int i = ans.s; i <= n; ++i)
		cout << 1;

	cout << endl;
}

main () {
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}