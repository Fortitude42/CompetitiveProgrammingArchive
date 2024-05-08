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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

 
void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	if (x < 0)
		x += MOD;
}

struct Matrix {
	int a[6][6];

	Matrix(){
		memset(a, 0, sizeof(a));
	}

	Matrix operator * (const Matrix &x) const {
		Matrix res;
		for (int i = 0; i < 6; ++i)
			for (int j = 0; j < 6; ++j)
				for (int k = 0; k < 6; ++k)
					add(res.a[i][j], a[i][k] * 1ll * x.a[k][j] % MOD);
		return res;
	}
};

Matrix binpow(Matrix a, ll n) {
	Matrix res;
	for (int i = 0; i < 6; ++i)
		res.a[i][i] = 1;

	while (n) {
		if (n & 1)
			res = res * a;
		n >>= 1;	
		a = a * a;
	}

	return res;
}

ll n;

void solve() {
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	Matrix a;
	a.a[0][0] = 1;
	
	Matrix b;
	b.a[0][0] = 1;
	b.a[2][0] = 1;
	b.a[4][0] = 1;

	b.a[1][1] = 1;
	b.a[2][1] = 1;
	b.a[3][1] = 3;
	b.a[5][1] = 1;

	b.a[0][2] = 1;
	b.a[1][3] = 1;
	b.a[2][4] = 1;
	b.a[3][5] = 1;
	
	Matrix c = a * binpow(b, n);
	cout << (0ll + c.a[0][0] + c.a[0][1] + c.a[0][2] + 2ll*c.a[0][3]) % MOD;
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}