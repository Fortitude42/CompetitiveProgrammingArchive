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
const int N = 5e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, h, w, l[M], r[M], x[M], y[M], cnt[M];
bool used[M][M+M];

int getX(int i, int j) {
	return (i & 1) ? j + j - 1 : n;
}

int getY(int i, int j) {
	return (i & 1) ? n : j + j - 1;
}

void write(int i) {
	cout << "yes\n" << i;
	exit(0);
}

void solve() {
	cin >> n >> w >> h >> m;
	for (int i = 1; i <= h; ++i) {
		l[i] = 1;
		r[i] = n;
		cnt[i] = n;

		for (int j = 1; j <= n; ++j) {
			x[i] += getX(i, j); 
			y[i] += getY(i, j);
		}
	}

	for (int i = 1; i <= m; ++i) {
		int lvl, k;
		cin >> lvl >> k;

		cnt[lvl]--;
		x[lvl] -= getX(lvl, k);
		y[lvl] -= getY(lvl, k);
			
		used[lvl][k] = 1;
		while (used[lvl][l[lvl]])
			++l[lvl];
		while (used[lvl][r[lvl]])
			--r[lvl];
		
		int totX = 0, totCnt = 0, totY = 0;
		for (lvl = h; lvl > 0; lvl--) {
			if (totCnt > 0) {
				if (l[lvl] > r[lvl])
					write(i);
				int L = l[lvl] - 1;
				int R = r[lvl];
				if ((lvl & 1)) {
					if (2*L*totCnt >= totX || totX >= 2*R*totCnt)
						write(i);
				} else {
					if (2*L*totCnt >= totY || totY >= 2*R*totCnt)
						write(i);
				}
			}
			totX += x[lvl];
			totY += y[lvl];
			totCnt += cnt[lvl];
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

