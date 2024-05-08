#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], b[N];
set < int > q;
vi pos[N];

int getPrv (int x) {
	if (!sz(q) || *q.begin() >= x)	
		return -1;

	auto it = q.lower_bound(x);
	it--;
	return *it;
}

int getNxt (int x) {
	if (!sz(q) || *q.rbegin() <= x)
		return inf;

	return *q.upper_bound(x);
}

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];              
		b[i] = a[i];
	}

	for (int i = n + 1; i <= n + n + n; ++i)
		a[i] = a[i - n];

	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n + n + n; ++i)  {
		a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
		pos[a[i]].pb(i);
	}

	int ans = inf, i, j, k;
	for (int x = 1; x <= n; ++x) {
		for (auto a : pos[x]) {
			int b = getPrv(a), c = getNxt(a);
			if (b == -1 || c == inf)
				continue;
			if (c - b < ans) {
				ans = c - b;
				i = b, j = a, k = c;
			}
		}

		for (auto a : pos[x])
			q.insert(a);
	}

	while (i > n)
		i -= n;
	while (j > n)
		j -= n;
	while (k > n)
		k -= n;


	cout << i << ' ' << j << ' ' << k << endl;
	
}