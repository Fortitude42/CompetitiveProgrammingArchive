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

int n, q;
int a[M], t[M];


void inc(int pos, int x) {
	while (pos <= n) {
		t[pos] += x;
		pos |= pos + 1;
	}
}

int get(int r) {
	int res = 0;
	while (r > 0) {
		res += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}



void solve() {
	cin >> n >> q;
	set < int > p;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] == 1)
			p.insert(i);

		inc(i, a[i]);
	}


	while (q--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int s;
			cin >> s;
			int all = get(1, n);
			if (s > all) {
				cout << "NO\n";
				continue;
			}

			if ((s & 1) == (all & 1)) {
				cout << "YES\n";
				continue;
			}

			if (sz(p)) {
				int l = *p.begin();
				int r = *p.rbegin();
				int pref = get(1, l);
				int suff = get(r, n);
				if (all - pref >= s || all - suff >= s) {
					cout << "YES\n";
					continue;
				}
			}

			cout << "NO\n";
		} else {
			int i, v;
			cin >> i >> v;
			if (a[i] == v)
				continue;
			a[i] = v;

			if (v == 2) {// 1 -> 2
				inc(i, 1);
				p.erase(i);
			} else {//2 -> 1
				inc(i, -1);
				p.insert(i);
			}
		}
	}



	for (int i = 1; i <= n; ++i)
		t[i] = 0;
}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;

  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}