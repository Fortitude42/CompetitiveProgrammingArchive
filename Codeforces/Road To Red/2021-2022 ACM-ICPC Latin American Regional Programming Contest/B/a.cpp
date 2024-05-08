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

using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;
 
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
 
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
 
vector<ll> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
 


 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n, f[M], c[M], fn, fp, cn, cp;
vector < ll > mm;
ll mx[M], mn[M];


void calculateMax() {
	int fnn = 1, fpp = 0, cnn = 1, cpp = 0, k = 1;
	while (1) {
		int cur = -1;
		bool flag = 0;

		if (fnn <= fn && cnn <= cn)
			cur = f[fnn] * c[cnn];
		if (fp + fpp <= n && cp + cpp <= n && cur < f[n - fpp] * c[n - cpp]) {
			cur = f[n - fpp] * c[n - cpp];
			flag = 1;
		}

		if (cur == -1)
			break;
		
		mx[k] = mx[k - 1] + cur;
		++k;
		if (!flag) {
			fnn++;
			cnn++;
		} else {
			fpp++;
			cpp++;
		}
	}

	vector < int > ff, cc;
	for (int i = 1; i <= n; ++i) {
		if ((i >= fnn && i <= fn) || (i >= fp && i <= n - fpp))
			ff.pb(f[i]);
	    if ((i >= cnn && i <= cn) || (i >= cp && i <= n - cpp))
	    	cc.pb(c[i]);
	}

	if (sz(ff) && ff[0] < 0)
		reverse(all(ff));
	else {
	    assert(!sz(cc) || cc[0] < 0);
		reverse(all(cc)); 
	}

	mm = multiply(ff, cc);	
	for (int i = 0; i < sz(ff); ++i)
		mx[i + k] = mx[k - 1] + mm[i];
	if (!(!sz(ff) || ff[0] * cc[0] != -1 || mm[0] == -1)) {
		for (int i = 0; i < sz(ff); ++i)
			mx[i + k]++;
	}
}

void calculateMin() {
	int fnn = 1, fpp = 0, cnn = 1, cpp = 0, k = 1;
	while (1) {
		int cur = 1;
		bool flag = 0;

		if (fnn <= fn && cp + cpp <= n)
			cur = f[fnn] * c[n - cpp];

		if (fp + fpp <= n && cnn <= cn && cur > f[n - fpp] * c[cnn])	{
			cur = f[n - fpp] * c[cnn];
			flag = 1;
		}

		if (cur == 1)
			break;
		
		mn[k] = mn[k - 1] + cur;
		++k;
		if (!flag) {
			fnn++;
			cpp++;
		} else {
			fpp++;
			cnn++;
		}
	}

	vector < int > ff, cc;
	for (int i = 1; i <= n; ++i) {
		if ((i >= fnn && i <= fn) || (i >= fp && i <= n - fpp))
			ff.pb(f[i]);
	    if ((i >= cnn && i <= cn) || (i >= cp && i <= n - cpp))
	    	cc.pb(c[i]);
	}
	if (sz(ff) && ff[0] < 0) {
		reverse(all(ff));
		reverse(all(cc));
	}

	mm = multiply(ff, cc);
	for (int i = 0; i < sz(ff); ++i)
		mn[i + k] = mn[k - 1] + mm[i]; 
	
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &f[i]);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);

	sort(c + 1, c + 1 + n);
	sort(f + 1, f + 1 + n);

	f[n + 1] = c[n + 1] = 1;
	for (int i = 1; i <= n + 1; ++i)
		if (f[i] > 0) {
			fn = i - 1;
			fp = i;
			break;
		}

	for (int i = 1; i <= n + 1; ++i)
		if (c[i] > 0) {
			cn = i - 1;
			cp = i;
			break;
		}

	calculateMax();
	calculateMin();

	for (int i = 1; i <= n; ++i)
		printf("%lld %lld\n", mn[i], mx[i]);
}

main () {
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}