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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



int n, a, b, c, k, o, q, qq; 
vector < pii > v;
string s;
ll cur, res;

void Z() {
	if (!o && q) {
		if (k < sz(v))
			res = max(res, cur + a);

		--q;
		++o;
		cur -= c;		
		return;
	}

	if (k < sz(v)) {
		cur += a;
		--v[k].s;
		if (!v[k].s) {
			if (!v[k].f)
				++q;
			else
				++qq;
			++k;
		}
	} else {
		cur -= c;

		if (q) {
			q--;
			o++;
			return;
		}
		if (qq) {
			qq--;
			return;
		}

		cur = -INF;
	}
}

void O() {
	if (!o) {
		cur = -INF;
		return;
	}

	o--;
	cur += b;

}


ll f(bool ok) {
	v.clear();
	q = 0;
	qq = 0;
 	o = 0;


	for (int i = 0; i < n; ) {
		int j = i, cnt = 0;

		while (j < n && s[j] == s[i]) {
			++j;
			++cnt;
		}

		if (cnt > 1 && s[i] == '0') 
			v.pb(mp((i == 0 || j == n), cnt - 1));		

		if (cnt == 1 && s[i] == '0') {
			if (i > 0 && j < n)
				++q;
			else
				++qq;
		}
		i = j;
	}

	sort(all(v));

	for (int i = 0; i < n - 1; ++i)
		if (s[i] == '1' && s[i + 1] == '1')
			++o;

	
	k = 0;
	cur = 0;
	res = 0;

	while (cur != -INF) {
		if (!ok) {
			Z();   
			res = max(res, cur);
//			cerr << cur << endl;
		}

		O();
		res = max(res, cur);
//		cerr << cur << endl;
		
		if (ok) {
			Z();
			res = max(res, cur); 
//			cerr << cur << endl;
		}
	}

	return res;
}   	

void solve() {
	cin >> n >> a >> b >> c >> s;
//	f(0);
//	f(0);
	cout << max(f(0), f(1)) << endl;
}

main () {
	fastio
	int TT;
	cin >> TT;

  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}