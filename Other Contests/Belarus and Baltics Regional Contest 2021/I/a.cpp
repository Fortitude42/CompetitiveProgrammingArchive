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
const int N = 5e5, inf = 2e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, q, a[M];
set < int > pos;
int t[M << 2], lz[M << 2], lz1[M << 2];

void build(int v = 1, int tl = 1, int tr = n) {
	lz1[v] = inf;
	lz[v] = 0;

	if (tl == tr) {
		t[v] = a[tl];
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void push(int v) {

	if (lz[v]) {
		
		t[v << 1] += lz[v];
		if (lz1[v << 1] != inf) 
			lz1[v << 1] += lz[v];
		lz[v << 1] += lz[v];

		t[v << 1 | 1] += lz[v];
		if (lz1[v << 1 | 1] != inf)
			lz1[v << 1 | 1] += lz[v];
		lz[v << 1 | 1] += lz[v];

		lz[v] = 0;
	}

	if (lz1[v] < inf) {
		
		t[v << 1] = min(t[v << 1], lz1[v]);
		lz1[v << 1] = min(lz1[v << 1], lz1[v]);

		t[v << 1 | 1] = min(t[v << 1 | 1], lz1[v]);
		lz1[v << 1 | 1] = min(lz1[v << 1 | 1], lz1[v]);

		lz1[v] = inf;
	}
}

void update(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		if (lz1[v] != inf) 
			lz1[v] += x;
		lz[v] += x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void update1(int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] = min(t[v], x);
		lz1[v] = min(lz1[v], x);
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;

	update1(l, r, x, v << 1, tl, tm);
	update1(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
}


int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return inf;

	if (l <= tl && tr <= r)
		return t[v];

	push(v);
	int tm = (tl + tr) >> 1;
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}
 
void solve() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build();
	for (int i = 1; i < n; ++i)
		if (a[i] < a[i + 1])
			pos.insert(i);

	scanf("%d", &q);
	while (q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			int d;
			scanf("%d", &d);
			update(l, r, d);
			if (l > 1 && !pos.count(l - 1) && get(l - 1, l - 1) < get(l, l))
				pos.insert(l - 1);				
		}
		
		if (t == 2) {
			while (1) {
				auto it = pos.lower_bound(l);
				if (it == pos.end() || *it >= r)
					break;

				int i = *it;
				pos.erase(i);
				update1(i + 1, r, get(i, i));
			}

			if (r < n && !pos.count(r) && get(r, r) < get(r + 1, r + 1))
				pos.insert(r);
		}

		if (t == 3)
			printf("%d\n", get(l, r));

/*		if (t == 1 || t == 2) {
			for (int i = 1; i <= n; ++i)
				cerr << get(i, i) << ' ';
			cerr << endl;          
		}*/
	}
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}