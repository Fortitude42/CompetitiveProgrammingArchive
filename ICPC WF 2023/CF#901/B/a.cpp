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

queue < pii > q;
map < pii, int > D;
int a, b, m, mx;
int c, d;

int getRand() {
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)
			res |= (1 << i);

	return res;
}

void ch(int x, int y, int c) {
	if (!D.count(mp(x, y))) {
		mx = max(mx, c);
		D[mp(x, y)] = c;
		q.push(mp(x, y));
	}
}
 
void solve() {
//	cin >> a >> b >> c >> d >> m;
//	a = getRand(), b = getRand(), m = getRand();
//	c = getRand(), d = getRand();
	for (int i = 0; i < 30; ++i) {
		if (i < 20)
			a |= (1 << i);
		if (i > 10)
			b |= (1 << i);

		if (i & 1)
			m |= (1 << i);
			
	}
	D.clear();


	D[mp(a, b)] = 0;
	q.push(mp(a, b));
	while (sz(q)) {
		int x = q.front().f, y = q.front().s;
		int cur = D[mp(x, y)];
		q.pop();

		ch(x & y, y, cur + 1);
		ch(x | y, y, cur + 1);
		ch(x, x^y, cur + 1);
//		ch(x, y^m, cur + 1);
	}
/*
	if (D.count(mp(c, d)))
		cout << D[mp(c, d)] << "\n";
	else
		cout << -1 << "\n";

    cout << sz(D) << endl;
	for (auto x : D) {
		cout << x.f.f << ' ' << x.f.s << ' ' << x.s << endl;
	}*/

//	assert(sz(d) <= 1552);
	cerr << a << ' ' << b << ' ' << m << ' ' << sz(D) << endl;
}

main () {
	srand(time(0));
  int TT;
  TT = 1;
  	fastio
//	cin >> TT;
	TT = 100;
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}