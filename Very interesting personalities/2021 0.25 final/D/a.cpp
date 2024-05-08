//by paradox & gege & parasat
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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


set < pii > q;
vector < pii > gg;
multiset < int > len;
map < int, int > cnt;
int n, m, a[M];

void add(int x, int y) {
//	cerr << x << ' ' << y << endl;

	cnt[x] += y;
	if (!cnt[x]) {//delete x
		auto it = q.lower_bound(mp(x + 1, 0));
		it--;
		
		int l = it->f, r = it->s;
		q.erase(mp(l, r));
		len.erase(len.find(r - l + 1));

		if (l < x) {
			q.insert(mp(l, x - 1)); 
			len.insert(x - l);
		}

		if (x < r) {
			q.insert(mp(x + 1, r)); 
			len.insert(r - x);
		}
	}

	if (cnt[x] == 1 && y == 1) {//add x
		int l = x, r = x;

		if (cnt.count(x + 1) && cnt[x + 1] > 0) {
			auto it = q.lower_bound(mp(x + 1, 0));
			int L = it->f, R = it->s;
			
			q.erase(mp(L, R));
			len.erase(len.find(R - L + 1));
			
			r = R;
		}

		if (cnt.count(x - 1) && cnt[x - 1] > 0) {
			auto it = q.lower_bound(mp(x + 1, 0));
			it--;
			
			int L = it->f, R = it->s;

			q.erase(mp(L, R));
			len.erase(len.find(R - L + 1));

			l = L;
		}

		q.insert(mp(l, r));
		len.insert(r - l + 1);
	}
}
 
void solve() {
	cnt.clear();
	gg.clear();
	len.clear();
	q.clear();

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		add(a[i] / m, 1);
		if (a[i] % m)
			gg.pb({m - a[i] % m, i});
	}



	int ans = 0, x = 0;
	if (sz(len))
		ans = max(ans, *len.rbegin());	
		
	sort(all(gg));
	for (int i = 0; i < sz(gg); ) {
		int j = i;
		while (j < sz(gg) && gg[i].f == gg[j].f) {
			add(a[gg[j].s] / m, -1);
			add((a[gg[j].s] / m) + 1, 1);
			j++;
		}

		if (sz(len)) {
			int cur = *len.rbegin();
			if (ans < cur) {
				ans = cur;
				x = gg[i].f;
			}
		}

		i = j;
	}

	printf("%d %d\n", ans, x);
	
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

