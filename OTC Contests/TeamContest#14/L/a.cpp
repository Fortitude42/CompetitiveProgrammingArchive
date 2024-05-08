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

 
int n, h[N], s[N], mx[N][18][2], d[N];
ll w;

void build () {
	for (int i = 1; i <= n; ++i) {
		if (i > 1)
			d[i] = d[i / 2] + 1;
		mx[i][0][0] = h[i] - i;
		mx[i][0][1] = h[i] + i;
	}

	for (int j = 1; j < 18; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			for (int x = 0; x < 2; ++x)
				mx[i][j][x] = max(mx[i][j - 1][x], mx[i + (1 << (j - 1))][j - 1][x]);
}

int get1 (int x) {
	return x * (x + 1) / 2;
}

int get1 (int l, int r) {
	return get1(r) - get1(l - 1);
}

int get (int l, int r, int i) {
	int D = d[r - l + 1];
	return max(mx[l][D][i], mx[r - (1 << D) + 1][D][i]);
}


bool check (int i, int H) {
	int lf = i, rg = i;
	int l = 1, r = i - 1;
	
	while (l <= r) {
		int mid = (l + r) / 2;
		if (get(mid, i - 1, 0) >= H - i) 
			l = mid + 1;
		else {
			r = mid - 1;
			lf = mid;
		}			
	}

	l = i + 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (get(i + 1, mid, 1) >= H + i)
			r = mid - 1;
		else {
			l = mid + 1;
			rg = mid;
		}	
	}
//	cerr << lf << ' ' << rg << endl;

	if (lf == 1 || rg == n)
		return 0;

	int sum = get1(H - (i - lf), H) + get1(H - (rg - i), H - 1);
	sum -= s[rg] - s[lf - 1];

	return sum <= w;
}

main () {
	file("landscape");
	scanf("%lld%lld", &n, &w);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &h[i]);     
		s[i] = s[i - 1] + h[i];
	}

	build();
	
	int res = *max_element(h + 1, h + 1 + n);

	for (int i = 1; i <= n; ++i) {
		int l = h[i] + 1, r = inf * 10;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(i, mid)) {
				res = max(res, mid);
				l = mid + 1;
			} else
				r = mid - 1;
		}
	}

	cout << res << endl;
}