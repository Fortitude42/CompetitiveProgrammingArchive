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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, r[N], c[N][14], a[N], cnt[N];
vpii v;
int get (int l, int r, int i) {
	if (!l)
		return c[r][i];

	return c[r][i] - c[l - 1][i];
}

int get (int l, int r) {
	if (!l)	
		return v[r].s;

	return v[r].s - v[l - 1].s;
}

void ask (int x) {
	cout << x << endl;
	string s;
	cin >> s;

	if (s == "End")
		exit(0);

	if (s == ">=") {
		for (int i = 1; i <= n; ++i) {
			if (a[i] && a[i] >= x)
				--cnt[i];
			cin >> a[i];
		}
	}

	if (s == "<=") {
		for (int i = 1; i <= n; ++i) {
			if (a[i] && a[i] <= x)
				--cnt[i];
			cin >> a[i];
		}
	}
}

int l2 (int x) {
	for (int i = 0; ; ++i)
		if ((1 << i) > x)
			return i;
}

int get1 (int i) {
	return min((i + 1) * v[i].s, (sz(v) - i) * get(i, sz(v) - 1));
}
 
main () {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
		
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[i] = k;
	}

	while (1) {
		v.clear();
		int mx = 0;
		for (int i = 1; i <= n; ++i)
			if (cnt[i]) {
				v.pb({a[i], cnt[i]});
			}			


		sort(all(v));
		for (int i = 0; i < sz(v); ++i) {
			for (int j = 1; j <= k; ++j)
				c[i][j] = !i ? 0 : c[i - 1][j];
			++c[i][v[i].s];
		}

		int j = -1, mn = inf;

		for (int i = 0; i < sz(v); ++i) {
			int s1 = 0, s2 = 0;
			for (int j = 1; j <= k; ++j) {
				s1 += l2(get(0, i, j));
				s2 += l2(get(i, sz(v) - 1, j));
			}

			if (max(s1, s2) < mn) {
				mn = max(s1, s2);
				j = v[i].f;
			}
		}
		ask(j);
	}
}                                                   