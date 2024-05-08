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

ll t[M];
char s[10];
set < pii > q;
map < int, int > id[M];
int n, Q, m[M*3], c[M*3], k;
vector < pair < int, ll > > g[M];

ll get(int c, int x) {
	if (!sz(g[c]) || g[c].back().f < x)
		return 0;
	
	int j = lower_bound(all(g[c]), mp(x, 0ll)) - g[c].begin();
	return g[c].back().s - (!j ? 0 : g[c][j - 1].s);
}

void inc(int pos, ll x) {
	while (pos < M) {
		t[pos] += x;
		pos |= pos + 1;
	}
}

void upd(int l, int r, ll x) {
	inc(l, x);
	inc(r + 1, -x);
}

ll get(int r) {
	ll res = 0;
	while (r >= 0) {
		res += t[r];
		r = (r & (r + 1)) - 1;
	}

	return res;
}
 
void solve() {
	scanf("%d%d", &n, &Q);
	q.insert(mp(1, n));
	id[1][n] = ++k;
	c[k] = 1;
	m[k] = 0;

	for (int i = 1; i <= Q; ++i) {
		scanf("\n%s", s);
		if (s[0] == 'C') {
			int l, r, cc;
			scanf("%d%d%d", &l, &r, &cc);
			while (sz(q)) {
				auto it = q.lower_bound(mp(l, 0));
				if (it != q.end() && it->f <= r) {
					int k1 = id[it->f][it->s];
					upd(it->f, it->s, get(c[k1], m[k1]));
					if (it->s > r) {
						if (!id[r + 1].count(it->s)) 
							id[r + 1][it->s] = ++k;
						int k2 = id[r + 1][it->s];
						
						q.insert(mp(r + 1, it->s));
						m[k2] = i;
						c[k2] = c[k1];
					}
					q.erase(it);
					continue;
				}

				if (it == q.begin())
					break;

				it--;
				if (it->s < l)
					break;
				int k1 = id[it->f][it->s];
				upd(it->f, it->s, get(c[k1], m[k1]));

				q.insert(mp(it->f, l - 1));
				if (!id[it->f].count(l - 1))
					id[it->f][l - 1] = ++k;
				int k2 = id[it->f][l - 1];

				m[k2] = i;
				c[k2] = c[k1];
				if (it->s > r) {
					q.insert(mp(r + 1, it->s));
					if (!id[r + 1].count(it->s))
						id[r + 1][it->s] = ++k;
					int k3 = id[r + 1][it->s];
					m[k3] = i;
					c[k3] = c[k1];
				}
				q.erase(it);
				break;
			}
				
			q.insert(mp(l, r));
			if (!id[l].count(r))
				id[l][r] = ++k;

			int k1 = id[l][r];
			m[k1] = i;
			c[k1] = cc;
		} else if (s[0] == 'A') {
			int c, x;
			scanf("%d%d", &c, &x);
			g[c].pb({i, (!sz(g[c]) ? 0 : g[c].back().s) + x});				
		} else {
			int j;
			scanf("%d", &j);
			auto it = q.lower_bound(mp(j, inf));
			it--;
			int k1 = id[it->f][it->s];
			upd(it->f, it->s, get(c[k1], m[k1]));
			m[k1] = i;
			printf("%lld\n", get(j));
		}
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