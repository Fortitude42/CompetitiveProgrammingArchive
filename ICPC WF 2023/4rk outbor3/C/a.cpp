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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m;
vi g[M];
ll s[M], t[M];

void inc(int pos, int x) {
	while (pos < M) {
		s[pos] += x;
		t[pos]++;
		pos |= pos + 1;
	}
}

pair < ll, ll > get(int r) {
	pair < ll, ll > res = mp(0, 0);
	while (r >= 0) {
		res.f += s[r];
		res.s += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}


void bfs(int st, vector < int > &d) {
	for (int i = 1; i <= n; ++i)
		d[i] = -1;

	queue < int > q;
	q.push(st);
	d[st] = 0;


	while (sz(q)) {
		int v = q.front();
		q.pop();

		for (auto to : g[v])
			if (d[to] == -1) {
				d[to] = d[v] + 1;
				q.push(to);
			}
	}
}
 
void solve() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	vi x(n + 1), y(n + 1);
	bfs(1, x);
	bfs(n, y);


	ll ans = 0;
	vector < pii > order;
	for (int i = 1; i <= n; ++i)
		order.pb(mp(x[i] - y[i], i));

	sort(all(order));
	reverse(all(order));
	ll tots = 0, tott = 0;

	for (auto xx : order) {
		int a = xx.s;
		int cur = x[n] - x[a] - 1;
		pair < ll, ll > tmp = mp(0, 0);
		if (cur >= 0)
			tmp = get(cur);
		

		ans += tmp.f;
		ans += tmp.s * (x[a] + 1);
		ans += (tott - tmp.s) * x[n];
		inc(y[a], y[a]);
		tots += y[a];
		tott++;
	}

	memset(s, 0, sizeof s);
	memset(t, 0, sizeof t);
	reverse(all(order));
	tots = 0, tott = 0;

	for (auto xx : order) {
		int a = xx.s;
		int cur = x[n] - 1 - y[a];
		pair < ll, ll > tmp = mp(0, 0);
		if (cur >= 0)
			tmp = get(cur);

		ans += tmp.f;
		ans += tmp.s * (1 + y[a]);
		ans += (tott - tmp.s) * x[n];

		inc(x[a], x[a]);
		tots += x[a];
		tott++;
	}

	ans /= 2;


	for (int a = 1; a <= n; ++a) 
		for (auto b : g[a])
			if (b > a)
				ans -= min({x[n], 1 + x[a] + y[b], 1 + y[a] + x[b]});	

	cout << ans << endl;
}

main () {        
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}