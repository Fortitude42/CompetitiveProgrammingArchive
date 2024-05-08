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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
ll a[M];
bool stop;
vector < pair < ll, int > > v;
 
void solve1() {
	for (int i = 1; i <= N; ++i) {
		printf("next\n");
		fflush(stdout);
		ll x;
		scanf("%lld", &x);
		if (x == -1) {
			stop = 1;
			break;
		}

		n = i;
		a[i] = x;
	}

	set < ll > q;
	sort(a + 1, a + 1 + n);

	while (sz(v) < 40) {
		int mx = -1;
		ll val = 0;

		for (int i = 1; i <= n; ++i) {
			if (!q.count(a[i])) {
				int j = i, cnt = 0;
				while (j <= n && a[j] == a[i]) {
					++j;
					++cnt;
				}
				if (mx < cnt) {
					mx = cnt;
					val = a[i];
				}

				i = j - 1;
			}
		}

		if (mx == -1)
			break;
		v.pb(mp(val, mx));
		q.insert(val);
	}
}

void solve() {	
	stop = 0;
	while (!stop)
		solve1();
	set < ll > vals;
	for (auto x : v)
		vals.insert(x.f);
	
	ll ans = 0;
	int mx = -1;

	for (auto x : vals) {
		int cnt = 0;
		for (auto y : v)
			if (y.f == x) 
				cnt += y.s;

		if (cnt > mx) {
			mx = cnt;
			ans = x;
		}
	}

	printf("%lld\n", ans);
	fflush(stdout);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

