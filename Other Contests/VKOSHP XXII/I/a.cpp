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

pii p[M];
int n, L, msk[M]; 
string s[M];

int find(int x) {
	for (int i = 0; i < 26; ++i)
		if (x & (1 << i))
			return i;
	return -1;
}

void rec(const vi &pos, int mask) {
	if (sz(pos) <= 1)
		return;

	int m = -1;	
	for (auto i : pos)
		if (m == -1) 
			m = msk[i];
		else
			m &= msk[i];
	


	m ^= mask;
	int bit = find(m);

	if (bit == -1) {
		puts("NO");
		exit(0);
	}

	mask |= (1 << bit);
	
	vector < pair < pii, int > > v;
	for (auto i : pos) {
		pii cur = {0, 0};
		for (int j = 0; j < L; ++j)
			if (s[i][j] - 'a' == bit) {
				cur.f += p[j].f;
				cur.s += p[j].s;

				if (cur.f >= mod.f)
					cur.f -= mod.f;

				if (cur.s >= mod.s)
					cur.s -= mod.s;
			}
		v.pb(mp(cur, i));
	}

	sort(all(v));
	for (int i = 0; i < sz(v); ) {
		int j = i;
		vi poss;
		while (j < sz(v) && v[i].f == v[j].f) 
			poss.pb(v[j++].s);

		rec(poss, mask);
		i = j;
	}
}

inline void precalc() {
	p[0] = {1, 1};
	for (int i = 1; i < M; ++i)
		p[i] = mp(p[i - 1].f * 1ll * base.f % mod.f, p[i - 1].s * 1ll * base.s % mod.s);
}

void solve() {
	cin >> L >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (auto c : s[i])
			msk[i] |= (1 << (c - 'a'));
	}

	vi all;
	for (int i = 0; i < n; ++i)
		all.pb(i);

	rec(all, 0);
	puts("YES");
}

main () {
	precalc();

	fastio
	int TT;
	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}