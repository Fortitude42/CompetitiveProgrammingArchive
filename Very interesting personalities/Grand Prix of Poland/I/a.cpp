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
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 3e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n, k, a[M];

int rec1(const vi &ones, const vi &zeros, int j) {
	if (!j)
		return sz(ones) + sz(zeros);

	vi z0, z1, o0, o1;
	for (auto i : zeros)
		if (a[i] & (1 << (j - 1)))
			z1.pb(i);
		else
			z0.pb(i);

	for (auto i : ones)
		if (a[i] & (1 << (j - 1)))
			o1.pb(i);
		else
			o0.pb(i);

/*	if (j == 2 && sz(ones) && a[ones[0]] == 19) {
		for (auto i : o0)
			cerr << a[i] << ' ';
		cerr << endl;
		for (auto i : o1)
			cerr << a[i] << ' ';
		cerr << endl;	

		for (auto i : z0)
			cerr << a[i] << ' ';
		cerr << endl;
		for (auto i : z1)
			cerr << a[i] << ' ';
		cerr << endl << endl;
	}*/


	if (k & (1 << (j - 1))) {
//	    if (j == 4)
//	    	cerr << rec1(o0, z1, j - 1) << ' ' << rec1(o1, z0, j - 1) << endl;

		return max({sz(ones), sz(zeros), rec1(o0, z1, j - 1) + rec1(o1, z0, j - 1)});  
	}

	return max({sz(ones), sz(zeros), rec1(o0, z0, j - 1), rec1(o1, z1, j - 1)});
}

int rec(const vi &ind, int j) {
	if (!sz(ind))
		return 0;

	vi ones, zeros;
	for (auto i : ind)
		if ((a[i] >> j) & 1)
			ones.pb(i);
		else
			zeros.pb(i);

/*	if (j == 4) {
		for (auto i : ones)
			cerr << i << ' ';
		cerr << endl;
		for (auto i : zeros)
			cerr << i << ' ';
		cerr << endl << endl;
	}*/
	
	if ((k >> j) & 1) 
		return rec1(ones, zeros, j);

	if (!j)
		return max(sz(ones), sz(zeros));

	return max(rec(ones, j - 1), rec(zeros, j - 1));
}
 
void solve() {
	scanf("%d%d", &n, &k);

	vi st;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);        
		st.pb(i);
	}

	printf("%d\n", rec(st, 19));
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

