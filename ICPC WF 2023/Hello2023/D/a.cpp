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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m;
set < int > q;
int a[M], b[M], x[M];
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	vector < pii > v;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		v.pb({b[i], i});
	}

	cin >> m;
	for (int i = 1; i <= m; ++i) 
		cin >> x[i];

	
	sort(all(v));
	sort(x + 1, x + 1 + m);


	for (int i = 1; i <= n; ++i)
		if (b[i] > a[i]) {
			cout << "NO\n";
			return;
		}
	q.clear();
	for (int i = 1; i <= n; ++i)
		q.insert(i);

	int j = 0;
	
	for (int i = 1; i <= m; ++i) {
		int l = -1;

		while (j < sz(v) && v[j].f < x[i]) {
			if (v[j].f != a[v[j].s]) {
				cout << "NO\n";
				return;
			}

			q.erase(v[j].s);
			++j;
		}

		while (j < sz(v) && v[j].f == x[i]) {
			if (v[j].f == a[v[j].s]) {
				q.erase(v[j].s);
				++j;
				continue;
			}

			if (l == -1) {
				l = v[j].s;
				q.erase(v[j].s);
				++j;
				continue;
			}

			auto it = q.lower_bound(l);
			if (it != q.end() && *it < v[j].s)
				break;			

			q.erase(v[j].s);
			++j;
		}
	}

	while (j < sz(v)) {
		if (v[j].f != a[v[j].s]) {
			cout << "NO\n";
			return;
		}

		++j;
	}

	cout << "YES\n";
	
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