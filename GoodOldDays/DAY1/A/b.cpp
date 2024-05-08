#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                       	
#define int long long 
 
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
 
const int inf = 1e18, maxn = 2e5 + 48, mod = 998244353, N = 2e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, res[N], ans, p[N], prv[N], l[N], r[N];
//vpii add[N];
map < int, vpii > add;
vi vals;

struct segment {
	int l, r, p, id;
} a[N];

vector < segment > g[N];

bool cmp (int x, int y) {
	return res[x] > res[y];
}


main () {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].p);
		l[i] = a[i].l, r[i] = a[i].r;
		p[i] = i;
		vals.pb(a[i].p);
		a[i].id = i;
	}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	k = sz(vals);

	
	for (int i = 1; i <= n; ++i) {
		a[i].p = lower_bound(all(vals), a[i].p) - vals.begin();
		g[a[i].p].pb(a[i]);
	} 


	for (int i = 0; i < k; ++i) {
		vi val;
		for (auto x : g[i]) {
			val.pb(x.l); 
			val.pb(x.r);
		}

		val.pb(inf);
		sort(all(val));
		val.resize(unique(all(val)) - val.begin());
		
		for (auto x : g[i]) {
//			x.l = lower_bound(all(val), x.l) - val.begin();
			add[x.l].pb(mp(x.r, x.id));
		}


		set < pii > q;
		for (int X = 0; X <= inf; ++X) {
			for (auto y : add[X])
				q.insert(y);	
			
			if (!sz(q)) {
			    if (X == inf)
			    	break;
				int Y = *lower_bound(all(val), X);
				if (X != Y)
					X = Y - 1;
			} else {
				if (q.begin()->f < X) {
					cout << "NO";
					return 0;
				}

//				cerr << q.begin()->s << ' ' << X << endl;
				res[q.begin()->s] = X;
				q.erase(q.begin());
		 	}
		}


		add.clear();
		if (sz(q)) {
			cout << "NO";
			return 0;
		}

	}


	sort(p + 1, p + 1 + n, cmp);

	multiset < int > qq;
	for (int i = 0; i < k; ++i)  {
		prv[i] = inf + 1; 
		qq.insert(prv[i]);
	}


	
	set < int > Q;	
	for (int j = 1; j <= n; ++j) {
		int i = p[j];

		qq.erase(qq.find(prv[a[i].p]));
	
		int cur = min(a[i].r, prv[a[i].p] - 1);

		if (sz(qq) && cur >= *qq.begin())  
			res[i] = *qq.begin();

		prv[a[i].p] = res[i];
		Q.insert(res[i]);
		qq.insert(prv[a[i].p]);
	}

	printf("%d\n", sz(Q));
	for (int i = 1; i <= n; ++i) {
	    assert(res[i] >= l[i] && res[i] <= r[i]);
		printf("%d\n", res[i]); 
	}


}                       