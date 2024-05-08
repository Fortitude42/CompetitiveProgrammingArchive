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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int K = 1200;

int n, q, d[M], up[2][M][18];
string s;
vi neq;



vector < vi > manacher(const string& s) {
	int n = sz(s);
	vector<vi> p = {vi(n+1), vi(n)};
	for (int z = 0; z < 2; ++z)
		for (int i=0,l=0,r=0; i < n; i++) {
			int t = r-i+!z;
			if (i<r) 
				p[z][i] = min(t, p[z][l+t]);
			
			int L = i-p[z][i], R = i+p[z][i]-!z;
			while (L>=1 && R+1<n && s[L-1] == s[R+1])
				p[z][i]++, L--, R++;

			if (R>r) 
				l=L, r=R;
		}

	return p;
}

vector < vi > m;


int get(int l, int r, int x) {
	int D = d[r - l + 1];
	return min(up[x][l][D], up[x][r - (1 << D) + 1][D]);
}

void build() {
	for (int x = 0; x < 2; ++x) {
		for (int i = 0; i < sz(m[x]); ++i)
			up[x][i][0] = m[x][i];

		for (int j = 1; j < 18; ++j)
			for (int i = 0; i + (1 << j) - 1 < sz(m[x]); ++i)
				up[x][i][j] = min(up[x][i][j - 1], up[x][i + (1 << (j - 1))][j - 1]);
	}
}

ll get(int x) {
	return x * 1ll * (x + 1) / 2;
}

bool eq(int l, int r) {
	int j = lower_bound(all(neq), l) - neq.begin();	
	if (j < sz(neq) && neq[j] < r)
		return 0;
	return 1;
}
 
void solve() {
	neq.clear();

	cin >> n >> q;
	cin >> s;
	m = manacher(s);
	build();

	for (int i = 0; i + 1 < n; ++i)
		if (s[i] != s[i + 1])
			neq.pb(i);



	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;

		if (eq(l, r)) {
			cout << 0 << "\n";
			continue;
		}

		ll ans = get(r - l + 1);
		
		int rg = (r - l) / 2;
		for (int mid = rg; mid >= max(0, rg - K); --mid) {
			int mn = get(l + mid, r - mid, 1);
			if (mn >= mid)
				ans -= 2*mid + 1;
		}

		rg = (r - l + 1) / 2;

		for (int mid = rg; mid >= max(1, rg - K); --mid) {
			int mn = get(l + mid, r - mid + 1, 0);
			if (mn >= mid)						
				ans -= 2*mid;
		}
//		assert(ans > 0);
		cout << ans << "\n";
	}


}

main () {
	for (int i = 2; i < M; ++i)
		d[i] = d[i >> 1] + 1;

  int TT;
  TT = 1;
  	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}