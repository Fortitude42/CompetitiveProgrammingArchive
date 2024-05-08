//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
#pragma GCC optimization ("unroll-loops")
 
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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, q;
set < int > qq;
set < int > t[M << 2];

void build(int v = 1, int tl = 1, int tr = n) {
	t[v].insert(n + 1);
	if (tl == tr)
		return;

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
}

void add(int pos, int x, int v = 1, int tl = 1, int tr = n) {
	t[v].insert(x);

	if (tl == tr) 
		return;
	
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		add(pos, x, v << 1, tl, tm);
	else
		add(pos, x, v << 1 | 1, tm + 1, tr);	
}

int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return n + 1;

	if (l <= tl && tr <= r)
		return *t[v].lower_bound(l);
		                    	
	int tm = (tl + tr) >> 1;
	return min(get(l, r, v << 1, tl, tm), get(l, r, v << 1 | 1, tm + 1, tr));
}
 
void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i <= n + 1; ++i)
		qq.insert(i);

	build();
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			if (!x) {
				while (1) {
					int y = *qq.lower_bound(l);
					if (y > r)
						break;
					qq.erase(y);
				}
			} else
				add(l, r);			
		} else {
			int j;
			scanf("%d", &j);
			if (!qq.count(j)) {
				puts("NO");
				continue;
			}

			auto it = qq.lower_bound(j);
			++it;
			int R = *it - 1;
			it--;
			it--;
			int L = *it + 1;

			int x = get(L, R);
			if (x >= L && x <= R) 
				puts("YES");
			else
				puts("N/A");								
		}
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