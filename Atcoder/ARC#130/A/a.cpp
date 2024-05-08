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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
string s;
pii p[M], h[M];

pii get(int l, int r) {
	if (l > r)
		return mp(0, 0);
	if (!l)
		return h[r];

	return mp(((h[r].f - h[l - 1].f * 1ll * p[r - l + 1].f) % mod.f + mod.f) % mod.f, ((h[r].s - h[l - 1].s * 1ll * p[r - l + 1].s) % mod.s + mod.s) % mod.s);
}

void solve() {
	fastio
	cin >> n >> s;

	h[0] = {s[0], s[0]};

	for (int i = 1; i < n; ++i) 
		h[i] = {(h[i - 1].f * 1ll * base.f + s[i]) % mod.f, (h[i - 1].s * 1ll * base.s + s[i]) % mod.s};
	
	map < pii, int > cnt;

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		pii a = get(0, i - 1);
		pii b = get(i + 1, n - 1);
		pii c = mp((b.f + p[n - 1 - i].f * 1ll * a.f) % mod.f, (b.s + p[n - 1 - i].s * 1ll * a.s) % mod.s);
/*		cerr << a.f << ' ' << a.s << endl;
		cerr << b.f << ' ' << b.s << endl;
		cerr << c.f << ' ' << c.s << endl << endl;*/
		ans += cnt[c]++;
	}

	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;
	p[0] = {1, 1};
	for (int i = 1; i < M; ++i)
		p[i] = {p[i - 1].f * 1ll * base.f % mod.f, p[i - 1].s * 1ll * base.s % mod.s};

//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}