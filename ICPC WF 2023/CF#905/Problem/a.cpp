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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

ll a[M], s[M];
int n, q, prv, l[M], r[M], x[M];
map < int, ll > m;


 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		s[i] = 0;
	}

	scanf("%d", &q);	
	int lst = 0;

	m.clear();
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &x[i]);
		m[l[i]] += x[i];
		if (r[i] + 1 <= n)
			m[r[i] + 1] -= x[i];

		while (sz(m) > 0 && m.begin()->s == 0) {
			m.erase(m.begin());
		}

		if (sz(m) > 0 && m.begin()->s < 0) {
			for (int j = lst + 1; j <= i; ++j) {
				s[l[j]] += x[j];
				if (r[j] + 1 <= n)
					s[r[j] + 1] -= x[j];
			}
			lst = i;
			m.clear();
//			cerr << lst << ' ' << i << endl;
		}
	}


	for (int i = 1; i <= n; ++i) {
		s[i] += s[i - 1];
		printf("%lld ", a[i] + s[i]);
	}

	printf("\n");

	
}

main () {
  int TT;
  TT = 1;
  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}