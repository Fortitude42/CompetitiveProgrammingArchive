#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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


struct Line {
mutable ll k, m, p;
bool operator<(const Line& o) const { return k < o.k; }
bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
// ( for doubles , use in f = 1/.0 , div (a , b) = a/b)
static const ll inf = LLONG_MAX;
ll div(ll a, ll b) { // f loored division
return a / b - ((a ^ b) < 0 && a % b); }
bool isect(iterator x, iterator y) {
if (y == end()) return x->p = inf, 0;
if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
else x->p = div(y->m - x->m, x->k - y->k);
return x->p >= y->p;
}
void add(ll k, ll m) {
auto z = insert({k, m, 0}), y = z++, x = y;
while (isect(y, z)) z = erase(z);
if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
while ((y = x) != begin() && (--x)->p >= y->p)
isect(x, erase(y));
}
ll query(ll x) {
    if (empty())
        return 0;
auto l = *lower_bound(x);
return l.k * x + l.m;
}
};




struct item {
	int d, p, r, g;
	bool operator < (const item &i) const {
		return d < i.d; 
	}
};

int n, c, D;
ll dp[M];
item a[M];


void solve(int tt) {
	cin >> n >> c >> D;
	if (!n)
		exit(0);

	for (int i = 1; i <= n; ++i)
		cin >> a[i].d >> a[i].p >> a[i].r >> a[i].g;

	sort(a + 1, a + 1 + n);

	LineContainer lc;
	for (int i = 1; i <= n;) {
		vector < pii > to_add;
		int j = i;
		while (i <= n && a[i].d == a[j].d) {
			ll cur = max(lc.query(a[i].d - 1), (ll)c);
			if (cur >= a[i].p)
				to_add.pb({a[i].g, cur - a[i].p + a[i].r - a[i].g*a[i].d});			
			i++;					
		}

		for (auto x : to_add)
			lc.add(x.f, x.s);
	}

	cout << "Case " << tt << ": " << max((ll)c, lc.query(D)) << "\n";
}

main () {
  int TT;
  TT = 1;
  for (int tt = 1; ; ++tt) {
    solve(tt);
  }
}