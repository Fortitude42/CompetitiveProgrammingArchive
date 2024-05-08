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


int n, pref[M], mx[M];
pii t[M], dp[M];
string s;

void inc(int pos, pii x) {
	pos = n - pos;
	while (pos <= n) {
		t[pos] = min(t[pos], x);
		pos |= pos + 1;
	}
}

pii get(int r) {
	r = n - r;
	pii res = mp(inf, inf);
	while (r >= 0) {
		res = min(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}

void solve() {
	cin >> n >> s;
	n += n;
	for (int i = 0; i <= n; ++i)
		t[i] = mp(inf, inf);

	s = "#" + s;
	          

	dp[0] = mp(0, 0);
	inc(0, mp(0, 0));
	          

	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1); 
		mx[i] = max(mx[i - 1], pref[i]);
		if (pref[i] < 0)
			continue;

		dp[i] = mp(inf, inf);
		if (pref[i - 1] >= 0)
			dp[i] = mp(dp[i - 1].f, -1);
		
		pii cur = get(mx[i] - pref[i]);
		cur.f++;

		dp[i] = min(dp[i], cur);
		inc(pref[i], mp(dp[i].f, i));
	}
	assert(dp[n].f <= 2);
	
	          
	int x = n;
	vector < pii > ans;

	while (x > 0) {
		if (dp[x].s == -1) {
			x--;
			continue;
		}

		ans.pb({dp[x].s + 1, x});
		x = dp[x].s;			
	}

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
}

main () {
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}