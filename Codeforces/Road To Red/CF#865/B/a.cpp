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


int n, a[M];


int ask(int i, int j) {
	cout << "? " << i << ' ' << j << endl;
	int x;
	cin >> x;
	return x;
}

vi get(vector < pii > order) {
	int l = 1, r = n;
	vi res(n);
	while (sz(order)) {
		res[order.back().s - 1] = r;
		order.ppb();
		r--;

		if (sz(order)) {
			res[order.back().s - 1] = l;
			order.ppb();
			l++;
		}
	}

	return res;
}
 
void solve() {
	cin >> n;
	int tmp;
	cout << "+ " << n << endl;
	cin >> tmp;
	if (tmp == -2)
		exit(0);
	cout << "+ " << n + 1 << endl;
	cin >> tmp;
	if (tmp == -2)
		exit(0);

	pii mx = {-1, -1};
	for (int i = 2; i <= n; ++i)
		mx = max(mx, mp(ask(1, i), i));

	int v = mx.s;
	vector < pii > order;
	order.pb(mp(0, v));
	
	for (int i = 1; i <= n; ++i)
		if (i != v)
			order.pb(mp(ask(v, i), i));

	sort(all(order));
	vi ans1 = get(order);
	reverse(all(order));
	vi ans2 = get(order);
	cout << "! ";
	for (auto x : ans1)
		cout << x << ' ';
	for (auto x : ans2)
		cout << x << ' ';
	cout << endl;

	cin >> tmp;
	if (tmp == -2)
		exit(0);

}

main () {
	int TT = 1;
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}