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
const int N = 1e5, inf = 2e8, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

ll n, nn;
set < ll > q;
vector < pair < ll, int > > primes;
vector < vector < ll > > ans;
 
inline void check(ll x) {
	if (q.count(x))	
		return;
	q.insert(x);
//	cerr << "---> " << x << endl;

	ll m = n;
	vector < ll > cur;
	while (x > 1 && !(m % x)) {
		m /= x;
		cur.pb(x);
	}

	while (!(m % (x + 1))) {
		m /= (x + 1);
		cur.pb(x + 1);
	}

	if (m > 1)
		return;

	if (x == 1) {
		cout << -1 << endl;
		exit(0);
	}

	ans.pb(cur);
}

void rec(int i = 0, ll x = 1) {
	if (i == sz(primes)) {
		check(x);
		if (x > 1)
			check(x - 1);
		return;
	}

	rec(i + 1, x);
	for (int y = 0; y < primes[i].s; ++y) {
		x *= primes[i].f;
		rec(i + 1, x);
	}
}

void solve() {
	cin >> n;
	if (n == 1) {
		cout << -1 << endl;
		return;
	}

	nn = n;
	for (int x = 2; x <= inf; ++x) {
		if (n % x)
			continue;
		int cnt = 0;
		while (!(n % x)) {
			n /= x;
			cnt++;
		}

		primes.pb({x, cnt});
	}

	if (n > 1)
		primes.pb({n, 1});

	n = nn;
	rec();

	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());
	cout << sz(ans) << endl;
	for (auto v : ans) {
		cout << sz(v) << ' ';
		for (auto x : v)
			cout << x << ' ';
		cout << endl;
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