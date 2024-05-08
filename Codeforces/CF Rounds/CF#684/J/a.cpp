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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, p[N], d[N], ans;

void f (int dist, int l) {
	int k = dist / d[l];
	ans += k * (d[l] + 1);
	dist %= d[l];
	ans += dist;
} 

main () {
	for (int i = 2; i < N; ++i)
		d[i] = d[i >> 1] + 1;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	sort(p + 1, p + 1 + n);
	reverse(p + 1, p + 1 + n);
	vpii v;
	for (int i = 2; i <= n; ) {
		int j = i, cnt = 0;
		while (j <= n && p[i] == p[j]) {
			++cnt;
			++j;
		}

		v.pb(mp(p[i], cnt));
		i = j;
	}

	int l = v[0].s, dist = p[1] - p[2];

	for (int i = 1; i < sz(v); ++i) {
		if (dist < d[l] * (v[i - 1].f - v[i].f)) {
			break;				
		}

		dist -= d[l] * (v[i - 1].f - v[i].f);
		ans += (d[l] + 1) * (v[i - 1].f - v[i].f);
		l += v[i].s;
	}

	f(dist, l);
	cout << ans << endl;
	return 0;
}