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
const int N = 1e7, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


map < string, string > m;
string s;
 
void solve() {
	cin >> s;
	if (m.count(s))
		cout << m[s] << endl;
	else { 
		sort(all(s));
		if (s[0] == s.back())
			cout << s << endl;
		else
			cout << -1 << endl;
	}
}

main () {
	m["12"] = "48";
	m["45"] = "5055555555";
	m["63"] = "111888";
	m["72"] = "8088888888";
	m["36"] = "48888";
	m["27"] = "3699";
	m["24"] = "8088";
	m["21"] = "7077";
	m["18"] = "288";
	m["15"] = "5055";
	m["81"] = "9099999999";
	m["54"] = "222888888";
	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

