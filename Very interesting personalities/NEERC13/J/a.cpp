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
const int N = 5e4, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;
pii dp[M];
string s, name[M];
map < string, int > mx;
 
bool isLetter(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void solve() {
	cin >> n;
	getline(cin, s);
	for (int i = 1; i <= n; ++i) {
		getline(cin, s);
		int j = 1;
		while (j < sz(s) && s[j] != ':')
			name[i] += s[j++];

		dp[i] = mp(1, 0);
		j++;
		int jj = j;

		while (1) {
			while (j < sz(s) && s[j] != '@')
				++j; 
			if (j == sz(s))
				break;

			if (j != jj && s[j - 1] != ' ') {
				j++;
				continue;
			}

			j++;
			
			string cur = "";
			while (j < sz(s) && s[j] != ' ') 
				cur += s[j++];
			
			if (cur != name[i] && mx.count(cur)) {
				int x = mx[cur];
				dp[i] = max(dp[i], mp(dp[x].f + 1, x));
			}
		}


		if (!mx.count(name[i]) || dp[mx[name[i]]].f < dp[i].f)
			mx[name[i]] = i; 		
	}

	int i = 1;
	for (int j = 2; j <= n; ++j)
		if (dp[j].f > dp[i].f)
			i = j;

	vi ans;
	while (i > 0) {
		ans.pb(i);
		i = dp[i].s;		
	}

	reverse(all(ans));
	cout << sz(ans) << endl;
	for (auto x : ans)
		cout << x << ' ';
		
}

main () {
	fastio
	file("join");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

