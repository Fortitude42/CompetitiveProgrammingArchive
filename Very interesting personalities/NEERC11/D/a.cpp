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
const int N = 4e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int K = 26;

int count_suffix[K];
int nxt[2][M][K];
int k[2];
bool has_last[K];
bool is_word[2][M];

ll ans;

string cur;

void add(int v, int opt, const string &s, int i = 0) {
	if (sz(s) == i) {
		is_word[opt][v] = true;
		return;
	}
	int c = s[i] - 'a';
	if (!nxt[opt][v][c]) {
		nxt[opt][v][c] = ++k[opt];
		if (opt)
			count_suffix[c]++;
	}
	add(nxt[opt][v][c], opt, s, i + 1);
}

void dfs(int v) {
	for (int toc = 0; toc < K; toc++) {
		if (nxt[0][v][toc]) {
			if (v && !is_word[0][nxt[0][v][toc]])
				ans += has_last[toc];
			dfs(nxt[0][v][toc]);
		} else if (v) {
			ans += count_suffix[toc];
		}
	}
}

void solve() {
	int n;
	cin >> n;

	set<string> unq;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		add(0, 0, s);
		reverse(all(s));
		add(0, 1, s);

		has_last[s[0] - 'a'] = true;
		unq.insert(s);
	}
	
	ans += sz(unq);
	dfs(0);
	cout << ans << "\n";
}

main () {
//	file("dictionary")
	fastio
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
