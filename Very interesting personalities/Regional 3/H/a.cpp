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


int n;
    
string st[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int xx[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string getRoman(int val){
	string res;
	for(int i = 0; i < 13; i++){
		while(val - xx[i] >= 0){
			val -= xx[i];
			res += st[i];
		}	
	}
	return res;
}

bool is_pal(string s){
	string t = s;
	reverse(all(t));
	return (t == s);
}

map<string, bool> ok;

void precalc(){
	for(int i = 1; i < 4000; i++){
		string s = getRoman(i);
		if(is_pal(s))         
			ok[s] = 1;
	}
}

int dp[M], p[M];
char c[M];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	
	for(int i = 1; i <= n; i++){
		dp[i] = inf;
		string cur;
		for(int j = i; j >= max(1, i - 4); j--){
			cur = c[j] + cur;
			if(ok.count(cur)){
				if(dp[i] > dp[j - 1] + 1){
					dp[i] = dp[j - 1] + 1;
					p[i] = j;
				}
			}
		}
	}

	cout << dp[n] << "\n";
	vector<string> path;
	int cur = n;
	while(cur >= 1){
		int go = p[cur];
		string s;
		for(int i = go; i <= cur; i++)
			s += c[i];
		path.pb(s);
		cur = go - 1;	
	}
	
	assert(sz(path) == dp[n]);
	reverse(all(path));
	for(auto x : path)
		cout << x << "\n";

}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	precalc();

	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

