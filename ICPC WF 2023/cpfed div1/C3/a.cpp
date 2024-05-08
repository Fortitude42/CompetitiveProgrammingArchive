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
const int N = 5e3, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



string s;
pii h[M];
int m, n;
pair < ll, int > q[M];
bool del[M];
char ans[M];
 
void solve(int tt) {
	cin >> m;
	if (!m)
		exit(0);

	cin >> s;
	n = sz(s);
	for (int i = 1; i <= m; ++i) {
		cin >> q[i].f;
		q[i].s = i;
	}
	sort(q + 1, q + 1 + m);

	
	vector < pair < char, pii > > v;
	for (int l = 0; l < n; ++l) {
		h[l] = {s[l], s[l]};
		v.pb(mp(s[l], mp(l, l)));
		del[l] = 0;
	}

	sort(all(v));
	ll cur = 0;
	int j = 1;
	while (sz(v)) {
		int pref = 0;
		while (pref < sz(v) && h[v[pref].s.f] == h[v[0].s.f])
			++pref;


		int pref1 = 0;

		for (int i = 0; i < pref; ++i) {
			int l = v[i].s.f;
			int r = v[i].s.s;
			int len = r - l + 1;
			while (j <= m && cur + len >= q[j].f) {
				ans[q[j].s] = s[l + q[j].f - cur - 1];
				j++;
			}

			cur += len;


			if (r + 1 < n) {
				++r;
				h[l] = mp((h[l].f * 1ll * base.f + s[r]) % mod.f, (h[l].s * 1ll * base.s + s[r]) % mod.s);
				v[i].s.s = r;
				v[i].f = s[r];
				++pref1;
			} else
				del[l] = 1;
		}

		if (pref1 != pref) {
			vector < pair < char, pii > > v1;
			for (int i = 0; i < sz(v); ++i)
				if (!del[v[i].s.f])
					v1.pb(v[i]);
			swap(v, v1);
			pref = pref1;
		}

		if (pref > 1)
			sort(v.begin(), v.begin() + pref);
	}

	cout << "Case #" << tt << ": ";
	for (int i = 1; i <= m; ++i)
		cout << ans[i];
	cout << endl;
}

main () {
	fastio
  int TT;
  TT = inf;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve(tt);
  }
}