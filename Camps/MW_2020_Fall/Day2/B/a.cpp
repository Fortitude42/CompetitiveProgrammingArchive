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


int n, t[N], timer;
char s[N];

bool check (int x) {
	++timer;
	deque < int > st;
	vector < pii > v, vv;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '2')
			st.pb(i);

		if (s[i] == '0' && sz(st)) {
			int j = st.front();
			st.pop_front();
			v.pb(mp(j, i));
			t[i] = t[j] = timer;
			if (sz(v) == x)
				break;
		}
	}

	if (sz(v) < x)
		return 0;

	while (sz(st))
		st.pop_back();

	for (int i = n - 1; i >= 0; --i) {
		if (t[i] == timer)
			continue;

		if (s[i] == '0')
			st.pb(i);

		if (s[i] == '2' && sz(st)) {
			int j = st.front();
			st.pop_front();
			vv.pb(mp(i, j));
			if (sz(vv) == x)
				break;				
		}
	}

	if (sz(vv) < x)
		return 0;

	reverse(all(vv));

/*	if (OK) {
	for (int i = 0; i < x; ++i)
		cerr << v[i].f << ' ' << v[i].s << endl;
	cerr << endl << endl;

	for (int i = 0; i < x; ++i)
		cerr << vv[i].f << ' ' << vv[i].s << endl;
	}*/
	for (int i = 0; i < x; ++i)
		if (v[i].s >= vv[i].f)
			return 0;

	return 1;        	
}


 
main () {
	while (scanf("%d", &n) == 1) {
		scanf("\n%s", s);

		int l = 1, r = n / 4, res = 0;

		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				res = mid;
				l = mid + 1;
			} else
				r = mid - 1;							
		}

		printf("%d\n", res);
	}
}