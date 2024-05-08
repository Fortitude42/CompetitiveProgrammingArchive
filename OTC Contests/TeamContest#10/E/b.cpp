#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e6 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


bool was[N];
int n, p[N], m;
char s[N], t[N];
stack < int > st;
vector < pair < vi, int > > a, b;
 
vi get1 (int l, int r) {
	int lst = 0;
	vi res;

	for (int i = l; i < r; ++i) {
		if (isdigit(s[i])) {
			lst *= 10;
			lst += s[i] - '0';
		} else if (lst) {
			res.pb(lst);
			lst = 0;
		}
	}

	if (lst)
		res.pb(lst);

	return res;
}

vector < pair < vi, int > > get () {
	for (int i = 0; i < n; ++i)
		was[i] = 0;

	vector < pair < vi, int > > res;

	for (int i = 0; i < n; ++i)
		if (s[i] == '(' || s[i] == '[') 
			st.push(i);
		else if (s[i] == ')' || s[i] == ']') {
			p[st.top()] = i;
			st.pop();
		}	


	int timer = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == ')' || s[i] == ']' || s[i] == ',')
			continue;

		if (s[i] == 'c') {
			i += 6;
			continue;
		}

		if (s[i] == '[') {
			res.pb(mp(get1(i, p[i]), 0));		
			i = p[i];
			continue;
		}

		if (s[i] == 's' && s[i + 1] == 'h') {
			i += 7;
			vi tmp = get1(i, p[i]);
			res.pb(mp(tmp, sz(tmp) > 1));
			i = p[i];
			continue;
		}

		i += 6;
		vi tmp = get1(i, p[i]);
		sort(all(tmp));
		res.pb(mp(tmp, 0));
		i = p[i];
	}   	

	return res;
}

vector < pair < vi, int > > f (vector < pair < vi, int > > a) {
	vector < pair < vi, int > > b;
	for (int i = 0; i < sz(a); ++i) {
		if (a[i].s || !sz(b) || b.back().s == 1)
			b.pb(a[i]);
		else {
			for (auto j : a[i].f)
				b.back().f.pb(j);
		}
	}

	return b;
}


main () {
	scanf("%s", s);
	n = strlen(s);
	a = get();
/*	for (auto x : a) {
		cerr << x.s << ' ';
		for (auto y : x.f)
			cerr << y << ' ';
		cerr << endl;
	}*/

	scanf("\n%s", s);
	n = strlen(s);
	b = get();
/*	for (auto x : b) {
		cerr << x.s << ' ';
		for (auto y : x.f)
			cerr << y << ' ';
		cerr << endl;
	}*/
	
	a = f(a);
	b = f(b);

	puts(a == b ? "equal" : "not equal");
}