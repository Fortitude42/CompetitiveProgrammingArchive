//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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


int n, c, cur;
map < int, int > cnt1, cnt;

 
void solve() {
	cin >> n >> c >> cur;
	cout << "accept" << endl;
	while (cur > 0) {
		int x;
		cin >> x;
		if (x < cur) {
			cout << "accept" << endl;
			cur = x;
		} else
			cout << "decline" << endl;		
	}

	vi vals;
	while (sz(vals) < n) {
		int x;
		cin >> x;
		if (x > cur) {
			cout << "accept" << endl;
			vals.pb(x - cur);
			cur = x;
		} else
			cout << "decline" << endl;		
	}

	int M = -1, mx = -1;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int s = 0;
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i)) 
				s += vals[i];

		if (s <= c && s > mx) {
			mx = s;
			M = mask;
		}				
	}

	for (int i = 0; i < n; ++i) {
		++cnt[vals[i]];
		if (M & (1 << i))
			++cnt1[vals[i]];
	}


	if (M == (1 << n) - 1) {
		int x;
		cin >> x;
		cout << "accept" << endl;
		cur = x;
		while (1) {
			cin >> x;
			if (x == mx) {
				cout << "stop" << endl; 
				return;
			}
			cout << "decline" << endl;
		}
	}

	while (1) {
		int x;
		cin >> x;
		if (x == mx) {
			cout << "stop" << endl;
			exit(0);
		}

		int y = cur - x;
		if (y < 0 || cnt[y] == cnt1[y])
			cout << "decline" << endl;
		else {
			cout << "accept" << endl;
			assert(cnt[y] > cnt1[y]);
			cur = x;
			cnt[y]--;
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
