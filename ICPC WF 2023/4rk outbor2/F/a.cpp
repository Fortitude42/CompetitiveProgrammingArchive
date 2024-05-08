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

int n;
vector < vi > vv;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
ll ret = a * b - M * ull(1.L / M * a * b);
return ret + M * (ret < 0) - M * (ret >= (ll)M);
}


ull modpow(ull b, ull e, ull mod) {
ull ans = 1;
for (; e; b = modmul(b, b, mod), e /= 2)
if (e & 1) ans = modmul(ans, b, mod);
return ans;
}

bool isPrime(ull n) {
if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
s = __builtin_ctzll(n-1), d = n >> s;
for (ull a : A) { // ^ count t ra i l in g zeroes
ull p = modpow(a%n, d, n), i = s;
while (p != 1 && p != n - 1 && a % n && i--)
p = modmul(p, p, n);
if (p != n-1 && i != s) return 0;
}
return 1;
}

ull pollard(ull n) {
auto f = [n](ull x) { return modmul(x, x, n) + 1; };
ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
while (t++ % 40 || __gcd(prd, n) == 1) {
if (x == y) x = ++i, y = f(x);
if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
x = f(x), y = f(f(y));
}
return __gcd(prd, n);
}
vector<ull> factor(ull n) {
if (n == 1) return {};
if (isPrime(n)) return {n};
ull x = pollard(n);
auto l = factor(x), r = factor(n / x);
l.insert(l.end(), all(r));
return l;
}


void F(int i, vi &res, const vector < pii > &v, int cur = 1) {
	if (i == sz(v)) {
		res.pb(cur);
		return;
	}


	for (int p = 0; p <= v[i].s; ++p) {
		F(i + 1, res, v, cur);
		if (p + 1 <= v[i].s)
			cur *= v[i].f;
	}
}

vi getfs(int n) {	
	assert(n > 0);

	vector < ull > f = factor(n);
	sort(all(f));
	vector < pii > v;
	for (int i = 0; i < sz(f); ++i) {
		int cnt = 1;
		while (i + 1 < sz(f) && f[i] == f[i + 1]) {
			++cnt;
			++i;
		}
		v.pb({f[i], cnt});
	}

	vi res;
	F(0, res, v, 1);
	return res;
}




 
void solve() {
	cin >> n;
	if (n == 2) {
		cout << 2;
		return;
	}

	int lst = 1;

	for (int b = 2; b*b <= n; ++b) {
		vi d;
		int m = n;
		while (m > 0) {
			d.pb(m % b);
			m /= b;
		}

		sort(all(d));
		vv.pb(d);
		lst = b;
	}

	sort(all(vv));
	vv.resize(unique(all(vv)) - vv.begin());


	int ans = sz(vv) + 1;

	if (lst + 1 <= n) {
		ans += n - lst;
		int l = lst + 1;
		set < pii > q;

		while (l <= n) {
			int x = n / l;
			int r = n / x;

			vi fs = getfs(n - x);

			for (auto b : fs) 
				if (b >= l && b <= r) {
					ans--;
					break;
				}


			l = r + 1;
		}
		
		ans++;
	}


	cout << ans << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}