//by paradox & gege & parasat
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
int d[M], st[M], en[M];
vi gl[M << 2], gr[M << 2];

void build(int v = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr) {
		gl[v].pb(st[tl]);
		gr[v].pb(en[tl]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	for (int i : gl[v << 1])
		gl[v].pb(i);
	for (int i : gl[v << 1 | 1])
		gl[v].pb(i);
	for (int i : gr[v << 1])
		gr[v].pb(i);
	for (int i : gr[v << 1 | 1])
		gr[v].pb(i);
	sort(all(gl[v]));
	sort(all(gr[v]));
}

int get(int l, int r, int x, int v = 1, int tl = 0, int tr = n - 1) {
	if (l > r || tl > r || l > tr)
		return 0;
	if (l <= tl && tr <= r) {
		int ir = upper_bound(all(gr[v]), x) - gr[v].begin();
		int il = upper_bound(all(gl[v]), x) - gl[v].begin();
		il = (tr - tl + 1) - il;
//		if (ir + il) {
//			cerr << "? " << l << ' ' << r << ' ' << x << " | " << v << ' ' << tl << ' ' << tr << "\n";
//			cerr << ir << ' ' << il << "\n";
//		}
		return tr - tl + 1 - (ir + il);
	}
	int tm = (tl + tr) >> 1;
	int le = get(l, r, x, v << 1, tl, tm);
	int ri = get(l, r, x, v << 1 | 1, tm + 1, tr);
	return le + ri;
}

void solve() {
	cin >> n;
	string ss;
	getline(cin, ss);

	for (int i = 1; i <= n; i++) {
		string ss;
		getline(cin, ss);

		int cur = 0;
		char sign = '#';
		for (int j = 0; j < sz(ss); j++) {
			if (isdigit(ss[j])) {
				cur = cur * 10 + ss[j] - '0';
			}

			if (ss[j] == ' ' || j + 1 == sz(ss)) {
				if (sign == '+')
					st[cur] = i;
				else
					en[cur] = i;
			}
			if (ss[j] == '+' || ss[j] == '-') {
				sign = ss[j];
				cur = 0;
			}
		}
	}

	build();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		int res = get(ans, n, d[i]);
		ans = (ans + res) % n;
//		cerr << "after: " << i << ' ' << ans << "\n";
	}

	cout << ans << "\n";
}

main () {
	fastio;
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

