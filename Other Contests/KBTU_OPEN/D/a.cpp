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

vi b, vals;
pii a[N], t[N], dp[N];
int n, k, tt[N], timer;

void inc (int pos, pii x) {
	while (pos < N) {
		t[pos] = max(t[pos], x);
		pos |= pos + 1;
	}
}

pii get (int r) {
	pii res = {0, 0};

	while (r >= 0) {
		res = max(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}


int main()
{
    scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].f, &a[i].s); 
		vals.pb(a[i].s);
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 1; i <= n; ++i)
		a[i].s = lower_bound(all(vals), a[i].s) - vals.begin();

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		b.pb(a[i].s);

	while (k--) {
		for (int i = 0; i < N; ++i)
			t[i] = mp(0, -1);

		for (int i = 0; i < sz(b); ++i) {
			pii cur = get(b[i]);
			dp[i] = mp(cur.f + 1, cur.s);
			inc(b[i], mp(cur.f + 1, i));
		}               	
		cerr << "hello\n";

		int j = 0;
		for (int i = 0; i < sz(b); ++i)
			if (dp[i].f > dp[j].f)
				i = j;

		++timer;
		while (j >= 0) {
			tt[j] = timer;
			j = dp[j].s;
		}

		vi c;
		for (int i = 0; i < sz(b); ++i)
			if (tt[i] != timer)
				c.pb(b[i]);

		b = c;
	}

	cout << n - sz(b);
}