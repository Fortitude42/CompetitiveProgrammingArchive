//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
#define int long long
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

int t, k; 

const ll P[] = {2,3,5,7,11,13,17,67,24251};
ll mul(ll A , ll B , ll P){ll C = A * B - (ll)((double)A * B / P + 0.1) * P; return C < 0 ? C + P : C;}
ll poww(ll a , ll b , ll p){ll tms = 1; while(b){if(b & 1) tms = mul(tms , a , p); a = mul(a , a , p); b >>= 1;} return tms;}

bool MR (ll x){
	if (x <= 1)
		return 0;

	for(ll i = 0 ; i < 9 ; ++i) if(x == P[i]) return 1; else if(x % P[i] == 0) return 0;
	ll cnt = x - 1 , num = 0; while(cnt % 2 == 0){++num; cnt >>= 1;}
	for(ll i = 0 ; i < 9 ; ++i){
		ll val = poww(P[i] , cnt , x); if(val == 1) continue;
		for(ll j = 0 ; j < num && val != x - 1 ; ++j) val = mul(val , val , x);
		if(val != x - 1) return 0;
	}
	return 1;
}


int Pow(int a, int n) {
	int res = 1;
	while (n--) {
		if (res > INF / a)
			return INF;
		res *= a;		
	}
	return res;
}

int revp(ll n, int m) {
	if ((1ll << m) > n)
		return -1;

	int l = 1, r = sqrtl(n);
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (Pow(mid, m) <= n)
			l = mid + 1;
		else
			r = mid - 1;
	}

	if (Pow(l - 1, m) == n)
		return l - 1;
	return -1;
}

void solve() {
	cin >> k;
	vi vals;
	for (int x = 1; x*x <= k; ++x) {
		if (k % x)
			continue;
		vals.pb(x - 1);
		vals.pb(x + 1);
		vals.pb(2*x + 1);
		vals.pb(2*x - 1);
		vals.pb(k/x - 1);
		vals.pb(k/x + 1);
		vals.pb(2*(k/x) + 1);
		vals.pb(2*(k/x) - 1);
	}
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
		
	int ans = 0;
	for (auto n : vals) {
		if (n <= 1)
			continue;

		ll pm = (n - 1) * 1ll * (n + 1);
		if (pm % k)	
			continue;

		pm /= k;
		if (MR(pm)) {
			++ans; 
			continue;
		}

		for (int m = 2; m <= 31; ++m) {
			int p = revp(pm, m);
			if (p != -1 && MR(p)) {
				++ans;
				break;
			}				
		}
	}

	cout << ans << endl;
}

main () {

	int TT;
	cin >> TT;
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

