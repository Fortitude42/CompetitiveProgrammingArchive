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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
int a, b, xa, ya, xb, yb, ans;
set < int > q;

int get (int l, int r, int k) {
//	cerr << l << ' ' << r << ' ' << k << endl;
	if (l < 0 && r < 0)
		return get(-r, -l, k);

	if (l < 0)
		return get(1, -l, k) + get(0, r, k);
	if (!l)
		return r / k + 1;
//	cerr << (r + k - 1) / k << endl;
	return r / k - (l - 1) / k;
}

main () {
	cin >> a >> b >> xa >> ya >> xb >> yb;
	a += a;
	b += b;

	if (xa > xb) {
		swap(xa, xb);
		swap(ya, yb);
	}

	{
		if ((xa + ya) % a == 0 && (xa - ya) % b != 0) 
			q.insert(xa + ya);
		if ((xb + yb) % a == 0 && (xb - yb) % b != 0)
			q.insert(xb + yb);

		ans = get(min(xa - ya, xb - yb), max(xa - ya, xb - yb), b) + sz(q);
	} 
	
	q.clear();
	int ans1 = 0;

	{
		if ((xa - ya) % b == 0 && (xa + ya) % a != 0)	
			q.insert(xa - ya);
		if ((xb - yb) % b == 0 && (xb + yb) % a != 0)
			q.insert(xb - yb);

		ans1 = get(min(xa + ya, xb + yb), max(xa + ya, xb + yb), a) + sz(q);
	}

	cout << max(ans, ans1);
}