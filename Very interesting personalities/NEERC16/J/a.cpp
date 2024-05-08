//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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
const int N = 1e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

                                                    
int n, w, h, m, t[2][M][M/4], sz[M], mn[M], mx[M];
bool used[M / 2][M];

void inc(int lvl, int pos, int x) {
	int tp = (lvl & 1);

	sz[lvl] += x;
	used[lvl][pos] = (x == -1); 
	

	lvl >>= 1;
	lvl = (M/4 - 1 - lvl);
	while (lvl < M/4) {
		t[tp][pos][lvl] += x;
		lvl |= (lvl + 1);
	}
} 

int get(int lvl, int pos) {
	int tp = (lvl & 1);
	lvl >>= 1;
	lvl = (M/4 - 1 - lvl);

	int res = 0;
	while (lvl >= 0) {
		res += t[tp][pos][lvl];
		lvl = (lvl & (lvl + 1)) - 1;
	}

	
	return res;
}


bool check(int lvl) {
	while (h > 0 && !sz[h])
		h--;
	
	if (lvl == h)
		return 1;

	ll tots = 0;
	int sum[2] = {0, 0};
	for (int l = lvl + 1; l <= h; ++l){
		sum[l & 1] += sz[l]; 
		tots += sz[l] * 1ll * w * w * n;
	}

	int l = inf, r = -inf;
	for (int x = 1; x <= n; ++x)
		if (!used[lvl][x]) {
			l = min(l, x);
			r = max(r, x);	
		}


	ll s = 0;
	for (int x = 1; x <= n; ++x) {
		s += get(lvl + 2, x) * 1ll * w * w * n;
		ll curs = s;
		curs += (sum[(lvl + 1) & 1] * 1ll * w * w * x);

		if (curs + curs >= tots) {
			cerr << curs << ' ' << tots << endl;
			if (curs + curs == tots)
				return (l <= x && x + 1 <= r);

			return (l <= x && x <= r);
		}
	}

	assert(0);
	return 0;
}


void solve() {
	cin >> n >> w >> h >> m;
	for (int i = 1; i <= h; ++i) 
		for (int j = 1; j <= n; ++j)
			inc(i, j, 1); 
		
	
	for (int i = 1; i <= m; ++i) {
		int l, k;
		cin >> l >> k;
		inc(l, k, -1);
		for (int l = 1; l <= h; ++l)
			if (!check(l)) {
				cout << "yes\n" << i << endl;
				return;
			}
	}

	cout << "no\n";

}

main () {
//	file("jenga");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

