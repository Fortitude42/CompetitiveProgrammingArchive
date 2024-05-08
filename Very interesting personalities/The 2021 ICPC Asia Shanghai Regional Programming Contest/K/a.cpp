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
const int N = 2e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, b = -1;
bool used[M];
vi order;

int get(int mask) {
	int mask1 = 0;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i))
			continue;

		int cnt = 0;
		if (i > 0 && mask & (1 << (i - 1)))
			++cnt;
		if (i < n - 1 && mask & (1 << (i + 1)))	
			++cnt;

		if (cnt == 1)
			mask1 |= (1 << i);
	}

	return mask1;
}

void dfs(int mask) {
	used[mask] = 1;
	int mask1 = get(mask);

	if (!used[mask1])
		dfs(mask1);

	order.pb(mask);
}

string Mask(int x) {
	string res = "";

	for (int i = 0; i < n; ++i) 
		res += (((x >> i) & 1) + '0');

	return res;
}

 
void solve() {
	cin >> n;
	for (int i = 0; i < (1 << n); ++i)
		if (!used[i])
			dfs(i);

	memset(used, 0, sizeof(used));
	reverse(all(order));
	for (auto x : order) {
		used[x] = 1;
		int y = get(x);
		if (x > 0 && y > 0 && used[y])
			b = x;
		x = y;
	}
	if (b == -1)
		cerr << b << endl;
	else {
		int m = n + n;
		while (m--) {
			cout << Mask(b) << endl;  
			b = get(b);
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

