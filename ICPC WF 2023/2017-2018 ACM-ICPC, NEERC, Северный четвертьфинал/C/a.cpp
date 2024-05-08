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

int cnt[30][30];
string s, cons;
set < char > vowels = {'a', 'e', 'i', 'o', 'u', 'w', 'y'};
 
void solve() {
	file("consonant");
	for (char c = 'a'; c <= 'z'; ++c)
		if (!vowels.count(c))
			cons += c;

	cin >> s;
	for (int i = 0; i + 1 < sz(s); ++i) {
		if (vowels.count(s[i]) || vowels.count(s[i + 1]))
			continue;
		
		++cnt[s[i] - 'a'][s[i + 1] - 'a'];
		++cnt[s[i + 1] - 'a'][s[i] - 'a'];
	}

	int m = sz(cons);
	pii ans = mp(0, 0);

	for (int mask = 0; mask < (1 << m); ++mask) {
		int sum = 0;
		for (int i = 0; i < m; ++i)
			for (int j = i + 1; j < m; ++j) {
				int biti = (mask >> i) & 1;
				int bitj = (mask >> j) & 1;
				if (biti != bitj)
					sum += cnt[cons[i] - 'a'][cons[j] - 'a'];				
			}

		ans = max(ans, mp(sum, -mask));
	}

	int mask = -ans.s;
	for (int i = 0; i < sz(s); ++i) {		
		for (int j = 0; j < sz(cons); ++j)
			if (s[i] == cons[j] && (mask >> j) & 1) {
				s[i] = s[i] - 'a' + 'A';
			}		
	}

	cout << s << endl;
}

main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}