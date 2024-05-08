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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int maxn = 1e6;


int m, k, s[M], nxt[M];
int a[M], b[M];
vi g[maxn];
 
void solve() {
	cin >> m >> k;

	int sum = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 1; i <= k; ++i) {
		cin >> b[i];
		++s[b[i]];
	}

	int n = k, ans = 0;
	set < pii > q;
	for (int i = 1; i <= m; ++i) {
		nxt[i] = (sum*1ll*(s[i] + 1) + a[i] - 1) / a[i];
		q.insert(mp(nxt[i], i));
	}

	while (n < maxn) {
		++n;
		for (auto i : g[n])
			q.insert(mp(nxt[i], i));

		auto it = q.begin();

		while (it != q.end()) {
			int i = it->s;
			if (nxt[i] < n) {
				cout << ans << "\n";
				return;
			}

			int cur = (n*1ll*a[i] + sum - 1) / sum;
			if (s[i] + 1 > cur) {
				++it;
				continue;
			}

			break;
		}

		if (it == q.end()) {//is it possible?
			cout << ans << "\n";
			return;
		}

		int i = it->s;
		q.erase(mp(nxt[i], i));
		++s[i];
		nxt[i] = (sum*1ll*(s[i] + 1) + a[i] - 1) / a[i];

		int pos = (sum*1ll*s[i]) / a[i] + 1;
		if (pos == n)
			q.insert(mp(nxt[i], i));
		else if (pos < maxn) 
			g[pos].pb(i);
		

		if (sz(q) > 0 && q.begin()->f <= n) {
			cout << ans << "\n";
			return;
		}

		++ans;
	}

	cout << "forever\n";
}

main () {
  int TT;
  TT = 1;
  fastio
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}