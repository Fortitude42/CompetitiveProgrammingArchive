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
const pii base = mp(1e6 + 3, 1e6 + 33), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 2e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
vi vals;
pii t[M];
int n, a[30], n1, ans[M];
vector < pair < pii, pii > > a1, a2;

void rec1(int i = 0, int s1 = 0, int s2 = 0, int s3 = 0, int mask = 0) {
	if (i == n1) {
		a1.pb({{s1 - s2, s2 - s3}, {s1 - s3, mask}});
		return;
	}

	rec1(i + 1, s1 + a[i], s2, s3, mask*3);
	rec1(i + 1, s1, s2 + a[i], s3, mask*3 + 1);
	rec1(i + 1, s1, s2, s3 + a[i], mask*3 + 2);
}

void rec2(int i = n1, int s1 = 0, int s2 = 0, int s3 = 0, int mask = 0) {
	if (i == n) {
		a2.pb({{s2 - s1, s3 - s2}, {s1 - s3, mask}});
		vals.pb(s3 - s2);
		return;
	}

	rec2(i + 1, s1 + a[i], s2, s3, mask*3);
	rec2(i + 1, s1, s2 + a[i], s3, mask*3 + 1);
	rec2(i + 1, s1, s2, s3 + a[i], mask*3 + 2);
}


void inc(int pos, pii x) {
	while (pos < sz(vals)) {
		t[pos] = min(t[pos], x);
		pos |= pos + 1;
	}
}

pii get(int r) {
	pii res = {inf, inf};
	while (r >= 0) {
		res = min(res, t[r]);
		r = (r & (r + 1)) - 1;
	}

	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	n1 = (n + 1) / 2;

	rec1();
	rec2();

	sort(all(a1));
	sort(all(a2));
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	
	for (int i = 0; i < sz(vals); ++i)
		t[i] = {inf, inf};
	
	

	int i = 0;
	pair < int, pii > res = {inf, {inf, inf}};
	for (auto x : a1) {
		while (i < sz(a2) && a2[i].f.f <= x.f.f) {
			inc((lower_bound(all(vals), a2[i].f.s) - vals.begin()), a2[i].s);
			i++;
		}
		pii cur = get(upper_bound(all(vals), x.f.s) - vals.begin() - 1);

		res = min(res, mp(x.s.f + cur.f, mp(x.s.s, cur.s)));
	}

	for (int i = n1 - 1; i >= 0; --i) {
		ans[i] = (res.s.f % 3) + 1;
		res.s.f /= 3;
	}
	for (int i = n - 1; i >= n1; --i) {
		ans[i] = (res.s.s % 3) + 1;
		res.s.s /= 3;
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	
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

