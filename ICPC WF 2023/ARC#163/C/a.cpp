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
set < int > q;
 
void solve() {
	cin >> n;
	if (n == 1) {
		cout << "Yes" << endl;
		cout << 1 << endl;
		return;
	}

	if (n == 2) {
		cout << "No\n";
		return;
	}

	q.clear();
	q.insert(2);
	q.insert(3);
	q.insert(6);

	while (sz(q) < n) {
		int del = -1;
		int add1 = -1, add2 = -2;
		for (auto x : q)
			if (!q.count(x + 1) && !q.count(x*(x + 1))) {
				del = x;
				add1 = x + 1;
				add2 = x*(x + 1);
				break;
			}

		assert(del != -1);
		q.erase(del);
		q.insert(add1);
		q.insert(add2);
	}

	cout << "Yes\n";
	for (auto x : q)
		cout << x << ' ';	
	cout << endl;
}

main () {
	fastio
  int TT;
  TT = 1;
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}