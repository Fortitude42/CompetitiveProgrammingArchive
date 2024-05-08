//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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

vector < pair < int, ll > > vv;
int n, q, a[M], b[M], c[M];
ll s[M], tt[M << 2];

struct node {
	ll mns, mxs;
	node() {}

	node(ll mnS, ll mxS) {
		mns = mnS;
		mxs = mxS;
	}
} t[M << 2];

node merge(const node &a, const node &b) {
	return node(min(a.mns, b.mns), max(a.mxs, b.mxs));
}

void build(int v = 1, int tl = 0, int tr = n) {
	if (tl == tr) {
		t[v] = node(s[tl], s[tl]);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = merge(t[v << 1], t[v << 1 | 1]);
} 

node get(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if (l > r || tl > r || l > tr)
		return node(inf, -inf);

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	return merge(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}

void build1(int v = 1, int tl = 0, int tr = sz(vv) - 1) {
	if (tl == tr) {
		tt[v] = vv[tl].s;
		return;
	}

	int tm = (tl + tr) >> 1;
	build1(v << 1, tl, tm);
	build1(v << 1 | 1, tm + 1, tr);
	tt[v] = max(tt[v << 1], tt[v << 1 | 1]);
}

ll get1(int l, int r, int v = 1, int tl = 0, int tr = sz(vv) - 1) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return tt[v];

	int tm = (tl + tr) >> 1;
	return max(get1(l, r, v << 1, tl, tm), get1(l, r, v << 1 | 1, tm + 1, tr));
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i]; 
		c[i] = b[i] - a[i];
//		c[i] = a[i] - b[i];
		s[i] = s[i - 1] + c[i];
//		cerr << c[i] << ' ' << s[i] << endl;
	}
	for (int i = 1; i <= n;) {
		ll sum = 0;
		int j = i;

		if (c[i] <= 0) {
			while (i <= n && c[i] <= 0)
				sum -= c[i++];			
		} else {
			while (i <= n && c[i] >= 0)
				sum += c[i++];
		}
		vv.pb({j, sum});
	}


	
	build();
	build1();
//	q = 1;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (s[r] != s[l - 1]) {
			cout << -1 << endl;
			continue;
		}

		node cur = get(l, r);
		if (cur.mxs < s[l - 1] || ) {
			cout << -1 << endl;
			continue;
		}        

		int l1 = upper_bound(all(vv), mp(l, INF)) - vv.begin();
		int r1 = lower_bound(all(vv), mp(r, INF)) - vv.begin() - 1;

		ll ans = get1(l1, r1 - 1);
		assert(l1 > 0);
		
		int rg = min(r, vv[l1].f - 1);
		assert(rg >= l);
		ans = max(ans, abs(s[rg] - s[l - 1]));
		
		int lf = max(l, vv[r1].f);
		assert(lf <= r);
		ans = max(ans, abs(s[r] - s[lf - 1]));

		cout << ans << endl;
	}
}

main () {
	fastio
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}