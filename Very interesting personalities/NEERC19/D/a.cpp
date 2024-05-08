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
const int N = 264, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], b[M], can[10];
vector < pii > ans;
bool t[M], was[M];
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			if (x)
				a[i] |= (1 << j);
		}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			if (x)
				b[i] |= (1 << j);
		}

		b[i] &= a[i];

		if (__builtin_popcount(a[i]) == 1) {
			t[i] = 0;
			b[i] = a[i];
		}
			
		if (!a[i])
			was[i] = 1;
	}
	
	was[1] = 1;

	for (int i = 2; i <= n; ++i)
		if (a[i] == 7) {
			was[i] = 1;
			t[i] = 1;
			ans.pb({1, i});
			can[b[i]] = i;
		}


	while (1) {
		bool run = 0;
		for (int i = 1; i <= n; ++i)
			if (!was[i] && can[a[i]]) {
				was[i] = 1;
				run = 1;
				ans.pb({can[a[i]], i});

				if (__builtin_popcount(a[i]) == 2)
					t[i] = 1;
				can[b[i]] = i;
			}

		if (!run)
			break;
	}

	for (int i = 1; i <= n; ++i)
		if (!was[i]) {
			if (can[a[i]]) {
				ans.pb({can[a[i]], i});
				continue;
			}
			
			vi bits;
			for (int x = 0; x < 3; ++x)
				if (a[i] & (1 << x))
					bits.pb(1 << x);

			if (sz(bits) == 1) {
				cout << "Impossible";
				return;
			}

			assert(sz(bits) == 2);
			if (!can[bits[0]] || !can[bits[1]]) {
				cout << "Impossible";
				return;
			}

			was[i] = 1;

			ans.pb({can[bits[0]], i});
			ans.pb({can[bits[1]], i});
           	
			can[a[i]] = i;
			t[i] = 0;
	}

	cout << "Possible\n";
	for (int i = 1; i <= n; ++i)
		cout << t[i] << ' ';
	cout << endl;
	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
	
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

