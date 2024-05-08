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
ll n;
int cnt[30];

int binpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % MOD;
		a = a * 1ll * a % MOD;
		n >>= 1;
	}

	return res;
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}
 
void solve() {
	cin >> s;
	cin >> n;

	int inv = 0;
	for (auto c : s) {
		for (int i = c - 'a' + 1; i < 26; ++i)
			add(inv, cnt[i]);
		++cnt[c - 'a'];		
	}

	int nn = n % MOD;
	int ans = nn*1ll*inv%MOD;
	
	int l = 0, d2 = binpow(2, MOD - 2);
	for (int i = 0; i < 26; ++i) {
		int cur = cnt[i]*1ll*l%MOD;
		cur = cur*1ll*(nn - 1)%MOD*nn%MOD;
		add(ans,cur*1ll*d2%MOD);

		l += cnt[i];
	}

	cout << ans << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}