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

int n, a[M], ans[M], cnt[M];
bool was[M], has[M];
set < pii > q;

void solve1() {
	memset(cnt, 0, sizeof cnt);
	q.clear();

	for (int i = 1; i <= n; ++i)
		if (has[a[i]])
			cnt[a[i]]++;

	int add = 0;
	for (int i = 1; i <= N; ++i)
		if (cnt[i] > 0)
			q.insert(mp(cnt[i], i));
		else if (was[i])
			++add;

	int k = 0;
	while (sz(q) > 0) {
//		cerr << k << ' ' << sz(q) + add << endl;
		ans[k] = min(ans[k], sz(q) + add);

		int i = q.begin()->s;
		q.erase(q.begin());

		cnt[i]--;
		if (cnt[i] > 0)
			q.insert(mp(cnt[i], i));
		k++;
	}
	for (int kk = k; kk <= n; ++kk)
		ans[kk] = min(ans[kk], sz(q) + add);
}

void solve2() {
	memset(cnt, 0, sizeof cnt);
	q.clear();

	for (int i = 1; i <= n; ++i)
		cnt[a[i]]++;

	for (int i = 1; i <= N; ++i)
		if (cnt[i] > 0)
			q.insert(mp(cnt[i], i));


	int k = 0, add = 1;
	while (sz(q) > 0) {
		ans[k] = min(ans[k], sz(q) + add);
//		cerr << k << ' ' << sz(q) + add << endl;

		int i = q.begin()->s;
		q.erase(q.begin());

		cnt[i]--;
		if (cnt[i] > 0)
			q.insert(mp(cnt[i], i));
		k++;
	}
	ans[k] = min(ans[k], sz(q) + add);
}

void solve() {
//	file("equal");
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		was[a[i]] = 1;
	}

	for (int i = 0; i <= n; ++i)
		ans[i] = inf;

	for (int i = 1; i <= N; ++i)
		for (int j = i + i; j <= N; j += i)
			if (was[j]) {
				has[i] = 1; 
				break;
			}

	solve1();
	solve2();
	for (int k = 0; k <= n; ++k)
		cout << ans[k] << ' ';
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}