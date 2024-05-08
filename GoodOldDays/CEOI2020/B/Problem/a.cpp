#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;
 
int n;
 
struct pt {
	int x, y, id;
 
	bool operator < (const pt &A) const {
		if (A.y == y)
			return x > A.x;
		return y < A.y;
	}
} a[N], b[N];
 
bool cmpx (pt a, pt b) {
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
 
bool cmpy (pt a, pt b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
 
bool check () {
	for (int i = 1; i <= n; ++i)
		if (a[i].x != b[i].x)
			return 0;
 
	return 1;
}
 
 
bool check1 () {
	for (int i = 1; i < n; ++i) 
		if ((a[i].y - b[i].y) * 1ll * (a[i + 1].x - b[i + 1].x) != (a[i + 1].y - b[i + 1].y) * 1ll * (a[i].x - b[i].x))
			return 0;
 
	return 1;	
}
 
main () {
    fastio
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y; 
		a[i].id = b[i].id = i;
	}
	
	if (check()) {
		for (int i = 1; i <= n; ++i) { 
			if (a[i].y > b[i].y)
				swap(a[i], b[i]);
		}
 
		sort(a + 1, a + 1 + n, cmpx);
		for (int i = 1; i < n; ++i)
			cout << b[a[i].id].x << ' ' << b[a[i].id].y << ' ' << a[i + 1].x << ' ' << a[i + 1].y << endl;
		return 0;	
	}
 
	if (check1()) {
		ldb k = (a[1].y - b[1].y + 0.0) / (a[1].x - b[1].x);
		for (int i = 1; i <= n; ++i) {
			if (k > 0 && a[i].x > b[i].x)
				swap(a[i], b[i]);			
 
			if (k <= 0 && a[i].x < b[i].x)
				swap(a[i], b[i]);			
		}
 
		vector < pair < db, pt > > V;
		for (int i = 1; i <= n; ++i) 
			V.pb(mp(a[i].y - k*a[i].x, a[i]));
 
		sort(all(V));
		for (int i = 0; i < n - 1; ++i)
			cout << b[V[i].s.id].x << ' ' << b[V[i].s.id].y << ' ' << V[i + 1].s.x << ' ' << V[i + 1].s.y << endl;
		return 0;		
	}
}