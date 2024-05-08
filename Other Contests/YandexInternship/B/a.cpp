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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 112;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

int n, m, num;
string s[N], side, position;
 
bool check (int i, int j) {
	if (s[i][j] != '.')
		return 0;

	if (side == "left")	
		return j < 3;
	return j > 3;
}

bool check1 (int j) {
	if (position == "aisle")
		return (j == 2 || j == 4);
	return (j == 0 || j == 6);
}

string toString (int x) {
	string res = "";
	while (x) {
		res += x % 10 + '0';
		x /= 10;
	}

	reverse(all(res));
	return res;
}

main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> s[i];
	
	cin >> m;
	while (m--) {
		cin >> num >> side >> position;
		vector < string > ans;
		vpii pos;

		for (int i = 1; i <= n && !sz(ans); ++i) 
			for (int j = 0; j + num - 1 < 7; ++j) {
				int ok = 0;
				vector < string > res;
				vpii pos1;
				for (int x = 0; x < num; ++x) {
					ok += check1(j + x);
					if (!check(i, j + x)) {
						ok = 0;            
						break;
					}
					res.pb(toString(i) + char(j + x - (j > 3) + 'A'));
					pos1.pb(mp(i, j + x));
				}

				if (ok) { 
					ans = res;
					pos = pos1;
					break;
				}
			}
		
		if (!sz(ans)) 
			cout << "Cannot fulfill passengers requirements" << endl;
		else {
			cout << "Passengers can take seats:";
			for (auto x : ans)
				cout << " " << x;
			cout << endl;


			for (auto x : pos) 
				s[x.f][x.s] = 'X';

			for (int i = 1; i <= n; ++i)
				cout << s[i] << endl;
			for (auto x : pos)
				s[x.f][x.s] = '#';
		}
	}
}	