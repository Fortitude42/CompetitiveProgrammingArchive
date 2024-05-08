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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 5012;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t, n;
string s; 

main () {
	fastio
	cin >> t;
	while (t--) {
		cin >> s;
		n = sz(s);
		string t = "", tt = "", c = "";
		int cnt = 0;

		while (sz(s) && s.back() == '9') {
			++cnt;
			s.ppb();
		}
		
		if (cnt) {
			string tmp = "";
			for (int i = 0; i < cnt; ++i)
				tmp += '9';

			int fst = s.back() - '0';
			if (sz(s)) {
				tmp += s.back();
				s.ppb();
			}



			if (sz(s) && ((s.back() - '0') &  1)) {
				fst += 10;
				s.back()--;
			}              
				

			if (sz(s) && ((s.back() - '0') & 1))
				fst += 10;		
			
			for (int i = 0; i < sz(tmp); ++i) {
				
			}
			
			int cur = 0;
		}

				

		n = sz(s);		
		for (int i = n - 1, carry = 0; i >= 0; --i) {
			int cur = s[i] - '0' - carry;
			if (i > 0 && ((s[i - 1] - '0') & 1)) {
				carry = 1;
				cur += 10;
			} else
				carry = 0;

			t += (cur / 2) + '0';
			tt += ((cur + 1) / 2) + '0';
			if (t.back() == tt.back()) {
				c += t.back();		    
				cerr << t.back() << endl;
			}
		}

		while (sz(c) > 1 && c.back() == '0')
			c.ppb();

		while (sz(t) > 1 && t.back() == '0')
			t.ppb();
		while (sz(tt) > 1 && tt.back() == '0')
			tt.ppb();

		reverse(all(t));
		reverse(all(tt));
		reverse(all(c));

		if (!sz(c))
			c = "-";


		cout << t << endl << tt << endl << c << endl;
	}
}