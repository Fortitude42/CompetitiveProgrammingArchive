#include "combo.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

string guess_sequence(int n) {
	string s = "";
	if (press("AB")) {       	
		if (press("A"))
			s += 'A';
		else
			s += 'B';
	} else {
		if (press("X"))
			s += 'X';
		else
			s += 'Y';
	}

	if (n == 1)
		return s;

	string ss = "";
	if (s[0] != 'A')
		ss += 'A';

	if (s[0] != 'B')
		ss += 'B';

	if (s[0] != 'X')
		ss += 'X';

	if (s[0] != 'Y')
		ss += 'Y';

	while (sz(s) < n - 1) {
		string p = s + ss[0] + s + ss[1] + ss[0] + s + ss[1] + ss[1] + s + ss[1] + ss[2];
		int cur = press(p);
		if (cur == sz(s))
			s += ss[2];
		else if (cur == sz(s) + 1)
			s += ss[0];
		else
			s += ss[1];
	}
	
	for (int i = 0; i < 2; ++i) {
		string p = s + ss[i];
		if (press(p) == n)
			return p;
	}   

	s += ss[2];
	return s;
}
