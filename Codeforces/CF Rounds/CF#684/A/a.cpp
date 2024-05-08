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
 
 
vector < pii > ans;
int t, n, m;
string s[N];
 
int in (int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
 
void Ans (vpii V) {
	for (auto x : V) {
		ans.pb(x);    
		s[x.f][x.s] = '1' + '0' - s[x.f][x.s];
	}	
}
 
void upd (int x, int y) {
	for (int ii = -1; ii <= 0; ++ii)
		for (int jj = -1; jj <= 0; ++jj)
			if (in(x + ii, y + jj) && in(x + ii + 1, y + jj + 1)) {
				vpii pos, pos1, cur;
				for (int xx = x + ii; xx <= x + ii + 1; ++xx)
					for (int yy = y + jj; yy <= y + jj + 1; ++yy)
						if (x == xx && y == yy)
							pos.pb({xx, yy});
						else
							pos1.pb({xx, yy});
				
				for (int j = 0; j < 3; ++j) {
					cur.pb(pos[0]);
					for (int i = 0; i < 3; ++i)
						if (i != j)
							cur.pb(pos1[i]);
					Ans(cur);
					cur.clear();
				}
 
				return;
			}
}
 
 
main () {
	srand(time(0));
	cin >> t;
	while (t--) {
		ans.clear();
 
		cin >> n >> m;
		for (int i = 0; i < n; ++i) 
			cin >> s[i];

 		for (int i = 0; i < n; ++i)
 			for (int j = 0; j < m; ++j) {
 				if (i >= n - 2 && j >= m - 2)
 					continue;

				if (s[i][j] == '0')
					continue;
				
				if (i == n - 1) {
					if (s[i][j + 1] == '1') {
						Ans({mp(i, j), mp(i - 1, j), mp(i - 1, j + 1)});
						Ans({mp(i, j + 1), mp(i - 1, j), mp(i - 1, j + 1)});
					} else {
						Ans({mp(i, j), mp(i, j + 1), mp(i - 1, j + 1)});
						Ans({mp(i, j + 1), mp(i, j + 2), mp(i - 1, j + 1)});
					}						
				} else if (j == m - 1) 
					Ans({mp(i, j), mp(i + 1, j), mp(i + 1, j - 1)});
				else
					Ans({mp(i, j), mp(i + 1, j), mp(i, j + 1)});
 			}
//		for (int i = 0; i < n; ++i, cerr << endl)
//			for (int j = 0; j < m; ++j)
//				cerr << s[i][j] << ' ';
			
		vpii pos, pos1;
		for (int i = n - 2; i < n; ++i)
			for (int j = m - 2; j < m; ++j)
				if (s[i][j] == '0')
					pos.pb(mp(i, j));
				else
					pos1.pb(mp(i, j));

		if (sz(pos1) == 1)
			upd(pos1[0].f, pos1[0].s);
		
		if (sz(pos1) == 2) {
			Ans({pos1[0], pos[0], pos[1]});
			Ans({pos1[1], pos[0], pos[1]});
		}

		if (sz(pos1) == 4) {
			upd(pos1.back().f, pos1.back().s);
			pos1.ppb();
		}

		if (sz(pos1) == 3) 
			Ans({pos1[0], pos1[1], pos1[2]});
		
		cout << sz(ans) / 3 << endl;
		for (int i = 0; i < sz(ans); i += 3) {
			for (int j = 0; j < 3; ++j)
				cout << ans[i + j].f + 1 << ' ' << ans[i + j].s + 1 << ' ';
			cout << endl;
		}			
	}
}