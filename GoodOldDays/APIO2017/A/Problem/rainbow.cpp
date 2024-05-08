#include "rainbow.h"
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
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 998244353, N = 2e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


int ar, ac, br, bc, ans, a[2][N], n, m;
bool was[2][N];
vi q[3];

bool in (int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs (int x, int y) {
    was[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int tox = x + dx[i], toy = y + dy[i];
		if (in(tox, toy) && !was[tox][toy] && !a[tox][toy])
			dfs(tox, toy);
	}
}
	
void init(int R, int C, int sr, int sc, int M, char *S) {
	n = R, m = C;
	--sr, --sc;
	a[sr][sc] = 1;
	for (int i = 0; i < M; ++i) {
		if (S[i] == 'N')
			--sr;
		else if (S[i] == 'S')	
			++sr;
		else if (S[i] == 'W')	
			--sc;
		else 
			++sc;	 			

		a[sr][sc] = 1;
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) 
				continue;
			q[i].pb(j);
			while (j + 1 < m && !a[i][j + 1])
				++j;
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < 2; ++i) {
			if (!was[i][j] && !a[i][j]) {
				q[2].pb(j); 
				dfs(i, j);
			}
		}
	}
}


int get (int l, int r, int i) {
	int a = upper_bound(all(q[i]), l) - q[i].begin();
	int b = upper_bound(all(q[i]), r) - q[i].begin() - 1;
	if (a > b)
		return 0;

	return b - a + 1;
}


int colour(int Ar, int Ac, int Br, int Bc) {
	--Ar, --Ac, --Br, --Bc;
	int i = 0;
	if (Ar && Br) 
		i = 1;
	else if (!Ar && Br)
		i = 2;	

	
	int ans = get(Ac, Bc, i);
	if (!a[Ar][Ac] || !a[Br][Ac])	
		++ans;
	
	
	return ans;
}

