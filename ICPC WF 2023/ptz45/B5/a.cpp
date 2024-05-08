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
vi solve(int n) {
	if (n == 1)
		return {1};
	if (n == 3)
		return {2, 3, 1};

	int k = 0;
	while ((1 << (k + 1)) <= n)
		k++;
	
//	cerr << n << ' ' << k << ' ' << (1 << (k + 1)) << endl;
//	exit(0);
	if (n <= (1 << k) + (1 << (k - 1))) 
		return {-1};
	
	if (n == (1 << (k + 1)) - 1) {
		if (n == 7)
			return {7, 5, 4, 6, 2, 3, 1};	
		vi tmp = solve(n - (1 << k));

		vi res;
		for (auto x : tmp) {
			res.pb(x + (1 << k));
			if (sz(res) == 2)
				res.pb((1 << k));
		}

		for (auto x : tmp)
			res.pb(x);
		return res;
	}

	assert(k >= 3);
	vi res = {(1 << k) + (1 << (k - 1))};
	res.pb((1 << k));


//	cerr << n << ' ' << (1 << (k - 1)) - 1 << endl;
	vi tmp = solve((1 << (k - 1)) - 1);
	for (auto x : tmp) {
		res.pb(x + (1 << k));
		if (x + (1 << k) + (1 << (k - 1)) <= n)
			res.pb(x + (1 << k) + (1 << (k - 1)));	
	}

	tmp = solve((1 << k) - 1);
	for (auto x : tmp)
		res.pb(x);
	return res;

}
 
void solve() {
	cin >> n;
	vi res = solve(n);
	if (res[0] == -1) {
		cout << "NO";
		return;
	}                 

	cout << "YES\n";
	for (auto x : res)
		cout << x << ' ';
/*
	cout << endl << endl;
	for (auto x : res) {
		for (int j = 5; j >= 0; --j)
			cout << ((x >> j) & 1);
		cout << endl;
	}*/
	
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}