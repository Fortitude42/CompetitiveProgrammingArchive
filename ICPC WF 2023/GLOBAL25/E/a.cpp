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

string s;
vector < string > ans;

bool solve(string s) {
	if (!sz(s))
		return 1;


	vector < pair < char, int > > v;
	vector < string > vv;
	for (int i = 0; i < sz(s);){
		int j = i, cnt = 0;
		string cur;
		while (j < sz(s) && s[i] == s[j]) {
		    cur += s[j];
			++j, ++cnt;
		}

		v.pb({s[i], cnt});
		vv.pb(cur);
		i = j;
	}

	if (!(sz(v) & 1)) {
		for (int i = 0; i < sz(v); i += 2) {
			string cur = vv[i] + vv[i + 1];
			ans.pb(cur);
		}

		return 1;
	}


	if (sz(v) == 1)
		return 0;

	for (int i = 0; i + 2 < sz(v); ++i) {
		if (v[i] != v[i + 2]) {
			string pref;
			string suff;
			string cur;

			int l = i;
			int r = i + 3;

			if (l & 1) 
				l--;
			if ((sz(v) - r) & 1)
				r++;
			

			for (int j = 0; j < l; ++j)
				pref += vv[j];

			for (int j = l; j < r; ++j)
				cur += vv[j];

			for (int j = r; j < sz(v); ++j)
				suff += vv[j];

			solve(pref);
			ans.pb(cur);
			solve(suff);
			return 1;
		}
	}
	if (v[1].s > 1) {
		string pref0, pref1;
		string suff;

		pref0 = vv[0];
		for (int j = 0; j < sz(vv[1]); ++j) {
			if (!j)
				pref0 += vv[1][j];
			else
				pref1 += vv[1][j];
		}
		pref1 += vv[2];

		for (int j = 3; j < sz(vv); ++j)
			suff += vv[j];
		ans.pb(pref0);
		ans.pb(pref1);
		solve(suff);
		return 1;
	}

	if (sz(v) == 3 || v[0].s == 1)
		return 0;
	
	string pref0, pref1, suff;
	pref0 = vv[0] + vv[1];
	for (int j = 0; j < sz(vv[2]); ++j) {
		if (!j)	
			pref0 += vv[2][j];
		else
			pref1 += vv[2][j];				
	}

	pref1 += vv[3];
	pref1 += vv[4];
	for (int j = 5; j < sz(vv); ++j)
		suff += vv[j];

	ans.pb(pref0);
	ans.pb(pref1);
	solve(suff);
	return 1;
}
 
void solve() {
	ans.clear();

	cin >> s;
	if (!solve(s)) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	cout << sz(ans) << "\n";
	for (auto x : ans)
		cout << x << " ";			
	cout << "\n";

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