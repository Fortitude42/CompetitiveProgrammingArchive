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
const pii base = mp(1e6 + 3, 1e6 + 33), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 500, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi vals, q2;
pii p[M], h[M];
vector < pii > q1;
int n, m, b[M], a[M], prv[M], d[M*4];
 
void precalc() {
	p[0] = {1, 1};
	for (int i = 1; i < M; ++i)
		p[i] = {p[i - 1].f * 1ll * base.f % mod.f, p[i - 1].s * 1ll * base.s % mod.s};
}

int norm(ll x, int m) {
	return ((x % m) + m) % m;
}

pii get(int l, int r) {
	return mp(norm(0ll + h[r].f - p[r - l + 1].f * 1ll * h[l - 1].f, mod.f), norm(0ll + h[r].s - p[r - l + 1].s * 1ll * h[l - 1].s, mod.s));
}

void solve() {
	vals.clear();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);	 
		vals.pb(a[i]);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(all(vals), a[i]) - vals.begin();

	m = 0;
	for (int i = 1; i <= n; ++i) {
		if (i < n && a[i] == a[i + 1]) {
			i++;
			continue;
		}
		b[++m] = i;
	}

	for (int i = 1; i <= m; ++i)
		h[i] = mp((h[i - 1].f * 1ll * base.f + a[b[i]]) % mod.f, (h[i - 1].s * 1ll * base.s + a[b[i]]) % mod.s);

	prv[0] = 0;
	for (int i = 1; i <= m; ++i) {
		prv[i] = -1;
		for (int k = 1; i - 2*k + 1 > 0; ++k)
			if (prv[i - 2*k] != -1 && get(i - 2*k + 1, i - k) == get(i - k + 1, i))
				prv[i] = i - 2*k;
	}

	if (prv[m] == -1) {
		cout << -1 << endl;
		return;
	}


	vector < vi > comps;
	while (m > 0) {
		vi cur;
		for (int i = prv[m] + 1; i <= m; ++i)
			cur.pb(b[i]);
		m = prv[m];
		comps.pb(cur);
	}


	int prv = 0, sz = 0;
	for (auto c : comps) {
		int k = sz(c);
		
		vi x, y;
		
		for (int i = 0; i < k / 2; ++i)
			x.pb(c[i]);

		for (int i = k/2; i < k; ++i)
			y.pb(c[i]);


		int l1 = prv + 1;
		int l2 = x.back() + 1;
		int sz1 = 0;

		for (int i = 0; i < sz(x); ++i) {
			while (l2 != y[i]) {
				q1.pb({sz, a[l2]});
				l2 += 2;
				sz += 2;
				sz1 += 2;
			}
			l2++;

			while (l1 != x[i]) {
				l1 += 2;
				sz += 2;
				sz1 += 2;
			}
			l1++;

			++sz;
			++sz1;
		}

		q2.pb(sz1);

		l1 = prv + 1;
		l2 = x.back() + 1;
		for (int i = 0; i < sz(x); ++i) {
			while (l2 != y[i]) {
				l2 += 2;
				sz += 2;
			}
			l2++;

			while (l1 != x[i]) {
				q1.pb({sz, a[l1]});
				l1 += 2;
				sz += 2;
			}
			l1++;

			++sz;
		}


		prv = y.back();
	}

	while (prv < n) {
		q2.pb(2);
		prv += 2;
	}

	cout << sz(q1) <<endl;
	for (auto x : q1)
		cout << x.f << ' ' << x.s << endl;

	cout << sz(q2) << endl;
	for (auto x : q2)
		cout << x << ' ';

	cout << endl;
}

main () {
	precalc();
	int TT;
	TT = 1;
	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}