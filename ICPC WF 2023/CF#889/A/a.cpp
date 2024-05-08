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

int n, a[30];

int get(int a, int b) {
	if (!a)
		return inf;

	int cnt = 0;
	while (a < b) {
		a += a;
		++cnt;
	}

	return cnt;
}

vector < pii > ans;
 
void solve() {
	cin >> n;
	ans.clear();
	int mxneg = 0, mxpos = 0;
	int cntneg = 0, cntpos = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < 0) {
			mxneg = max(mxneg, -a[i]);
			++cntneg;
		}

		if (a[i] > 0) {
			mxpos = max(mxpos, a[i]);
			++cntpos;
		}
	}

	int f1 = cntpos + get(mxneg, mxpos);
	int f2 = cntneg + get(mxpos, mxneg);
	if (f1 < f2) {
		int j = 1;
		for (int i = 1; i <= n; ++i) 
			if (a[i] == -mxneg)
				j = i;			
		
		while (-a[j] < mxpos) {
			ans.pb(mp(j, j));
			a[j] += a[j];
		}

		for (int i = 1; i <= n; ++i)
			if (a[i] > 0)
				ans.pb({i, j});

		for (int i = n; i > 1; --i)
			ans.pb({i - 1, i});		
	} else {
		int j = 1;
		for (int i = 1; i <= n; ++i) 
			if (a[i] == mxpos)
				j = i;			
		
		while (a[j] < mxneg) {
			ans.pb(mp(j, j));
			a[j] += a[j];
		}

		for (int i = 1; i <= n; ++i)
			if (a[i] < 0)
				ans.pb({i, j});
			
		for (int i = 1; i < n; ++i)
			ans.pb({i + 1, i});
	}


	cout << sz(ans) << endl;
	for(auto x : ans)
		cout << x.f << ' ' << x.s << endl;	
}

main () {
  int TT;
  TT = 1;
	cin >> TT;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}