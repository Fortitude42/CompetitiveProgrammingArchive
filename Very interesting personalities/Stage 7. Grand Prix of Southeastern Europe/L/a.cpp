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

ll l, r, b[60];

//https://codeforces.com/group/OxWQShaH6g/contest/103439/submission/137286543
const ll P[] = {2,3,5,7,11,13,17,67,24251};
ll mul(ll A , ll B , ll P){ll C = A * B - (ll)((double)A * B / P + 0.1) * P; return C < 0 ? C + P : C;}
ll poww(ll a , ll b , ll p){ll tms = 1; while(b){if(b & 1) tms = mul(tms , a , p); a = mul(a , a , p); b >>= 1;} return tms;}

bool MR (ll x){
	for(ll i = 0 ; i < 9 ; ++i) if(x == P[i]) return 1; else if(x % P[i] == 0) return 0;
	ll cnt = x - 1 , num = 0; while(cnt % 2 == 0){++num; cnt >>= 1;}
	for(ll i = 0 ; i < 9 ; ++i){
		ll val = poww(P[i] , cnt , x); if(val == 1) continue;
		for(ll j = 0 ; j < num && val != x - 1 ; ++j) val = mul(val , val , x);
		if(val != x - 1) return 0;
	}
	return 1;
}


void add(ll x) {
	for  (int i = 59; i >= 0; --i) {
		if ((x >> i) & 1) {
			if (!b[i]) {
				b[i] = x;
				break;
			}
			x ^= b[i];
		}
	}
}

int p(ll x) {
	int cnt = 0;
	while (!(x & 1)) {
		cnt++;
		x >>= 1;
	}

	return cnt;
}

void upd(ll l, int i) {
	ll r = l + (1ll << i) - 1;
	if (r - l <= 4096) {
		for (ll x = l; x <= r; ++x)
			if (MR(x)) {
				add(x);
			}
		return;
	}

	for (int j = 1; j < i; ++j)
		add((1ll << j));

	add(l + 1);	
}

void solve() {
	memset(b, 0, sizeof(b));
	scanf("%lld%lld", &l, &r);
	do {
		for (int i = 59; i >= 0; --i)
			if (!(l % (1ll << i)) && l + (1ll << i) - 1 <= r) {
				upd(l, i);
				l += (1ll << i);
				break;
			}
//		cerr << l << ' ' << r << endl;
	} while (l <= r);
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
		ll ans = 1;
		for (int i = 0; i < 60; ++i)
			if (b[i])
				ans += ans;

		printf("%lld\n", ans);
	}
}

