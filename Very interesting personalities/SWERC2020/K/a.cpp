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
const int N = 3e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n;
string s;
pii p[M], h[M];
map < pii, int > cnt;
 
int norm(ll x, int m) {
	return ((x % m) + m) % m;
}

pii get(int l, int r) {
	if (!l)
		return h[r];

	return mp(norm(h[r].f - h[l - 1].f * 1ll * p[r - l + 1].f, mod.f), norm(h[r].s - h[l - 1].s * 1ll * p[r - l + 1].s, mod.s));
}

pii get(int len) {
	cnt.clear();

	for (int i = 0; i + len - 1 < n; ++i)
		++cnt[get(i, i + len - 1)];

	for (int i = 0; i + len - 1 < n; ++i)
		if (cnt[get(i, i + len - 1)] == 1)
			return mp(i, i + len - 1);

	return mp(-1, -1);
}


void solve() {
	cin >> s;
	n = sz(s);

	h[0] = {s[0], s[0]};
	for (int i = 1; i < n; ++i)
		h[i] = mp((h[i - 1].f * 1ll * base.f + s[i]) % mod.f, (h[i - 1].s * 1ll * base.s + s[i]) % mod.s);

	int l = 1, r = n - 1;
	pii res = mp(0, n - 1);
	while (l <= r) {
		int mid = (l + r) >> 1;
		pii cur = get(mid);
		if (cur.f != -1) {
			res = cur;
			r = mid - 1;
		} else
			l = mid + 1;
	}

	for (int i = res.f; i <= res.s; ++i)
		cout << s[i];
}

main () {
	fastio
	p[0] = {1, 1};
	for (int i = 1; i < M; ++i)
		p[i] = {p[i - 1].f * 1ll * base.f % mod.f, p[i - 1].s * 1ll * base.s % mod.s};

	
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

