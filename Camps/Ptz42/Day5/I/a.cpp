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
const int N = 3e5 + 1, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int l[M], r[M], x[M];
vi in[M], out[M];
int ord[M];

int n;
int a[M], b[M];
int p[M], pref[M];
int g[M << 2], q[M << 2];

int ans[M];

void upd(int v) {
	g[v] = min(g[v << 1], g[v << 1 | 1]);
}

void build(int v = 1, int tl = 0, int tr = N - 1) {
	if (tl == tr) {
		g[v] = pref[tl] - (tl <= n ? tl : 0);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	upd(v);
}

void push(int v = 1, int tl = 0, int tr = N - 1) {
	if (!q[v])
		return;

	if (tl != tr) {
		q[v << 1] += q[v];
		q[v << 1 | 1] += q[v];
	}
	g[v] += q[v];
	q[v] = 0;
}

void upd(int l, int r, int val, int v = 1, int tl = 0, int tr = N - 1) {
	push(v, tl, tr);
	if (l > r || tl > r || l > tr)
		return;
	if (l <= tl && tr <= r) {
		q[v] += val;
		push(v, tl, tr);
		return;
	}

	int tm = (tl + tr) >> 1;
	upd(l, r, val, v << 1, tl, tm);
	upd(l, r, val, v << 1 | 1, tm + 1, tr);
	upd(v);
}
 
void solve() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &x[i], &l[i], &r[i]);
		in[l[i]].pb(x[i]);
		out[r[i]].pb(x[i]);
		ord[i] = i;
	}

	multiset<int> s;
	for (int i = 1; i <= n; i++) {
		for (int cur : in[i])
			s.insert(-cur);
		if (!s.empty())
			a[i] = -*s.begin();
		if (sz(s) > 1)
			b[i] = -*(++s.begin());
		for (int cur : out[i])
			s.erase(s.find(-cur));
	}

	sort(ord + 1, ord + 1 + m, [&](const int &i, const int &j) {
		if (x[i] != x[j])
			return x[i] > x[j];
		return l[i] < l[j];
	});

	for (int i = 1; i <= n; i++)
		p[a[i]]++;
	for (int i = 0; i < N; i++)
		pref[i] = (i ? pref[i - 1] : 0) + p[i];

	build();
//	cerr << g[1] << "\n";

	set<int> pos;
	for (int i = 1; i <= n; i++)
		pos.insert(i);
	
	bool hasAnswer = false;
	for (int ii = 1; ii <= m; ii++) {
		int i = ord[ii];

		vector<int> upds;
//		cerr << "i = " << i << " | " << x[i] << "\n";
		
		auto it = pos.lower_bound(l[i]);
		while (it != pos.end() && *it <= r[i]) {
//			cerr << b[*it] << ' ' << a[*it] - 1 << "\n";
			upd(b[*it], a[*it] - 1, 1);
			upds.pb(*it);

			pos.erase(it);
			it = pos.lower_bound(l[i]);
		}

		push();
//		cerr << "g: " << g[1] << "\n";
		if (g[1] >= 0) {
			hasAnswer = true;
			for (int cur : upds)
				a[cur] = b[cur];
			break;
		}

		for (int cur : upds)
			upd(b[cur], a[cur] - 1, -1);
	}

	if (!hasAnswer) {
		printf("NO\n");
		return;
	}

	vector<pii> res;
	for (int i = 1; i <= n; i++)
		res.pb({a[i], i});
	sort(all(res));

	for (int i = 0; i < sz(res); i++)
		ans[res[i].se] = i + 1;

	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

