#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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


int n, w, res[N];
pair < pii, int > a[N];

struct ST {
	ST *l, *r;
	ll sum;
	int cnt;

	ST () {
		l = r = NULL;
		sum = cnt = 0;
	}

	ST (ST *L, ST *R) {
		l = L, r = R;
		sum = (!l ? 0 : l->sum) + (!r ? 0 : r->sum);
		cnt = (!l ? 0 : l->cnt) + (!r ? 0 : r->cnt);
	}

	void update (int pos, int x, int y, int tl = 0, int tr = inf*2) {
		if (tl == tr) {
			sum += x;
			cnt += y;
			return;
		}

		int tm = (tl + tr) >> 1;
		if (pos <= tm) {
			if (!l) 
				l = new ST();
			
			l->update(pos, x, y, tl, tm);
		} else {
			if (!r)
				r = new ST();
			r->update(pos, x, y, tm + 1, tr);
		}

		sum = (!l ? 0 : l->sum) + (!r ? 0 : r->sum);
		cnt = (!l ? 0 : l->cnt) + (!r ? 0 : r->cnt);
	}


	ll get (int k, int tl = 0, int tr = inf*2) {
		if (tl == tr)
			return tl * 1ll * k;

		if (cnt == k)
			return sum;
		
		int tm = (tl + tr) >> 1;
		if (!l)
			return r->get(k, tm + 1, tr);

		if (l && l->cnt >= k)
			return l->get(k, tl, tm);

		return l->sum + r->get(k - l->cnt, tm + 1, tr);
	}
};

ST *T;

 
main () {
	T = new ST();
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].f.s, &a[i].f.f);
		a[i].s = i;
	}

	sort(a + 1, a + 1 + n);

	ll ans = INF;
	for (int i = 1; i <= n; ++i) {
		T->update(a[i].f.s, a[i].f.s, 1);
//		cout << " + " << a[i].f.s << endl;
	}
	
	
	
	int j = -1;
	ll cur = 0;
	for (int i = 1; i <= min(w, n) + 1; ++i) {
		if (w - i + 1 <= n) {
			ll sum = T->get(w - i + 1) + cur;
//			cout << i << ' ' << w - i + 1 << ' ' << cur << ' ' << T->get(w - i + 1) << endl;
			if (ans > sum) {
				ans = sum;
				j = i - 1;
			}
		}

		cur += a[i].f.s;
		T->update(a[i].f.s, -a[i].f.s, -1);
//		cout << " - " << a[i].f.s << endl;
		T->update(a[i].f.f - a[i].f.s, a[i].f.f - a[i].f.s, 1);
//		cout << " + " << a[i].f.f - a[i].f.s << endl;
	}

	vector < pii > v;
	for (int i = 1; i <= j; ++i) {
		++res[a[i].s];
		v.pb({a[i].f.f - a[i].f.s, a[i].s});
	}

	for (int i = j + 1; i <= n; ++i)
		v.pb({a[i].f.s, a[i].s});


	sort(all(v));
	for (int i = 0; i < w - j; ++i)
		++res[v[i].s];

	printf("%lld\n", ans);
	for (int i = 1; i <= n; ++i)
		printf("%d", res[i]);

}