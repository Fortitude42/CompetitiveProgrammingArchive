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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5e4 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, k, s[N][10], mn[N][10], mx[N][10], p[N], cnt[N];
set < pii > q[10], qq[10];

int get (int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge (int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])
		swap(v, u);

	p[u] = v;
	cnt[v] += cnt[u];
	for (int i = 0; i < k; ++i) {
		q[i].erase(mp(mx[v][i], v));
		qq[i].erase(mp(mn[v][i], v));
		q[i].erase(mp(mx[u][i], u));
		qq[i].erase(mp(mn[u][i], u));
	}

	for (int i = 0; i < k; ++i) {
		mx[v][i] = max(mx[v][i], mx[u][i]); 
		mn[v][i] = min(mn[v][i], mn[u][i]);
		q[i].insert(mp(mx[v][i], v));
		qq[i].insert(mp(mn[v][i], v));
	}
}

int cmp (int i, int j) {
	i = get(i), j = get(j);
	bool ok1 = 0, ok2  = 0;
	for (int x = 0; x < k; ++x) {
		if (mx[i][x] > mn[j][x]) 
			ok1 = 1;
		if (mx[j][x] > mn[i][x])
			ok2 = 1;
	}

	if (ok1 && ok2)
		return 0;
	if (ok1)
		return 1;
	return -1;
}

main () {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k; ++j) {
			scanf("%d", &s[i][j]);   
			mx[i][j] = mn[i][j] = s[i][j];
		}

		p[i] = i;
		cnt[i] = 1;
		int l = -1, r = -1;
		for (int j = 0; j < k; ++j) {
//			cerr << "---> " << l << endl;
			auto it = q[j].lower_bound(mp(s[i][j], 0));
			if (it != q[j].end() && (l == -1 || cmp(l, it->s) >= 0)) 
				l = it->s;			                                  
			

			auto it1 = qq[j].lower_bound(mp(s[i][j], 0));
			if (it1 != qq[j].begin()) {
			    --it1;
			    if (r == -1 || cmp(r, it1->s) <= 0)
					r = it1->s;                                                
			}
		}		

/*		for (auto x : q[0])
			cerr << x.s << ' ';
		cerr << endl;
		for (auto x : qq[0])	
			cerr << x.s << ' ';
		cerr << endl;
		cerr << l << ' '  << r << endl << endl;*/
			
		if (l == -1 || r == -1 || cmp(l, r) > 0) {
			for (int j = 0; j < k; ++j) {
				q[j].insert(mp(mx[i][j], i));
				qq[j].insert(mp(mn[i][j], i));
			}
			printf("1\n");
			continue;
		}

		while (1) {
			if (get(l) == get(r))
				break;
			l = get(l);

			int ll = q[0].lower_bound(mp(mx[l][0], inf))->s;
			merge(l, ll);
			l = ll;
		}
		merge(i, l);

		printf("%d\n", cnt[get((*q[0].rbegin()).s)]);
	}
		
	
}