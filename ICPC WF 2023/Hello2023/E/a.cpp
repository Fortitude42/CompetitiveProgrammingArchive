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
const int N = 250, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n;
bool used[M];


int ask(int id) {
	cout << "? " << id << ' ';
	for (int i = 1; i <= n; ++i)
		cout << used[i];
	cout << endl;
	int x;
	cin >> x;
	return x;
}
 
void solve() {
	cin >> n;
	 
	vector < vi > v;
	v.pb({1});

	for (int i = 2; i <= n; ++i) {
		memset(used, 0, sizeof used);
		for (int j = 1; j < i; ++j)
			used[j] = 1;

		int x = ask(i);
		if (x == 0) {
			v.pb({i});
			continue;
		}

		if (x == i - 1) {
			reverse(all(v));
			v.pb({i});
			reverse(all(v));
			continue;
		}

		reverse(all(v));
		int ii = 0;
		int s = 0;
		while (ii < sz(v) && s < x) {
			s += sz(v[ii]);
			++ii;
		}

		assert(s >= x);

		if (s == x) {
			memset(used, 0, sizeof used);
			for (int j = 0; j < ii; ++j) {
				for (auto x : v[j])
					used[x] = 1;
			}

			int y = ask(i);

			if (y == x) {
				vector < vi > V;
				for (int j = 0; j < ii; ++j)
					V.pb(v[j]);
				V.pb({i});
				for (int j = ii; j < sz(v); ++j)
					V.pb(v[j]);
				v = V;
				reverse(all(v));
				continue;
			}
		}

		int l = ii - 1;
		while (l - 1 >= 0) {
			memset(used, 0, sizeof used);
			int tot = 0;
			for (int i1 = 0; i1 <= l - 1; ++i1)
				for (auto j : v[i1]) {
					used[j] = 1;
					++tot;
				}

			int xx = ask(i);
			if (xx == tot)
				break;							
			--l;
		}

		int r = ii - 1;
		while (r + 1 < sz(v)) {
			memset(used, 0, sizeof used);
			int tot = 0;
			for (int i1 = r + 1; i1 < sz(v); ++i1)
				for (auto j : v[i1]) {
					used[j] = 1;
					++tot;
				}

			int xx = ask(i);
			if (xx == 0) 
				break;
			++r;
		}


		vector < vi > V;
		for (int j = 0; j < l; ++j)
			V.pb(v[j]);

		vi nw = {i};
		for (int j = l; j <= r; ++j) 
			for (auto x : v[j])
				nw.pb(x);
		V.pb(nw);
		for (int j = r + 1; j < sz(v); ++j)
			V.pb(v[j]);		
		v = V;
		reverse(all(v));
	}

	memset(used, 0, sizeof used);
	for (auto x : v[0])
		used[x] = 1;
	cout <<  "! ";
	for (int x = 1; x <= n; ++x)
		cout << used[x];
	cout << endl;
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }                      
}