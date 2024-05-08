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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

const int w = 63;

int n, m;
string s;
ll cur[M], os[M], qs[M], suff[M], pref[M];


ll get(int l, int r) {
	int bll = l / w;
	int blr = r / w;

	int posl = l - bll*w;
	int posr = r - blr*w;

	if (bll == blr) {
		return ((cur[bll] & pref[posr]) & suff[posl]) >> posl;
	}


	assert(blr == bll + 1);
	assert(posl > 0);

/*	if (l == 2 && r == 3) {
		cerr << ((cur[bll] & suff[posl]) >> posl) << endl;
		cerr << ((cur[blr] & pref[posr]) << (w - posl)) << endl;
	}
*/
	return (((cur[bll] & suff[posl]) >> posl) | ((cur[blr] & pref[posr]) << (w - posl)));

}
 
void solve() {
	for (int i = 0; i < w; ++i) 
		pref[i] = (!i ? 0 : pref[i - 1]) | (1ll << i);
	
	for (int i = w - 1; i >= 0; --i)
		suff[i] = suff[i + 1] | (1ll << i);

	cin >> n >> s;

	for (int i = 0; i < n; i += w) {
		ll o = 0, q = 0;
		for (int j = 0; j < w; ++j) {
			if (i + j < n && s[i + j] == '1')
				o |= (1ll << j);
			if (i + j < n && s[i + j] == '?')
				q |= (1ll << j);
		}

		os[m] = o;
		qs[m] = q;
		m++;
	}


	for (int k = 1; k <= n; ++k) {
		if (k <= w) {
			string t = s;
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				if (t[i] == '?' && (i >= k && t[i - k] == '1'))
					t[i] = '1';

				ans += (t[i] == '1');
			}
			cout << ans << "\n";
			continue;
		} 

		//k > w
		int ans = 0;
		for (int bl = 0; bl < m; ++bl) {
			int l = bl*w, r = min(n - 1, (bl + 1)*w - 1);
			cur[bl] = os[bl];


			if (r < k) {
			    ans += __builtin_popcountll(cur[bl]);
				continue;
			}
			
			if (l < k) {
				// l < k <= r
				int len = k - l;
				cur[bl] |= ((get(0, r - k) << len) & qs[bl]);
			    ans += __builtin_popcountll(cur[bl]);
				continue;
			}
			

			cur[bl] |= (get(l - k, r - k) & qs[bl]);
//			cerr << l - k << ' ' << r - k << ' ' << get(l - k, r - k) << endl;
			ans += __builtin_popcountll(cur[bl]);						
		}

		cout << ans << "\n";
	}
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}