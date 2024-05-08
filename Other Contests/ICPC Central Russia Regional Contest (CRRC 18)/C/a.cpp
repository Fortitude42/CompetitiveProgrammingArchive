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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 
string s;
map < string, int > f(map < string, int > a, map < string, int > b, int c) {
	for (auto x : b) {
		if (!a.count(x.f))
			a[x.f] = 0;

		a[x.f] += x.s * c;
	}

	return a;
}

int nxt(int pos) {
	int bal = 0;
	while (1) {
		if (s[pos] == '(')
			++bal;
		if (s[pos] == ')')
			--bal;

		if (!bal)
			return pos;

		pos++;
	}
}

map < string, int > solve(int l, int r) {
	map < string, int > res;
	int sign = 1;

	while (l <= r) {
		if (s[l] == '(') {
			int x = nxt(l);
			assert(x <= r);
			map < string, int > cur = solve(l + 1, x - 1);
			res = f(res, cur, sign);
			l = x + 1;			
			continue;
		} 

		if (s[l] == '*') {
			sign = 1;     
			l++;
			continue;
		}

		if (s[l] == '/') {
			sign = -1;    
			l++;
			continue;
		}

		string cur = "";

		while (l <= r && s[l] != '*' && s[l] != '/') 
			cur += s[l++];

		if (!res.count(cur))
			res[cur] = 0;

		res[cur] += sign;
	}	

	return res;
}

bool cmp(string a, string b) {
	if (sz(a) < sz(b))
		return 1;
	if (sz(a) > sz(b))
		return 0;

	for (int i = 0; i < sz(a); ++i) {
		pii x, y;
		if (a[i] >= 'a' && a[i] <= 'z') {
			x.f = a[i] - 'a';
			x.s = 1;
		} else {
			x.f = a[i] - 'A';
			x.s = 0;
		}

		if (b[i] >= 'a' && b[i] <= 'z') {
			y.f = b[i] - 'a';
			y.s = 1;
		} else {
			y.f = b[i] - 'A';
			y.s = 0;
		}

		if (x < y)
			return 1;
		if (x > y)
			return 0;
	}

	return 1;
		
}


main () {
	cin >> s;
	for (int i = 0; i + 1 < sz(s); ++i) {
		assert(s[i] != ')' || s[i + 1] != '(');
//		cerr << i << endl;
		assert((s[i] < 'a' || s[i] > 'z') || s[i + 1] != '(');
		assert((s[i] < 'A' || s[i] > 'Z') || s[i + 1] != '(');
	}

	map < string, int > res = solve(0, sz(s) - 1);
	vector < string > a, b;
	
	for (auto x : res) {
		while (x.s > 0) {
			a.pb(x.f);
			x.s--;
		}

		while (x.s < 0) {
			b.pb(x.f);
			x.s++;
		}
	}

	sort(all(a), cmp);
	sort(all(b), cmp);


	for (int x = 0; x < sz(a); ++x) {
		cout << a[x];
		if (x < sz(a) - 1)
			cout << "*";
	}
	cout << endl;

	for (int x = 0; x < sz(b); ++x) {
		cout << b[x];
		if (x < sz(b) - 1)
			cout << "*";
	}
}