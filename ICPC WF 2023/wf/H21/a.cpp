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
const int N = 1e6, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

int n;

struct Bracket{
	int ind, mnbal, bal;
	Bracket() {
	
	}

	Bracket(string s) {
		bal = 0, mnbal = 0;
		for (auto c : s) {
			if (c == '(')
				bal++;
			if (c == ')')
				bal--;

			mnbal = min(mnbal, bal);
		}
	}
};

Bracket b[M];

bool cmp(Bracket i, Bracket j) {
	if (i.mnbal >= 0 && j.mnbal < 0)
		return 1;

	if (i.mnbal < 0 && j.mnbal >= 0)
		return 0;

	if (i.mnbal >= 0 && j.mnbal >= 0)
		return (i.ind < j.ind);

	//mnbal < 0
	pii ii = mp(min(i.mnbal, i.bal + j.mnbal), i.bal);
	pii jj = mp(min(j.mnbal, j.bal + i.mnbal), j.bal);

	return ii > jj;
}
 
void solve() {
	fastio
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		b[i] = Bracket(s);
		b[i].ind = i;
		sum += b[i].bal;
	}

	if (sum != 0) {
		cout << "impossible\n";
		return;
	}


	sort(b + 1, b + 1 + n, cmp);
//	for (int i = 1; i <= n; ++i)
//		cerr << b[i].ind << endl;

	for (int i = 1; i <= n; ++i) {
		if (sum + b[i].mnbal < 0) {
			cout << "impossible";
			return;
		}

		sum += b[i].bal;
	}

	for (int i = 1; i <= n; ++i)
		cout << b[i].ind << "\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}