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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, a[M], cnt[3], v[3], s[M][3];
 
void Swap(int x, int y) {
	for (int i = 1; i <= 3*n; ++i) 
		if (a[i] == v[x])
			a[i] = v[y];
		else if (a[i] == v[y])
			a[i] = v[x];

	swap(cnt[x], cnt[y]);
	swap(v[x], v[y]);
}

int get(int l, int r, int i) {
	return s[r][i] - s[l - 1][i];
}

void solve() {
	scanf("%d\n", &n);
	for (int i = 1; i <= 3*n; ++i) {
		char c;
		scanf("%c", &c);
		a[i] = c - 'A';
		++cnt[a[i]];
	}

	v[0] = 0;
	v[1] = 1;
	v[2] = 2;

	if (cnt[0] < cnt[1]) 
		Swap(0, 1);

	if (cnt[0] < cnt[2])
		Swap(0, 2);

	if (cnt[1] < cnt[2])
		Swap(1, 2);

	if (cnt[2] == n) {
		printf("0\n");
		return;
	}

	if (cnt[0] >= n && cnt[1] >= n) {
		vi x, y;

		for (int i = 1; i <= 3*n; ++i) {
			for (int j = 0; j < 3; ++j)
				s[i][j] = s[i - 1][j];
			++s[i][a[i]];

			if (a[i] == v[2])
				x.pb(i);
			else
				y.pb(i);
		}

		for (int i = 0, j = n - cnt[2] - 1; j < sz(y); ++i, ++j) {
			if (get(y[i], y[j], 0) == cnt[0] - n) {
				printf("1\n");
				printf("%d %d %c", y[i], y[j], v[2] + 'A');
				return;
			}
		}
	}

	printf("2\n");
	
	int c0 = 0, c1 = 0;
	for (int i = 1; i <= n*3; ++i) {
		if (a[i] == v[0])
			++c0;
		if (a[i] == v[1])
			++c1;

		if (c0 == n || c1 == n) {
			printf("%d %d %c\n", i + 1, 3*n, v[2] + 'A');
			if (c0 == n)
				printf("%d %d %c\n", i + 1, i + n - c1, v[1] + 'A');
			else
				printf("%d %d %c\n", i + 1, i + n - c0, v[0] + 'A');
			return;
		}
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

