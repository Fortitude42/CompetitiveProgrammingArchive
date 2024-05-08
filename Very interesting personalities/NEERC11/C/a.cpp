//by paradox & gege & parasat
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

int m, n, k, L, smin, smax, dp[2004][40], p[2004][40], lz[2004][50], s1[2004];
map < char, int > id;
string s, t[30][40];
string T[40];
char l[30];

int get1(int l, int r) {	
	l--;
	r--;
	return s1[r] - (!l ? 0 : s1[l - 1]);
}

int get(int l, int j) {
	if (s[j] == ' ')
		return get1(l, l + k - 1);
	if (lz[l][j] != -1)	
		return lz[l][j];
	l--;

	int jj = j;
	j = id[s[j]];	
	int res = 0;
	for (int i = 1; i <= m; ++i) {
		for (int x = 0; x < k; ++x)	
			res += (t[j][i][x] != T[i][l + x]);
	}

	return lz[l + 1][jj] = res;
}
 
void solve() {
	cin >> m >> n >> k >> smin >> smax;
	getline(cin, s);
	for (int i = 1; i <= m; ++i) {
		getline(cin, s);
		int j = 0, ind = 0;
		while (j < sz(s)) {
			if (i == 1) {
				l[ind] = s[j]; 
				id[l[ind]] = ind;
				L++;
			}
			j += 2;
			for (int x = 0; x < k; ++x)
				t[ind][i] += s[j++];
			j++;				
			ind++;
		}
	}


	getline(cin, s);
	for (int i = 0; i < sz(s); ++i) {
		int x;
		cin >> x;
		while (x--) {
			for (int j = 1; j <= m; ++j)
				T[j] += '.'; 			
		}
		if (s[i] == ' ') {
			for (int j = 1; j <= m; ++j)
				for (int x = 0; x < k; ++x)
					T[j] += '.';
		} else {
			int ind = id[s[i]];
			for (int j = 1; j <= m; ++j)
				T[j] += t[ind][j];			
		}
	}


	for (int i = 1; i <= m; ++i) {
		while (sz(T[i]) < n)
			T[i] += '.';
		for (int j = 0; j < n; ++j)
			s1[j] += (T[i][j] != '.');
	}

	for (int j = 1; j < n; ++j)
		s1[j] += s1[j - 1];
	
		
	getline(cin, s);
	getline(cin, s);
	for (int i = 0; i < 2004; ++i)
		for (int j = 0; j < 40; ++j)
			dp[i][j] = inf;


	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= sz(s); ++j)
			for (int x = 0; x <= n; ++x) {
				if (j > 1 && !(smin <= x && x <= smax))
					continue;
				if (i < k + x || dp[i - k - x][j - 1] == inf)
					continue;

				int cur = dp[i - k - x][j - 1] + get(i - k + 1, j - 1) + get1(i - k - x + 1, i - k);
				if (cur < dp[i][j]) {
					dp[i][j] = cur;
					p[i][j] = x;
				}
			}

	
	int ii = 0;
	for (int i = 1; i <= n; ++i)
		if (dp[i][sz(s)] + get1(i + 1, n) < dp[ii][sz(s)] + get1(ii + 1, n))
			ii = i;
	
	int jj = sz(s);
	vi ans;


	while (jj > 0) {
		int x = p[ii][jj];
		ans.pb(x);
		ii -= (k + x);
		jj--;
	}

   	reverse(all(ans));	
   	for (auto x : ans)
   		cout << x << ' ';
}

main () {
	fastio
	//file("caption");
	memset(lz, -1, sizeof(lz));
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
