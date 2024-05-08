#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 1e6 + 48, mod = 1e9 + 7, N = 1e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, nxt[maxn][26], Sz, res1, res2, id[N];
bool was[maxn], bad[maxn];
pii h[maxn], pw[maxn];
string s[N], t[N];
set < pii > q;

inline pii get (int l, int r) {
	return {(h[r].f - h[l - 1].f * 1ll * pw[r - l + 1].f % Mod.f + Mod.f) % Mod.f, (h[r].s - h[l - 1].s * 1ll * pw[r - l + 1].s % Mod.s + Mod.s) % Mod.s};
}

void solve () {
	for (int i = 0; i < m; ++i) {
		int v = 0;
		for (int x = sz(t[i]) - 1; x >= 0; --x) {
			if (nxt[v][t[i][x] - 'a'] == -1)
				nxt[v][t[i][x] - 'a'] = ++Sz;
			v = nxt[v][t[i][x] - 'a'];
		}

		was[v] = 1;
	}
	

	for (int i = 0; i < m; ++i) {
		int v = 0;
		h[0] = {t[i][0], t[i][0]};
		for (int j = 1; j < sz(t[i]); ++j)
			h[j] = {(h[j - 1].f * 1ll * base.f + t[i][j]) % Mod.f, (h[j - 1].s * 1ll * base.s + t[i][j]) % Mod.s};

		for (int x = sz(t[i]) - 1; x > 0; --x) {
			v = nxt[v][t[i][x] - 'a'];
			if (was[v]) 
				q.insert(h[x - 1]);			
		}
	}

	memset(nxt, -1, sizeof(nxt));
	memset(was, 0, sizeof(was));
	Sz = 0;

	for (int i = 0; i < n; ++i) {
		int v = 0;
		for (auto c : s[i]) {
			if (nxt[v][c - 'a'] == -1)
				nxt[v][c - 'a'] = ++Sz;
			v = nxt[v][c - 'a'];
		}
		was[v] = 1;
		id[i] = v;
	}

	for (int i = 0; i < n; ++i) {
		h[0] = {s[i][0], s[i][1]};

		for (int j = 1; j < sz(s[i]); ++j)
			h[j] = {(h[j - 1].f * 1ll * base.f + s[i][j]) % Mod.f, (h[j - 1].s * 1ll * base.s+ s[i][j]) % Mod.s};

		int v = 0;
		for (int j = 0; j < sz(s[i]) - 1; ++j) {
			v = nxt[v][s[i][j] - 'a'];
			if (was[v] && q.count(get(j + 1, sz(s[i]) - 1))) 
				bad[v] = bad[id[i]] = 1;			
		}
	}

	for (int i = 0; i < n; ++i)
		if (!bad[id[i]])
			++res2;
}
 
main () {
    pw[0] = {1, 1};
    for (int i = 1; i < maxn; ++i)
    	pw[i] = {pw[i - 1].f * 1ll * base.f % Mod.f, pw[i - 1].s * 1ll * base.s % Mod.s};
	
	memset(nxt, -1, sizeof(nxt));
	fastio
	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		cin >> s[i];
	

	for (int i = 0; i < m; ++i) 
		cin >> t[i];
	
	solve();
	swap(n, m);
	for (int i = 0; i < max(n, m); ++i) {
		swap(s[i], t[i]);
		reverse(all(s[i]));
		reverse(all(t[i]));
	}
	
	q.clear();
	memset(nxt, -1, sizeof(nxt));
	memset(was, 0, sizeof(was));
	memset(bad, 0, sizeof(bad));
	Sz = 0;
	

	swap(res1, res2);
	solve();
	cout << res1 << ' ' << res2 << endl;
}