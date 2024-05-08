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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int T, n, p[N], pos[N];

struct node {
	int mx, mn, add;
};

node t[N << 2];


void build(int v = 1, int tl = 0, int tr = n) {
	t[v].mn = t[v].mx = t[v].add = 0;
	if (tl == tr) 
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void push(int v) {
	if (t[v].add) {
		t[v << 1].add += t[v].add;
		t[v << 1 | 1].add += t[v].add;

		t[v << 1].mx += t[v].add;
		t[v << 1 | 1].mx += t[v].add;

		t[v << 1].mn += t[v].add;
		t[v << 1 | 1].mn += t[v].add;
		t[v].add = 0;
		return;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 0, int tr = n) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v].add += x;
		t[v].mn += x;
		t[v].mx += x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
	t[v].mn = min(t[v << 1].mn, t[v << 1 | 1].mn);
}

pii get(int l, int r, int v = 1, int tl = 0, int tr = n) {
	if (l > r || tl > r || l > tr)
		return mp(inf, -inf);

	if (l <= tl && tr <= r)
		return mp(t[v].mn, t[v].mx);

	push(v);
	int tm = (tl + tr) >> 1;
	pii a = get(l, r, v << 1, tl, tm);
	pii b = get(l, r, v << 1 | 1, tm + 1, tr);
	return mp(min(a.f, b.f), max(a.s, b.s));
}

bool inter(pii a, pii b) {
	if (a.f > b.f)
		swap(a, b);
	return b.f <= a.s;
}
 
main () {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
			pos[p[i]] = i;
		}
		
		build();
		for (int i = 1; i <= n; ++i)
			update(i, n, -1);

		for (int i = 1; i <= n; ++i) {
			if (i > 1) 
				update(pos[i - 1], n, 1);
			update(pos[i], n, 1);

			pii a = get(0, pos[i] - 1);
			pii b = get(pos[i] + 1, n);
//			cerr << i << ' ' << a.f << ' ' << a.s << ' ' << b.f << ' ' << b.s << endl;
			bool ok = inter(a, b);

			a = get(0, pos[i] - 2);
			b = get(pos[i], n);
			ok |= inter(a, b);
			printf("%c", ok ? 'y' : 'n');
		}
		printf("\n");
	}
}