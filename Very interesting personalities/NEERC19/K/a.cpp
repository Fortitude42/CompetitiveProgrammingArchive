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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int K = 22;

ll c[K][K];
int cnt[K], suf[K];
 
void solve() {
	ll n;
	scanf("%lld", &n);
//	cerr << "! " << n << "\n";
	
	int k = 1;
	while (n) {
		++k;
		cnt[n % k]++;
		n /= k;
	}
//	cerr << "k: " << k << "\n";	
	assert(k < K);

	ll ans = 0;
	for (int fi = k - 1; fi > 0; fi--) {
		if (!cnt[fi])
			continue;
		cnt[fi]--;
		
		suf[k] = cnt[k];
		for (int i = k - 1; i >= 0; i--)
			suf[i] = suf[i + 1] + cnt[i];

		ll cur = 1;
		for (int i = k - 1; i >= 0; i--) {
			if (!cnt[i])
				continue;
			int curCnt = k - 1 - i - suf[i + 1] - (!i);
			cur *= c[curCnt][cnt[i]];
//			cerr << i << " | select from " << curCnt << " exactly " << cnt[i] << " | " << c[curCnt][cnt[i]] << "\n";
		}

//		cerr << fi << " " << cur << "\n";

		ans += cur;
		cnt[fi]++;
	}

	printf("%lld\n", ans - 1);

	memset(cnt, 0, sizeof cnt);
}

void precalc() {
	c[0][0] = 1;
	for (int i = 1; i < K; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
}

main () {
	precalc();
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
