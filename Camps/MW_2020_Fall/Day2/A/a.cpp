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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 33), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

pii p[N];
int n, a[N];
set < pii > q;
 
void add (int &x, int y, int m) {
	x += y;
	if (x >= m)
		x -= m;
	if (x < 0)
		x += m;
}

void f () {
	pii H = {0, 0};
	for (int i = 0; i < n; ++i) {
	    add(H.f, p[i].f * 1ll * a[i] % Mod.f, Mod.f);
	    add(H.s, p[i].s * 1ll * a[i] % Mod.s, Mod.s);
	}
	
	for (int i = n - 1; i >= 0; --i) {
		add(H.f, -p[n - 1].f * 1ll * a[i] % Mod.f, Mod.f);
		add(H.s, -p[n - 1].s * 1ll * a[i] % Mod.s, Mod.s);

		H.f = H.f * 1ll * base.f % Mod.f;
		H.s = H.s * 1ll * base.s % Mod.s;

		add(H.f, a[i], Mod.f);
		add(H.s, a[i], Mod.s);
		q.insert(H);
	}
}

main () {
	p[0] = {1, 1};
	for (int i = 1; i < N; ++i)
		p[i] = {p[i - 1].f * 1ll * base.f % Mod.f, p[i - 1].s * 1ll * base.s % Mod.s};

	while (scanf("%d", &n) == 1) {		
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		q.clear();	
		f();
		reverse(a, a + n);
		f();
		cout << sz(q) << endl;
	}
}