#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, p[N], cnt[N], l[N], r[N], h[N];
bool was[N];
pii a[N];
ll L, R;

int Get (int v) {
	return v == p[v] ? v : p[v] = Get(p[v]);
}

void merge (int v, int u) {
	v = Get(v), u = Get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])
		swap(v, u);
	
	p[u] = v;
	cnt[v] += cnt[u];
}

ll f (ll x) {
	if (x < 0)
		return 0;

	return x*(x + 1) / 2;
}

ll g (ll n, ll x) {
	return f(n) - f(n - x);
}

ll get (ll s) {
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		ll len = s / h[i];
		res += g(l[i] + r[i] + 1, len);
/*		cerr << g(l[i] + r[i] + 1, len) << ' ';
		cerr << g(l[i], len) << ' ';
		cerr << g(r[i], len) << ' ' << len << endl;*/
		res -= g(l[i], len);
		res -= g(r[i], len);
	}

	return res;
}
 
ll F (int i, ll len) {
	ll L = max(1ll, l[i] - len + 2);
	ll R = min(l[i] + 1, l[i] + r[i] - len + 2);
	return R - L + 1;
}

main () {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &h[i]);     
		a[i] = {h[i], i};
		p[i] = i;
		cnt[i] = 1;
	}
	scanf("%lld%lld", &L, &R);

	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (was[a[i].s - 1]) {
			l[a[i].s] = cnt[Get(a[i].s - 1)]; 
			merge(a[i].s, a[i].s - 1);
		}

		if (was[a[i].s + 1]) {
			r[a[i].s] = cnt[Get(a[i].s + 1)];
			merge(a[i].s, a[i].s + 1);
		}

		was[a[i].s] = 1;
	}

	ll lf = 0, rg = INF, s = 0;
	while (lf <= rg) {
		ll mid = (lf + rg) / 2;
		if (get(mid) >= L) {
			s = mid;
			rg = mid - 1;
		} else
			lf = mid + 1;
	}

	ll t = min(R, get(s));
	while (L <= t) {
		printf("%lld ", s);
		++L;
	}

	set < pair < pll, pll > > q;
	for (int i = 1; i <= n; ++i) {
		ll len = s / h[i] + 1;
		if (l[i] + r[i] + 1 < len)
			continue;
		ll s = h[i]*len;
		ll cnt = F(i, len);
//		if (s == 20) {
//			cerr << l[i] << ' ' << r[i] << ' ' << len << ' ' << cnt << endl;
//		}
		q.insert(mp(mp(s, cnt), mp(len, i)));
	}

	while (L <= R) {
		++L;

		pair < pll, pll > t = *q.begin();
		q.erase(q.begin());
		printf("%lld ", t.f.f);
		--t.f.s;
		if (!t.f.s) {
			++t.s.f;
			if (l[t.s.s] + r[t.s.s] + 1 < t.s.f)
				continue;

			t.f.f = t.s.f*h[t.s.s];
			t.f.s = F(t.s.s, t.s.f);
		}
		q.insert(t);
	}

}