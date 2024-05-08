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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 9;
const int M = N + 17;
const ll INF = 1e18;

ll d[M];
int s, e;
pii f[M], f1[M];
vi g[M], gg[M];
int n, m, a[M], b[M], c[M];
set < pair < ll, int > > q;


void add(int &x, int y, int m) {
	x += y;
	if (x >= m)
		x -= m;
}

vi ans;
 
void solve() {                       
	fastio
	cin >> n >> m;
	cin >> s >> e;

	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	for (int i = 1; i <= n; ++i)
		d[i] = INF;

	d[s] = 0;
	q.insert(mp(0, s));


	while (sz(q)) {
		int v = q.begin()->s;
		q.erase(q.begin());

		for (auto i : g[v]) {
			int to = (a[i]^b[i]^v);
			if (d[to] > d[v] + c[i]) {
				q.erase(mp(d[to], to));
				d[to] = d[v] + c[i];
				q.insert(mp(d[to], to));
			}
		}
	}


	for (int i = 1; i <= m; ++i) {
		if (d[a[i]] == d[b[i]] + c[i])
		    gg[b[i]].pb(a[i]);
		if (d[b[i]] == d[a[i]] + c[i])
			gg[a[i]].pb(b[i]);
	}

	vector < pair < ll, int > > order;
	for (int i = 1; i <= n; ++i)
		order.pb(mp(d[i], i));

	sort(all(order));


	f[s] = mp(1, 1);
	for (auto x : order) {
		int v = x.s;

		for (auto to : gg[v]) {
			add(f[to].f, f[v].f, mod.f);
			add(f[to].s, f[v].s, mod.s);
		}
	}

	f1[e] = mp(1, 1);
	for (auto x : order) {
		int v = x.s;

		pii cur = mp(f[e].f*1ll*f1[v].f%mod.f,
				     f[e].s*1ll*f1[v].s%mod.s);

		if (cur == f[v] && d[v] == d[e]*2) 
			ans.pb(v);

		for (auto to : gg[v]) {
			add(f1[to].f, f1[v].f, mod.f);
			add(f1[to].s, f1[v].s, mod.s);
		}
	}


	if (!sz(ans))	
		cout << "*";
	else {
		sort(all(ans));
		for (auto x : ans)
			cout << x << ' ';
	}
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}