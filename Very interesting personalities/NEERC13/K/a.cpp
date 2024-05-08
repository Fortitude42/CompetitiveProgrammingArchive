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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, p, c, h, cnt[M], b[M], l[M];
set < pii > q;
 
void inc(int x, int y) {
	if (x != h)
		q.erase(mp(cnt[x], x));
	cnt[x] += y;
	if (x != h)
		q.insert(mp(cnt[x], x));
}

void solve() {
	cin >> n >> p >> c >> h;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		++cnt[b[i]];
	}

	int cnt1 = 0;
	for (int i = 1; i <= p; ++i) {
		cin >> l[i];
		if (i > 1 && l[i] != h) {
			++cnt[l[i]]; 
			cnt1++;
		}
	}

	for (int i = 1; i <= c; ++i) 
		if (i != h)
			q.insert(mp(cnt[i], i));
	
	vi ans;
	for (int i = 1; i <= n; ++i) {
		if (c == 1) {
			ans.pb(i);
			continue;
		}

		if (n == 1) {
			if (l[p] == h)
				ans.pb(i);
			continue;
		}

	    inc(b[i], -1);
	    inc(l[1], 1);
		if (cnt[h] - cnt1 > 0 && cnt[h] - cnt1 > (*q.rbegin()).f) 
			ans.pb(i);
		

		inc(b[i], 1);
		inc(l[1], -1);
	}

	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ';
}

main () {
	file("kabaleo");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

