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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 999983, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n, k, l, s[55], L; 
set < int > q;

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}

vi mult (vi x, vi y) {
    vi res;
    int n = sz(x), m = sz(y);
    res.resize(n + m - 1);

	for (int i = 0; i < sz(x); ++i) 
		for (int j = 0; j < sz(y); ++j)
			add(res[i + j], x[i] * 1ll * y[j] % mod);	

	return res;
}

main () {
	cin >> t;
	while (t--) {
		q.clear();

		cin >> n >> k >> l;
		for (int i = 1; i <= l; ++i) {
			cin >> s[i];              
			add(s[i], 0);
			q.insert(s[i]);
		}

		L = l;
		sort(s + 1, s + 1 + l);
		l = unique(s + 1, s + 1 + l) - s - 1;

		if (l > k) {
			cout << 0 << endl;
			continue;
		}


		vi v;
		v.pb(1);
		for (int i = 1; i <= l; ++i) {
			vi vv;
			vv.pb(mod - s[i]);
			vv.pb(1);
			v = mult(v, vv);
		}

		if (l == k) {
			cout << 1 << endl;
			cout << k << ' ';
			reverse(all(v));
			for (auto i : v)	
				cout << i << ' ';
			cout << endl;
			continue;
		}

		cout << n << endl;
		int timer = 0;
		for (int i = mod - 1; i > 0; --i) {
			if (q.count(i))
				continue;
			vi vv;
			vv.pb(-i);
			vv.pb(1);
			
			vi v1 = mult(v, vv);
			reverse(all(v1));
			cout << sz(v1) - 1 << ' ';
			for (int i : v1) {
				cout << i << ' ';
				assert(i > 0);
			}
			cout << endl;
			++timer;
			if (timer == n)
				break;
		}
	}
}