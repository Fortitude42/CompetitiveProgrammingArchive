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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, k, cnt[M], s[M], a[M];
 
pii check(int x) {
	for (int i = 1; i + x <= n; ++i)
		if (2*(cnt[i + x] - cnt[i - 1]) - n >= k)
			return {i, i + x};

	return {-1, -1};
}

void solve() {

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cnt[i] = 0;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}

	for (int i = 1; i <= n; ++i)
		cnt[i] += cnt[i - 1];

	int l = 0, r = n - 2;
	pii ans = {1, n};
	while (l <= r) {
		int mid = (l + r) >> 1;
		pii cur = check(mid);
		if (cur.f != -1) {
			ans = cur;
			r = mid - 1;
		} else
			l = mid + 1;			
	}

	cout << ans.f << ' ' << ans.s << endl;
	if (k == 1) {
		cout << 1 << ' ' << n << endl;
		return;
	}

	l = 1;
	int kk = 0;
	for (int r = 1; r <= n; ++r) {
		s[r] = s[r - 1] + (ans.f <= a[r] && a[r] <= ans.s);

		if (2*(s[r] - s[l - 1]) > (r - l + 1)) {
			cout << l << ' ' << r << endl;
			++kk;

			l = r + 1;
			if (kk == k - 1) {
				cout << l << ' ' << n << endl;
				return;
			}
		}
	}   	
}

main () {
	fastio
	int TT;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}