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
const int N = 4e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 15;
const ll INF = 1e18;

int n, a[M], dp[2][90][90][M];

int get(int l, int r) {
	return a[r] - a[l - 1];
}

int getk(int l, int r) {
	return (n - r) - (l - 1);
}

//k = n - r - l + 1;
//l = n - r - k + 1;
//r = n - l - r + 1;

int getr(int l, int k) {
	return n - l - k + 1;
}


int getl(int r, int k) {
 	return n - r - k + 1;
}
 
int rec(int tp, int k1, int k, int i) {
	int &res = dp[tp][k1][k][i];
	if (res != -inf)
		return res;

	if (!tp) {
		int l = i;
		int r = getr(l, k1);

		if (r - l + 1 < k)
			return res = 0;

		res = rec(1, getk(l + k, r), k, r) + get(l, l + k - 1);//(l, r) -> (l + k, r)

		if (l == 1 && r == n)
			cerr << rec(1, getk(l + k, r), k, r) << ' ' << get(l, l + k - 1) << endl;

		if (r - l + 1 >= k + 1)
			res = max(res, rec(1, getk(l + k + 1, r), k + 1, r));//(l, r) -> (l + k + 1, r)
		return res;
	}

	int r = i;
	int l = getl(r, i);
	if (r - l + 1 < k)
		return res = 0;

	res = rec(0, getk(l, r - k), k, l) - get(r - k + 1, r);//(l, r) -> (l, r - k)
	if (r - l + 1 >= k + 1)
		res = min(res, rec(0, getk(l, r - k - 1), k + 1, l) - get(r - k, r));//(l, r) -> (l, r - k - 1)
	return res;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];               
		a[i] += a[i - 1];
	}

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 90; ++j)
			for (int x = 0; x < 90; ++x)
				for (int y = 0; y < M; ++y)
					dp[i][j][x][y] = -inf;

	cout << rec(0, getk(1, n), 1, 1);
}

main () {
	int TT;
	TT = 1;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

