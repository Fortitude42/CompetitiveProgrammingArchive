//template by paradox & gege & parasat
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
const ll INF = 1e11;

const int K = 57;

ll s[M], f[M];

void precalc() {
	f[0] = f[1] = 1;
	s[0] = 1;
	s[1] = 2;

	for (int i = 2; i <= K; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		s[i] = s[i - 1] + f[i];
	}
}

int n, c[M];
 
void solve() {
	cin >> n;
	ll sum = 0;
	set < pii > q;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i]; 
		q.insert(mp(c[i], i));
		sum += c[i];
	}

	int k = -1;
	for (int i = 0; i <= K; ++i)
		if (s[i] == sum) {
			k = i;
			break;
		}

	if (k == -1) {
		puts("NO");
		return;
	}

	int prv = -1;
	for (int i = k; i >= 0; --i) {
		if (prv != -1)
			q.erase(mp(c[prv], prv));

		if (!sz(q)) {
			puts("NO");
			return;
		}

		int x = (*q.rbegin()).s;
		if (c[x] < f[i]) {
			puts("NO");
			return;
		}

		q.erase(mp(c[x], x));
		c[x] -= f[i];
		q.insert(mp(c[x], x));

		if (prv != -1)
			q.insert(mp(c[prv], prv));
		prv = x;
	}

	puts("YES");
}

main () {
	precalc();
	int TT = 1;
	fastio
	cin >> TT;
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}