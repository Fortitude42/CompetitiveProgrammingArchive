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
const int N = 1e5, inf = 1e9, MOD = 1e9;
const int M = N + 17;
const ll INF = 1e18;
const int K = 175;

int c[20][20], cnt, pos[20][20];

unsigned long long n;
int k;


struct Matrix {
	int a[K][K];
	Matrix(int diag=0) {
		memset(a, 0, sizeof a);
		for (int i = 0; i < K; ++i)
			a[i][i] = diag;
	}

	Matrix operator *(const Matrix m) const {
		Matrix res;
		for (int i = 0; i < K; ++i)
			for (int j = 0; j < K; ++j)
				for (int k = 0; k < K; ++k)
					res.a[i][j] = (res.a[i][j] + 0ll + a[i][k]*1ll*m.a[k][j]) % MOD;
		return res;
	}
};

Matrix binpow(Matrix a, unsigned long long n) {
	Matrix res = Matrix(1);
	while (n > 0) {
		if (n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;	
	}

	return res;
}

	 
void solve() {
	cin >> n >> k;
	for (int i = 0; i <= k; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}


	for (int i = 0; i <= k; ++i)
		for (int j = 0; i + j <= k; ++j)
			pos[i][j] = cnt++;

	Matrix a, b;
	for (int i = 0; i <= cnt; ++i)
		a.a[0][i] = 1;
	
	for (int i = 0; i <= k; ++i)
		for (int j = 0; i + j <= k; ++j) {
			int col = pos[i][j];
			for (int x = 0; x <= j; ++x)
				for (int y = 0; x + y <= j; ++y) {
					int row = pos[x][y + i];
					b.a[row][col] = c[j][x]*1ll*c[j-x][y]%MOD;
				}
		}	

	b.a[cnt][cnt] = 1;
	b.a[pos[0][k]][cnt] = 1;

	a = a * binpow(b, n);


	int res = a.a[0][cnt];
	vi ans;
	while (res > 0) {
		ans.pb(res % 10);
		res /= 10;
	}
		

	while (sz(ans) < 9)
		ans.pb(0);

	reverse(all(ans));
	for (auto x : ans)
		cout << x;			
 
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}                            