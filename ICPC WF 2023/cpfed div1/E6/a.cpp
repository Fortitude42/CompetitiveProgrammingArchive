#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")


#define rep(i, a, b) for(int i = a; i < (b); ++i)
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
const int N = 3e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
int n = sz(a), L = 31 - __builtin_clz(n);
static vector<complex<long double>> R(2, 1);
static vector<C> rt(2, 1);
for (static int k = 2; k < n; k *= 2) {
R.resize(n); rt.resize(n);
auto x = polar(1.0L, acos(-1.0L) / k);
rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
}
vi rev(n);
rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
for (int k = 1; k < n; k *= 2)
for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
C z = rt[j+k] * a[i+j+k];
a[i + j + k] = a[i + j] - z;
a[i + j] += z;
}
}
vd conv(const vd& a, const vd& b) {
if (a.empty() || b.empty()) return {};
vd res(sz(a) + sz(b) - 1);
int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
vector<C> in(n), out(n);
copy(all(a), begin(in));
rep(i,0,sz(b)) in[i].imag(b[i]);
fft(in);
for (C& x : in) x *= x;
rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
fft(out);
rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
return res;
}



int n;
double dp[M][60], s[M][60];

void solve() {
	cin >> n;
	dp[0][0] = 1;
	s[0][0] = 1;

	for (int h = 1; h <= 60; ++h) {
		vd _dp, _s;
		for (int i = 0; i <= n; ++i) {
			_dp.pb(dp[i][h - 1]);
			_s.pb(s[i][h - 1]);
		}

		vd _dp2 = conv(_dp, _dp);
		vd _sdp = conv(_s, _dp);

		for (int i = 0; i <= n; ++i) {
			if (i > 0) {
				dp[i][h] = 2*_sdp[i - 1] - _dp2[i - 1];
				dp[i][h] /= i;
			}
			s[i][h] = s[i][h - 1] + dp[i][h];
		}
	}

		
	cout << fixed << setprecision(6);
	for (int h = 1; h <= min(59, n); ++h)
		cout << dp[n][h] << endl;
	for (int h = 60; h <= n; ++h)
		cout << 0.0 << endl;
}

main () {
	fastio
	int TT = 1;
 	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}