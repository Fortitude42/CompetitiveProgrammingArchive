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
const int M = N + 17, maxn = 5e6 + 11;
const ll INF = 1e18;


int n, m, cnt[M][30], cnt1[M][30], L[M], id[maxn], p[M];
vector < int > g[M], vals[M];
string s[M];


void clear() {
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		memset(cnt[i], 0, sizeof cnt[i]);
	}

	for (int i = 1; i <= m; ++i) {
		id[L[i]] = 0;
		L[i] = 0;
		vals[i].clear();
		memset(cnt1[i], 0, sizeof cnt1[i]);
	}
	m = 0;
}


bool cmp(int x, int y) {
	return L[x] < L[y];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		for (auto c : s[i]) {
			++cnt[i][c - 'a'];
		}
	}
	
	
	L[++m] = sz(s[1]);
	id[L[m]] = m;
	for (int j = 0; j < 30; ++j) {
		cnt1[m][j] = cnt[1][j];
		if (cnt1[m][j] > 0)
			vals[m].pb(j);
	}
	g[1].pb(L[m]);             


	
	for (int i = 2; i <= n; ++i) {
		int j = 0;
		int cur = sz(s[i]);
		while (cur > 0) {
			int x = min(cur, g[i - 1][j]);
			if (!id[x]) {
				id[x] = ++m;
				L[m] = x;

				for (int j1 = 0; j1 < 30; ++j1) {
					cnt1[m][j1] = cnt[i][j1];
					if (cnt1[m][j1] > 0)
						vals[m].pb(j1);
				}
			}

			cur -= x;
			g[i].pb(x);

		
			for (auto j1 : vals[id[x]]) {
				cnt[i][j1] -= cnt1[id[x]][j1];
				if (cnt[i][j1] < 0) {
					cout << "NO\n";
					clear();
					return;
				}
			}

			j = (j + 1) % sz(g[i - 1]);
		}

	}


	for (int i = 1; i <= m; ++i)
		p[i] = i;

	sort(p + 1, p + 1 + m, cmp);
	
	assert(L[p[m]] == sz(s[1]));
	string S;
	for (int i = m; i > 0; --i) {
		int cur = L[p[i]], prv = L[p[i - 1]];
		for (int j = 0; j < 30; ++j) {
			int delta = cnt1[id[cur]][j] - cnt1[id[prv]][j];
			if (delta < 0) {
				clear();
				cout << "NO\n";
				return;
			}

			while (delta--)
				S += (char)(j + 'a');
		}		
	}
	
	reverse(all(S));
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {/*
		for (auto j : g[i])          	
			cerr << j << " ";
		cerr << endl;*/

		for (auto j : g[i])
			cout << S.substr(0, j);
		cout << "\n";
	}

	clear();
}

main () {
  int TT;
  TT = 1;
	fastio
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}