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
ll p[M];

bool check(ll x) {
	ll y = x;
	while (x > 0) {
		int x1 = x % 10;
		int y1 = y % 2;
		if (x1 != y1)
			return 0;
		x /= 10;
		y /= 2;
	}

	return 1;
}

void solve() {
	p[0] = 1;
	for (int i = 1; i <= 18; ++i)
		p[i] = p[i - 1] * 10ll;

//	cin >> n;
//	n++;
	
	for (int len = 18; len <= 18; ++len) {
		vi v(len);
//		v[len - 1] = 1;
		while (1) {
			bool stop = 0;
			for (int i = 0; i < len; ++i) {
				if (v[i] <= 1)
					break;
				if (i == len - 1) {
					stop = 1;
					break;
				}
				v[i] = 0;
				v[i + 1]++;
			}

			if (stop)
				break;

			ll cur = 0;
			for (int i = 0; i < len; ++i)
				cur += p[i] * v[i];

			if (check(cur)) {
/*				n--;
				if (!n) {
					cout << cur << endl;
					return;
				}*/
				for (int i = len - 1; i >= 0; --i)
					cout << v[i];
				cout << endl;
			}
			++v[0];
		}
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
