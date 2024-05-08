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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, a[N], b[N], t[N + N], ans, c[N];
vi cur, vals, vv;
bool was[N];

void inc (int pos, int x) {
	while (pos < N + N) {
		vv.pb(pos);
		t[pos] = max(t[pos], x);
		pos |= pos + 1;
	}
}   

int get (int r) {
	int res = 0;
	while (r >= 0) {
		res = max(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}

int calc (int l, int r) {
	for (auto x : vv)
		t[x] = 0;
	vv.clear();
	vals.clear();

	if (r - l - 1 < sz(cur)) {
//		cerr << l << ' ' << r << ' ' << sz(cur) << endl;
		cout << -1 << endl;
		exit(0);
	}

	vi cur1;
	for (int i = 0; i < sz(cur); ++i)
		if (l + i + 1 <= a[cur[i]] && a[cur[i]] <= r - (sz(cur) - i)) {
			cur1.pb(a[cur[i]] - i);                                        
			vals.pb(a[cur[i]] - i);
		}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 0; i < sz(cur1); ++i)
		cur1[i] = lower_bound(all(vals), cur1[i]) - vals.begin();
	

	for (auto x : cur1) {
		int y = get(x);
		inc(x, y + 1);
	}

//	cerr << sz(cur) - get(N + N - 1) << endl;
	return sz(cur) - get(N + N - 1);
}

 
main () {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);       
		
	for (int i = 1; i <= k; ++i)  {
		scanf("%d", &b[i]);        
		was[b[i]] = 1;
	}
	
	
	a[0] = -inf;
	was[n + 1] = 1;
	a[n + 1] = inf + inf / 10;

	int prv = 0;
	for (int i = 1; i <= n + 1; ++i) 
		if (was[i]) {
			ans += calc(a[prv], a[i]);
			prv = i;
			cur.clear();
		} else 
			cur.pb(i);
		
	
	cout << ans << endl;			
}