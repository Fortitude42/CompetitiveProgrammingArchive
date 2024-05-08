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

int n, a[M];
pii par[M][2];



bool is_inc(vi a) {
	for (int i = 1; i < sz(a); ++i)
		if (a[i] < a[i - 1])
			return 0;

	return 1;
} 

bool is_dec(vi a) {
	reverse(all(a));
	return is_inc(a);
}


void chck(vi a1, vi a2) {
	if ((is_inc(a1) || is_dec(a1)) && (is_inc(a2) || is_dec(a2))) {
		cout << sz(a1) << ' ' << sz(a2) << endl;
		for (auto x : a1)
			cout << x << ' ';
		cout << endl;
		for (auto x : a2)
			cout << x << ' ';
		exit(0);
	}
}


void solve1() {
	int dec = inf, inc = -inf;
	//a[1], dec
	//inc, a[1]

	for (int i = 2; i <= n; ++i) {
		int ndec = -inf, ninc = inf;
		if (a[i] < a[i - 1]) {
			ninc = inc;//inc, a[i - 1] -> inc, a[i]
			par[i][1] = mp(inc, a[i - 1]);
		} else {
			ndec = dec;//a[i - 1], dec -> a[i], dec
			par[i][0] = mp(a[i - 1], dec);
		}

		if (dec > a[i] && a[i - 1] < ninc) {
			ninc = a[i - 1];//a[i - 1], dec -> a[i - 1], a[i]
			par[i][1] = mp(a[i - 1], dec);
		}

		if (inc < a[i] && a[i - 1] > ndec)  {
			ndec = a[i - 1];//inc, a[i - 1] -> a[i], a[i - 1]
			par[i][0] = mp(inc, a[i - 1]);
		}

		dec = ndec;
		inc = ninc;
	}

	if (inc == inf && dec == -inf){
		return;
	}

	pii x;
	if (inc < inf)
		x = mp(inc, a[n]);
	else
		x = mp(a[n], dec);
	vi is, ds;
	for (int i = n; i >= 1; --i) {
		if (x.f == a[i]) {
			if(!is.empty() && is.back() < a[i]) assert(0);
			is.pb(a[i]);
			x = par[i][0];
		} else {
			assert(x.s == a[i]);
			if(!ds.empty() && ds.back() > a[i]) assert(0);
			ds.pb(a[i]);
			x = par[i][1];
		}
	}   	

	reverse(all(is));
	reverse(all(ds));
	if (!sz(is)) {
		is.pb(ds.back());
		ds.ppb();
	}

	if (!sz(ds)) {
		ds.pb(is.back());
		is.ppb();
	}
	cout << sz(is) << ' ' << sz(ds) << endl;
	for (auto x : is)
		cout << x << ' ';
	cout << endl;
	for (auto x : ds)
		cout << x << ' ';
	exit(0);
}


void solve3() {
	vi a1, a2;
	for (int i = 1; i <= n; ++i) {
		if (!sz(a2) || a2.back() < a[i])
			a2.pb(a[i]);
		else
			a1.pb(a[i]);

		if (sz(a1) && a2.back() < a1.back())
			swap(a1, a2);
	}

	chck(a1, a2);
}

void solve4() {
	vi a1, a2;
	for (int i = 1; i <= n; ++i) {
		if (!sz(a2) || a2.back() > a[i])
			a2.pb(a[i]);
		else
			a1.pb(a[i]);

		if (sz(a1) && a2.back() > a1.back())
			swap(a1, a2);
	}

	chck(a1, a2);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	solve1();

	solve3();         	
	solve4();
	cout << "Fail";
}

main () {
  	int TT;
  	TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}