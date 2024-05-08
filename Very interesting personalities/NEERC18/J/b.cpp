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

int n, m, a[40];
set < string > q;
vector < string > v, twl;
map < string, string > L;
 
bool isWord(const string &s) {
	if (isdigit(s[0]))
		return 0;

	for (auto x : s)
		if (!isdigit(x) && x != '$' && x != '_' && (x < 'a' || x > 'z') && (x < 'A' || x > 'Z'))
			return 0;

	return 1;
}

bool isDigit(const string &s) {
	for (auto x : s)
		if (!isdigit(x))
			return 0;

	return 1;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		q.insert(s);
	}
	
	cin >> m;

	string s;
	getline(cin, s);
	while (m--) {
		getline(cin, s);
		int j = sz(s);
		for (int i = 0; i < sz(s); ++i)
			if (s[i] == '#') {
				j = i;	 
				break;
			}

		while (sz(s) > j)
			s.ppb();

		int l = 0;
		while (l < sz(s)) {
			if (s[l] == ' ') {
			    l++;
				continue; 
			}


			int x = -1;
			for (int r = l; r < sz(s); ++r) {
			    string cur = s.substr(l, r - l + 1);
				if (isWord(cur) || q.count(cur) || isDigit(cur)) 
					x = r;
			}

			if (x == -1) {
			    cout << s[l] << endl;
				exit(0); 
			}
			
			v.pb(s.substr(l, x - l + 1));
			l = x + 1;
		}
	}



	for (int len = 1; sz(twl) < 2000; ++len) {
		memset(a, 0, sizeof(a));
		while (sz(twl) < 2000) {
			if (a[0] > 0)
				break;

			string cur = "";
			for (int x = 1; x <= len; ++x)
				cur += (char)(a[x] + 'a');

			if (!q.count(cur))
				twl.pb(cur);
			
			++a[len];
			int j = len;			
			while (a[j] == 26) {
				a[j] = 0;
				j--;
				a[j]++;
			}				

		}
	}

	string res = "";
	vector < string > lst;
	int k = 0;

	for (auto s : v) {
		string t = s;
		if (!q.count(s) && !isDigit(s)) { 
			if (!L.count(s))
				L[s] = twl[k++];
			t = L[s];		
		}

		bool bad = 0;

		if (sz(lst)) {
			string cur = lst.back() + t[0];
			if (isDigit(cur) || isWord(cur))
				bad = 1;
		}

		for (int i = sz(lst) - 1; i >= 0 && !bad; --i) {
			string cur = "";
			for (int j = i; j < sz(lst); ++j) {
				cur += lst[j]; 
			    if (sz(cur) > 20)
			        break;
			}
			
			if (sz(cur) > 20)
				break;

			for (int j = 0; j < sz(t) && sz(cur) <= 20; ++j) {
				cur += t[j];
				if (q.count(cur)) {
					bad = 1; 
					break;
				}
			}
		}
		

		if (bad) {
			res += " ";
			lst.clear();
		}

		res += t;
		lst.pb(t);
	}

	cout << res << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

