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
 
const int inf = 1e9, maxn = 8e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, nxt[maxn][26], par[maxn], Sz;
set < int > q[maxn];
string s[N], t[N];
set < pair < int, pii > > Q;
char f[maxn];

void add (string s, int j) {
	int v = 0;
	q[v].insert(j);

	for (int i = 0; i < sz(s); ++i) {
		int x = s[i] - 'a';
		if (nxt[v][x] == -1) {
			nxt[v][x] = ++Sz; 
			par[Sz] = v;
		}

		v = nxt[v][x];		
		q[v].insert(j);
	}
} 

void del (string s, int j) {
	int v = 0;
	q[v].erase(j);

	for (int i = 0; i < sz(s); ++i) {
		int x = s[i] - 'a';

		v = nxt[v][x];
		q[v].erase(j);
	}
}


main () {
	memset(nxt, -1, sizeof(nxt));

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("\n%s", f);
		m = strlen(f);
		for (int j = 0; j < m; ++j)
			s[i] += f[j];

		add(s[i], i);
	}

	for (int i = 1; i <= n; ++i) {
		scanf("\n%s", f);
		m = strlen(f);
		int v = 0, len = 0;
		for (int j = 0; j < m; ++j) {
			int x = f[j] - 'a';
			if (nxt[v][x] == -1) 
				break;

			v = nxt[v][x];
			++len;
		}


		Q.insert(mp(len, mp(v, i)));
	}

	vpii ans;
	ll res = 0;
	while (sz(Q)) {
		pair < int, pii > cur = *Q.rbegin();
		Q.erase(cur);
		int len = cur.f, v = cur.s.f, i = cur.s.s; 
		if (!sz(q[v])) {
			--len;
			v = par[v];
			Q.insert(mp(len, mp(v, i)));
			continue;
		}

		int j = *q[v].begin();
		del(s[j], j);
		ans.pb(mp(j, i));
		res += len;
	}

	printf("%lld\n", res);
	for (auto x : ans)
		printf("%d %d\n", x.f, x.s);
}