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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int n, s, t, a[N];

struct line {
	int k, b;
	line () {
	
	}

	line (int k_, int b_) {
		k = k_;
		b = b_;
	}                                 	
};

int l, r, d[N], b[N];
vector < line > v[2];

ldb inter (line A, line B) {
	return (A.b - B.b + 0.0) / (B.k - A.k);
}


void addLine (int i, line L) {
	if (sz(v[i]) && L.k >= v[i].back().k)
		return;

//	if (!i)	
//		cout << L.k << ' ' << L.b << endl;

	while (sz(v[i]) > 1 && inter(v[i].back(), L) <= inter(v[i].back(), v[i][sz(v[i]) - 2]))	
		v[i].ppb();
	v[i].pb(L);
}

int get (int i, int x) {
//	cerr << x << endl;
	int res = v[i][0].k*x + v[i][0].b;

	int l = 1, r = sz(v[i]) - 1;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (inter(v[i][mid], v[i][mid - 1]) <= (x + 0.0)) {
			res = min(res, v[i][mid]o.k*x + v[i][mid].b);
			l = mid + 1;
		} else
			r = mid - 1;
	}

//	if (!i)
//		cout << x << " =  " << res << endl;

	return res;
}
 
main () {
	scanf("%lld%lld%lld", &n, &s, &t);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);     
		d[i] = INF;
	}

	d[s] = 0;
	b[s] = a[s];
	l = r = s;

	addLine(0, line(a[s], -a[s] * s));
	addLine(1, line(a[s], a[s] * s));

	while (1) {
//		cerr << l << ' ' << r << endl;
		if (l == 1 && r == n)
			break;

		if (l == 1)  {
			r++;
			d[r] = min(d[r - 1] + b[r - 1], get(0, r));
			b[r] = min(a[r], b[r - 1]);
			continue;
		}

		if (r == n) {
			--l;
			d[l] = min(d[l + 1] + b[l + 1], get(1, -l));
			b[l] = min(b[l + 1], a[l]);
			continue;
		}

		d[r + 1] = min(d[r] + b[r], get(0, r + 1));
		d[l - 1] = min(d[l] + b[l], get(1, -l + 1));

		if (d[r + 1] < d[l - 1]) {
			++r;
			b[r] = min(b[r - 1], a[r]);
			addLine(1, line(a[r], d[r] + a[r] * r));
		} else {
			--l;
			b[l] = min(b[l + 1], a[l]);
			addLine(0, line(a[l], d[l] - a[l]*l));
		}
	}	


//	for (int i = 1; i <= n; ++i)
//		cout << d[i] << ' ';
	for (int i = 1; i <= n; ++i)
		cerr << d[i] << ' ';
	cout << d[t] << endl;
//	cerr << d[t] << endl;
}