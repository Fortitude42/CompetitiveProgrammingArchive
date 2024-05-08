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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, a, b;
 
void solve() {
	cin >> a >> b >> n;

	bool revx = 0, revy = 0;
	if (a < 0) {
		revx = 1;
		a = -a;
	}

	if (b < 0) {
		revy = 1;
		b = -b;
	}

	vector < pair < pii, pii > > ans;
	while (1) {
		ans.pb({{a, b}, {a - n + 1, b - n + 1}});

		if (a >= n - 1 && b >= n - 1) {
			a -= n - 1;
			b -= n - 1;
			if (!a && !b)
				break;
			if (a > b)
				a--;
			else
				b--;	
			continue;
		}

		if (a >= n - 1) {
			a -= n - 1;
			b = 0;
			if (!a)
				break;	
			a--;
			continue;
		}

		if (b >= n - 1) {
			b -= n - 1;
			a = 0;
			swap(ans.back().f, ans.back().s);
			if (!b)
				break;
			b--;
			continue;
		}

		ans.ppb();
		if (!sz(ans) || ((ans.back().f.f != a + 1 || max(0, ans.back().f.s) != b) && (ans.back().s.f != a + 1 || max(0, ans.back().s.s) != b))) 
			ans.pb({{n - 1, b}, {0, b - n + 1}});		
		else
			ans.pb({{a - n + 1, 0}, {a, n - 1}});
		break;
	}   	

	cout << sz(ans) << endl;
	for (auto x : ans)  {
		if (revx) {
			x.f.f = -x.f.f;
			x.s.f = -x.s.f;
		}

		if (revy) {
			x.f.s = -x.f.s;
			x.s.s = -x.s.s;
		}

		swap(x.f, x.s);

		cout << x.f.f << ' ' << x.f.s << ' ' << x.s.f << ' ' << x.s.s << endl;
	}
	
}

main () {
	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

                       