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


int n, a[N], cnt[N], b[N], t[N];
vi vals;

void inc (int pos, int x) {
//	cerr << " + " << pos << ' ' << x << endl;
	while (pos < N) {
		t[pos] = min(t[pos], x);
		pos |= pos + 1;
	}
}
            	

int get (int r) {
	int res = inf;
	while (r >= 0) {
		res = min(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}


main () {
	for (int i = 0; i < N; ++i)
		t[i] = inf;


	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	int mx = *max_element(a + 1, a + 1 + n);
	vals.pb(0);

	for (int i = 1; i <= n; ++i) {
		cnt[i] = cnt[i - 1];
		if (a[i] == mx)
			++cnt[i];


		b[i] = cnt[i]*2 - i;
		vals.pb(b[i]);
//		cerr << i << ' ' << cnt[i] << ' ';
//		cerr << cnt[i] * 2 - i << endl;
	}
	
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	int l = 0, r = -1;
	for (int i = 0; i <= n; ++i) {
		b[i] = lower_bound(all(vals), b[i]) - vals.begin();
		int lf = get(b[i] - 1);
		if (i - lf > r - l) {
			l = lf + 1;
			r = i;
		}

		inc(b[i], i);
	}

	cout << l << ' ' << r << endl;
}