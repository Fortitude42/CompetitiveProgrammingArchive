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
const int N = 100, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

                                                    

ll r[M];
int n, w, h, m, flag;
int used[M/2][M], cnt[M/2][M];
   
bool check(int lvl) {
	ll tot = 0, diff = 0;
	for (int l = lvl + 1; l <= h; ++l) {
		for (int x = 1; x <= n; ++x)
			if (!used[l][x]) {
				tot += n;
				if ((l & 1) != (lvl & 1))
					++diff;
			}
	}

	if (!tot)
		return 1;

	int l = inf, r = 0;

	for (int x = 1; x <= n; ++x)
		if (!used[lvl][x]) {
			l = min(l, x); 
			r = max(r, x);
		}

	
/*	if (flag) {
		for (int l = lvl + 1; l <= h; ++l) {
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j) {
					if (((l & 1) && !used[l][i]) || (!(l & 1) && !used[l][j]))
						++cnt[i][j];
				}					
		}

		ll s = 0;
		for (int i = 1; i <= n; ++i, cout << endl)
			for (int j = 1; j <= 7; ++j) {
				cout << cnt[i][j] << ' '; 
				s += cnt[i][j];
			}
		cout << s << endl;
		exit(0);
	}*/

	ll pref = 0;
	for (int x = 1; x <= n; ++x) {
		ll cur = diff * 1ll * x;
		for (int l = lvl + 1; l <= h; ++l) 
			if ((l & 1) == (lvl & 1))
				pref += (1 - used[l][x]) * n;

		cur += pref; 
		
		
		if (cur + cur >= tot) {
			cerr << l << ' ' << r << ' ' << x << endl;
			if (cur + cur == tot) 
				return (l <= x && x + 1 <= r);
			return (l <= x && x <= r);
		}
	}

	return 0;
}

void solve() {
	cin >> n >> w >> h >> m;
	for (int i = 1; i <= m; ++i) {
		int l, k;
		cin >> l >> k;
		used[l][k] = 1;
		if (i == 77)
			flag = 1;
		for (int l = 1; l <= h; ++l)
			 if (!check(l)) { 
			 	cout << "yes\n";
			 	cout << i << endl;
			 	return;
			 }
	}

	cout << "no";
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

