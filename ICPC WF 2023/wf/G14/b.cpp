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
const int N = 200, inf = 2e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

struct TwoSat{
	int n;
	vector < vi > gr;
	vi values;
	TwoSat(int n = 0): n(n), gr(2*n) {}


	int addVar() { // ( optional )
		gr.emplace_back();
		gr.emplace_back();
		return n++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].pb(j^1);
		gr[j].pb(f^1);
	}

	void setValue(int x) {
		either(x,  x);
	}

	void atMostOne(const vi &li) {
		if (sz(li) <= 1)
			return;

		int cur = ~li[0];
		for (int i = 2; i < sz(li); ++i) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}

		either(cur, ~li[1]);
	}


	vi val, comp, z; 
	int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) 
			if (!comp[e])
				low = min(low, val[e] ? val[e] : dfs(e));
		if (low == val[i]) {
			do {
				x = z.back(); z.pop_back();
				comp[x] = low;
				if (values[x>>1] == -1)
					values[x>>1] = x&1;
			} while (x != i);
		}
		return val[i] = low;
	}

	bool solve() {
		values.assign(n, -1);
		val.assign(2*n, 0); comp = val;
		for(int i = 0; i < 2*n; ++i) 
			if (!comp[i]) 
				dfs(i);

		for(int i = 0; i < n; ++i) 
			if (comp[2*i] == comp[2*i+1]) 
				return 0;
		return 1;
	}
};


vector < pii > g[M*M];
int n, d[M][M];
vi vals;

bool check(int l, int r) {
	for (auto e : g[l]) {
		TwoSat ts = TwoSat(n);
		ts.setValue(e.f);
		ts.setValue(e.s);
		for (int i = l + 1; i < sz(vals); ++i) {
			for (auto e1 : g[i]) {
				ts.either(e1.f, e1.s);
				if (i > r)
					ts.either(~e1.f, ~e1.s);
			}
		}

		if (ts.solve())
			return 1;
	}

	return 0;
}


int getRand() {
	int res = 0;
	for (int j = 0; j < 25; ++j)
		if (rand() & 1)
			res |= (1 << j);

	return res;
}
 
void solve() {
	fastio
	n = 200;
	if (n <= 2) {
		cout << 0 << "\n";
		return;
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			d[i][j] = getRand();
			vals.pb(d[i][j]);
		}

	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			d[i][j] = lower_bound(all(vals), d[i][j]) - vals.begin();
			g[d[i][j]].pb({i, j});
		}

	int ans = vals.back();
	for (int i = 0; i < n; ++i) {
		int res = 0;
		for (int j = 0; j < n; ++j)
			if (j != i)
				for (int x = j + 1; x < n; ++x)
					if (x != i)
						res = max(res, vals[d[j][x]]);

		ans = min(ans, res);
	}

	for (int l = 0, r = sz(vals) - 1; r >= 0; --r) {
		while (vals[l] + vals[r] < ans && l <= r && !check(l, r))
			l++;

		if (l > r)
			break;
		ans = min(ans, vals[r] + vals[l]);
	}

	cout << ans << "\n";


	
}

main () {
	srand(time(0));
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}