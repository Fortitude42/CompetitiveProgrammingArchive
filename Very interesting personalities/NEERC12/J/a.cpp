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

int a, b, c;
bool was[M];
vi steps;

bool in(int x) {
	return x >= 0 && x <= a + b + c;
}
 
void rec(int pos, int aa, int bb, int cc) {
	steps.pb(pos);
	was[pos] = 1;

	if (sz(steps) == a + b + c + 1) {
		if (steps.back() == a + b + c) {
			for (int i = 0; i < sz(steps); ++i)
				cout << steps[i] << ' ';
			cout << endl;
			for (int i = 1; i < sz(steps); ++i)
				cout << steps[i] - steps[i - 1] << ' ';
			cout << endl;
			exit(0);
		}
		

		steps.ppb();
		was[pos] = 0;
		return;
	}

	for (int ii = 3; ii > 0; --ii) {
		int i = 4 - ii;
		int na = aa - (i == 1), nb = bb - (i == 2), nc = cc - (i == 3);
		if (na < 0 || nb < 0 || nc < 0)
			continue;

		if (in(pos + i) && !was[pos + i])
			rec(pos + i, na, nb, nc);
	}

	for (int ii = 3; ii > 0; --ii) {
		int i = 4 - ii;
		int na = aa - (i == 1), nb = bb - (i == 2), nc = cc - (i == 3);
		if (na < 0 || nb < 0 || nc < 0)
			continue;
		if (in(pos - i) && !was[pos - i]) 
			rec(pos - i, na, nb, nc);
	}



	steps.ppb();
	was[pos] = 0;
}

void solve() {
	cin >> a >> b >> c;
	rec(0, a, b, c);
}

main () {

	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

