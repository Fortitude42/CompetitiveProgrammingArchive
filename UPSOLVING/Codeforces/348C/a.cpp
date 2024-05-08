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
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 25;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

vi b[M], g[M];
int n, m, q, index[M];
bool was[block + 11][M];
ll sum[block + 11], add[block + 11], a[M];


void solve() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
		
	for (int i = 1; i <= m; ++i) {
		int k;
		scanf("%d", &k);
		b[i].resize(k);
		for (int j = 0; j < k; ++j) 
			scanf("%d", &b[i][j]);		
	}


	vector < pii > groups;
	vi Big;

	for (int i = 1; i <= m; ++i)
		groups.pb({sz(b[i]), i});

	sort(all(groups));
	reverse(all(groups));

	for (int i = 0; i < min(sz(groups), block); ++i) {
		index[groups[i].s] = i + 1;
		Big.pb(groups[i].s);
		for (int j = 0; j < groups[i].f; ++j) {
			was[i][b[groups[i].s][j]] = 1;      
			sum[i] += a[b[groups[i].s][j]];
		}
	}


	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < sz(Big); ++j) {
			int cnt = 0;
			for (auto x : b[i]) 
				cnt += was[j][x];				
			g[i].pb(cnt);
		}
	

	while (q--) {
		char c;
		int k;
		scanf("\n%c%d", &c, &k);
		if (c == '?') {
			//calculating additions from 'small' groups
			ll S = 0;
			if (!index[k]) {
				for (auto x : b[k])
					S += a[x];
			} else
				S = sum[index[k] - 1];

			//calculating additions from 'big' groups
			for (int j = 0; j < sz(Big); ++j) 
				S += add[j] * g[k][j];    				
			
			printf("%lld\n", S);			    
		} else {
			int x;
			scanf("%d", &x);
			if (index[k])
				add[index[k] - 1] += x;
			else {
				for (int j = 0; j < sz(Big); ++j) 
					sum[j] += g[k][j] * 1ll * x;
				for (auto j : b[k])
					a[j] += x;
			}			
			
		}
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