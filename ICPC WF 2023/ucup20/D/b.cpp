#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofas5")
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
const int N = 30, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, k, p[M], sz, m, cnt[M][M], pw[M];
bool used[M];
map < int, int > dp[M*2];

map < vi, int > id;
vector < vi > curs;
vi cur;


void rec(int lst = 1, int sum = 0) {
	if (sum == n) {
		assert(!id.count(cur));
		id[cur] = m++;
		curs.pb(cur);
		return;
	}

	for (int x = lst; sum + x <= n; ++x) {
		cur.pb(x);
		rec(x, sum + x);
		cur.ppb();
	}
}


void dfs(int v) {
	used[v] = 1;
	++sz;
	if (!used[p[v]])
		dfs(p[v]);
}


int calc(const vi &v, int k) {
	int h = 0;
	for (int i : v)
		h = (h + pw[i]) % MOD;

	if (dp[k].count(h))
		return dp[k][h];

	if (!k) {
		if (sz(v) == n) 
			return dp[k][h] = 1;		
		return dp[k][h] = 0;
	}



	return dp[k][h] = res;			
}


void solve() {
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		used[i] = 0;
	}


	vi cur;
	for (int i = 1; i <= n; ++i) 
		if (!used[i]) {
			sz = 0;
			dfs(i);
			cur.pb(sz);
		}


	cout << calc(cur, k) << "\n";			
}

main () {
    pw[0] = 1;
	pw[1] = 1e6 + 3;
	for (int i = 2; i < M; ++i)
		pw[i] = pw[i - 1] * 1ll * pw[1] % MOD;

  int TT;
  TT = 1;
  	fastio
	cin >> n >> k >> TT;
	rec();

	for (auto v : curs) {
		int res = 0;
		vi to = v;

		for (int j = 1; j < sz(v); ++j) {
			swap(to[j], to.back());
			to.ppb();		

			for (int i = 0; i < j; ++i) {
				to[i] += v[j];
				res = (res + 1ll * v[i] * v[j] * calc(to, k - 1)) % MOD;
				to[i] -= v[j];
			}

			to.pb(v[j]);
			swap(to[j], to.back());
		}

		for (int i = 0; i < sz(v); ++i) {
			swap(to[i], to.back());
			to.ppb();

			for (int x = 1; x + x <= v[i]; ++x) {
			    to.pb(x);
			    to.pb(v[i] - x);
				res = (res + 1ll * cnt[v[i]][x] * calc(to, k - 1)) % MOD;
				to.ppb();
				to.ppb();
			}

			to.pb(v[i]);
			swap(to[i], to.back());
		}		
	}

	for (int i = 1; i <= n; ++i) {
		for (int i1 = 1; i1 <= i; ++i1)
			for (int i2 = i1 + 1; i2 <= i; ++i2) {
			    int g1 = i2 - i1;
			    int g2 = i - g1;
				++cnt[i][min(g1, g2)];
			}
	}

  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}