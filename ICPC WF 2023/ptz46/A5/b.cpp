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
 
const int maxn = sqrtl(5e10) + 12;
const int B = 5e7;

bool used[maxn], bad[B + 11];
ll val[B + 11];
vector < ll > pr;



void precalc() {
	for (int i = 2; i < maxn; ++i)
		if (!used[i]) {
			pr.pb(i);
			for (int j = i; j < maxn; j += i)
				used[j] = 1;
		}
}

__int128 solve(ll l, ll r) {
	memset(bad, 0, sizeof bad);
	memset(val, 0, sizeof val);
	for (auto &p : pr) {
		ll l1 = ((l + p - 1) / p) * p;
		while (l1 <= r) {
			if (!val[l1 - l])
				val[l1 - l] = p;
			l1 += p;
		}

		l1 = ((l + p*p - 1) / (p*p))*p*p;
		while (l1 <= r) {
			bad[l1 - l] = 1;
			l1 += p*p;
		}
	}
	__int128 ans = 0;
	for (ll i = l; i <= r; ++i)
		if (bad[i - l])
			ans++;
		else if (!val[i - l])
			ans += i;
		else
			ans += val[i - l];

	return ans;
}
const ll INF = 5e10;

inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

 
main () {
	cout << fixed << setprecision(1);
	precalc();
	__int128 sum = 0;
	for (ll i = 1; i <= 1000; ++i) {
		sum += solve(max(2ll, (i - 1)*B + 1), i*B);
		print(sum);    putchar(','); putchar(' ');
		cerr << i << "/" << 1000 << endl;
	}
}