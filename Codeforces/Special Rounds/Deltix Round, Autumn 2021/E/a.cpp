//by parasat
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

 

int n, q, t[M << 2][3][3];
string abc = "abc";
char s[M];

void upd(int v) {
	for (int i = 0; i < 3; ++i)
		for (int j = i; j < 3; ++j) {
		    t[v][i][j] = inf;
			for (int x = i; x <= j; ++x)
				t[v][i][j] = min(t[v][i][j], t[v << 1][i][x] + t[v << 1 | 1][x][j]);
		}
				
}

void build(int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		for (int i = 0; i < 3; ++i)
			for (int j = i; j < 3; ++j) 
				t[v][i][j] = 0;

		for (int i = 0; i < 3; ++i)
			t[v][i][i] = (s[tl] == abc[i]);
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	upd(v);
}

void update(int pos, char c, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		for (int i = 0; i < 3; ++i)
			for (int j = i; j < 3; ++j) 
				t[v][i][j] = 0;

		for (int i = 0; i < 3; ++i)
			t[v][i][i] = (c == abc[i]);
		return;
	}

	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		update(pos, c, v << 1, tl, tm);
	else
		update(pos, c, v << 1 | 1, tm + 1, tr);	

	upd(v);
}

void solve() {
	scanf("%d%d", &n, &q);
	scanf("\n%s", (s + 1));
	build();


	while (q--) {
		int pos;
		char c;
		scanf("%d %c", &pos, &c);
		update(pos, c);
		printf("%d\n", t[1][0][2]);
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