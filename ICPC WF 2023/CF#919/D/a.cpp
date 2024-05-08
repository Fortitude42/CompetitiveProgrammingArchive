#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 2e18;

int n, q, ans[M], l[M];
pii b[M], a[M];
 
void solve() {
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].f, &a[i].s);

	for (int i = 1; i <= q; ++i) {
		scanf("%lld", &b[i].f);
		b[i].s = i;
	}


	sort(b + 1, b + 1 + q);
	

	for (int i = 1; i <= n; ++i) {
		l[i] = l[i - 1];
		if (a[i].f == 1)
			l[i]++;
		else {
			if (l[i] <= INF / (a[i].s + 1))
				l[i] = l[i]*(a[i].s + 1);
			else {
				l[i] = INF;
				n = i;
				break;
			}
		}			
	}

	assert(l[n] >= b[q].f);
	set < pii > qq;
	for (int i = 1; i <= q; ++i)
		qq.insert(b[i]);


	for (int i = n; i > 0; --i) {
		while (sz(qq) > 0) {
			pii cur = *qq.rbegin();

			if (cur.f <= l[i - 1])
				break;

			qq.erase(cur);
			//cur.f > l[i - 1]
			if (a[i].f == 1) {
				assert(cur.f == l[i]);
				ans[cur.s] = a[i].s;
			} else {
				cur.f %= l[i - 1];
				if (!cur.f)
					cur.f = l[i - 1];

				qq.insert(cur);
			}
		}
	}


	for (int i = 1; i <= q; ++i)
		prin	tf("%lld ", ans[i]);
	printf("\n");
}

main () {
  int TT;
  TT = 1;
  scanf("%lld", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}