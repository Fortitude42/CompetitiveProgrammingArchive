#include <bits/stdc++.h>
#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;



int get(string t) {
	int ans = 0;
	for (auto c : t)
		ans = ans*10 + c - '0';
	return ans;
}

main () {
	
	string s;
	vi a;
	vector < string > b;
	while (cin >> s) {                                                       
		if (isdigit(s[0])) {
			a.pb(get(s)); 
		} else {
		    s[1]++;
			b.pb(s);
		}
	}
	vector < pair < int, string > > v;
	for (int i = 0; i < sz(a); ++i) {
		v.pb(mp(a[i], b[i]));
	}

	set < string > q = {"A1", "D1", "E1", "F1", "G1", "I1", "K1",
	"A2", "B2", "E2", "G2", "I2", "J2", "K2", "L2",
	"C3", "D3", "F3", "G3", "H3", "I3", "K3", "L3",
	"A4", "B4", "D4", "E4", "G4", "I4", "J4", "L4",
	"A5", "B5", "D5", "F5", "I5",
	"C6", "E6", "I6", "J6",
	"A7", "B7", "C7", "E7", "K7"};

	sort(all(v));
	reverse(all(v));
	for (auto x : v)
		if (!q.count(x.s))
			cout << x.s << "---> " << x.f << endl;
}
