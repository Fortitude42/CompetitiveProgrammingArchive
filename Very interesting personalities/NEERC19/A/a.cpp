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
const ll INF = 3e18;

int n;
ll a[M], b[M], t[M];
vector < ll > events;
multiset < ll > prefq, suffq;
set < pair < ll, int > > pref, suff;
 
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld%lld", &a[i], &b[i], &t[i]);
		
		events.pb(a[i]);
		events.pb(a[i] + 1);
		events.pb(b[i] - t[i] + 1);

		suff.insert(mp(a[i], i));
		suffq.insert(a[i] + t[i]);
	}


	events.pb(INF);

	sort(all(events));
	events.resize(unique(all(events)) - events.begin());

	
	int j = 0;
	ll cur = 0, ans = 0;
	while (1) {
//		cerr << cur << ' ' << ans << endl;
		while (sz(suff)) {
			int i = suff.begin()->s;
			if (a[i] >= cur)
				break;

			suff.erase(mp(a[i], i));
			suffq.erase(suffq.find(a[i] + t[i]));
			pref.insert(mp(b[i] - t[i], i));
			prefq.insert(t[i]);
		}

		while (sz(pref)) {
			int i = pref.begin()->s;
			if (b[i] - t[i] >= cur)
				break;

			pref.erase(mp(b[i] - t[i], i));
			prefq.erase(prefq.find(t[i]));
		}

		ll prefTime = INF, suffTime = INF;

		if (sz(pref)) {
		    assert(sz(prefq) > 0);
			prefTime = cur + *prefq.begin(); 
		}

		if (sz(suff)) {
		    assert(sz(suffq) > 0);		
			suffTime = *suffq.begin(); 
		}

		if (prefTime == INF && suffTime == INF)
			break;

		if (suffTime < prefTime) { 
			++ans;
			cur = suffTime;
			continue;
		}

		while (events[j] <= cur)
			++j;
		
		assert(events[j] != INF);

		ll T = prefTime - cur;

		ll step = max(1ll, (events[j] - cur) / T);
		ans += step;
		cur += step*T;
	}

	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                       