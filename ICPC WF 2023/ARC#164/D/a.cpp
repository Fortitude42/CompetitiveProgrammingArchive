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
const int N = 6000, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

int n, f[M], rf[M];
string s;


int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		n >>= 1;
		a = a * 1ll * a % MOD;
	}

	return res;
}

int cnk(int n, int k) {
	return f[n] * 1ll * rf[k] % MOD * rf[n - k] % MOD;
}

void precalc() {
	f[0] = 1;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] * 1ll * i % MOD;
	
	rf[M - 1] = binpow(f[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; --i)
		rf[i] = rf[i + 1] * 1ll * (i + 1) % MOD;
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void sub(int &x, int y) {
	x -= y;
	if (x < 0)
		x += MOD;
}

 
void solve() {
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < sz(s); ++i) {
		string t = s[i] == '?' ? "+-" : s.substr(i, 1);
		int lq = 0, rq = 0, lm = 0, rm = 0, lp = 0, rp = 0;
		for (int j = 0; j < i; ++j) {
			if (s[j] == '?')
				++lq;
			else if (s[j] == '+')
				++lp;
			else
				++lm;
		}

		for (int j = i + 1; j < sz(s); ++j) {
			if (s[j] == '?')
				++rq;
			else if (s[j] == '+')
				++rp;
			else
				++rm;
		}

		for (char c : t) {
			int m = (c == '-') + lm + rm;
			int p = (c == '+') + lp + rp;
			for (int lqm = 0; lqm + m <= n && lqm <= lq; ++lqm) {
				int rqm = n - (m + lqm);
				if (rqm < 0 || rqm > rq)
					continue;

				int lqp = lq - lqm;
				int rqp = rq - rqm;
				
				int F = ((lp + lqp) - (lm + lqm)) - ((rp + rqp) - (rm + rqm));
				if (c == '-')
					F = -F;
				
				int var = cnk(lq, lqm) * 1ll * cnk(rq, rqm) % MOD;
				
				if (F > 0)
					sub(ans, var*1ll*i % MOD);
				else
					add(ans, var*1ll*i % MOD);
			}
		}
	}

	cout << ans << endl;
}

main () {
	fastio
	precalc();
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}