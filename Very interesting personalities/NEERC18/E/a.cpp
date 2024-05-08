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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
vector < pii > v;

void write() {
	for (auto x : v) {
		cout << (char)(x.f - 1 + 'a');
		cout << x.s << ' ';
	}
	exit(0);
}

void Move(int x, int y) {
	v.pb({x, y});
	if (sz(v) < n - 2) 
		return;	

	if (x == 8) {
		if (sz(v) == n - 1) {
			v.pb({8, 8});
			write();
		}
		return;
	}

	if (sz(v) == n - 2) {
		if (y == 8) {
			if (x == 7) {
				v.ppb();
				v.pb({7, 2});
				v.pb({7, 8});
				v.pb({8, 8});
				write();
			}

			v.pb({x + 1, y});
			v.pb({8, y});
			write();
		}

		v.pb({8, y});
		v.pb({8, 8});
		write();
	}
} 


void solve() {
	cin >> n;
	n++;

	for (int i = 1; i <= 8; ++i) {
		int j = 2 - (i & 1);
		int e = 8;
		if (i == 8)
			e = 7;

		Move(i, j);
		Move(i, e);
		for (int x = e - 1; x > 0; --x)
			if (x != j)
				Move(i, x);

//		Move(i + 1, 3 - j);
	}

}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

