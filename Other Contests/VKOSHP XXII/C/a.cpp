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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, q, nxt[M][30], len[M], dp[M][30], Sz, up[M][20];
int cnt[M], tin[M], timer, a[M], tout[M];
string s;
char S[M];


void add(const string &t) {
	int v = 0;
	for (auto c : t) {
		int cc = c - 'a';
		if (nxt[v][cc] == -1) {
			len[++Sz] = len[v] + 1;
			nxt[v][cc] = Sz;
		}

		v = nxt[v][cc];
	}

	++cnt[v];
}

void dfs(int v, int par = -1) {
	tin[v] = ++timer;

	up[v][0] = par;
	for (int i = 1; i < 20; ++i)
		if (up[v][i - 1] != -1)
			up[v][i] = up[up[v][i - 1]][i - 1];

	a[timer] = a[timer - 1] + cnt[v];
	for (int i = 0; i < 26; ++i) {
		if (nxt[v][i] != -1)
			dfs(nxt[v][i], v);

		dp[v][i] = v;

		if (nxt[v][i] != -1 && len[v] < sz(s)) 
			dp[v][i] = dp[nxt[v][i]][i];	
	}

	tout[v] = timer;
}

inline int get(int v, int lvl) {
	for (int i = 19; i >= 0; --i)
		if (len[v] - (1 << i) >= lvl)
			v = up[v][i];
	return v;
}

inline int f(int v, int c) {
	int T = tin[v];
	if (len[v] < sz(s))	
		for (int ca = 0; ca < c; ++ca)
			if (nxt[v][ca] != -1)
				T = tout[nxt[v][ca]];

	return a[T] - (len[v] == sz(s) ? cnt[v] : 0);
}
 
void solve() {
	memset(nxt, -1, sizeof(nxt));
	memset(up, -1, sizeof(up));

	scanf("%d%d", &n, &q);
	scanf("\n%s", S);
	s.resize(strlen(S));
	for (int i = 0; i < sz(s); ++i)
		s[i] = S[i];

	while (n--) {
		string t;
		scanf("\n%s", S);
		t.resize(strlen(S));
		for (int i = 0; i < sz(t); ++i)
			t[i] = S[i];
		add(t);
	}

	dfs(0);

	int v = 0, c = -1;
	for (auto cc : s) {
		if (nxt[v][cc - 'a'] == -1) {
		    c = cc - 'a';
			break;                      
		}
		
		v = nxt[v][cc - 'a'];
	}

	printf("%d\n", f(v, c));
	
	while (q--) {
		int k;
		char cc;
		scanf("%d %c", &k, &cc);
		if (len[v] >= k - 1) {
			v = get(v, k - 1);
			c = cc - 'a';
			v = dp[v][c];
		}

		printf("%d\n", f(v, c));
	}
}

main () {
	fastio

	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}