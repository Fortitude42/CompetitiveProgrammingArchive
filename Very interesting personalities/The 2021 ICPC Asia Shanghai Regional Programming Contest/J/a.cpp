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
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
int n, s[M];
string a, b;
pii c[M];
bitset < M > pref[M], cur, ans;

void solve() {
	cin >> n >> a >> b;	

	a = "#" + a;
	b = "#" + b;

	c[0] = mp(0, 0);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + (a[i] - '0');
		c[i] = mp(2*s[i] - i, i);
	}

	sort(c, c + 1 + n);

	ans.set();
	cur.reset();
	for (int i = 0; i <= n; ) {
		int j = i;
		while (j <= n && c[j].f == c[i].f) {
			if (b[c[j].s] == '1')
				ans &= ((cur << (M - c[j].s)) | pref[M - c[j].s]);
			j++;
		}

		for (int x = i; x < j; ++x)
			cur[c[x].s] = 1;

		i = j;
	}

	cur.reset();
	for (int i = n; i >= 0;) {
		int j = i;
		while (j >= 0 && c[j].f == c[i].f) 
			cur[c[j--].s] = 1;

		for (int x = i; x > j; --x) {
		    if (b[c[x].s] == '0') 
				ans &= ((cur << (M - c[x].s)) | pref[M - c[x].s]); 
		}

		i = j;
	}
	
	bool ok = 0;
	for (int i = 1; i <= n; ++i) {
		if ((2*s[i] - i > 0 && b[i] == '0') || (2*s[i] - i <= 0 && b[i] == '1') || ok) {
			ans[M - i] = 0;                                                              
			ok = 1;
		}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d", (int)ans[M - i]);
	printf("\n");

}

main () {
	int TT;
	TT = 1;
	pref[0][0] = 1;
	for (int i = 1; i < M; ++i) {
		pref[i] = pref[i - 1];    
		pref[i][i] = 1;
	}

//	scanf("%d", &TT);
	fastio

	cin >> TT;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

