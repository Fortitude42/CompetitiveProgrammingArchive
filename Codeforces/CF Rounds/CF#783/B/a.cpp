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
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


ll s[M];
vector < ll > vals;
int n, t[M][2], tt[M][2], timer, mx[M], TT[M];


void inc(int pos, int lvl, int x) {
	if (lvl)
		pos = M - 1 - pos;

	while (pos < M) {
		if (tt[pos][lvl] != timer) {
			tt[pos][lvl] = timer; 
			t[pos][lvl] = x;
		} else
			t[pos][lvl] = max(t[pos][lvl], x);
		pos |= pos + 1;
	}
}

int get(int r, int lvl) {
	if (lvl)
		r = M - 1 - r;

	int res = -inf;
	while (r >= 0) {
		if (tt[r][lvl] == timer)
			res = max(res, t[r][lvl]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}


 
void solve() {
	++timer;
	vals.clear();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &s[i]); 
		s[i] += s[i - 1];
		vals.pb(s[i]);
	}

	vals.pb(0);

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	
	for (int i = 0; i <= n; ++i) {
		int j = lower_bound(all(vals), s[i]) - vals.begin();
		if (!i) {
			inc(j, 0, 0); 
			inc(j, 1, 0); 
			TT[j] = timer;
			mx[j] = 0;
		} else {
			int cur = -inf;
			if (TT[j] == timer)
				cur = max(cur, mx[j]);
			
			cur = max(cur, get(j - 1, 0) + i);
			cur = max(cur, get(j + 1, 1) - i);
			
			inc(j, 0, cur - i);
			inc(j, 1, cur + i);
			if (TT[j] != timer) {
				TT[j] = timer;
				mx[j] = cur;
			} else
				mx[j] = max(mx[j], cur);

			if (i == n)
				printf("%d\n", cur);
		}
	}
}

main () {
	int TT;
	TT = 1;
  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}