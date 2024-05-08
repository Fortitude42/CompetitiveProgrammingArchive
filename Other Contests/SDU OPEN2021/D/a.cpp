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
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 25;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int t;

bool add(int x) {
	cout << "+ " << x << endl;
	string res;
	cin >> res;
	return (res == "YES");
}

bool del(int x) {
	cout << "- " << x << endl;
	string res;
	cin >> res;
	return (res == "YES");
}


void ans(int x) {
	cout << "! " << x << endl;
	string res;
	cin >> res;

	if (res == "Incorrect")
		exit(0);
}

main () {
	cin >> t;
	while (t--) {
		int res = -1;
		for (int x = 1; x <= block; ++x) 
			if (add(x)) {
				res = x - 1; 
				break;
			}		

		if (res != -1) {
			ans(res);    
			continue;
		}

		int l = -1;

		for (int x = block*2; x <= 500 + block; x += block)
			if (add(x)){
				l = x;   
				break;
			}

			
		for (int x = 1; x <= block; ++x) 
			if (!del(x)) {
				res = l - x;
				break;
			}
		
		ans(res);	
	}
}