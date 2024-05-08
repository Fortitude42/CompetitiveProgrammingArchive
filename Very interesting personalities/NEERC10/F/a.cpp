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
typedef unsigned long long ll;
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 10, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 2;
const ll INF = 1e18;

const int K = 10;
const int L = 19;
const int W = 62;

int c[K][K];

int nxt_g[K][K][W];
int nxt_f[L][K][K][W];

int get_g(int v, int to, ll length) {
	for (int k = W - 1; k >= 0; k--) {
		if ((1ull << k) <= length) {
			length -= (1ll << k);
			v = nxt_g[to][v][k];
		}
	}
	return v;
}

int get_f(int i, int v, int to, ll length) {
	for (int k = W - 1; k >= 0; k--) {
		if ((1ull << k) <= length) {
			length -= (1ll << k);
			v = nxt_f[i][v][to][k];
			to = (to + (1ll << k)) % 10;
		}
	}
	return v;
}
 
void solve() {
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			scanf("%d", &c[i][j]);
	
	long long l, r;
	scanf("%lld %lld", &l, &r);
	ll a = l, b = r;

	for (int k = 0; k < 3; k++) {
		for (int to = 0; to < K; to++) {
			for (int v = 0; v < K; v++) {
				nxt_g[to][v][k] = k ? nxt_g[to][nxt_g[to][v][k - 1]][k - 1] : c[v][to];
//				cerr << nxt_g[to][v][k] << ' ';
			}
//			cerr << "\n";
		}
//		cerr << "\n";
	}
	
	ll dg = 1;
	for (int i = 0; i < L; i++) {
		for (int k = 0; k < 3; k++) {
			for (int v = 0; v < K; v++) {
				for (int to = 0; to < K; to++) {
					if (!k) {
						nxt_f[i][v][to][k] = get_g(v, to, dg);
					} else {
						nxt_f[i][v][to][k] = nxt_f[i][nxt_f[i][v][to][k - 1]][(to + (1ll << (k - 1))) % 10][k - 1];
					}
					cout << nxt_f[i][v][to][k] << ' ';
				}
				cout << "\n";
			}
			cout << "\n";
		}
		cout << "\n";
		dg *= 10;
	}
   	
	vi ans;
	dg = 1;

	for (int i = 0; i < 4; i++) {
		int v = a / dg % (dg * 10);
		ll prelen = min(b - a, (i ? dg - a % dg - 1 : 0));
		ll len = (b - a - prelen) / dg;
		cerr << v << " " << prelen << ' ' << len << " | ";
		v = get_g(v, v, prelen);
		cerr << v << " | ";
		v = get_f(i, v, (v + 1) % 10, len);
		cerr << v << " | ";

		ll left = (b - a - prelen) % dg;
		v = get_g(v, v, left);
		cerr << v << "\n";
		ans.pb(v);

		dg *= 10;
		cerr << "ok\n";
	}

	reverse(all(ans));
	for (int v : ans)
		printf("%d", v);
	printf("\n");
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}