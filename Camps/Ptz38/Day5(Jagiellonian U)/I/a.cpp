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

int t, n;
char s[N];
vi v, one;
vector < vi > ans;

vi subtract (vi a, vi b) { //a - b
    vi c;
	for (int i = 0, carry = 0; i < sz(a); ++i) {
		int cur = a[i] - (i >= sz(b) ? 0 : b[i]) - carry;
		if (cur < 0) {
			cur += 10;
			carry = 1;
		} else
			carry = 0;
		c.pb(cur);	
	}

	while (sz(c) && !c.back())
		c.ppb();

	return c;
} 

bool cmp (vi a, vi b) {//a <= b
	if (sz(a) < sz(b))
		return 1;
	
	if (sz(a) > sz(b))
		return 0;

	for (int i = sz(a) - 1; i >= 0; --i)
		if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return 0;

	return 1;
}

main () {
	scanf("%d", &t);
	one.pb(1);

	while (t--) {
		scanf("\n%s", s);
		n = strlen(s);
		v.clear();
		ans.clear();
		for (int i = n - 1; i >= 0; --i)
			v.pb(s[i] - '0');

		while (sz(v) > 0) {
			if (sz(v) == 2 && !v[0] && v[1] == 1) {
				ans.pb({1});
				ans.pb({9});
				break;
			}

			vi va, vb;
			n = sz(v);
			for (int i = 0; i < n; ++i) {
				if (i >= n / 2)
					va.pb(v[i]);
				if (i < (n + 1) / 2)
					vb.pb(v[i]);
			}

			reverse(all(va));
				

			if (!cmp(va, vb)) {
				reverse(all(va));
				va = subtract(va, one);
				reverse(all(va));
			}
			

			int m = sz(va);
			int ok = 0;
			if (n % 2 == 1 && m == (n + 1) / 2)
				ok = 1;
			for (int i = m - 1 - ok; i >= 0; --i)
				va.pb(va[i]);
				
			reverse(all(va));

			ans.pb(va);
			v = subtract(v, va);
		}
		

		printf("%d\n", sz(ans));
		for (auto x : ans) {
			reverse(all(x));
			for (auto y : x)
				printf("%d", y);
			printf("\n");
		}
	}
}