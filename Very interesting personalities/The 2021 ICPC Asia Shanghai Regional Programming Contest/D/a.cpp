// template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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
const int N = 3e7, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int lp[M];

int __gcd(int a, int b) {
 return b == 0 ? a : __gcd(b, a % b);
}

void precalc() {
	for (int i = 2; i*i <= N; ++i) {
		if (!lp[i])
			for (int j = i*i; j <= N; j += i)
				lp[j] = i;
	}

	for (int i = 2; i <= N; ++i)
		if (!lp[i])
			lp[i] = i;

}

int get(int x) {
	int k = 1;
	while (x > 1) {
		int y = lp[x], cnt = 0;
		while (!(x % y)) { 
			x /= y;        
			cnt++;
		}

		if (cnt & 1)
			k *= y;
	}

	return k;
}

void solve() {
	ll p, q;
 scanf("%lld %lld", &p, &q);
 int gcd = __gcd(p, q);
 p /= gcd;
 q /= gcd;

 if (p - 2 * q < 0) {
  printf("0 0\n");
  return;
 }

 int k = get(p + 2*q);
 int k1 = get(p + 2*q);
	if (k != k1) {
		printf("0 0");
		return;
	}
	
	p *= 4*k;
	q *= 4*k;

 ll delta = sqrtl(p - 2 * q);
 ll disc = sqrtl(p + 2 * q);
 if (delta * delta != p - 2 * q || disc * disc != p + 2 * q) {
  printf("0 0\n");
  return;
 }

 ll a = 0, b = 0;
 if ((-delta + disc) % 2 == 0) {
  a = (-delta + disc) / 2;
  b = a + delta;
 }

 printf("%lld %lld\n", a, b);
}

int main() {
	precalc();
 int TT;
 TT = 1;
 scanf("%d", &TT);
 for (int tt = 1; tt <= TT; ++tt) {
  solve();
 }
}