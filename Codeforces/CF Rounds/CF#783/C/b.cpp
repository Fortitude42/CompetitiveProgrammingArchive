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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, len = inf, K;
vector < pii > cur, ans;

bool col[M], d[M];
set < int > yy;
 
void rec(int Move = 1) {
	vi x, y;
	x.pb(Move);
	for (auto i : yy) {
		if ((sz(cur) > 0 && abs(i - cur.back().s) <= 2) || (sz(cur) > 1 && abs(i - cur[sz(cur) - 2].s) <= 2))
			y.pb(i);
	}

	for (auto i : yy) {
		if ((sz(cur) > 0 && abs(i - cur.back().s) <= 2) || (sz(cur) > 1 && abs(i - cur[sz(cur) - 2].s) <= 2));
		else
			y.pb(i);	
	}

	vector < pii > c;
	for (auto i : x)
		for (auto j : y)
			if (!d[i - j + M / 2]) 
				c.pb({i, j});
		
	if (!sz(c)) {
		if (sz(cur) <= K) {
			ans = cur;
			cout << sz(ans) << endl;
			for (auto x : ans)
				cout << x.f << ' ' << x.s << endl;
			exit(0);
		}

		return;
	}


	for (auto x : c) {
		col[x.s] = 1;
		d[x.f - x.s + M / 2] = 1;
		cur.pb(x);
		yy.erase(x.s);
		rec(Move + 1);
		cur.ppb();
		yy.insert(x.s);
		col[x.s] = 0;
		d[x.f - x.s + M / 2] = 0;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		yy.insert(i);
	K = (n / 3)*2 + 1;
	if (n % 3 == 0)
		K++;
		
	rec();
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}