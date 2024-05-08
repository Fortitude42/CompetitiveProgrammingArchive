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

void update(int l, int r, int x) {
	for (int i = l; i <= r; ++i)
		a[i] += x;
}

void update1(int l, int r, int x) {
	for (int i = l; i <= r; ++i)
		a[i] = min(a[i], x);
}

int get(int l, int r) {
	int mn = a[l];
	for (int i = l + 1; i <= r; ++i)
		mn = min(mn, a[i]);
	return mn;
}
 
void solve() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

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