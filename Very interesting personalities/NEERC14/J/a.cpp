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
const int N = 50, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n;
vi v;
string s;
bool used[M];

void rec(int i = 0) {
	if (i == sz(s)) {
		for (auto x : v)
			cout << x << ' ';
		exit(0);
	}


	int d1 = s[i] - '0';
	if (!d1)
		return;

	if (i + 1 < sz(s)) {
		int d2 = s[i + 1] - '0';
		if (d1*10 + d2 <= n && !used[d1*10 + d2]) {
			v.pb(d1*10 + d2);
			used[d1*10 + d2] = 1;
			rec(i + 2);
			v.ppb();
			used[d1*10 + d2] = 0;
		}

		if (!d2)
			return;
	}

	if (d1 <= n && !used[d1]) {
		v.pb(d1);
		used[d1] = 1;
		rec(i + 1);
		v.ppb();
		used[d1] = 0;
	}
}

void solve() {
	cin >> s;
	int len = 0;
	while (len < sz(s)) {
		n++;
		len += (n < 10 ? 1 : 2);
	}
	
	rec();
}

main () {
	file("joke");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

