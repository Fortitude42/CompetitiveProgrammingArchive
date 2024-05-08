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
const int N = 1e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

string a;
int b, d;
int p[M], pp[M];


bool le(string sa, string sb) {
	if (sz(sa) != sz(sb))
		return sz(sa) < sz(sb);
	for (int i = 0; i < sz(sa); ++i)
		if (sa[i] != sb[i])
			return sa[i] < sb[i];


	return 1;
}


bool check(int len) {
	int y = (b - pp[len - 1]) % b;
	for (int x = (!d); x < b; ++x) 
		if (x*1ll*p[len] % b == y) {
			string cur = "";
			for (int i = 0; i < len; ++i)
				cur += ('0' + d);
			
			while (x > 0) {
				cur += (x % 10) + '0';
				x /= 10;
			}

			reverse(all(cur));

			return le(cur, a);
		}
	


	return 0;
}
 
void solve() {
	cin >> b >> d >> a;

	p[0] = 1;
	pp[0] = d % b;

	for (int i = 1; i <= sz(a); ++i) {
		p[i] = p[i - 1] * 10ll % b;
		pp[i] = (0ll + pp[i - 1] + p[i]*1ll*d) % b;
	}

	int l = 1, r = sz(a), res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			res = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}

	cout << res << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}