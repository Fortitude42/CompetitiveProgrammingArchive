//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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

	y		continue;
		int l = max(d, cmn[v] + v * t);
		int r = min(u, cmx[v] + v * t);
//		cerr << v << " | " << l << ' ' << r << "\n";
		area += max(0LL, r - l + 1);

// 		cerr << "cminmax: " << v << " | " << cmn[v] << ' ' << cmx[v] << "\n";
		p[max(d, cmn[v] + v * times)]++;
		p[min(u, cmx[v] + v * times) + 1]--;
    }
    return area;
}
 
void solve() {
	scanf("%lld %lld", &a, &b);

	for (int i = 0; i <= b; i++)
		cmx[i] = a;
	int u = a, d = 0;

	while (true) {
		int l = d, r = d - 1;
		ll area = getarea(d, u, times);

		ll cur = 0;
		int bal = 0;

		for (int i = d; i < u; i++) {
			bal += p[i];
			cur += bal;
// 			cerr << "i level: " << i << ' ' << cur << "\n";

			if (cur + cur <= area)
				r = i;
			else
				break;
		}

		if (area == 1) {
			u = r + 1;
			break;
		}

		for (int i = 0; i <= b; i++) {
			if (cmn[i] > cmx[i])
				continue;
			p[max(d, cmn[i] + i * times)]--;
			p[min(u, cmx[i] + i * times) + 1]++;
		}

// 		cerr << "area = " << area << ' ' << cur << "\n";

		assert(times < 80);
		bool res = ask(l, r);
		if (!res) {
			l = r + 1;
			r = u;
		}

		for (int i = 0; i <= b; i++) {
			cmn[i] = max(l - times * i, cmn[i]);
			cmx[i] = min(cmx[i], r - times * i);
		}

		u = r + b;
		d = l;
		++times;
	}

	printf("answer %lld\n", u);
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

