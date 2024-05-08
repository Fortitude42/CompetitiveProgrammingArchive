//by parasat
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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, cnt[61], c[M], pref1[M], pref2[M];
ll a[M], mx[M], mn[M], ans;

inline void add(ll i, int x) {
	cnt[__builtin_popcountll(i)] += x;
}

void calc(int l = 1, int r = n) {
	if (l > r)
		return;

	int m = (l + r) >> 1;

	//calculation of mx, mn, pref1, pref2
	mx[m] = mn[m] = a[m];
	for (int i = m - 1; i >= l; --i) {
		mx[i] = max(mx[i + 1], a[i]);  
		mn[i] = min(mn[i + 1], a[i]);
	}

	for (int i = m + 1; i <= r; ++i) {
		mx[i] = max(mx[i - 1], a[i]);  
		mn[i] = min(mn[i - 1], a[i]);		
	}

	for (int i = m; i >= l; --i) {
		pref1[i] = (i == m ? m : pref1[i + 1]);
		while (pref1[i] <= r && mx[i] >= mx[pref1[i]])
			++pref1[i];

		pref2[i] = (i == m ? m : pref2[i + 1]);
		while (pref2[i] <= r && mn[i] <= mn[pref2[i]])
			++pref2[i];
	}

	//mxi >= mxj && mni <= mnj
	for (int i = m; i >= l; --i) 
		if (__builtin_popcountll(mx[i]) == __builtin_popcountll(mn[i]))
			ans += min(pref1[i], pref2[i]) - m;
		
	
	//mxi < mxj && mni > mnj
	int i = m, cnt1 = 0;
	for (int j = m; j <= r; ++j) {
		while (i >= l && mx[j] > mx[i] && mn[j] < mn[i]) {
			--i;
			++cnt1;
		}

		if (__builtin_popcountll(mx[j]) == __builtin_popcountll(mn[j]))
			ans += cnt1;                                              
	}


	//mxi >= mxj && mni > mnj
	int L = pref2[m], R = pref1[m] - 1;
	for (int x = L; x <= R; ++x)
		add(mn[x], 1);

	for (int i = m; i >= l; --i) {
		while (L < pref2[i]) {
			if (L <= R)
				add(mn[L], -1);
			L++;
		}

		while (R + 1 < pref1[i]) {
			R++;
			if (L <= R)
				add(mn[R], 1);
		}
		ans += cnt[__builtin_popcountll(mx[i])];
	}

	for (int x = L; x <= R; ++x)
		add(mn[x], -1);

	//mxi < mxj && mni <= mnj
	L = pref1[m], R = pref2[m] - 1;
	for (int x = L; x <= R; ++x) 
		add(mx[x], 1);

	for (int i = m; i >= l; --i) {
		while (L < pref1[i]) {
			if (L <= R)
				add(mx[L], -1);
			L++;                
		}

		while (R + 1 < pref2[i]) {
			R++;
			if (L <= R)
				add(mx[R], 1); 
		}

		ans += cnt[__builtin_popcountll(mn[i])];
	}

	for (int x = L; x <= R; ++x)
		add(mx[x], -1);

	calc(l, m - 1);
	calc(m + 1, r);
} 

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);

	ans = 0;
	calc();
	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}