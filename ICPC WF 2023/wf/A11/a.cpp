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
const int N = 1e5, inf = 1e15, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int a, m, p, q, r, s;
int pw[40];
vector < int > ans;

vector < int > get(int lf, int n) {
	vector < int > res(n + 2);
	res.back() = n;
	for (int i = n; i >= 0; --i) {
		res[i] = lf / pw[i];
		lf %= pw[i];
		res.back() += res[i];
	}

	return res;
}

vector < pair < int, char > > f(vector < pair < int, char > > res) {
	vector < pair < int, char > > r;
	for (int i = 0; i < sz(res); ++i) {
		pair < int, char > cur = res[i];
		while (i + 1 < sz(res) && res[i + 1].s == cur.s) {
			cur.f += res[i + 1].f;
			i++;
		}

		r.pb(cur);
	}

	return r;
}

void f(vector < int > cur) {
	if (cur == ans)
		return;

	if (cur.back() != ans.back()) {
		if (cur.back() < ans.back())
			ans = cur;
		return;
	}

	int i1 = sz(ans) - 2, i2 = sz(cur) - 2;
	while (1) {
		assert(i1 >= 0 && i2 >= 0);
		if (ans[i1] > cur[i2]) {
			return;
		}
		if (ans[i1] < cur[i2]) {
			ans = cur;
			return;
		}

		i1--, i2--;
	}
}

                                                   
void solve(int tt) {
	cin >> a >> m >> p >> q >> r >> s;
	if (!a)
		exit(0);

	cout << "Case " << tt << ": ";
	
	ans = {inf};
	pw[0] = 1;

	for (int n = 0; ; ++n) {
		pw[n + 1] = pw[n] * m;
		if (m == 1 && n > 0)
			break;		
        
		int lf = max(0ll, r - p*pw[n]);
		int rg = s - q*pw[n];

		if (rg < 0)
			break;

		lf = (lf + a - 1) / a;
		rg = rg / a;
		if (lf > rg) 
			continue;

		vector < int > cur = get(lf, n);
		f(cur);
	
		for (int i = 1; i <= n; ++i) {
			vector < int > tmp = cur;
			tmp[i]++;     
			tmp.back()++;

			for (int j = 0; j < i; ++j) {
			    tmp.back() -= tmp[j];
				tmp[j] = 0;				
			}

			int L = 0;
			for (int i = 0; i <= n; ++i) {
				L += tmp[i]*pw[i];
			}

			if (L <= rg) {
				f(tmp);
			}
		}

	}

	if (ans.back() == inf) {
		cout << "impossible\n";
		return;
	}

//	for (auto x : ans)
//		cerr << x << ' ';
//	cerr << "----> " << ans.back() << endl;
	ans.ppb();

	vector < pair < int, char > > res;
	for (int i = sz(ans) - 1; i >= 0; --i) {
		if (ans[i] > 0)
			res.pb(mp(ans[i], 'A'));
		if (i > 0)
			res.pb(mp(1, 'M'));
	}

	
	res = f(res);
	if (!sz(res)) {
		cout << "empty\n";
		return;
	}

//	cerr << res.s << endl

	for (auto x : res)
		cout << x.f << x.s << ' ';
	cout << endl;
}

main () {
  for (int tt = 1; ; ++tt) {
    solve(tt);
  }
}