//template by paradox & gege & parasat
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

vi g[M], colors, fstEdges, used[M], sum1[M], vals[M];
int n, a[M], b[M], c[M], cnt[M], totCnt, d[M];
int sum[M], par[M], ind[M], cur[M], tt[M], timer;
bool was[M];
ll ans;
 
void dfs(int v, int p = 0) {
	cnt[v] = 1;

	for (auto i : g[v]) {
		int to = a[i]^b[i]^v;
		if (!was[to] && to != p) {
			cur[i] = 0;
			dfs(to, v);
			cnt[v] += cnt[to];
		}
	}
}

int Find(int v) {
	for (auto i : g[v]) {
		int to = a[i]^b[i]^v;
		if (cnt[to] < cnt[v] && !was[to] && cnt[to] > totCnt - cnt[to]) 
			return Find(to);		
	}

	return v;
}

void dfs1(int v, int p = 0) {
	cnt[v] = 1;
	d[v] = d[p] + 1;


	for (auto i : g[v]) {
		int to = a[i]^b[i]^v;

		if (!was[to] && to != p) {
			used[c[i]].pb(i);

			if (sz(used[c[i]]) == 1) {
				fstEdges.pb(i); 
				if (tt[c[i]] != timer) {
					tt[c[i]] = timer;
					colors.pb(c[i]);
				}
			}

			par[to] = !p ? to : par[v];
			dfs1(to, v);

			if (sz(used[c[i]]) == 2)
				cur[used[c[i]][0]] += cnt[to];

			used[c[i]].ppb();
			cnt[v] += cnt[to];
		}
	}
}

void Centroid(int v) {     
	++timer;
	fstEdges.clear();
	colors.clear();

	dfs(v);
	totCnt = cnt[v];

	v = Find(v);
	
	dfs1(v);
	for (auto c : colors) {
		sum[c] = 0;  
		sum1[c].clear();
		vals[c].clear();
	}

	for (auto i : fstEdges) {
		if (d[a[i]] > d[b[i]])
			swap(a[i], b[i]);
		vals[c[i]].pb(par[b[i]]);
	}


	for (auto c : colors) {
		sort(all(vals[c]));
		vals[c].resize(unique(all(vals[c])) - vals[c].begin());
		sum1[c].resize(sz(vals[c]));
	}

	for (auto i : fstEdges) {
		sum[c[i]] += cnt[b[i]];
		ind[i] = lower_bound(all(vals[c[i]]), par[b[i]]) - vals[c[i]].begin();
		sum1[c[i]][ind[i]] += cnt[b[i]];
	}
	
	for (auto i : fstEdges)
		ans += (cnt[b[i]] - cur[i]) * 1ll * (totCnt - (sum[c[i]] - sum1[c[i]][ind[i]]) - cnt[par[b[i]]]);
	


	was[v] = 1;
	for (auto i : g[v]) {
		int to = a[i] ^ b[i] ^ v;
		if (!was[to])
			Centroid(to);
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		g[a[i]].pb(i);
		g[b[i]].pb(i);
	}

	Centroid(1);
	printf("%lld\n", ans);
}

main () {
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}