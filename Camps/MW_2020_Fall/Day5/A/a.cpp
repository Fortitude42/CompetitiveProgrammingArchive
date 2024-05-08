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


vi comp[N];
bool was[N];
set < pii > q;
stack < pii > st;
int n, m, v, u, w, p[N], cnt[N];
vector < pair < int, pii > > e;

int get (int v) {
	return p[v] == v ? v : get(p[v]);
}

void merge (int v, int u, int w) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (cnt[v] < cnt[u])
		swap(v, u);

	st.push(mp(u, w));

	p[u] = v;
	cnt[v] += cnt[u];

	while (sz(comp[u])) {
		comp[v].pb(comp[u].back());
		comp[u].ppb();
	}
}

void undo (int u) {
	if (was[u])
		return;

	int v = p[u];
	
//	cerr << u << ' ' << v << endl;

	q.erase(mp(cnt[v], v));
	
	cnt[v] -= cnt[u];
	p[u] = u;

	for (int x = 0; x < cnt[u]; ++x) {
		comp[u].pb(comp[v].back());
		comp[v].ppb();
	}

	q.insert(mp(cnt[u], u));
	q.insert(mp(cnt[v], v));
}
        	
 
main () {
	while (1) {
		e.clear();
		q.clear();
		while (sz(st))
			st.pop();

		scanf("%d%d", &n, &m);
		if (!n && !m)
			return 0;
		
		while(m--) {
			scanf("%d%d%d", &v, &u, &w);
			e.pb(mp(w, mp(v, u)));
		}

		sort(all(e));
		for (int i = 1; i <= n; ++i) {
			was[i] = 0;
			p[i] = i;
			comp[i].clear();
			comp[i].pb(i);
			cnt[i] = 1;
		}

		sort(all(e));
		reverse(all(e));
		for (auto x : e)
			merge(x.s.f, x.s.s, x.f);
		
		q.insert(mp(n, get(1)));
		reverse(all(e));

		for (auto x : e) {
			while (sz(st) && st.top().s == x.f) {
				undo(st.top().f);                
				st.pop();
			}

			while (sz(q)) {
				int v = q.begin()->s;
				if (cnt[v] == (*q.rbegin()).f)
					break;

				while (sz(comp[v])) {
					was[comp[v].back()] = 1;
					comp[v].ppb();
				}
				q.erase(q.begin());
			}
		}

		for (int i = 1; i <= n; ++i)
			if (!was[i])
				printf("%d ", i);
		printf("\n");
	}
}