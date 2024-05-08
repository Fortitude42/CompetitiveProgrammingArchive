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
 
const int inf = 1e9, maxn = 1e6 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, m, a[N], b[N], c[maxn], t[maxn << 2], add[maxn << 2];
ll e[maxn], f[maxn], dp[maxn];
int l[maxn], r[maxn];
bool was[maxn];

inline void push (int v) {
	if (add[v]) {
		t[v << 1] += add[v];
		t[v << 1 | 1] += add[v];
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		add[v] = 0;
	}
}


void update (int l, int r, int x, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (l > r || tl > r || l > tr)
		return;

	if (l <= tl && tr <= r) {
		t[v] += x;
		add[v] += x;
		return;
	}

	push(v);

	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);		
}

int getRight (int l, int r, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (l > r || l > tr || tl > r || t[v] > 0)
		return -1;

	if (tl == tr)
		return tl;
	push(v);
	int tm = (tl + tr) >> 1;

	int x = getRight(l, r, v << 1 | 1, tm + 1, tr);
	if (x != -1)
		return x;
	
	return getRight(l, r, v << 1, tl, tm);
}

int getLeft (int l, int r, int v = 1, int tl = 0, int tr = maxn - 1) {
	if (l > r || tl > r || l > tr || t[v] > 0)
		return -1;

	if (tl == tr)
		return tl;

	push(v);
	int tm = (tl + tr) >> 1;
	int x = getLeft(l, r, v << 1, tl, tm);
	if (x != -1)
		return x;

	return getLeft(l, r, v << 1 | 1, tm + 1, tr);
}

ll get (int l, int r) {
	return (e[r] - f[r]) - (e[l - 1] - f[l - 1]);
}

 
main () {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		f[b[i]] += b[i];
		--c[b[i]];
	}

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		e[a[i]] += a[i];
		++c[a[i]];
		was[a[i]] = 1;
	}

	

	for (int i = 0; i < maxn; ++i) {
		e[i] += e[i - 1];           
		f[i] += f[i - 1];
	}

	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));


		
	for (int i = 0; i < maxn; ++i) {
		if (c[i])
			update(0, i, c[i]);
		if (was[i])
			l[i] = getRight(0, i);
	}

	memset(t, 0, sizeof(t));
	memset(add, 0, sizeof(add));
	for (int i = maxn - 1; i >= 0; --i) {
		if (c[i])
			update(i, maxn - 1, c[i]);

		if (was[i])
			r[i] = getLeft(i, maxn - 1);
	}

	for (int i = 0; i < maxn; ++i)
		dp[i] = INF;

	dp[0] = 0;
	for (int i = 1; i < maxn; ++i) {
		if (!was[i]) {
			dp[i] = min(dp[i - 1], dp[i]); 
			continue;
		}

		if (l[i] != -1)
			dp[i] = min(dp[i], dp[l[i] - 1] + get(l[i], i));
		if (r[i] != -1)
			dp[r[i]] = min(dp[r[i]], dp[i - 1] - get(i, r[i]));
	}


	cout << dp[maxn - 1] << endl;
}