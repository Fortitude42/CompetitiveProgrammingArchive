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

vi pos[M];
pii ans[M];
int n, k, m, c[M];
int t[M << 2], add[M << 2];


void push(int v) {
	if (add[v]) {
		add[v << 1] += add[v];
		t[v << 1] += add[v];

		add[v << 1 | 1] += add[v];
		t[v << 1 | 1] += add[v];

		add[v] = 0;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = m) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		add[v] += x;
		return;
	}

	push(v);	                                   	
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int l, int r, int v = 1, int tl = 1, int tr = m) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	push(v);	
	int tm = (tl + tr) >> 1;
	return max(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

 
void solve() {
	cin >> n >> k;
	m = n*k;
	for (int i = 1; i <= m; ++i) {
		cin >> c[i]; 
		pos[c[i]].pb(i);
	}

	set < pii > q;
	for (int i = 1; i <= n; ++i) {
		reverse(all(pos[i])); 
//		cerr << sz(pos[i]) << ' ' << pos[i][sz(pos[i]) - 2] << endl;
		q.insert(mp(pos[i][sz(pos[i]) - 2], i));
	}
		

	while (sz(q)) {
		int i = q.begin()->s;
		q.erase(q.begin());

		int l = pos[i].back();
		int r = pos[i][sz(pos[i]) - 2];
//		cerr << l << ' ' << r << endl;
	
		if (get(l, r) == (n + k - 2) / (k - 1)) {
//			cerr << i << ' ' << sz(pos[i]) << endl;
			pos[i].ppb();
			assert(sz(pos[i]) >= 2);
			q.insert(mp(pos[i][sz(pos[i]) - 2], i));
			continue;
		}

		update(l, r, 1);
		ans[i] = mp(l, r);
	}

	for (int i = 1; i <= n; ++i)
		cout << ans[i].f << ' ' << ans[i].s << endl;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}