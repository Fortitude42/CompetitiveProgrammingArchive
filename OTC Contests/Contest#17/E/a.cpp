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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 25e4 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int T, n, a[N], p[N], pp[N], t[N];

void inc (int pos, int x) {
	pos = n + 1 - pos;
	while (pos < N) {
		t[pos] = max(t[pos], x);
		pos |= pos + 1;
	}
}

int get (int r) {
	r = n + 1 - r;

	int res = 0;
	while (r > 0) {
		res = max(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}
 
main () {
	fastio
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			p[a[i]] = -1;
			pp[i] = -1;
			t[i] = 0;
		}

		for (int i = n; i > 0; --i) {
			pp[i] = p[a[i]];
			p[a[i]] = i;
		}

		for (int i = 1; i <= n; ++i) {
			int cur = get(i + 1);
			inc(i, cur + 1);

			if (pp[i] != -1) {
				cur = get(pp[i] + 1);
				inc(pp[i], cur + 2);
			}
		}

		cout << *max_element(t + 1, t + 1 + n) << endl;
	}
}