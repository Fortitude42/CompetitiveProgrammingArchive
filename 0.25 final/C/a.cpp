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


int n, cnt;

bool in (int x) {
	return x > 0 && x <= n;
} 

int ask (int i, int j) { 
	if (!in(i) || !in(j) || i > j)
		return 0;

	--cnt;
	cout << i << ' ' << j << endl;

	string s;
	cin >> s;
	if (s == "WIN")
		exit(0);

	if (s == "SWAPPED")
		return 1;

	return 0;
}

void Ask (int i) {
	if (i >= n)
		return;

	for (int j = i + 1; j <= n; ++j) {
		if (!cnt)
			return;
		ask(i, j);
	}

	if (cnt)
		Ask(i + 1);	
}

main () {
	cin >> n;
	cnt = 2*n;
	Ask(1);

	for (int i = 2; i <= n; ++i) {
		cnt = 2*n;
		int x = -1;
		for (int j = 2; j <= i; ++j) {
			int jj = ask(j - 1, j);
			if (jj) {
				x = j;
				break;
			}
		}

		if (x == -1) {
			Ask(i);
			continue;
		}

		int y = -1;
		
		for (int j = i; j > max(1, x - 2); --j) {
			int jj = ask(j - 1, j);
			if (jj) {
				y = j - 1;
				break;
			}
		}

		if (y == -1 || x == y) {
		    for (int j = i + 1; j <= n; ++j)
				ask(x, j);
			ask(x - 1, x);
			Ask(i + 1);
			continue;
		}


		ask(x, y);	
		ask(x - 1, x);
		ask(y, y + 1);
		Ask(i + 1);
	}
}