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
const int N = 1e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
bitset < M > b[M], cur;
int n, m, f, q, a[M];
bool was[M];

int get(char c) {
	if (isdigit(c))
		return c - '0';	
	return 10 + c - 'a';
}

void solve() {
	cin >> m >> f;
	for (int i = 0; i < f; ++i) {
		cin >> a[i]; 
		a[i] %= m;
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < sz(s); ++j) {
			int x = get(s[j]);
			int l = j*4;
			int r = min(m - 1, j*4 + 3);
			int len = r - l + 1;

			for (int y = 0; y < len; ++y)
				if (x & (1 << y))
					b[i][l + y] = 1;
		}
	}

	vi ans;
	cin >> q;
	while (q--) {
		int u;
		cin >> u;
		u %= m;

		cur.reset();
		for (int i = 0; i < f; ++i)
			cur[a[i]*u % m] = 1;

		for (int i = 0; i < n; ++i)
			if (!was[i] && ((cur & b[i]) == cur)) {
				was[i] = 1;
				ans.pb(i);
			}						
	}

	sort(all(ans));
	cout << sz(ans) << ' ';
	for (auto x : ans)
		cout << x << ' ';
}

main () {
	//file("filter");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

