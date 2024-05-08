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


int n, m, x[103], j;
bool used[M];


pii choose_segment() {
	int y = 0;
	for (int i = 1; i <= n; ++i)
		y = max(y, x[i]);

	for (int i = 1; i <= n; ++i)
		if (x[i] == y) {
			x[i] = -1;
			break;
		}

	int l = -1, mn = inf;
	for (int i = 1; i <= m; ++i) {
		if (used[i])
			continue;

		int len = 1;
		while (i + 1 <= m && !used[i + 1]) {
			++len;
			++i;
		}

		if (len >= y && len < mn) {
			mn = len;
			l = i - len + 1;
		}
	}

	if (l == -1)	
		return mp(-1, y);
	return mp(l, y);
}


void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> x[i];

	sort(x + 1, x + 1 + n);
	reverse(x + 1, x + 1 + n);

	int j = -1;
	for (int i = 1; i <= n; ++i)
		if (i - 1 >= (m / x[i]))
			j = i;
	
	if (j == -1) {
		cout << "Alessia\n";
		for (int i = 1; i <= n; ++i) {
			pii x = choose_segment();
			assert(x.f != -1);
			cout << x.s << ' ' << x.f << endl;
			int pos;
			cin >> pos;
			used[pos] = 1;
		}

		return;
	}

	cout << "Bernardo\n";
	for (int i = 1; i <= n; ++i) {
		int y, a;
		cin >> y >> a;

		int pos1 = a;
		for (int pos = a; pos <= y + a - 1; ++pos)
			if (pos % x[j] == (x[j] - 1)) {
				pos1 = pos;
				break;
			}
		cout << pos1 << endl;
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