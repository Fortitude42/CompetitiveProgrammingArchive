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
const int N = 2e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;

vi get(vi mask) {
	vi mask1(n);
	for (int i = 0; i < n; ++i) {
		if (mask[i])
			continue;

		int cnt = 0;
		if (i > 0 && mask[i - 1])
			++cnt;
		if (i < n - 1 && mask[i + 1])	
			++cnt;

		if (cnt == 1)
			mask1[i] = 1;
	}

	return mask1;
}

 
void solve() {
	srand(time(0));
	cin >> n;

		
	if (n == 3) {
		cout << "Unlucky";
		return;
	}

	vi zero(n);

	int timer = 0, x = 0;
	while (1) {
		vi R, RR;
		for (int i = 0; i < n; ++i)
			R.pb(rand() & 1);

		 
		x = (x + 1) % n;	
		for (int i = 0; i < x; ++i)
			if (i % 2)
				R[i] = 1;
				else
					R[i] = 0;			



		if (timer < 8) {
			for (int i = 0; i < n; ++i)
				R[i] = (timer >> (i % 3)) & 1;
		}
		++timer;

			
		int m = 2*n + 1;

		set < vi > q;
		bool ok = 1, ok1 = 0;

		RR = R;
		while (m--) {
			if (q.count(R)) 
				ok1 = 1;			
			q.insert(R);
			R = get(R);
			if (R == zero) {
				ok = 0;      
				break;
			}
		}


		if (ok && ok1) {
			for (auto x : RR)
				cout << x;
			return;
		}
	}
}

main () {
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

