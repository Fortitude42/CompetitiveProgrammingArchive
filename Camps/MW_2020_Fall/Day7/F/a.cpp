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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n, l[N], r[N], mn[N], t[N << 2], lz[N << 2], mx[N], s[N];

void push (int v) {
	if (lz[v] != -1) {
		t[v << 1] = max(t[v << 1], lz[v]);
		lz[v << 1] = max(lz[v << 1], lz[v]);

		t[v << 1 | 1] = max(t[v << 1 | 1], lz[v]);
		lz[v << 1 | 1] = max(lz[v << 1 | 1], lz[v]);

		lz[v] = -1;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 0, int tr = N - 1) {
	if (l > r || tl > r || l > tr)
		return;
	
	if (l <= tl && tr <= r) {
		lz[v] = max(lz[v], x);
		t[v] = max(t[v], x);
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v);

	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get (int pos, int v = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr)
		return t[v];

	int tm = (tl + tr) >> 1;
	push(v);

	if (pos <= tm)
		return get(pos, v << 1, tl, tm);

	return get(pos, v << 1 | 1, tm + 1, tr);
}


main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		++l[i];
		++r[i];
		++s[l[i]];
		--s[r[i] + 1];
	}


	memset(t, -1, sizeof(t));
	memset(lz, -1, sizeof(lz));
	memset(mx, -1, sizeof(mx));

	for (int i = 0; i < N; ++i)
		mn[i] = N - 1;

	for (int i = 1; i <= n; ++i) {
		mn[l[i]] = min(mn[l[i]], r[i]);
		mx[l[i]] = max(mx[l[i]], r[i]);
	}

	for (int i = N - 2; i >= 0; --i) 
		mn[i] = min(mn[i], mn[i + 1]);

	for (int i = 1; i < N; ++i) {
		mx[i] = max(mx[i], mx[i - 1]);
		s[i] += s[i - 1];
	}

	int x = *min_element(r + 1, r + 1 + n);
	update(1, x, 0);

	for (int i = 0; i < N; ++i) 
		if (get(i) > -1 && s[i]) 
			update(max(i, mx[i]) + 1, mn[i + 1], i);
		
	x = N - 1;
	while (!s[x] || get(x) == -1)
		x--;	


	vi ans;
	while (x) {
		ans.pb(x);
		x = get(x);
	}

	sort(all(ans));
	for (int i = 1; i <= n; ++i) 
		if (ans.back() < l[i] || *lower_bound(all(ans), l[i]) > r[i]) {
//			assert(n <= 100000);
			cout << -1 << endl;
			return 0;
		}

	printf("%d\n", sz(ans));
	for (auto x : ans)
		printf("%d\n", x - 1);
}