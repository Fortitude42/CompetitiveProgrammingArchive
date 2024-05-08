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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 52;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


map < pii, int > cnt, was;
int n, mn = inf, m;
string s[N];
vpii h[N];
pii p[N];

 
pii get (int i, int l, int r) {
	if (!l)
		return h[i][r];
	return mp(((1ll*h[i][r].f - h[i][l - 1].f * 1ll * p[r - l + 1].f) % Mod.f + Mod.f) % Mod.f, ((1ll*h[i][r].s - h[i][l - 1].s * 1ll * p[r - l + 1].s) % Mod.s + Mod.s) % Mod.s);
}

bool check (int len) {
	cnt.clear();

	for (int i = 1; i <= n; ++i) {
		was.clear();
		for (int l = 0, r = len - 1; r < sz(s[i]); ++l, ++r) {
		    pii cur = get(i, l, r);
			if (!was.count(cur))   {
				was[cur] = 1;
				++cnt[cur];
			}

			if (i == 1 && l == 2 && r == 3)
				cerr << cur.f << ' ' << cur.s << endl;
			if (i == 2 && l == 3 && r == 4)
				cerr << cur.f << ' ' << cur.s << endl;
		}
	}

	for (auto x : cnt)
		if (x.s == n)
			return 1;

	return 0;
}

main () {
	p[0] = {1, 1};
	for (int i = 1; i < N; ++i) 
		p[i] = {p[i - 1].f * 1ll * base.f % Mod.f, p[i - 1].s * 1ll * base.s % Mod.s};
	

	cin >> n;
	for (int i = 1; i <= n; ++i)  {
		cin >> s[i];               
		mn = min(mn, sz(s[i]));
		s[i] += s[i];
		
		m = sz(s[i]);
		h[i].resize(m);
		h[i][0] = {s[i][0], s[i][0]};
		for (int j = 0; j < m; ++j)
			h[i][j] = mp((h[i][j - 1].f * 1ll * base.f + s[i][j]) % Mod.f, (h[i][j - 1].s * 1ll * base.s + s[i][j]) % Mod.s);
	}


	int l = 1, r = mn, res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		} else 
			r = mid - 1;
	}

	cout << res << endl;
}