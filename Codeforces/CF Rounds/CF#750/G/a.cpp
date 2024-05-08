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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, a[N], lp[N], r[N], nxt[N];
vpii pos[N], gg[N];
char s[N];

void precalc() {
	for (int x = 2; x < N; ++x)
		if (!lp[x])
			for (int y = x; y < N; y += x) 
				lp[y] = x;
}

inline int get(int l, int r, int x) {
	return pos[x][r].s - (!l ? 0 : pos[x][l - 1].s);
}

 
main () {
	precalc();

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]); 
	
	
	scanf("\n%s", (s + 1));

	for (int i = 1; i <= n; ++i) {
		while (a[i] > 1) {
			int x = lp[a[i]], p = 0;
			while (!(a[i] % x)) {
				a[i] /= x;
				p++;
			}

			pos[x].pb({i, s[i] == '/' ? -p : p});
		} 
	}

	multiset < int > q;
	q.insert(n + 1);

	for (int x = 1; x < N; ++x) {
		if (!sz(pos[x]))
			continue;
		
		//preparing for calculation
		for (int j = 1; j < sz(pos[x]); ++j)
			pos[x][j].s += pos[x][j - 1].s;


		//calculating array nxt
		for (int j = sz(pos[x]) - 1; j >= 0; --j) {
			if (s[pos[x][j].f] == '/') {
				nxt[j] = j;              
				continue;
			}

			nxt[j] = j + 1;
			while (nxt[j] < sz(pos[x])) {
				if (get(j, nxt[j], x) < 0)
					break;
				nxt[j] = max(nxt[j] + 1, nxt[nxt[j]]);
			}
		}

		//working with array nxt
		nxt[sz(pos[x])] = sz(pos[x]);
		for (int j = 0; j <= sz(pos[x]); ++j)
			nxt[j] = nxt[j] == sz(pos[x]) ? n + 1 : pos[x][nxt[j]].f;

		q.insert(nxt[0]);
		r[x] = nxt[0];
/*		for (int j = 0; j <= sz(pos[x]); ++j)
			cerr << nxt[j] << ' ';
		cerr << endl;*/

		for (int j = 1; j <= sz(pos[x]); ++j) 
			gg[pos[x][j - 1].f].pb({x, nxt[j]});
		
	}


	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += *q.begin() - i;
//		cerr << i << ' ' << *q.begin() << endl;
		for (auto j : gg[i]) {
			q.erase(q.find(r[j.f]));
			r[j.f] = j.s;
			q.insert(r[j.f]);
		}
	}

	printf("%lld\n", ans);
}