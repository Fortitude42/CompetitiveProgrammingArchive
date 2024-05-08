//template by paradox & gege & parasat
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
const int N = (1 << 20), inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, k, f[M], ans[M], F[M][3], b[M];

int get(int x) {
	int res = 0;
	while (!(x & 1)) {
		res++;
		x >>= 1;
	}

	return res;
}

void precalc() {
	f[0] = 0;
	for (int i = 1; i < M; ++i)
		f[i] = f[i - 1] + get(i);
}

int cnk(int n, int k) {
	return (f[n] == f[k] + f[n - k]);
}

int s(int nn, int kk) {
	int j = k - kk;
	if (F[nn][j] != -1)
		return F[nn][j];

	F[nn][j] = 0;
	for (int k1 = kk; k1 <= nn; ++k1)
		F[nn][j] ^= cnk(nn, k1);

	return F[nn][j];
}
 
void solve() {
	memset(F, -1, sizeof(F));
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	

	for (int i = 1; i <= n; ++i) {
		int j = i, sum = 0;

		while (1) {
			if (sum > 20 || b[i] >= (1 << (20 - sum)))
				break;

			int nn = (n - 1) - (j - i);
			int kk = k;
			if (i > 1) {
				nn--;
				kk = max(0, kk - 1);
			}
			
			if (j < n) {
				nn--;
				kk = max(0, kk - 1);
			}

			
			if (nn >= kk) {
				ans[(1 << sum)*b[i]] ^= s(nn, kk); 
			}
			
			if (j == n)
				break;

			j++;
			sum += b[j];
		}
	}

	int j = M - 1;
	while (!ans[j] && j > 0)
		j--;

	for (int i = j; i >= 0; --i)
		cout << ans[i];
}

main () {
	precalc();
	int TT = 1;
	fastio
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}