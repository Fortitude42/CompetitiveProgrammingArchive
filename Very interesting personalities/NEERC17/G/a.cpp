//by paradox & gege & parasat
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
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
typedef tree < pair < ll, int >, null_type, less < pair < ll, int > >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 3e10;


int n, r, a[M]; 
ll b[M], c[M], k;
ordered_set q1, q2;


bool check(ll S) {
	for (int i = 2; i <= n - r + 1; ++i) {
		if (i >= r + 1)
			q1.insert(mp(b[i + r - 1] - b[i - 1], i));
		else
			q2.insert(mp(b[i - 1] - c[i - 1] + b[i + r - 1], i));		
	}

	ll cnt = 0;
	for (int x = 1; x + r - 1 <= n; ++x) {
		cnt += q1.order_of_key(mp(S - (b[x + r - 1] - b[x - 1]), inf));
		cnt += q2.order_of_key(mp(S + b[x - 1] + b[x + r - 1] - c[x + r - 1], inf));

		if (x + r + r - 1 <= n) 
			q1.erase(mp(b[x + r + r - 1] - b[x + r - 1], x + r)); 		
		
		if (x + r <= n && r > 1)
			q2.erase(mp(b[x] - c[x] + b[x + r], x + 1));

		if (x + r + r - 1 <= n && r > 1)
			q2.insert(mp(b[x + r - 1] - c[x + r - 1] + b[x + r + r - 1], x + r));
	}

	return cnt < k;
}

void solve() {          
	cin >> n >> r >> k;
	ll suma = 0;

	for (int i = 1; i <= n; ++i) { 
		cin >> a[i]; 
		suma += a[i];
	}


	for (int i = 1; i <= n; ++i) {
		cin >> b[i]; 
		b[i] -= a[i];                  
		b[i] += b[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		cin >> c[i]; 
		c[i] -= a[i];
		c[i] += c[i - 1];
	}


	ll l = 0, r = INF;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << l + suma << endl;
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

