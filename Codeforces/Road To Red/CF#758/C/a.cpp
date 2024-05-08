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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a[M], b[M], posa[M], posb[M], aa[M], bb[M];
vi vala, valb;
bool good[M];
 
void solve() {
	vala.clear();
	valb.clear();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &aa[i]); 
		vala.pb(aa[i]);
	}
	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &bb[i]); 
		valb.pb(bb[i]);
	}

	sort(all(vala));
	sort(all(valb));

	for (int i = 1; i <= n; ++i) {
		posa[i] = (lower_bound(all(vala), aa[i]) - vala.begin()) + 1;
		a[posa[i]] = i;

		posb[i] = (lower_bound(all(valb), bb[i]) - valb.begin()) + 1;
		b[posb[i]] = i;
	}


	queue < int > q;
	set < int > qa, qb;
	for (int i = 1; i <= n; ++i) {
		qa.insert(i);
		qb.insert(i);
		good[i] = 0;
	}
	
	q.push(a[n]);
	qa.erase(n);

	if (a[n] != b[n])
		q.push(b[n]);
	qb.erase(n);

	while (sz(q)) {
		int v = q.front();
		q.pop();

		good[v] = 1;

		while (sz(qa)) {
			int u = *qa.rbegin();
			if (posa[v] >= u)
				break;

			u = a[u];
			q.push(u);
			qa.erase(posa[u]);
			qb.erase(posb[u]);
		}

		while (sz(qb)) {
			int u = *qb.rbegin();
			if (posb[v] >= u)
				break;

			u = b[u];
			q.push(u);
			qa.erase(posa[u]);
			qb.erase(posb[u]);
		}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d", good[i]);
	printf("\n");
}

main () {
	int TT = 1;
  	scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}