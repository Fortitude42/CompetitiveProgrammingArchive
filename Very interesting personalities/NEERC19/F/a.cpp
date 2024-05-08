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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, m, ka, kb, a[M], b[M];
vector < pii > ans;
int cnt[M];

 
void solve() {
	cin >> n >> m >> ka >> kb;
	for (int i = 1; i <= ka; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}

	reverse(a + 1, a + 1 + ka);

	for (int i = 1; i <= kb; ++i) {
		cin >> b[i];
		++cnt[b[i]];
	}

	reverse(b + 1, b + 1 + kb);

	set < int > leaves;
	int v1 = a[1], v2 = n + m;

	for (int i = 1; i <= n + m; ++i)
		if (i != v1 && i != v2 && !cnt[i])
			leaves.insert(i);
	
	ans.pb({v1, v2});
	while (sz(leaves)) {
		int v = *leaves.begin();
		leaves.erase(leaves.begin());
		
		if (v <= n) {
			if (!kb)
				ans.pb({v, v2});
			else {
				ans.pb({v, b[kb]}); 
				--cnt[b[kb]];
				if (!cnt[b[kb]] && b[kb] != v2)
					leaves.insert(b[kb]);
				kb--;				
			}
		} else {
			if (!ka)
				ans.pb({v1, v});
			else {
				ans.pb({a[ka], v}); 
				--cnt[a[ka]];
				if (!cnt[a[ka]] && a[ka] != v1)
					leaves.insert(a[ka]);
				ka--;
			}
		}
	}

	assert(sz(ans) < n + m);
	if (sz(ans) != n + m - 1 || ka > 0 || kb > 0) {		
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;		
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

