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
 
const int inf = 1e9, maxn = 2e5 + 5e4 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, t[maxn << 2], lz[maxn << 2], x, y, c;
multiset < int > q[N];
vpii g[maxn];

void push (int v) {
	if (lz[v]) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];

		t[v << 1] += lz[v];
		t[v << 1 | 1] += lz[v];
		lz[v] = 0;
		return;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		lz[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v);

	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

inline int getPrv (int pos, int c) {
	if (!sz(q[c]) || *q[c].begin() >= pos)
		return -1;

	auto it = q[c].lower_bound(pos);
	--it;
	return *it;
}

inline int getNxt (int pos, int c) {
	if (!sz(q[c]) || *q[c].rbegin() < pos)
		return inf;

	return *q[c].lower_bound(pos);
}

inline void add (int pos, int c, int k) {
	int prv = getPrv(pos, c);	
	int nxt = getNxt(pos, c);
	update(max(prv + 1, pos - k), pos, 1);
	update(max(prv + 1, nxt - k), pos, -1);
	q[c].insert(pos);
}

inline void del (int pos, int c, int k) {
	q[c].erase(q[c].find(pos));
	int prv = getPrv(pos, c);
	int nxt = getNxt(pos, c);

	update(max(prv + 1, pos - k), pos, -1);
	update(max(prv + 1, nxt - k), pos, 1);
}

bool check (int k) {
	memset(t, 0, sizeof(t));
	memset(lz, 0, sizeof(lz));

	for (int i = 0; i < N; ++i)
		q[i].clear();

	for (int i = 1; i <= k + 1; ++i) 
		for (auto x : g[i])
			add(x.f, x.s, k);
	
	for (int i = k + 2; i < maxn; ++i) {
		if (t[1] == m)
			return 1;

		for (auto x : g[i])
			add(x.f, x.s, k);
		for (auto x : g[i - k - 1])
			del(x.f, x.s, k);
	}

	return 0;
}

 
main () {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i) {
		scanf("%d%d%d", &x, &y, &c);
		g[x].pb({y, c});
	}
	
	int l = 0, r = maxn - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}

	cout << r + 1 << endl;
}