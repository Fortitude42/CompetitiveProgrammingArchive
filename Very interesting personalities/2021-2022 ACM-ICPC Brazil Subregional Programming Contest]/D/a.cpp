//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 5e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

bool OK;
pii p[M];          
int n, m;
vector < pair < int, pii > > e;


pii get(int v) {
	if (v != p[v].f) {
		int parity = p[v].s;
		p[v] = get(p[v].f);
		p[v].s ^= parity;
	}

	return p[v];
}

inline void merge(int v, int u) {
	pii pv = get(v);
	pii pu = get(u);
	if (pv == pu)
		OK = 0;
	
	v = pv.f, u = pu.f;

	if (v == u)
		return;	

	if (rand() & 1)
		swap(v, u);

	p[u] = mp(v, pv.s^pu.s^1);
}


bool check1(const vector < pii > &e) {
	map < int, int > cnt;
	map < pii, int > cnt1;
	for (int i = 0; i < sz(e); ++i) {
		int v = e[i].f, u = e[i].s;
		if (v > u)
			swap(v, u);

		++cnt[v];
		if (v != u) {
			++cnt[u];
			++cnt1[mp(v, u)];  
		}

		if (cnt[v] + (v != u ? cnt[u] - cnt1[mp(v, u)] : 0) <= i) {
			return 1;                                               		
		} else {
		//	assert(cnt[v] + (v != u ? cnt[u] - cnt1[mp(v, u)] : 0) == i + 1);
		}
	}

	return 0;
}

bool check (const vector < pii > &e) {
	vector < pii > ee;

	for (int i = 0; i < sz(e); ++i) {
		pii a = get(e[i].f), b = get(e[i].s);
//		cerr << a.f << ' ' << b.f << ' ' << a.s << ' ' << b.s << endl;
		if (a.f == b.f && a.s != b.s);
		else 
			ee.pb(mp(a.f + n*a.s, b.f + n*b.s)); 		
	}

	return check1(ee);
}

void solve() {
	OK = 1;
	        
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		p[i] = {i, 0};
	
	while (m--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		e.pb({w, {v, u}});
	}

	sort(all(e));
	reverse(all(e));

	vi ans;
	
	for (int i = 0; i < sz(e); ) { 
		int j = i;
		vector < pii > ee;
		while (j < sz(e) && e[i].f == e[j].f) {
			ee.pb(e[j].s);
			j++;
		}

		if (check(ee))
			ans.pb(e[i].f);

	   	for (auto x : ee)
	   		merge(x.f, x.s);

		if (!OK)
			break;

		i = j;
	}

	if (OK)
		ans.pb(0);        
	sort(all(ans));			
	if (!sz(ans))
		puts("IMPOSSIBLE");
	else {
		for (auto x : ans)
			printf("%d\n", x);
	}	
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

