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
const int N = 5000, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int a, b, c;
vi d;


void solve() {
	d.clear();
	cin >> a >> b >> c;
	if (c % 3 == 0) {
		a -= 2;
		for (int i = 0; i < c/3; ++i)
			d.pb(3);
		d.pb(1);
		for (int i = 0; i < c/3; ++i)
			d.pb(-3);
		d.pb(1);
		for (int i = 0; i < c/3; ++i)
			d.pb(3);
	} else if (c % 3 == 1) {
		a--;
		b -= 2;
		d.pb(2);
		for (int i = 0; i < c/3; ++i)
			d.pb(3);
		d.pb(1);
		for (int i = 0; i < c/3; ++i)
			d.pb(-3);
		d.pb(-2);
		for (int i = 0; i < c/3 + 1; ++i)
			d.pb(3);
	} else {
		a -= 2;
		for (int i = 0; i < c/3+1; ++i)
			d.pb(3);
		d.pb(-1);
		for (int i = 0; i < c/3; ++i)
			d.pb(-3);
		d.pb(-1);
		for (int i = 0; i < c/3+1; ++i)
			d.pb(3);
	}

	while (a > 1) {
		a--;
		d.pb(1);
	}
	cerr << b << endl;
	for (int i = 0; i < (b + 1)/2; ++i)
		d.pb(2);
	d.pb((b&1) ? -1 : 1);
	for (int i = 0; i < b/2; ++i)
		d.pb(-2);

	int pos = 0;
	for (int i = 0; i <= sz(d); ++i) {
		cout << pos << ' ';
		if (i < sz(d))
			pos += d[i];
	}

	cout << endl;
}

main () {
//	file("jumping");
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

