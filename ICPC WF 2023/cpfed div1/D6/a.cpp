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
const int N = 1e2 + 5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, x[M], y[M], p[10];


string tostring(int x) {
	if (!x)
		return "0";
	string res;
	while (x > 0) {
		res += (x % 10) + '0';
		x /= 10;		
	}
	
	reverse(all(res));
	return res;
}

string tmp[10];


string get(int x, int k) {
	string res;
	for (int j = 0; j <= k; ++j) {
		if (x & (1 << j))
			tmp[j] = "(x&" + tostring(p[j]) + ")";
		else
			tmp[j] = "((~x)&"+ tostring(p[j]) + ")";
					
		tmp[j] = "(" + tmp[j] + "*" + tostring(p[k - j]) + ")";			
	}
		
	for (int j = 0; j < k; ++j)
		res += "(";
			           
	for (int j = 0; j <= k; ++j) {
		res += tmp[j];
		if (j > 0)
			res += ")";
		if (j < k)
			res += "&";
	}

	
	return res;
}



const int K = 8;

void solve() {
	p[0] = 1;
	for (int i = 1; i < 10; ++i)
		p[i] = p[i - 1]*2;
	
	cin >> n;	
	for (int i = 1; i <= n; ++i) 
		cin >> x[i] >> y[i];		

	string ans;
	for (int k = 0; k < K; ++k) {
		map < int, int > m;
		for (int i = 1; i <= n; ++i) {
			int xx = x[i] % (1 << (k + 1));
			int yy = y[i] % (1 << (k + 1));
			assert(!m.count(xx) || m[xx] == yy);
			m[xx] = yy;
		}

		for (auto x : m) {
			if (x.s & (1 << k)) {
				if (!sz(ans))
					ans = get(x.f, k);
				else
					ans = "(" + ans + "+" + get(x.f, k) + ")";
			}
		}
	}

	if (!sz(ans))
		ans = "0";

	cout << ans << endl;
}

main () {
//	freopen(".out", "w", stdout);
	fastio
	int TT = 1;
 	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}                                  