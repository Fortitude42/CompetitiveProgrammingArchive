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
const int N = 1e2, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, r, c;
vi a[M];

int _find(int i) {
	for (int j = 0; j < n; ++j)
		if (a[i][j] == i)
			return j;

	assert(0);
}

void _move(int i, int p) {
	int g = _find(i) % c;
	vi tmp;
	for (int pc = 0; pc < c; ++pc) 
		for (int pr = 0; pr < r; ++pr) {
			int val;
			if (pc == g)
				val = a[i][pr*c + p];
			else if (pc == p)
				val = a[i][pr*c + g];
			else
				val = a[i][pr*c + pc];
			tmp.pb(val);
		}
	
	a[i] = tmp;
}


int get(int x, int y) {
	return x*r + y;
} 

void solve() {
	cin >> r >> c;
	n = r*c;
	vector < pii > coords = {
		mp((r + 1)/2 - 1, (c + 1)/2 - 1),
		mp((r + 1)/2, c/2),
		mp(r/2 - 1, (c + 1)/2 - 1),
		mp(r/2, c/2)
	};


	for (auto x : coords)
		cout << get(x.f, x.s) << ' ';
	cout << endl;


	for (int p = 0; p < c; ++p) {
		for (int i = 0; i < n; ++i) {
			a[i].clear();
			for (int j = 0; j < n; ++j)
				a[i].pb(j);
		}
		for (int s = 0; s < r+c; ++s) 
			for (int i = 0; i < n; ++i)
				_move(i, p);
			
		int pos = _find(0);

		bool ok = 1;
		for (int i = 1; i < n; ++i) {
			ok &= _find(i) == pos;
//			cerr << _find(i) << ' ';
		}
//		cerr << endl;

		if (!ok)
			continue;

		int ans = inf;
		int posx = pos / c, posy = pos % c;
		for (auto x : coords) {
			ans = min(ans, abs(posx - x.f) + abs(posy - x.s));
		}

		cout << "==== " << p << " ";
		cout << ans << endl;
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