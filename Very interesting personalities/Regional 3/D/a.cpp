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

int n, p[M], res[M];
set < int > q[M], qq;

int getNext(int i) {
	if (*qq.rbegin() > i)
		return *qq.upper_bound(i);
	return *qq.begin();
}

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}
 
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k;
		p[i] = i;
		scanf("%d", &k);
		while (k--) {
			int x;
			scanf("%d", &x);
			q[i].insert(x);
		}
		qq.insert(i);
	}

	for (int i = 0; i < n; ++i) {
		if (!qq.count(i))
			continue;
		
		int j = getNext(i);
		if (i == j)
			break;

		int x = -1;
		for (auto y : q[i])
			if (!q[j].count(y)) {
				x = y;
				break;
			}

		if (x == -1) {
			merge(i, j);
			qq.erase(j);
			i--;
			continue;
		} 
	}

	if (sz(qq) == 1) {
		int i = *qq.begin();
		int j = *q[i].begin();
		for (int x = 0; x < n; ++x)
			printf("%d ", j);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (!qq.count(i))
			continue;
		int j = getNext(i);

		int x = -1;
		for (auto y : q[i])
			if (!q[j].count(y)) {
				x = y;
				break;
			}

		res[get(i)] = x;
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", res[get(i)]);
		
	
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
