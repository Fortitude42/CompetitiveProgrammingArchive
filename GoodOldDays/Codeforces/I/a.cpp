#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 52;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
map < pair < string, int >, int > d;
set < pair < int, pair < string, int > > > q;

int n, c[N];
string s[N];

bool check (string s) {
	for (int i = 0; i < sz(s); ++i)
		if (s[i] != s[sz(s) - i - 1])
			return 0;

	return 1;
}

pair < string, int > get (string lf, string rg) {
	for (int i = 0; i < min(sz(lf), sz(rg)); ++i)
		if (rg[sz(rg) - i - 1] != lf[i])
			return mp("", -1);

	if (sz(lf) == sz(rg))
		return mp("", 0);

	if (sz(lf) > sz(rg))
		return mp(lf.substr(sz(rg), sz(lf) - sz(rg)), 0);

	return mp(rg.substr(0, sz(rg) - sz(lf)), 1);
}

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> c[i];
		for (int j = 0; j < 2; ++j)		
			if (!d.count(mp(s[i], j)) || d[mp(s[i], j)] > c[i]) {
				d[mp(s[i], j)] = c[i]; 
				q.insert(mp(c[i], mp(s[i], j)));
			}
	}

	while (sz(q)) {
		pair < string, int > v = q.begin()->s;
		int cost = q.begin()->f;
		q.erase(q.begin());

		if (check(v.f)) {
			cout << cost << endl;
			return 0;
		}

		for (int i = 1; i <= n; ++i) {
			pair < string, int > to;
			if (!v.s)
				to = get(v.f, s[i]);
			else
				to = get(s[i], v.f);

			if (to.s == -1)
				continue;

			if (!d.count(to) || d[to] > cost + c[i]) {
			    if (d.count(to))
					q.erase(mp(d[to], to));
				d[to] = cost + c[i];
				q.insert(mp(d[to], to));
			}
		}
	}

	cout << -1 << endl;
}
