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
const int N = 1e5, inf = 1e9, MOD = 998244353;
const int M = N + 17;
const ll INF = 1e18;

const int gen = 5;

 
int pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % MOD;
    if (step & b) x = (long long)x * a % MOD;
    step >>= 1;
  }
  return x;
}
 
void fft(vector <int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    int j = 0;
    int x = i, y = n - 1;
    while (y > 0) {
      j = (j << 1) + (x & 1);
      x >>= 1;
      y >>= 1;
    }
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 1; len < n; len *= 2) {
    int root = pw(gen, (MOD - 1) / (2 * len));
    for (int i = 0; i < n; i += 2 * len) {
      int w = 1;
      for (int j = 0; j < len; j++) {
        int u = a[i + j];
        int v = (long long)a[i + j + len] * w % MOD;
        a[i + j] = u + v;
        if (a[i + j] >= MOD) a[i + j] -= MOD;
        a[i + j + len] = u - v;
        if (a[i + j + len] < 0) a[i + j + len] += MOD;
        w = (long long)w * root % MOD;
      }
    }
  }
}
 
vector <int> multiply(vector <int> a, vector <int> b) {
  int an = a.size();
  int bn = b.size();
  int need = an + bn - 1;
  int nn = 1;
  while (nn < 2 * an || nn < 2 * bn) nn <<= 1;
  a.resize(nn);
  b.resize(nn);
  fft(a);
  fft(b);
  for (int i = 0; i < nn; i++) a[i] = (long long)a[i] * b[i] % MOD;
  reverse(++a.begin(), a.end());
  fft(a);
  int inv = pw(nn, MOD - 2);
  for (int i = 0; i < nn; i++) a[i] = (long long)a[i] * inv % MOD;
  a.resize(need);
  return a;
}

vi binpow(vi a, int n) {
	vi b = {1};
	while (n) {
		if (n & 1)
			b = multiply(b, a);
		n >>= 1;
		a = multiply(a, a);
	}

	return b;
}
void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		a = a * 1ll * a % MOD;
		n >>= 1;
	}

	return res;
}


int x1, x2, x3, k; 

void solve() {
	cin >> x1 >> x2 >> x3 >> k;
	vi a = {1, 1, 1};
	vi v = binpow(a, k);
	int ans = 0;
	for (int x = -k; x <= k; ++x) {
		add(ans, v[x + k] * 1ll * abs(x1 - x2 + x) % MOD); 
		add(ans, v[x + k] * 1ll * abs(x1 - x3 + x) % MOD); 
		add(ans, v[x + k] * 1ll * abs(x2 - x3 + x) % MOD);
	}

	ans = ans * 1ll * binpow(binpow(3, k) * 2 % MOD, MOD - 2) % MOD;
	cout << ans << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

