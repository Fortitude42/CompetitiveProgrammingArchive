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

int q, pos[M];
string s;
vi g[60];
 
int find(char c, int pos) {
	int cc = c - 'a';
	if (!sz(g[cc]) || g[cc].back() <= pos)
		return inf;

	return *upper_bound(all(g[cc]), pos);
}

void solve() {
	fastio
	cin >> s >> q;

	for (int i = 0; i < sz(s); ++i) 
		g[s[i] - 'a'].pb(i);
	
	string p = "";
	pos[0] = -1;

	while (q--) {
		string t;
		cin >> t;
		if (t == "push") {
			char c;
			cin >> c;
			p += c;

			pos[sz(p)] = find(c, pos[sz(p) - 1]);
		} else 
			p.pop_back();

		puts(pos[sz(p)] < inf ? "YES" : "NO");
	}
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}