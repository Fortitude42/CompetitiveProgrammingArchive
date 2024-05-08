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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, ans[M];
vi valr, valc;
int r[M], c[M];
vi g[M];
vector < pair < pii, int > > gg[M];
multiset < pii > q;

bool cmp(int i, int j) {
	return r[i] < r[j];
}
 
void solve() {
	fastio
	cin >> n;
	for (int i = 1; i <= 2*n; ++i) {
		cin >> r[i] >> c[i];
		valr.pb(r[i]);
		valc.pb(c[i]);
	}



	sort(all(valr));
	valr.resize(unique(all(valr)) - valr.begin());


	sort(all(valc));
	valc.resize(unique(all(valc)) - valc.begin());


	for (int i = 1; i <= 2*n; ++i) {
		r[i] = lower_bound(all(valr), r[i]) - valr.begin();
		c[i] = lower_bound(all(valc), c[i]) - valc.begin();
		g[c[i]].pb(i);
	}



	for (int ic = 0; ic < sz(valc); ++ic) {
		sort(all(g[ic]), cmp);
		for (auto i : g[ic]) 
			if (i <= n) {
				q.insert(mp(r[i], i));
			}else {
				auto it = q.lower_bound(mp(r[i], inf));
				if (it == q.begin()) {
					cout << "syntax error\n";
					return;
				}
				--it;
				int j = it->s;

				ans[j] = i - n;
				q.erase(mp(r[j], j));

				//we make pair i-j
				gg[c[j]].pb(mp(mp(r[j], r[i]), 0));
				gg[c[i]].pb(mp(mp(r[j], r[i]), 1));
			}

	}

	multiset < int > q;
	for (int ic = 0; ic < sz(valc); ++ic) {
		for (auto x : gg[ic]) {
			if (!x.s) {
				q.insert(x.f.f);
				q.insert(x.f.s);
			}
		}


		for (auto x : gg[ic]) {
			q.erase(q.find(x.f.f));
			q.erase(q.find(x.f.s));
			auto it = q.lower_bound(x.f.f);
			if (it != q.end() && *it <= x.f.s) {
				cout << "syntax error\n";
				return;
			}

			q.insert(x.f.f);
			q.insert(x.f.s);
		}

		for (auto x : gg[ic])
			if (x.s) {
				q.erase(q.find(x.f.f));
				q.erase(q.find(x.f.s));
			}		
	}
		


	for (int i = 1; i <= n; ++i)
		cout << ans[i] << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}