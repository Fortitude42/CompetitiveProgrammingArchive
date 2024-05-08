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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


struct line {
	int k, b;
	line () {
		k = b = 0;
	}

	line (int _k, int _b) {
		k = _k;
		b = _b;
	}
};

ll sum;
bool was[N];
ll res[N], s[N];
multiset < int > q;
int n, tp[N], d[N];
line b[N], t[N << 2];
pii mx[N], mn[N], a[N];


ll get1 (line L, int x) {
	return L.k * 1ll * x + L.b;
}

void update (line L, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		if (get1(L, tl) > get1(t[v], tl))
			t[v] = L;
		return;
	}

	int tm = (tl + tr) >> 1;
	bool a = get1(L, tl) > get1(t[v], tl);
	bool b = get1(L, tm + 1) > get1(t[v], tm + 1);

	if (a != b) {
		if (b)
			swap(L, t[v]);
		update(L, v << 1, tl, tm);
	} else {
		if (a)
			swap(L, t[v]);
		update(L, v << 1 | 1, tm + 1, tr);
	}
}

ll get (int pos, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) 
		return get1(t[v], pos);

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return max(get(pos, v << 1, tl, tm), get1(t[v], pos));
	return max(get(pos, v << 1 | 1, tm + 1, tr), get1(t[v], pos));
}

ll get2 (int pos) {
	ll res = 0;
	for (int i = 1; i <= n; ++i)
		if (was[i])
			res = max(res, get1(b[i], pos));
	return res;
}
 


main () {
	fastio
		
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> tp[i] >> d[i];
		a[i] = mp(d[i], i);
		mx[tp[i]] = max(mx[tp[i]], a[i]);
		mn[i] = mp(inf, inf);
		sum += d[i];
	}
	

	for (int i = 1; i <= n; ++i)
		mn[tp[i]] = min(mn[tp[i]], a[i]);

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (mx[i].f && mx[i] != mn[i]) {
			q.insert(mx[i].f);
			b[i] = line(mx[i].f, -mn[i].f);
		}
		
		s[i] = s[i - 1] + a[i].f;
	}


	for (int i = n; i > 0; --i) {
		if (sz(q)) 
			res[i] = *q.rbegin() * 1ll * i - s[i];
		res[i] = max(res[i], get(i) - s[i - 1]);
//		cerr << get(i) << ' ' << get2(i) << endl;
//		assert(get(i) == get2(i));
//		cerr << i << endl;

		int j = a[i].s;
		int t = tp[j];
		if (!was[t] && mx[t] != mn[t] && mn[t].s == j) {
			was[t] = 1;
			q.erase(q.find(mx[t].f));
//			cerr << b[t].k << ' ' << b[t].b << endl;
			update(b[t]);
		}
	}
	
		
	for (int i = 1; i <= n; ++i) {
		res[i] = max(res[i], res[i - 1]); 
		cout << sum + res[i] << endl;
	}
}   